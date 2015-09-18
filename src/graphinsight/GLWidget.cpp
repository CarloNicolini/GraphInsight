/****************************************************************************
**
** Copyright (C) 2010 Michele Dallachiesa (michele.dallachiesa@gmail.com)
** All rights reserved.
**
** Warning: This program is protected by copyright law and international
** treaties. Unauthorized reproduction and distribution of this program,
** or any portion of it, may result in severe civil and criminal penalties,
** and will be persecuted to the maximum extent possible under the law.
**
****************************************************************************/

#include <QPainter>
#include <stdexcept>
#include "GLWidget.h"
#include "Common.h"
#include "QUtils.h"
#include "Statistic.h"
#include "ui_HelpDialog.h"

#include "LicenseType.h"
#include <Eigen/Core>
#include <Eigen/Geometry>


#ifndef GL_MULTISAMPLE
#define GL_MULTISAMPLE  0x809D
#endif


using namespace Eigen;

// opengl+qt: http://www.informit.com/articles/article.aspx?p=1405557
// funzionalita  avanzate antialiasing: http://developer.nvidia.com/forums/index.php?showtopic=4732
// problemi eventuali con glitch ed opengl https://bugreports.qt-project.org/browse/QTBUG-17869
/**
 * @brief GLWidget::GLWidget
 * @param parent
 */
GLWidget::GLWidget(QWidget *parent)
    : QGLWidget(QGLFormat(QGL::SampleBuffers), parent),
      autoRotation(DEFAULT_AUTOROTATION),
      fastGraph(DEFAUT_FAST_GRAPH),
      updateFastGraph(DEFAUT_FAST_GRAPH),
      textureId(-1),
      isMoving(false)
{
    this->fps = 0;
    this->layoutThread.initEmptyGraph();
    this->skipResetScene = false;
    this->rotationEnabled = true;
    this->options.drawNodes=true;
    this->startTimer(1000 / 60); // 60 fps
    // Very important
    this->setAutoFillBackground(false);
    this->useGLSLShaders=false;
    this->glWidgetTimer.start();
    this->keyShiftPressed=false;
    this->isDrawingSelectionRectangle=false;
    //#define MULTIPLE_NODES_SELECTION
    // Enable mouse tracking
#ifdef MULTIPLE_NODES_SELECTION
    this->setMouseTracking(true);
#endif
    // Load a simple GLSL shader
    /*
    if (this->useGLSLShaders)
        this->loadShader("GlossyReflection.vert","GlossyReflection.frag","chrome.bmp");
    */
    // Set default values
    this->glEnabled=true;
    this->nonIntersectingLabels=false;
    // Set 0 quality level for new graph
    this->setQuality(0);
}

/**
 * @brief GLWidget::saveFile
 * @param pathname
 * @return
 */
bool GLWidget::saveFile(const QString &pathname)
{  QProgressDialog progress("Saving graph (with layout) to file...", NULL, 0, 2);
    progress.setWindowModality(Qt::WindowModal);
    progress.setValue(1);
    progress.show();

    QFileInfo fi(pathname);

    layoutThread.layoutMutex.lock();

    layoutThread.dataSet.graphGL->normalizeCoordinates();

    bool ret = false;
    layoutThread.dataSet.errorMessage  = "Unknown file extension";

    if(fi.suffix().compare(QString("cnf"),Qt::CaseInsensitive) == 0)
    {  ret = true; // nothing to save
    }

    if(fi.suffix().compare(QString("cnf2"),Qt::CaseInsensitive) == 0)
    {  ret = true; // nothing to save
    }

    if(fi.suffix().compare(QString("dimacs"),Qt::CaseInsensitive) == 0)
    {  ret = layoutThread.dataSet.writeDimacs(pathname);
    }

    if(fi.suffix().compare(QString("net"),Qt::CaseInsensitive) == 0)
    {  ret = layoutThread.dataSet.writePajek(pathname);
    }

    if(fi.suffix().compare(QString("dot"),Qt::CaseInsensitive) == 0)
    {  ret = layoutThread.dataSet.writeDot(pathname);
    }

    if(fi.suffix().compare(QString("gp"),Qt::CaseInsensitive) == 0)
    {  ret = layoutThread.dataSet.writeGnuPlotBW(pathname);
    }

    if(fi.suffix().compare(QString("gpc"),Qt::CaseInsensitive) == 0)
    {  ret =    layoutThread.dataSet.writeGnuPlotColors(pathname);
    }

    if(fi.suffix().compare(QString("svg"),Qt::CaseInsensitive) == 0)
    {  ret =    layoutThread.dataSet.writeSvg(pathname);
    }

    layoutThread.layoutMutex.unlock();

    progress.setValue(2);
    progress.show();
    return ret;
}

void checkGLErrors(const QString& prefix)
{
    switch (glGetError()) {
    case GL_NO_ERROR:
        //qDebug() << prefix << tr("No error.");
        break;
    case GL_INVALID_ENUM:
        qDebug() << prefix << QObject::tr("Invalid enum.");
        break;
    case GL_INVALID_VALUE:
        qDebug() << prefix << QObject::tr("Invalid value.");
        break;
    case GL_INVALID_OPERATION:
        qDebug() << prefix << QObject::tr("Invalid operation.");
        break;
    case GL_STACK_OVERFLOW:
        qDebug() << prefix << QObject::tr("Stack overflow.");
        break;
    case GL_STACK_UNDERFLOW:
        qDebug() << prefix << QObject::tr("Stack underflow.");
        break;
    case GL_OUT_OF_MEMORY:
        qDebug() << prefix << QObject::tr("Out of memory.");
        break;
    default:
        qDebug() << prefix << QObject::tr("Unknown error.");
        break;
    }
}

/**
 * @brief GLWidget::paintGL
 */
void GLWidget::paintGL()
{
    paintEvent(NULL);
}

/**
 * @brief GLWidget::paintEvent
 */
