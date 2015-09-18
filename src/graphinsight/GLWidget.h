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


#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QGLWidget>
#include <QtOpenGL>

#include <sstream>
#include <cmath>
#include <time.h>

#include "GraphLayoutGL.h"
#include "GLUtils.h"
#include "LayoutThread.h"
#include "Statistic.h"
#include "GraphLayoutGLOptions.h"
#include "LabelVisualizer.h"
#include "Arcball.h"
#include "Timer.h"
#include "LabelVisualizer.h"

using namespace std;
#define SELECTION_BUFFER_SIZE 512
#define DEFAULT_ZOOM 1.0f
#define DEFAULT_INITIAL_ZOOM 0.6f;
#define DEFAULT_FULLSCREEN false
#define DEFAULT_AUTOROTATION false
#define DEFAULT_REACH_INITIAL_ZOOM true
#define DEFAUT_FAST_GRAPH false
#define DEFAULT_DISPLAY_GRID true
#define SCREENSHOT_WIDTH 3000.0

class GLWidget : public QGLWidget
{  Q_OBJECT
    // PUBLIC CONSTRUCTOR
public:
    GLWidget(QWidget *parent = 0);

    //http://eigen.tuxfamily.org/dox/TopicStructHavingEigenMembers.html
    EIGEN_MAKE_ALIGNED_OPERATOR_NEW
    public:
        bool autoRotation;

    bool fastGraph;
    bool glEnabled;

    bool keyCmdPressed;
    bool keySpacePressed;
    bool keyShiftPressed;
    bool isDrawingSelectionRectangle;
    QPoint selectionRectangleStart,selectionRectangleEnd;
    bool nonIntersectingLabels;
    bool reachInitialZoom;
    bool rotationEnabled;
    bool updateFastGraph;
    double fps;
    double initialZoom;
    double zoom;
    int mouseDownX;
    int mouseDownY;
    int currentMouseX,currentMouseY;

    // Camera and view parameters
    Eigen::Vector3f cameraPosition;
    Eigen::Vector3f cameraTranslation;
    Eigen::Vector3f objectRotationAngle;
    // Lights parameters
    Eigen::Matrix<GLfloat,1,4> light0Position;
    Eigen::Matrix<GLfloat,1,4> light1Position;
    Eigen::Matrix<GLfloat,1,4> lightAmbient;
    Eigen::Matrix<GLfloat,1,4> lightDiffuse;
    Eigen::Matrix<GLfloat,1,4> lightSpecular;

    Timer glWidgetTimer;
    Eigen::Vector3d rotationAxis;
    Eigen::Vector3d startPoint;

    // The main layout thread
    LayoutThread layoutThread;
    // The visualization options class
    GraphLayoutGLOptions options;

    // For use with OpenGL GLSL shaders programs
#ifdef USESHADERS
    QString vertexShaderFile, fragmentShaderFile;
    QGLShaderProgram shaderProgram;
#endif

    // PUBLIC SLOTS
public slots:
    void updateColors();
    bool openFile(QString pathname, int methodType, int nDimensions);
    bool saveFile(const QString &pathname="");
    bool saveImage(const QString &pathname="");

    void initEmpty();
    void randomizeCoordinates();
    void reload( int methodType, int nDimensions);
    void resetScene();
    void setEdgeRadius(int v);
    void setGLEnabled(bool v);
    void setLabelFontSize(int v);
    void setLabelMinNodeDegree(int v);
    void setLabelShowSelectedItemAdjacent(bool v);
    void setLabelShowSelectedItem(bool v);
    void setNodeRadius(int v);
    void setNonIntersectingLabels(bool val);
    void stop();
    void visualizationFilterNodeDegree(int v);

    // PROTECTED MEMBER METHODS
protected:
    // Reimplementations of QGLWidget GL methods
    void initializeGL();
    void paintGL();
    void paintEvent(QPaintEvent *event);
    void resizeGL(int width, int height);

    // Mouse and keyboard handling
    void keyPressEvent(QKeyEvent*);
    void keyReleaseEvent(QKeyEvent*);
    void mouseDoubleClickEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void wheelEvent(QWheelEvent * event);
    void timerEvent(QTimerEvent *event);

    int getSelectedObjectId(int x, int y);
#ifdef USESHADERS
    void loadShader(QString vertexShaderFile,QString fragmentShaderFile,QString textureFile="");
    void beginShader();
    void endShader();
#endif

    void abort();
    void autoRotateStep();
    void disableFastGraph();
    void disableRotation();
    void enableFastGraph();
    void enableRotation();

    void normalizeObjectRotationAngle();
    void runDefaultAction(int id);
    void showHelp();
    void showLogo(bool isNightMode);


    // PROTECTED MEMBER VARIABLES
    Arcball arcball;
    bool isMoving;
    bool skipResetScene;
    int listId;
    int textureId;
    bool useGLSLShaders;
    vector<LNode*> selectedNodesList;

    // SIGNALS
signals:
    void dataSetLoaded();
    void graphStatsChanged(int nodes, int edges, int stepsCount, unsigned long elapsedTime, QString layoutStatus);
    void hasAborted();
    void layoutCompleted();
    void selectedNodeChanged(LNode *lnode);
    void nodeUnselected();
    void paintFinished(double fps);
    // PUBLIC SLOTS
public slots:
    void setShowEdges(bool b);
    void setFastMode(bool b);
    void setAutoRotation(bool b);
    void setSpacing(int v);
    void setZoom(int v);
    void contextMenu(const QPoint &);
    void selectedNodeAction();
    void selectedNodeAttrAction();
    void unselectNode();
    void setNodeColorMethod(int methodId);
    void setEdgeColorMethod(int methodId);
    void setSelectedNode(int id);
    void setFog(int v);
    void setNightMode(bool v);
    void setQuality(int v);
    void setShowGrid(bool v);
    void setEdgeType(int v);

};

#endif // GLWIDGET_H