void GLWidget::paintEvent(QPaintEvent *event)
{
    this->makeCurrent();
    static int frameCounter = 0;
    static long elapsedTime = 0;

    if(!glEnabled)
    {  glMatrixMode(GL_MODELVIEW);
        if(options.nightMode)
        {
            //qglClearColor(Qt::black);
            glClearColor(AMBIENT_COLOR_BLACK, 0.0f);
        }
        else
        {
            //qglClearColor(Qt::white);
            glClearColor(AMBIENT_COLOR_WHITE, 0.0f);
        }
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
        glLoadIdentity();
        return;
    }

    GraphLayoutGL *g = static_cast<GraphLayoutGL *>(layoutThread.dataSet.graphGL->g);
    layoutThread.layoutMutex.lock();
    // update fps stats
    if(frameCounter == 0)
    {  glWidgetTimer.start();
        //myElapsedTime(&fpsBegin, &fpsEnd, true);
    }
    frameCounter++;

    // reset opengl scene
    glMatrixMode(GL_MODELVIEW);

    if(options.nightMode)
    {  glClearColor(AMBIENT_COLOR_BLACK, 0.0f);
    }
    else
    {  glClearColor(AMBIENT_COLOR_WHITE, 0.0f);
    }

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity(); // Load the Identity Matrix to reset our drawing locations
    gluLookAt((cameraPosition[0]+ cameraTranslation[0]),
            (cameraPosition[1]+cameraTranslation[1]),
            cameraPosition[2] * (zoom),
            (cameraPosition[0]+ cameraTranslation[0]),
            (cameraPosition[1]+cameraTranslation[1]),
            0.0, 0.0,1.0, 0.0);

    if(options.showGrid)
    {
        glPushAttrib(GL_ALL_ATTRIB_BITS);
        glEnable(GL_FOG);
        glFogi(GL_FOG_MODE, GL_EXP2);
        glFogf(GL_FOG_DENSITY, .1f);
        Eigen::Matrix<GLfloat,1,4> fogColor;
        if(options.nightMode)
        {
            fogColor <<  0.0f,0.0f,0.0f,1.0f; // color of fog
            glColor4f(0.8f,0.8f,0.8f,1.0f);   // color of lines
        }
        else
        {
            fogColor<< 1.0f, 1.0f, 1.0f, 1.0f;
            glColor4f(0.5,0.5,0.5,1);
        }
        // Color the fog, in night mode the fog is black
        glFogfv(GL_FOG_COLOR, fogColor.data());

        glLineWidth(2.0);
        GLUtils::drawGrid(-200,-2 * options.boundingRadius * 2/ 3 ,-200, 400.0, 400, 90, 1.0, 0.0, 0.0);

        if(options.nightMode)
        {  glColor4f(0.3f,0.3f,0.3f,0.5f);
        }
        else
        {
            fogColor<< 1.0f, 1.0f, 1.0f, 1.0f;
            glColor4f(0.5f,0.5f,0.5f,0.5f);
        }

        GLUtils::drawPlane(-200,-2.1* options.boundingRadius * 2/ 3 ,-200, 400.0, 90, 1.0, 0.0, 0.0);
        glDisable(GL_FOG);
        glPopAttrib();
    }

    if(layoutThread.dataSet.graphGL->nDimensions == 2)
    {  glRotatef(objectRotationAngle[0], 0.0f,1.0f, 0.0f); // Rotate our object around the y axis
        glRotatef(objectRotationAngle[1], 1.0f, 0.0f, 0.0f); // Rotate our object around the x axis
        glRotatef(objectRotationAngle[2], 0.0f, 0.0f, 1.0f); // Rotate our object around the z axis

    }
    else
    {  arcball.applyRotationMatrix();
    }

    options.glListId = listId;
    options.glWidget = this;

    //g->assertConsistentCoordinates();

    // Draw the graph layout
#ifdef USESHADERS
    if (this->useGLSLShaders)
        this->beginShader();
#endif
    g->draw(&options,this->fastGraph,updateFastGraph,false);
    glPushAttrib(GL_ALL_ATTRIB_BITS);
    if(layoutThread.dataSet.graphGL == g)
    {  g->drawSelectedNodeAndEdges(&options);
    }
    glPopAttrib();

#ifdef MULTIPLE_NODES_SELECTION
    // Draw the selected nodes in red
    if (!this->selectedNodesList.empty())
    {
        g->drawSelectedNodesList(this->selectedNodesList,&options);
    }
#endif
#ifdef USESHADERS
    if (this->useGLSLShaders)
        this->endShader();
#endif
    if(layoutThread.dataSet.graphGL->nDimensions == 2)
    {
        glEnable(GL_DEPTH_TEST);
    }

    updateFastGraph = false; // if true, set it to false. otherwise, nothing changes.

    glPushAttrib(GL_ALL_ATTRIB_BITS);
    glColor4f(0.0f,0.0f,1.0f,0.2f);
    this->showLogo(options.nightMode);

    // se è attivo il calcolo dell'intersezione delle label usa la coppia computeLabels-drawAllLabels
    // altrimenti usa l'opzione anti-intersezione usa la vecchia funzione per le label, molto più veloce per la navifzione
    if (nonIntersectingLabels)
    {  g->drawLabelsNonIntersectingMode(&options, layoutThread.dataSet, layoutThread.dataSet.graphGL == g->g);
    }
    else
        g->drawAllNodeLabels(&options, layoutThread.dataSet, layoutThread.dataSet.graphGL == g->g);
    glPopAttrib();
    //elapsedTime = myElapsedTime(&fpsBegin, &fpsEnd, false);
    elapsedTime  = glWidgetTimer.getElapsedTimeInMicroSec();
    if(elapsedTime >= 5000000)
    {  fps = frameCounter / 5.0f;
        elapsedTime = 0;
        frameCounter = 0;
    }

    // Draw the selection rectangle
#ifdef MULTIPLE_NODES_SELECTION
    if (isDrawingSelectionRectangle)
    {
        QRect selectionRectangle(this->selectionRectangleStart,this->selectionRectangleEnd);
        QPainter painter(this);
        painter.begin(this);
        painter.setRenderHint(QPainter::Antialiasing);
        painter.setRenderHint(QPainter::TextAntialiasing);
        painter.save();
        painter.setPen(QColor(255,0,0,64));
        painter.setBrush(QBrush(QColor(255,0,0,64)));
        painter.drawRect(selectionRectangle);
        painter.restore();
        painter.end();
    }
#endif

    layoutThread.layoutMutex.unlock();
    emit paintFinished(fps);
#ifdef DEBUG
    checkGLErrors("OPENGL-ERROR:");
#endif
}

/**
 * @brief GLWidget::showLogo
 * @param isNightMode
 */
void GLWidget::showLogo(bool isNightMode)
{
    QFont f = this->font();
    f.setPointSize(15);
    if(isNightMode)
    {  glColor4f(1.0,1.0,1.0,1);
    }
    else
    {  glColor4f(0.0,0.0,0.0,1);
    }
    renderText(width()-220,height()-70,QString("Powered by"),f, layoutThread.dataSet.graphGL->nodes.size()+1);

    f.setPointSize(16);
    f.setBold(true);
    renderText(width()-220,height()-50,QString("GraphInsight!"),f, layoutThread.dataSet.graphGL->nodes.size()+1);
    if(isNightMode)
    {  glColor4f(0.5,0.5,0.5,1);
    }
    else
    {  glColor4f(0.0,0.0,0.0,0.5);
    }
    f.setPointSize(12);
    renderText(width()-220,height()-35,QString("www.GraphInsight.com"),f, layoutThread.dataSet.graphGL->nodes.size()+1);

    // For Professional and academic license, avoid watermarking
    if (LicenseType == ProfessionalLicense || LicenseType == AcademicLicense)   // Professional
        return;

    // For TrialLicense put a dense watermark
    double waterMarkAlpha=0.1;
    if (LicenseType==TrialLicense)
        waterMarkAlpha=0.1;

    if(isNightMode)
    {  glColor4f(1,1,1,waterMarkAlpha);
    }
    else
    {  glColor4f(0,0,0,waterMarkAlpha);
    }

    //srand(0);
    for(int i = 0; i < height();)
    {  int inc = 100;//+rand()%20;
        i += inc;
        f.setPixelSize(60);
        renderText(-width()/2,i,QString("GraphInsight GraphInsight GraphInsight GraphInsight GraphInsight GraphInsight"),f, layoutThread.dataSet.graphGL->nodes.size()+1);
    }
}

/**
 * @brief GLWidget::resizeGL
 * @param width
 * @param height
 */
void GLWidget::resizeGL(int width, int height)
{
    glViewport(0, 0, (GLsizei) width, (GLsizei) height); // Set our viewport to the size of our window
    glMatrixMode(GL_PROJECTION); // Switch to the projection matrix so that we can manipulate how our scene is viewed
    glLoadIdentity(); // Reset the projection matrix to the identity matrix so that we don't get any artifacts (cleaning up)
    gluPerspective(45.0, (GLfloat) width / (GLfloat) height, 0.0001, 100.0); // Set the Field of view angle (in degrees), the aspect ratio of our window, and the new and far planes
    glMatrixMode(GL_MODELVIEW); // Switch back to the model view matrix, so that we can start drawing shapes correctly
    arcball.setWidthHeight(width, height);
}

/**
 * @brief GLWidget::gGetSelectedObjectId
 * @param x
 * @param y
 * @return
 */
int GLWidget::getSelectedObjectId(int x, int y)
{
    QMutexLocker locker(&layoutThread.layoutMutex);
    if(layoutThread.dataSet.graphGL != layoutThread.dataSet.graphGL->g)
        return -1;

    // http://www.lighthouse3d.com/opengl/picking/index.php?openglway3
    // http://glprogramming.com/red/chapter13.html

    GLuint selectBuf[SELECTION_BUFFER_SIZE];
    GLint viewport[4];
    glPushAttrib(GL_ALL_ATTRIB_BITS);
    glSelectBuffer(SELECTION_BUFFER_SIZE, selectBuf);
    glRenderMode(GL_SELECT);

    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();

    glGetIntegerv(GL_VIEWPORT, viewport);

    int threshold;
    if(options.sphereQuality == 0)
    {  threshold = options.nodeRadius * 600;
    }
    else
    {  threshold = 5;
    }

    gluPickMatrix(x, viewport[3] - y, threshold, threshold, viewport);
    // Set the Field of view angle (in degrees), the aspect ratio of our window, and the new and far planes
    gluPerspective(45.0, (GLfloat) width() / (GLfloat) height(), 0.01, 100.0);
    glMatrixMode(GL_MODELVIEW);
    glInitNames();
    // draw selectable objects....
    layoutThread.dataSet.graphGL->draw(&options, false, false, true);
    // end.
    // restoring the original projection matrix
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    glFlush();
    // returning to normal rendering mode
    int hits = glRenderMode(GL_RENDER);
    // if there are hits process them
    if (hits == 0)
    {  //cerr << "gGetSelectedObjectId " << x << " " << y << " = " << -1 << "\n";
        glPopAttrib();
        return -1;
    }
    GLuint names, z, zmin = 0xffffffff;
    GLuint *p = static_cast<GLuint*>(selectBuf);
    int retId = -1;
    for (int i = 0; i < hits; i++)
    {  names = p[0];
        z = p[1];
        p += 3;
        for (GLuint j = 0; j < names; j++)
        {  GLuint id = *(p++);
            if (z < zmin)
            {  retId = id;
                zmin = z;
            }
        }
    }
    glPopAttrib();
    return retId;
}

/**
 * @brief GLWidget::wheelEvent
 * @param event
 */
void GLWidget::wheelEvent(QWheelEvent * event)
{  zoom -= (double)event->delta() * 0.001 *zoom;
    if(zoom <= 0.001)
        zoom = 0.001;

    if(zoom > 2.0)
        zoom = 2.0;

    reachInitialZoom = false;
    update();
}

/**
 * @brief GLWidget::mouseDoubleClickEvent
 * @param event
 */
void GLWidget::mouseDoubleClickEvent(QMouseEvent *event)
{
    if (event->type() == QEvent::MouseButtonDblClick)
    {  int id = getSelectedObjectId(event->x(), event->y());
        if(id != -1)
        {  layoutThread.layoutMutex.lock();
            setSelectedNode(id);
            layoutThread.layoutMutex.unlock();
            runDefaultAction(id);
        }
        else
        {  unselectNode();
        }
        keyShiftPressed=false;
        isDrawingSelectionRectangle=false;
        selectedNodesList.clear();
    }
    update();
}


/**
 * @brief GLWidget::mousePressEvent
 * @param event
 */
void GLWidget::mousePressEvent(QMouseEvent *event)
{
#ifdef MULTIPLE_NODES_SELECTION
    if (keyShift)
    {
        keyCmd=false;
        // Update the projections
        Timer timer; timer.start();
        this->layoutThread.dataSet.graphGL->computeGraphNodesProjectionsXY();
        qDebug() << "Time to compute projections= " << timer.getElapsedTimeInMilliSec();
        // If the SHIFT key is being pressed, then take the starting point of the selection rectangle
        isDrawingSelectionRectangle=true;
        selectionRectangleStart = QPoint(event->pos().x(),event->pos().y());
        this->selectedNodesList.clear();
        qDebug() << "Start drawing rectangle in " << event->pos().x() << "," << event->pos().y();
    }
#endif
    reachInitialZoom = false;
    mouseDownX = event->x();
    mouseDownY = event->y();

    if (event->button() == Qt::LeftButton)
    {  int id = getSelectedObjectId(event->x(), event->y());
        if(id != -1)
        {  layoutThread.layoutMutex.lock();
            setSelectedNode(id);
            layoutThread.layoutMutex.unlock();
        }
    }

    arcball.startRotation(mouseDownX,mouseDownY);
    update();
}

/**
 * @brief GLWidget::enableFastGraph
 */
void GLWidget::enableFastGraph()
{  fastGraph = true;
    updateFastGraph = true;
}

/**
 * @brief GLWidget::disableFastGraph
 */
void GLWidget::disableFastGraph()
{  fastGraph = false;
}

/**
 * @brief GLWidget::mouseReleaseEvent
 * @param event
 */
void GLWidget::mouseReleaseEvent(QMouseEvent *event)
{
    this->mouseDownX=event->x();
    this->mouseDownY=event->y();
#ifdef MULTIPLE_NODES_SELECTION
    if (keyShift && isDrawingSelectionRectangle)
    {
        //qDebug() << "mouse released in (" << event->pos().x() << "," << event->pos().y() <<")";
        //keyShift=false;
        isDrawingSelectionRectangle=false;
        for (NodesRand::const_iterator iter = this->layoutThread.dataSet.graphGL->nodesRand.begin();
             iter!=this->layoutThread.dataSet.graphGL->nodesRand.end();++iter)
        {
            LNode *n = static_cast<LNode*>(*iter);
            if ((n->labelX >= selectionRectangleStart.x() &&  n->labelX <= selectionRectangleEnd.x() &&
                 n->labelY >= selectionRectangleStart.y() && n->labelY <= selectionRectangleEnd.y())
                    ||
                    (n->labelX >= selectionRectangleEnd.x() &&  n->labelX <= selectionRectangleStart.x() &&
                     n->labelY >= selectionRectangleEnd.y() && n->labelY <= selectionRectangleStart.y()) )
            {
                qDebug() << "Inserted node " << n->id << " " << n->ptrEntity->toQString() ;
                this->selectedNodesList.push_back(n);
            }
        }
    }
#endif
    options.sphereQuality = options.sphereQualityOrig;

    isMoving = false;

    arcball.stopRotation();

    update();
}

/**
 * @brief GLWidget::keyReleaseEvent
 * @param event
 */
void GLWidget::keyReleaseEvent(QKeyEvent *event)
{
    switch((int)event->key())
    {
    case Qt::Key_Control:
    {
        this->keyCmdPressed = false;
#ifdef MULTIPLE_NODES_SELECTION
        this->setMouseTracking(true);
#endif
        break;
    }
    case ' ':
    {
        this->keySpacePressed = false;
        break;
    }
    case Qt::Key_Shift:
    {
        this->keyShiftPressed=false;
        this->isDrawingSelectionRectangle=false;
        this->selectionRectangleStart=this->selectionRectangleEnd=QPoint(-100,-100);
        break;
    }
    default:
    {
        QGLWidget::keyReleaseEvent(event);
        break;
    }
    }

    update();
}

/**
 * @brief GLWidget::keyPressEvent
 * @param event
 */
void GLWidget::keyPressEvent(QKeyEvent *event)
{
    switch((int)event->key())
    {  case Qt::Key_Control:
    {
        keyCmdPressed = true;
#ifdef MULTIPLE_NODES_SELECTION
        this->setMouseTracking(false);
#endif
        break;
    }
    case Qt::Key_Space:
    {
        keySpacePressed = true;
        break;

    }
    case Qt::Key_H:
        //case (int)'h':
    {
        showHelp();
        break;
    }
    case Qt::Key_Shift:
    {
        keyShiftPressed=true;
        this->selectionRectangleStart = QPoint(this->currentMouseX,this->currentMouseY);
        this->selectionRectangleEnd = QPoint(this->currentMouseX,this->currentMouseY);
        qDebug() << "When pressed shift position= " << this->currentMouseX << " " << this->currentMouseY ;
        break;
    }
    default:
    {
        QGLWidget::keyPressEvent(event);
        break;
    }
    }

    reachInitialZoom = false;

    update();
}

/**
 * @brief GLWidget::mouseMoveEvent
 * @param event
 */
#include <QEvent>
void GLWidget::mouseMoveEvent(QMouseEvent *event)
{
    this->currentMouseX = event->pos().x();
    this->currentMouseY = event->pos().y();
    // If defined allows to select many nodes a time displaying a red rectangle
#ifdef MULTIPLE_NODES_SELECTION
    if (keyShift && isDrawingSelectionRectangle )
    {
        selectionRectangleEnd = QPoint(currentMouseX,currentMouseY);
        //qDebug() << "rectangle size" << selectionRectangleEnd.x()-selectionRectangleStart.x() << "," << selectionRectangleEnd.y()-selectionRectangleStart.y();
        update();
        return;
    }
#endif

    isMoving = true;
    if (layoutThread.dataSet.graphGL->nodesRand.size()>1000)
        options.sphereQuality = std::min(options.sphereQualityOrig, 5);
    float xoff = (float) (event->x() - mouseDownX) ;
    float yoff = (float) (event->y() - mouseDownY) ;

    mouseDownX = event->x();
    mouseDownY = event->y();

    switch(layoutThread.dataSet.graphGL->nDimensions)
    {  case 2:
        if(keyCmdPressed)
        {  if (abs(xoff) > abs(yoff))
            {  yoff = 0;
            }
            else
            {  xoff = 0;
            }
            objectRotationAngle[2] -= xoff + yoff; // in 2d, consideriamo entrambe le direzioni per rotazioni sullo stesso asse, Z.
        }
        else
        {  cameraTranslation[0] -= xoff * 0.01 * (zoom+0.01);
            cameraTranslation[1] += yoff * 0.01 * (zoom + 0.01);
        }
        break;

    case 3:
        if(keyCmdPressed)
        {  cameraTranslation[0] -= xoff * 0.01 * (zoom+0.01);
            cameraTranslation[1] += yoff * 0.01 * (zoom + 0.01);
        }
        else
        {  // le rotazioni sono sempre solo su un asse,
            // ed assumiamo che quindi l'utente voglia ruotare lungo l'asse
            // con la maggior differenza.
            if (abs(xoff) > abs(yoff))
                yoff = 0;
            else
                xoff = 0;

            arcball.updateRotation(event->x(),event->y());

            objectRotationAngle[0] += xoff;
            if(keySpacePressed)
                objectRotationAngle[2] += yoff;
            else
                objectRotationAngle[1] += yoff;

            normalizeObjectRotationAngle();
        }
        break;

    default:
        std::logic_error("Not supported key");
        exit(0);
    }

    // limit camera translation...
    if(cameraTranslation[0] > 1)
        cameraTranslation[0] = 1;
    if(cameraTranslation[1] > 1)
        cameraTranslation[1] = 1;
    if(cameraTranslation[2] > 1)
        cameraTranslation[2] = 1;
    if(cameraTranslation[0] < -1)
        cameraTranslation[0] = -1;
    if(cameraTranslation[1] < -1)
        cameraTranslation[1] = -1;
    if(cameraTranslation[2] < -1)
        cameraTranslation[2] = -1;
    update();
}

/**
 * @brief GLWidget::normalizeObjectRotationAngle
 */
void GLWidget::normalizeObjectRotationAngle()
{  for (int i = 0; i <= 2; i++)
    {  if (objectRotationAngle[i] > 360.0f)
            objectRotationAngle[i] -= 360.0f;
        if (objectRotationAngle[i] < 0)
            objectRotationAngle[i] = 360.0f;
    }
}

/**
 * @brief GLWidget::autoRotateStep
 */
void GLWidget::autoRotateStep()
{  if(!rotationEnabled)
        return;

    if(layoutThread.dataSet.graphGL->nDimensions == 3)
    {  objectRotationAngle[0] += 0.5f;
    }
    else
    {  objectRotationAngle[0] = 0.0f;
        objectRotationAngle[1] = 0.0f;
        objectRotationAngle[2] -= 0.5f;
    }
    normalizeObjectRotationAngle();
}

/**
 * @brief GLWidget::timerEvent
 * @param event
 */
void GLWidget::timerEvent(QTimerEvent *event)
{  if(!glEnabled)
    {  return;
    }

    static bool flip = false;
    static int steps = 0, stepsNew = 0;

    //double elapsedTime = myElapsedTime(&begin, &end, flip = !flip);
    double elapsedTime=0.0;
    // double thisElapsedTime  = glWidgetTimer.getElapsedTimeInMicroSec();
    if ( !flip )
        elapsedTime = glWidgetTimer.getElapsedTimeInMicroSec();
    else
        glWidgetTimer.start();

    if (reachInitialZoom)
    {
        double cameraZoomSpeed  = 800000;
        zoom -= elapsedTime/cameraZoomSpeed * (zoom - initialZoom);
        if (zoom - 0.001 <= initialZoom)
        {  zoom = initialZoom;
            reachInitialZoom = false;
        }
        update();
    }

    if (autoRotation)
        autoRotateStep();

    int completed;
    layoutThread.layoutMutex.lock();
    emit graphStatsChanged(layoutThread.dataSet.graphGL->statsNodesCount, layoutThread.dataSet.graphGL->statsEdgesCount, layoutThread.stepsCount, layoutThread.elapsedTime,layoutThread.statusText);
    completed = layoutThread.layoutCompleted;
    stepsNew = layoutThread.stepsCount;
    if(completed)
        layoutThread.layoutCompleted = false;
    layoutThread.layoutMutex.unlock();

    if(completed)
    {  emit layoutCompleted();
        update(); // serve per tecniche HDE/Circular da singolo step.
    }

    if(steps != stepsNew)
    {  update();
    }

    steps = stepsNew;
}

/**
 * @brief GLWidget::reload
 * @param methodType
 * @param nDimensions
 */
void GLWidget::reload(int methodType, int nDimensions)
{

    layoutThread.stopMe();

    while(layoutThread.isRunning())
    {
#ifdef _WIN32
        usleepwin32(1);
#else
        usleep(1);
#endif
    }

    layoutThread.initReload( methodType, nDimensions);
    layoutThread.start(QThread::LowestPriority);

    while(!layoutThread.doingSteps)   // || interruptAction from user interaction
    {
#ifdef _WIN32
        usleepwin32(1);
#else
        usleep(1);
#endif
    }

    if(layoutThread.dataSet.graphGL->nDimensions == 2 || methodType == GraphLayout::MethodCircularLayout)
    {  objectRotationAngle[0] = 0.0f;
        objectRotationAngle[1] = 0.0f;
        objectRotationAngle[2] = 0.0f;
    }

}

/**
 * @brief GLWidget::initEmpty
 */
void GLWidget::initEmpty()
{  layoutThread.dataSet.clean();
    if (layoutThread.dataSet.graphGL!=NULL)
        layoutThread.dataSet.graphGL = new GraphLayoutGL();
}

/**
 * @brief GLWidget::openFile
 * @param pathname
 * @param methodType
 * @param nDimensions
 * @return
 */
bool GLWidget::openFile(QString pathname, int methodType, int nDimensions)
{  QProgressDialog progress("Loading graph...", NULL, 0, 3);
    progress.setWindowModality(Qt::WindowModal);
    progress.setValue(0);

    // terminate 2nd thread
    layoutThread.stopMe();
    while(layoutThread.isRunning())
    {  progress.show();
        qApp->processEvents();
#ifdef _WIN32
        usleepwin32(1);
#else
        usleep(1);
#endif
    }
    progress.setValue(1);

    progress.setLabelText("Initializing layout...");

    layoutThread.initOpenFile(pathname,methodType, nDimensions);

    zoom = DEFAULT_ZOOM;
    initialZoom = DEFAULT_INITIAL_ZOOM;
    reachInitialZoom = DEFAULT_REACH_INITIAL_ZOOM;

    layoutThread.start();

    progress.setValue(2);
    layoutThread.wait(1);
    while(!layoutThread.doingSteps && layoutThread.state != 5)
    {
        progress.show();
        qApp->processEvents();
#ifdef _WIN32
        usleepwin32(1);
#else
        usleep(1);
#endif
    }
    progress.setValue(3);
    progress.show();
    qApp->processEvents();

    emit dataSetLoaded();

    progress.close();
    return layoutThread.state != 5;
}

/**
 * @brief GLWidget::setShowEdges
 * @param b
 */
void GLWidget::setShowEdges(bool b)
{  options.drawEdges = b;

    if(b)
    {  disableFastGraph(); // otherwise, edges flag is not considered.
    }

}

/**
 * @brief GLWidget::setFastMode
 * @param b
 */
void GLWidget::setFastMode(bool b)
{

    if(b)
    {  enableFastGraph();
    }
    else
    {  disableFastGraph();
    }
}

/**
 * @brief GLWidget::setAutoRotation
 * @param b
 */
void GLWidget::setAutoRotation(bool b)
{  autoRotation = b;
    //setFastMode(b);
}

/**
 * @brief GLWidget::initializeGL
 */
void GLWidget::initializeGL()
{
    // inits a lot of scene vars, without GL calls.
    // Sets the lights colors, material colors
    resetScene();
    qglClearColor(Qt::black);
    // http://stackoverflow.com/questions/4207506/where-is-gl-multisample-defined
    glEnable(GL_MULTISAMPLE);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LINE_SMOOTH);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glLineWidth(1.5);
    glEnable(GL_CULL_FACE);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_LIGHTING);

    glHint(GL_POLYGON_SMOOTH_HINT, GL_NICEST);
    glEnable(GL_POLYGON_SMOOTH);

    // set up OpenGL
    glEnable( GL_POINT_SMOOTH );// Smooth out points
    glEnable( GL_LINE_SMOOTH );// Smooth out lines
    glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);// Smooth out lines
    glEnable(GL_BLEND);// Enable Blending
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);// Specifies pixel arithmetic
    glEnable(GL_COLOR_MATERIAL);

    // set up two light sources:

    glMaterialfv(GL_FRONT, GL_AMBIENT, lightAmbient.data());
    glMaterialfv(GL_FRONT, GL_DIFFUSE, lightDiffuse.data());
    glMaterialfv(GL_FRONT, GL_SPECULAR, lightSpecular.data());
    glMaterialf(GL_FRONT, GL_SHININESS, 100.0f);

    glLightfv(GL_LIGHT0, GL_AMBIENT, lightAmbient.data());
    glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDiffuse.data());
    glLightfv(GL_LIGHT0, GL_SPECULAR, lightSpecular.data());
    glLightfv(GL_LIGHT0, GL_POSITION, light0Position.data());
    glEnable(GL_LIGHT0);

    glLightfv(GL_LIGHT1, GL_AMBIENT, lightAmbient.data());
    glLightfv(GL_LIGHT1, GL_DIFFUSE, lightDiffuse.data());
    glLightfv(GL_LIGHT1, GL_SPECULAR, lightSpecular.data());
    glLightfv(GL_LIGHT1, GL_POSITION, light1Position.data());
    glEnable(GL_LIGHT1);

    // glEnable(GL_CULL_FACE);
    glDepthMask(GL_TRUE);

    // This is the id of the whole display list
    listId = glGenLists(1);
}

/**
 * @brief GLWidget::setQuality
 * @param v
 */
void GLWidget::setQuality(int v)
{  // 0 3 4 8 16 24 32 64
    switch(v)
    {  case 0:
        options.sphereQuality = 0;
        break;
    case 1:
        options.sphereQuality = 3;
        break;
    case 2:
        options.sphereQuality = 4;
        break;
    case 3:
        options.sphereQuality = 8;
        break;
    case 4:
        options.sphereQuality = 16;
        break;
    case 5:
        options.sphereQuality = 24;
        break;
    case 6:
        options.sphereQuality = 32;
        break;
    case 7:
        options.sphereQuality = 64;
        break;
    default:
        throw std::out_of_range("Unknown quality level of spheres!");
    }
    options.sphereQualityOrig = options.sphereQuality;
    update();
}

/**
 * @brief GLWidget::setNodeRadius
 * @param v
 */
void GLWidget::setNodeRadius(int v)
{  if(v == 0)
    {  options.drawNodes = false;
        //qDebug() << "now doesn't draw nodes";
    }
    else
    {  options.drawNodes = true;
    }

    options.nodeRadius = options.nodeRadiusFactor  * pow((double)v/50.0f,3) * 0.8;

    update();
}

/**
 * @brief GLWidget::setEdgeRadius
 * @param v
 */
void GLWidget::setEdgeRadius(int v)
{

    if(v == 0)
    {  options.drawEdges = false;
    }
    else
    {  options.drawEdges = true;
    }

    if(options.drawNodes)
    {  options.edgeRadius =  (double)v/100.0f * options.nodeRadius;
    }
    else
    {  options.edgeRadius =  options.edgeRadiusFactor * pow((double)v/50.0f,3);
    }

    update();
}

/**
 * @brief GLWidget::setSpacing
 * @param v
 */
void GLWidget::setSpacing(int v)
{  options.boundingRadius = 1.5f  * pow((double)v/50.0f,5);
}

/**
 * @brief GLWidget::resetScene
 */
void GLWidget::resetScene()
{
    //qDebug() << "CALLING GLWidget::resetScene";
    if(skipResetScene)
        return;
    arcball.reset();
    // camera:position
    cameraPosition<< 0.0f, 0.0f, 4.0f;
    cameraTranslation[0] = 0.0f;
    cameraTranslation[1] = 0.0f;
    cameraTranslation[2] = 0.0f;
    // camera:zoom
    zoom = DEFAULT_ZOOM;
    initialZoom = DEFAULT_INITIAL_ZOOM;
    reachInitialZoom = DEFAULT_REACH_INITIAL_ZOOM;

    startPoint = Vector3d(0,0,0);

    // object

    if(layoutThread.dataSet.graphGL->nDimensions == 3)
    {  objectRotationAngle[0] = 30.0f;
    }
    else
    {  objectRotationAngle[0] = 0.0f;
    }
    objectRotationAngle[1] = 0.0f;
    objectRotationAngle[2] = 0.0f;

    // lights
    lightAmbient << 0.0f, 0.0f, 0.0f, 1.0f;
    lightDiffuse<< 0.8f, 0.8f, 0.8f, 1.0f;
    lightSpecular<< 0.9f, 0.9f, 0.9f, 1.0f;
    light0Position<< 1.0, 1.0, 4.0, 0.0;
    light1Position<< 4.0, 4.0, 0.0, 0.0;

    autoRotation = DEFAULT_AUTOROTATION;
    //sphereRadius = DEFAULT_SPHERE_RADIUS;

    // mouse
    mouseDownX = 0.0f;
    mouseDownY = 0.0f;

    //other
    fastGraph = DEFAUT_FAST_GRAPH;
    updateFastGraph = DEFAUT_FAST_GRAPH;

    keyCmdPressed = false;
    keySpacePressed = false;
    unselectNode();
    update();
}

/**
 * @brief GLWidget::stop
 */
void GLWidget::stop()
{
    if(!layoutThread.isRunning())
        return;
    layoutThread.stopMe();
    if(layoutThread.state >= 3)
    {  while(layoutThread.isRunning())
        {
#ifdef _WIN32
            usleepwin32(1);
#else
            usleep(1);
#endif
        }
        return;
    }
    // layout was not completed, so we may need more time to stop.
    QProgressDialog progress("Stopping layout...", NULL, 0, 1);
    progress.setWindowModality(Qt::WindowModal);
    progress.setAutoClose(true);
    progress.setValue(0);

    while(layoutThread.isRunning())
    {  progress.show();
        qApp->processEvents();
#ifdef _WIN32
        usleepwin32(1);
#else
        usleep(1);
#endif
    }
    progress.setValue(1);

}

/**
 * @brief GLWidget::saveImage
 * @param pathname
 * @return
 */
bool GLWidget::saveImage(const QString &pathname)
{
    QString qpathname(pathname);
    return grabFrameBuffer().save(qpathname, NULL, -1);
}

/**
 * @brief GLWidget::abort
 */
void GLWidget::abort()
{
    layoutThread.stopMe();

    while(layoutThread.isRunning())
    {
#ifdef _WIN32
        usleepwin32(1);
#else
        usleep(1);
#endif
    }


    emit hasAborted();
}


/**
 * @brief GLWidget::setZoom
 * @param v
 */
void GLWidget::setZoom(int v)
{  zoom =  DEFAULT_ZOOM * pow((double)v/50.0f,5);

}

/**
 * @brief GLWidget::randomizeCoordinates
 */
void GLWidget::randomizeCoordinates()
{  layoutThread.dataSet.graphGL->initRandomCoordinates();
}

/**
 * @brief GLWidget::enableRotation
 */
void GLWidget::enableRotation()
{  rotationEnabled = true;
}

/**
 * @brief GLWidget::disableRotation
 */
void GLWidget::disableRotation()
{

    objectRotationAngle[0] = 0.0f;
    objectRotationAngle[1] = 0.0f;
    objectRotationAngle[2] = 0.0f;

    rotationEnabled = false;
}

/**
 * @brief GLWidget::contextMenu
 * @param pos
 */
#include <QMenu>
void GLWidget::contextMenu(const QPoint &pos)
{
    QMenu *menu = new QMenu;
    int id = getSelectedObjectId(pos.x(), pos.y());

    if(id == -1)
    {  LNode *l = layoutThread.dataSet.graphGL->getSelectedNode();
        if(l)
            id = l->id;
    }
    bool sep = false;
    if(id != -1)
    {  this->setSelectedNode(id);
        Entity *e = layoutThread.dataSet.graphGL->nodes[id]->ptrEntity;
        for(vector<EntityAttribute*>::iterator iter1 = e->attributes.begin(); iter1 != e->attributes.end(); ++iter1)
        {
            EntityAttribute *eAttr = (*iter1);
            if (eAttr->valueString.empty())
                continue;
            switch((*iter1)->type)
            {  case EntityAttribute::TypeString:
                menu->addAction(QString("Search in Google for \"").append(QString((*iter1)->toString()->c_str())).append(QString("\"")), this, SLOT(selectedNodeAttrAction()));
                menu->actions().at(menu->actions().size()-1)->setData(qVariantFromValue((void *)*iter1));
                sep = true;
                break;

            case EntityAttribute::TypeUrl:
                menu->addAction(QString("Open Url \"").append(QString((*iter1)->toString()->c_str())).append(QString("\"")), this, SLOT(selectedNodeAttrAction()));
                menu->actions().at(menu->actions().size()-1)->setData(qVariantFromValue((void *)*iter1));
                sep = true;
                break;

            case EntityAttribute::TypeImage:
                menu->addAction(QString("View Image \"").append(QString((*iter1)->toString()->c_str())).append(QString("\"")), this, SLOT(selectedNodeAttrAction()));
                menu->actions().at(menu->actions().size()-1)->setData(qVariantFromValue((void *)*iter1));
                sep = true;
                break;
            }
        }

        //        menu->addAction(QString("Run action on node ").append(QString::number(id)), this, SLOT(selectedNodeAction()));
    }

    if(sep)
    {  menu->addSeparator();
        sep = false;
    }

    if(layoutThread.dataSet.graphGL->getSelectedNode())
    {  menu->addAction(QString("Clear selection"), this, SLOT(unselectNode()));
        sep = true;
    }

    if(sep)
    {  menu->addSeparator();
    }

    menu->addAction(QString("Reset scene"), qApp->activeWindow(), SLOT(resetVisualization()));
    menu->addAction(QString("Save as image..."), qApp->activeWindow(), SLOT(saveImage()));
    /*
    // Remove node menu (XXX)
    //menu->addAction(QString("Remove node"),this->layoutThread.dataSet,SLOT(re))
    //menu->addSeparator();
    menu->addSeparator();

    LNode *n = layoutThread.dataSet.graphGL->getSelectedNode();
    QStringList nodeProperties;
    // Create a menu with all the node properties
    // The first attribute is the title, while the other are the remaining attributes
    if (n!=NULL)
    {
        QMenu *propertiesMenu = menu->addMenu("Properties");
        Entity* e = n->ptrEntity;
        if (!e->attributes.empty())
        {
            QStringList attrsList;

            for (std::vector<EntityAttribute*>::iterator iter = e->attributes.begin(); iter!=e->attributes.end();++iter)
            {
                attrsList.push_back( QString::fromStdString( ((*iter)->valueString) ));
            }
            if (!attrsList.empty())
                propertiesMenu->addAction(attrsList.at(0));
            propertiesMenu->addSeparator();
            for (int i=1; i<attrsList.size();i++)
                propertiesMenu->addAction(attrsList.at(i));
        }

        nodeProperties << "Id:\t" + QString::number(n->id);
        nodeProperties << "Degree:\t" + QString::number(n->degree);
        nodeProperties << "Neighbors count:\t" + QString::number(n->neighborsRand.size());
        nodeProperties << "Weight:\t" + QString::number(n->weight,'g',1);
        nodeProperties << "Component:\t"+  QString::number(n->component);
        nodeProperties << "Coords:\t(" + QString::number(n->px,'g',3) +","+ QString::number(n->px,'g',3) +","+ QString::number(n->pz,'g',3) +")";

        for (int i=0; i<nodeProperties.size();i++)
            propertiesMenu->addAction(nodeProperties.at(i));
    }
*/
    menu->exec(this->mapToGlobal(pos));
}

/**
 * @brief GLWidget::selectedNodeAction
 */
void GLWidget::selectedNodeAction()
{  LNode *selectedNode = layoutThread.dataSet.graphGL->getSelectedNode();
    if(!selectedNode)
        return;

    QDesktopServices::openUrl(QUrl(QString("http://google.com/#q=").append(QString::number(selectedNode->id))));
}

/**
 * @brief GLWidget::unselectNode
 */
void GLWidget::unselectNode()
{
    layoutThread.dataSet.graphGL->setSelectedNode(-1);
    emit selectedNodeChanged(NULL);
    emit nodeUnselected();
}

/**
 * @brief GLWidget::setNodeColorMethod
 * @param methodId
 */
void GLWidget::setNodeColorMethod(int methodId)
{  options.nodeColorMethodId = methodId;
    //  DEBUG_PRINT("nodeColorMethod = " << methodId);

    update();
}

/**
 * @brief GLWidget::setEdgeColorMethod
 * @param methodId
 */
void GLWidget::setEdgeColorMethod(int methodId)
{  options.edgeColorMethodId = methodId;
    update();
}

/**
 * @brief GLWidget::setSelectedNode
 * @param id
 */
void GLWidget::setSelectedNode(int id)
{  /* XXX VECCHIA VERSIONE
   LNode *selectedNode = lt.dataSet.graph->getSelectedNode();

   if(selectedNode && selectedNode->id == id) {
       return;
   }

   // options.selectedNodeBigRadius = 2.0;
   lt.dataSet.graph->setSelectedNode(id);
   emit selectedNodeChanged(lt.dataSet.graph->getSelectedNode());
   */
    // VERSIONE CORRETTA CARLO CON GESTIONE ECCEZIONI
    try
    {  layoutThread.dataSet.graphGL->getNode(id);
    }
    catch ( ... )
    {  return;
    }
    layoutThread.dataSet.graphGL->setSelectedNode(id);
    emit selectedNodeChanged(layoutThread.dataSet.graphGL->getSelectedNode());
}

/**
 * @brief GLWidget::selectedNodeAttrAction
 */
void GLWidget::selectedNodeAttrAction()
{
    QAction *action = qobject_cast<QAction *>(sender());
    EntityAttribute *e = static_cast<EntityAttribute *> (action->data().value<void *>());
    std::string s = *e->toString();
    switch(e->type)
    {
    case EntityAttribute::TypeUrl:
    {
        QDesktopServices::openUrl(QUrl(QString(s.c_str())));
        break;
    }
    case EntityAttribute::TypeImage:
    {
        QDesktopServices::openUrl(QUrl(QString("file://").append(QString(s.c_str()))));
        break;
    }
    case EntityAttribute::TypeString:
    {
        QDesktopServices::openUrl(QUrl(QString("http://google.com/#q=").append(QString(s.c_str()))));
        break;
    }
    }
}

/**
 * @brief GLWidget::setFog
 * @param v
 */
void GLWidget::setFog(int v)
{
    double fogv = 0.15f  * pow((double)v/50.0f,2);
    if(v > 0)
    {
        glEnable(GL_FOG);
        glFogi(GL_FOG_MODE, GL_EXP2);
        glFogf(GL_FOG_DENSITY, fogv);
        Eigen::Matrix<GLfloat,1,4> fogColor(1.0f,1.0f,1.0f,1.0f);
        glFogfv(GL_FOG_COLOR, fogColor.data());
    }
    else
    {
        glDisable(GL_FOG);
    }
}

/**
 * @brief GLWidget::showHelp
 */
void GLWidget::showHelp()
{  //  cerr << "showing dialog\n";
    QDialog *w2 = new QDialog();
    Ui_HelpDialog dh;
    dh.setupUi(w2);
    w2->setWindowFlags(Qt::WindowStaysOnTopHint | Qt::SplashScreen);//Qt::SplashScreen
    w2->setWindowTitle("Quick help");
    w2->exec();
}

/**
 * @brief GLWidget::visualizationFilterNodeDegree
 * @param v
 */
void GLWidget::visualizationFilterNodeDegree(int v)
{  options.filterMinNodeDegree = v;

    update();
}

/**
 * @brief GLWidget::setLabelMinNodeDegree
 * @param v
 */
void GLWidget::setLabelMinNodeDegree(int v)
{  options.labelMinNodeDegree = v;

    update();
}

/**
 * @brief GLWidget::setLabelFontSize
 * @param v
 */
void GLWidget::setLabelFontSize(int v)
{  options.labelFontSize = v;
    update();
}

/**
 * @brief GLWidget::setNightMode
 * @param v
 */
void GLWidget::setNightMode(bool v)
{  options.nightMode = v;
    update();

}

/**
 * @brief GLWidget::setLabelShowSelectedItem
 * @param v
 */
void GLWidget::setLabelShowSelectedItem(bool v)
{  options.labelShowSelectedItem = v;
    update();
}

/**
 * @brief GLWidget::setLabelShowSelectedItemAdjacent
 * @param v
 */
void GLWidget::setLabelShowSelectedItemAdjacent(bool v)
{  options.labelShowSelectedItemAdjacent = v;

    update();
}

/**
 * @brief GLWidget::setShowGrid
 * @param v
 */
void GLWidget::setShowGrid(bool v)
{  options.showGrid = v;
    update();

}

/**
 * @brief GLWidget::setEdgeType
 * @param v
 */
void GLWidget::setEdgeType(int v)
{  options.edgeType = v;
    update();

}

/**
 * @brief GLWidget::setGLEnabled
 * @param v
 */
void GLWidget::setGLEnabled(bool v)
{  glEnabled = v;
    update();
}

/**
 * @brief GLWidget::runDefaultAction
 * @param id
 */
void GLWidget::runDefaultAction(int id)
{
    // Currently unused
    return;
    Entity *e = layoutThread.dataSet.graphGL->getSelectedNode()->ptrEntity;
    for(vector<EntityAttribute*>::iterator iter1 = e->attributes.begin(); iter1 != e->attributes.end(); ++iter1)
    {  switch((*iter1)->type)
        {  case EntityAttribute::TypeString:
            QDesktopServices::openUrl(QUrl(QString("http://google.com/#q=").append((*iter1)->toString()->c_str())));
            break;
        case EntityAttribute::TypeUrl:
            QDesktopServices::openUrl(QUrl(QString((*iter1)->toString()->c_str())));
            break;
        case EntityAttribute::TypeImage:
            QDesktopServices::openUrl(QUrl(QString("file://").append(QString((*iter1)->toString()->c_str()))));
            break;
        default:
            exit(1);
        }
    }

}

/**
 * @brief GLWidget::setNonIntersectingLabels
 * @param val
 */
void GLWidget::setNonIntersectingLabels(bool val)
{
    nonIntersectingLabels=val;
    //qDebug() << this->width() << " " << this->height() << endl;
    layoutThread.dataSet.graphGL->setWidthAndHeight(this->width(),this->height());
}

#ifdef USESHADERS
/**
 * @brief GLWidget::loadShader Load vertex and fragment shader for support of GLSL programs
 * @param _vertexShaderFile
 * @param _fragmentShaderFile
 */
void GLWidget::loadShader(QString _vertexShaderFile, QString _fragmentShaderFile, QString textureFile)
{
    this->vertexShaderFile=_vertexShaderFile;
    this->fragmentShaderFile=_fragmentShaderFile;
    this->shaderProgram.addShaderFromSourceFile(QGLShader::Vertex,vertexShaderFile);
    this->shaderProgram.addShaderFromSourceFile(QGLShader::Fragment,fragmentShaderFile);
    if (!textureFile.isEmpty())
    {
        QFileInfo fileinfo(textureFile);
        if (!fileinfo.exists())
        {
            qDebug() << "file not found";
            exit(0);
        }
        else
            this->textureId=this->bindTexture(textureFile);
    }
    qDebug() << this->shaderProgram.log();
}

/**
 * @brief GLWidget::beginShader Begin the shader program on current vertices
 */
void GLWidget::beginShader()
{
    this->shaderProgram.link();
    qDebug() << this->shaderProgram.bind();
    this->shaderProgram.setUniformValue("textureUnit",this->textureId);
    //qDebug() << this->shaderProgram.log();
}

/**
 * @brief GLWidget::endShader End the shader program on current vertices
 */
void GLWidget::endShader()
{
    this->shaderProgram.release();
}
#endif
/**
 * @brief GLWidget::updateColors
 */
void GLWidget::updateColors()
{
    GraphLayoutGL *g = static_cast<GraphLayoutGL *>(layoutThread.dataSet.graphGL->g);
    if (g)
        g->draw(&options,this->fastGraph,updateFastGraph,false);
}
