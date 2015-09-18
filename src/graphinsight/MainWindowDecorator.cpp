/****************************************************************************
**
** Copyright (C) 2013 Carlo Nicolini (nicolini.carlo@gmail.com)
** All rights reserved.
**
** Warning: This program is protected by copyright law and international
** treaties. Unauthorized reproduction and distribution of this program,
** or any portion of it, may result in severe civil and criminal penalties,
** and will be persecuted to the maximum extent possible under the law.
**
****************************************************************************/

#include <QFile>
#include <QMutex>
#include <stdexcept>
#include <LayoutThread.h>
#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "MainWindowDecorator.h"
#include "DocumentationText.h"
#include "LNode.h"
#include "Timer.h"
#include "Common.h"

#include "PythonQt.h"
#include "PythonQtMisc.h"
#include "PythonQtClassInfo.h"
#include "PythonQtMethodInfo.h"
#include "PythonQtConversion.h"
#include "BackgroundLayoutThread.h"

/**
 * @brief MainWindowDecorator::MainWindowDecorator
 * @param parentWin
 */
MainWindowDecorator::MainWindowDecorator(QObject *parentWin) :
    QObject(parentWin)
{
    mainwin=static_cast<MainWindow*>(parentWin);
    glWidget=mainwin->getGLWidget();
    glWidget->setGLEnabled(true);
    tableWidget = this->mainwin->getUi()->tableWidgetDatabase;
    batchMode=false;
    currentLayoutMethod=-1;
    isLayoutMethodChanged=false;
    stopRequested=false;
    this->backgroundStepper=NULL;

    // SIGNAL CONNECTED TO TABLE WIDGET AND NODE SELECTION STATUS
    // When a file is opened, we must sync the python dictionary
    QObject::connect(this->mainwin,SIGNAL(fileOpened(QString)),this,SLOT(sync()));
    // When batch mode is set, the tableWidget is disabled
    QObject::connect(this,SIGNAL(__batchModeSet(bool)),mainwin->getUi()->tabWidget,SLOT(setEnabled(bool)));

    // When a new graph is created, the following slots are called!
    QObject::connect(this,SIGNAL(__graphLoaded()),mainwin,SLOT(resetVisualization())); //OK
    //QObject::connect(this,SIGNAL(qualityChanged(int)),glWidget,SLOT(setQuality(int))); //OK
    //QObject::connect(this,SIGNAL(qualityChanged(int)),mainwin->getUi()->comboBoxGlobalQuality,SLOT(setCurrentIndex(int))); //OK

    QObject::connect(this,SIGNAL(__tableWidgetCleared()),mainwin,SLOT(updateDataSet())); //OK
    QObject::connect(this,SIGNAL(__tableWidgetCleared()),mainwin,SLOT(resetVisualization()));   //OK, set the gui to normal status
    QObject::connect(this,SIGNAL(__tableWidgetCleared()),mainwin,SLOT(updateDataSet()));
    QObject::connect(this,SIGNAL(__tableWidgetChanged()),mainwin,SLOT(updateDataSet()));

    QObject::connect(this,SIGNAL(__tableWidgetCleared()),mainwin,SLOT(updateAttributes())); //OK
    QObject::connect(this,SIGNAL(__tableWidgetChanged()),mainwin,SLOT(updateAttributes()));

    // Node insertion signal/slots
    QObject::connect(this,SIGNAL(__nodeInserted()),mainwin,SLOT(updateDataSet()));
    QObject::connect(this,SIGNAL(__nodeInserted()),this->glWidget,SLOT(repaint())); // For performance issues this signal can be disconnected
    // Node remotion signal/slots
    QObject::connect(this,SIGNAL(__nodeRemoved()),mainwin,SLOT(updateDataSet()));
    QObject::connect(this,SIGNAL(__nodeRemoved()),this->glWidget,SLOT(repaint()));

    // Edge insertion slots
    //QObject::connect(this,SIGNAL(edgeInserted()),mainwin,SLOT(updateDataSet())); // not needed, because dataset is only composed of nodes
    QObject::connect(this,SIGNAL(__edgeInserted()),this->glWidget,SLOT(repaint()));
    // Edge remotion slots
    QObject::connect(this,SIGNAL(__edgeRemoved()),this->glWidget,SLOT(repaint()));
    QObject::connect(this,SIGNAL(__edgeRemoved()),this->mainwin,SLOT(updateDataSet()));

    // Layout signal/slots
    QObject::connect(this,SIGNAL(__layoutMethodChanged(int)),this->mainwin->getUi()->comboBoxAlgorithm,SLOT(setCurrentIndex(int)));
    QObject::connect(this,SIGNAL(__layoutDimensionChanged(int)),this->mainwin->getUi()->comboBoxDimension,SLOT(setCurrentIndex(int)));
    QObject::connect(this,SIGNAL(__layoutDimensionChanged(int)),this->glWidget,SLOT(resetScene()));
    QObject::connect(this,SIGNAL(__layoutMethodChanged(int)),this->glWidget,SLOT(resetScene()));

    QObject::connect(this,SIGNAL(__graphLayoutStatusChanged()),this->glWidget,SLOT(repaint()));
    QObject::connect(this,SIGNAL(__graphLayoutStatusChanged()),this->glWidget,SLOT(updateGL()));

    // Connect the change of layout method via user interaction with the selection of current layout method
    QObject::connect(this->mainwin->getUi()->comboBoxAlgorithm,SIGNAL(currentIndexChanged(int)),this,SLOT(setCurrentLayoutMethod(int)));
    // Connect the change of layout dimension via user interaction with the selection of current layout method
    QObject::connect(this->mainwin->getUi()->comboBoxDimension,SIGNAL(currentIndexChanged(int)),this,SLOT(setCurrentLayoutDimension(int)));

    // Set start value for layout method and dimension
    this->currentLayoutMethod = this->mainwin->getUi()->comboBoxAlgorithm->currentIndex();
    this->currentLayoutDimension = this->mainwin->getUi()->comboBoxDimension->currentIndex()+2;

    // A simple hack to make sure that layout methods are added as valuated methods
    QString layoutMethodsList;
    int totalLayoutMethods=0;
    GraphLayout *g = this->glWidget->layoutThread.dataSet.graphGL->g;
    while ( g->layoutMethods[totalLayoutMethods]!=NULL)
    {  QString stringlayoutmethod(g->layoutMethods[totalLayoutMethods]);
        stringlayoutmethod = "Layout" + stringlayoutmethod.replace(" ","").replace("-","").replace("(","").replace(")","");
        layoutMethodsList += stringlayoutmethod + "=" + QString::number(totalLayoutMethods) + ";\n";
        totalLayoutMethods++;
    }

    // in this way we have defined the variables of layout methods in the current python context
    mainwin->getCurrentPythonContext().evalScript(layoutMethodsList);
    pyNodesDict=PyDict_New();
#ifdef EXPOSE_EDGES
    pyEdgesDict=PyDict_New();
#endif
    this->sync();

}

MainWindowDecorator::~MainWindowDecorator()
{
    Py_XDECREF(pyNodesDict);
#ifdef EXPOSE_EDGES
    Py_XDECREF(pyEdgesDict);
#endif
    if (doc)
        delete doc;
}

/**
 * @brief MainWindowDecorator::LNodeToPyObject Convert a LNode to a commodity PyObject
 * @param n
 * @return
 */
PyObject *MainWindowDecorator::LNodeToPyObject(LNode *n)
{  PythonQtInstanceWrapper* wrap = (PythonQtInstanceWrapper*)PythonQt::priv()->wrapPtr(n, "LNode");
    wrap->_ownedByPythonQt = true;
    wrap->_useQMetaTypeDestroy = true;
    return (PyObject*)wrap;
}

/**
 * @brief MainWindowDecorator::setCurrentLayoutMethod, slot connected to action change layout method
 * @param layoutmethod
 */
void MainWindowDecorator::setCurrentLayoutMethod(int layoutMethod)
{
    this->stop();
    if ( layoutMethod != currentLayoutMethod )
    {
        this->currentLayoutMethod=layoutMethod;
        //qDebug() << "MainWindowDecorator LayoutMethod= " << this->currentLayoutMethod << "layoutdimension= " << this->currentLayoutDimension;
        isLayoutMethodChanged = true;
    }
    else
        isLayoutMethodChanged=false;
    //this->glWidget->layoutThread.dataSet.graphGL->g->init(currentLayoutMethod,currentLayoutDimension,false,false);
}

/**
 * @brief MainWindowDecorator::setCurrentLayoutDimension
 * @param layoutDimension
 */
void MainWindowDecorator::setCurrentLayoutDimension(int layoutDimension)
{
    this->stop();
    if ( layoutDimension+2 != currentLayoutDimension )
    {
        this->currentLayoutDimension=layoutDimension+2; // +2 because index != dimension!!!
        //qDebug() << "LayoutMethod= " << this->currentLayoutMethod << "layoutdimension= " << this->currentLayoutDimension;
        isLayoutMethodChanged=true;
    }
    else
        isLayoutMethodChanged=false;
    //this->glWidget->layoutThread.dataSet.graphGL->g->init(currentLayoutMethod,currentLayoutDimension,false,false);
}

/**
 * @brief MainWindowDecorator::setBatchMode
 * @param _batchMode
 */
void MainWindowDecorator::setBatchMode(bool _batchMode)
{  // If batch mode was TRUE and now is getting set to FALSE
    if (this->batchMode != _batchMode)
    {
        this->sync();
        emit __tableWidgetChanged();
    }

    this->batchMode = _batchMode;
    this->mainwin->getUi()->comboBoxGlobalQuality->setCurrentIndex(0);
    this->glWidget->setQuality(0);
    emit __batchModeSet(!_batchMode);  // this signal deactivate the dataset widget and also the other widgets
}

/**
 * @brief MainWindowDecorator::initEmpty
 */
void MainWindowDecorator::initEmpty()
{
    ////this->stop();
    this->glWidget->options.drawIsolatedNodes=true;
    this->mainwin->openFile("empty");
    this->mainwin->updateDataSet();
    this->mainwin->getUi()->tabWidget->setEnabled(true);
    this->glWidget->setGLEnabled(true);
    this->mainwin->resetVisualization();
    this->sync();
#ifdef EXPOSE_EDGES
    this->syncEdges();
#endif
    emit __tableWidgetCleared();
}

/**
 * @brief MainWindowDecorator::openFile
 * @param str
 * @return
 */
void MainWindowDecorator::loadGraph(const QString &str)
{
    ////this->stop();
    QFile file(str);
    if (!file.exists())
    {  throw std::runtime_error("File doesn't exist");
    }
    file.close();
    this->initEmpty();
    this->mainwin->openFile(str);
    this->sync();
}

/**
 * @brief MainWindowDecorator::addAttribute
 * @param propertyName
 */
void MainWindowDecorator::addAttribute(const QString &propertyName)
{
    if ( std::find(this->glWidget->layoutThread.dataSet.colNames.begin(),this->glWidget->layoutThread.dataSet.colNames.end(),propertyName.toStdString()) != this->glWidget->layoutThread.dataSet.colNames.end() )
        throw std::out_of_range("Attribute " + propertyName.toStdString() + " already exists, choose another name");
    ////this->stop();
    this->glWidget->layoutThread.dataSet.colNames.push_back(propertyName.toStdString());
    for (NodesRand::iterator iter = this->glWidget->layoutThread.dataSet.graphGL->nodesRand.begin(); iter!=this->glWidget->layoutThread.dataSet.graphGL->nodesRand.end();++iter)
    {
        Node *n =(*iter);
        n->ptrEntity->attributes.push_back(new EntityAttributeString(""));
    }
    emit __hasAttributes(true);
    emit __tableWidgetChanged();
}

/**
 * @brief MainWindowDecorator::removeAttribute
 * @param attributeName
 */
void MainWindowDecorator::removeAttribute(const QString &attributeName)
{
    vector< std::string> allAttributeNames = this->glWidget->layoutThread.dataSet.colNames;
    int attributeIndex=-1;
    for ( unsigned int i=0; i<allAttributeNames.size();i++)
    {
        if (allAttributeNames.at(i)==attributeName.toStdString())
        {
            attributeIndex=i;
            break;
        }
    }
    // Attribute is not found
    if (attributeIndex==-1)
        throw std::out_of_range("No attribute \"" + attributeName.toStdString() +"\" found");

    this->removeAttribute(attributeIndex);
}

void MainWindowDecorator::removeAttribute(int attributeIndex)
{
    if (attributeIndex >this->glWidget->layoutThread.dataSet.colNames.size()-1 || attributeIndex < 0 )
        throw std::out_of_range(string("Pick attribute index in [0, "+ stringify<int>(this->glWidget->layoutThread.dataSet.colNames.size()-1)  + "]"));

    // Remove the attribute from column names
    std::vector<std::string>::iterator iterCol = std::find( this->glWidget->layoutThread.dataSet.colNames.begin(),
                                                            this->glWidget->layoutThread.dataSet.colNames.end(),
                                                            this->glWidget->layoutThread.dataSet.colNames.at(attributeIndex));
    this->glWidget->layoutThread.dataSet.colNames.erase(iterCol);

    // Update the nodes
    bool hasStillAttributes=true;
    for (NodesRand::iterator iter = this->glWidget->layoutThread.dataSet.graphGL->nodesRand.begin(); iter!=this->glWidget->layoutThread.dataSet.graphGL->nodesRand.end();++iter)
    {
        Node *n =(*iter);
        n->ptrEntity->removeEntityAttribute(attributeIndex);
        if (n->ptrEntity->attributes.empty())
            hasStillAttributes=false;
    }

    emit __hasAttributes(hasStillAttributes);

    this->mainwin->updateAttributes();
    this->mainwin->updateDataSet();
}

/**
 * @brief MainWindowDecorator::initLayout
 * @param layoutMethod
 * @param dimensions
 * @param randomize
 * @param shakeZ
 * @return
 */
void MainWindowDecorator::initLayout(int layoutMethod,int dimensions, bool randomize, bool shakeZ)
{
    //this->stop();
    if ( !this->glWidget->layoutThread.dataSet.graphGL->lmOk(layoutMethod) )
    {
        throw std::logic_error("Non allowed layout method for this graph");
    }

    if  ( this->currentLayoutMethod != layoutMethod )
        this->glWidget->resetScene();

    int totalLayoutMethods=0;
    while (this->glWidget->layoutThread.dataSet.graphGL->g->layoutMethods[totalLayoutMethods++]!=NULL) {};

    totalLayoutMethods--;// to compensate for NULL
    // Handle out of range error!
    QString errorMessageLayout("Possible layout methods are in range [ 0, ");
    errorMessageLayout+=QString::number(totalLayoutMethods) + QString(" ]");
    if (layoutMethod<0 || layoutMethod>=totalLayoutMethods)
    {  throw std::out_of_range(errorMessageLayout.toStdString());
        // return; //because cppcheck says Consecutive return, break, continue, goto or throw statements are unnecessary.
    }

    // Handle wrong dimensions error
    QString errorMessageDimension("Possible layout methods are in range [ 0, ");
    errorMessageDimension+=QString::number(totalLayoutMethods-1) + QString(" ]");
    if (dimensions!=2 && dimensions!=3)
    {  throw std::out_of_range("Dimensions can only be 2 or 3");
        //return; Consecutive return, break, continue, goto or throw statements are unnecessary.
    }

    glWidget->layoutThread.dataSet.graphGL->init(layoutMethod,dimensions,randomize,shakeZ);
    emit __layoutMethodChanged(layoutMethod);
    emit __layoutDimensionChanged(dimensions-2);//because the values are 0,1
    emit __graphLayoutStatusChanged();
    if ( layoutMethod == GraphLayout::MethodKamadaKawai && glWidget->layoutThread.dataSet.graphGL->hasNegativeWeightCycles)
        throw std::logic_error("Graph has negative weight cycles, shortest path algorithms fail. Kamada Kawai layout is unreliable");
}


/**
 * @brief MainWindowDecorator::steps
 * @param nsteps
 * @return
 */
void MainWindowDecorator::steps(int nsteps)
{
    this->stop();
    // If there were some insertNode or removeNode we must regenerate the vector<double> solution
    if ( this->glWidget->layoutThread.dataSet.graphGL->solution.size()!=this->glWidget->layoutThread.dataSet.graphGL->nodes.size()*this->glWidget->layoutThread.dataSet.graphGL->nDimensions )
    {
        if (this->currentLayoutDimension==GraphLayout::MethodKamadaKawai)
        {
            throw std::logic_error("Must init layout because node number changed");
            //return;
        }
    }

    if ( isLayoutMethodChanged )
    {
        this->glWidget->layoutThread.dataSet.graphGL->g->init(currentLayoutMethod,currentLayoutDimension,false,false);
        isLayoutMethodChanged=false;
    }

    if ( !this->glWidget->layoutThread.dataSet.graphGL->lmOk(this->currentLayoutMethod) )
    {
        throw std::logic_error("Non allowed layout method for this graph");
    }
    if (this->glWidget->layoutThread.dataSet.graphGL->statsNodesCount==0)
        return;

    // This command spawns a new thread so that the gui is left responsive
    stepsMutex.lock();  // We must lock the class to prevent calling this method in succession
    this->workerThread = new QThread;
    //QThread* thread = new QThread;
    backgroundStepper = new BackgroundLayoutThread(this->glWidget,nsteps);
    // Stop the current running layout if a new file is opened
    backgroundStepper->moveToThread(this->workerThread);

    // These two connections must be before
    QObject::connect(workerThread, SIGNAL(started()), this->mainwin, SLOT(printStatusBarStart()));
    QObject::connect(backgroundStepper, SIGNAL(finished()), this->mainwin, SLOT(printStatusBarStop()));

    QObject::connect(workerThread, SIGNAL(started()), backgroundStepper, SLOT(process()));
    QObject::connect(backgroundStepper, SIGNAL(finished()), workerThread, SLOT(quit()));
    QObject::connect(backgroundStepper, SIGNAL(finished()), backgroundStepper, SLOT(deleteLater()));
    QObject::connect(workerThread, SIGNAL(finished()), workerThread, SLOT(deleteLater()));
    QObject::connect(this->mainwin,SIGNAL(fileOpenRequested()),this,SLOT(stop()));
    QObject::connect(this,SIGNAL(__stopLayoutRequested()),backgroundStepper,SLOT(requestStop()));

    if ( !batchMode )
    {
        QObject::connect(backgroundStepper, SIGNAL(stepsDone(int )), glWidget, SLOT(updateGL()));
    }

    workerThread->start();
    this->glWidget->layoutThread.dataSet.graphGL->updateDynamicStats();
    emit __graphLayoutStatusChanged();
    stepsMutex.unlock();
}

void MainWindowDecorator::stepsBlocking(int nsteps)
{
    for  (int i=0; i<nsteps;i++)
        this->glWidget->layoutThread.dataSet.graphGL->steps(1);
}

/**
 * @brief MainWindowDecorator::stop
 */
void MainWindowDecorator::stop()
{
    if (this->backgroundStepper!=NULL)
    {
        this->backgroundStepper->requestStop();
    }
}

/**
 * @brief MainWindowDecorator::insertNode
 * @param nodeId
 * @param attribute
 * @return true if the node was added, false otherwise
 */
void MainWindowDecorator::insertNode(int nodeId)
{
    this->stop();
    // Find if the node is already existent
    if (this->glWidget->layoutThread.dataSet.graphGL->nodeExists(nodeId))
    {  throw std::runtime_error("Node " + stringify<int>(nodeId) +" already exists");
        //return;
    }
    else
    {  std::vector< std::string > stdAttrString(this->glWidget->layoutThread.dataSet.colNames.size());
        LNode *tmpNode = static_cast<LNode*>(this->glWidget->layoutThread.dataSet.addNodeEntity(nodeId,stdAttrString));
        tmpNode->px += Common::unifRand(-10.0,10.0);
        tmpNode->py += Common::unifRand(-10.0,10.0);
        tmpNode->pz += Common::unifRand(-10.0,10.0);

        if (batchMode)
            return;

        // Insert the node in the pyNodeDict python dictionary
        // Here we don't need to decrease reference count of variables
        PyObject *key = PyInt_FromLong((long int)nodeId);
        PyObject *value =  LNodeToPyObject(tmpNode);
        PyDict_SetItem(pyNodesDict, key ,value);
        Py_XDECREF(key);
        Py_XDECREF(value);

        emit __nodeInserted();
        return;
    }
}

/**
 * @brief MainWindowDecorator::insertNode
 * @param nodeId
 * @param attribute
 * @return true if the node was added, false otherwise
 */
void MainWindowDecorator::insertNode(int nodeId, const QStringList &attribute)
{
    //this->stop();
    // Handle errors, it the attributes length is != than set attributes
    // Find if the node is already existent
    if (this->glWidget->layoutThread.dataSet.graphGL->nodeExists(nodeId))
    {  throw std::runtime_error("Node " + stringify<int>(nodeId) +" already exists");
        //return;
    }
    else
    {  if ( (unsigned int)attribute.size()!=this->glWidget->layoutThread.dataSet.colNames.size())
        {  throw std::length_error("Number of input attributes mismatch");
            //return;
        }

        std::vector< std::string > stdAttrString(attribute.size());
        for ( int i=0; i<attribute.size(); i++)
            stdAttrString.at(i) = attribute.at(i).toStdString();

        LNode *tmpNode = static_cast<LNode*>(this->glWidget->layoutThread.dataSet.addNodeEntity(nodeId,stdAttrString));
        tmpNode->px +=Common::unifRand(-10.0,10.0);
        tmpNode->py += Common::unifRand(-10.0,10.0);
        tmpNode->pz +=Common::unifRand(-10.0,10.0);

        if (batchMode)  // if batchmode==true no other structure is updated
            return;

        // Insert the node in the pyNodeDict python dictionary
        // Here we don't need to decrease reference count of variables
        PyObject *key = PyInt_FromLong((long int)nodeId);
        PyObject *value =  LNodeToPyObject(tmpNode);
        PyDict_SetItem(pyNodesDict, key ,value);
        Py_XDECREF(key);
        Py_XDECREF(value);
        emit __nodeInserted();
        return;
    }
}

/**
 * @brief MainWindowDecorator::insertNode
 * @param nodeId
 * @param attribute
 */
void MainWindowDecorator::insertNode(int nodeId, const QString &attribute)
{
    this->stop();
    QStringList attributes(attribute);
    this->insertNode(nodeId,attributes);
}

/**
 * @brief MainWindowDecorator::removeNode
 * @param nodeId
 * @return true if the node was removed, false otherwise
 */
void MainWindowDecorator::removeNode(int nodeId)
{
    this->stop();
    Node *node = (this->glWidget->layoutThread.dataSet.graphGL->getNode(nodeId));
    if (node!=NULL)
    {  LNode *ln = static_cast<LNode*>(node);
        // Unselect the node
        this->glWidget->layoutThread.dataSet.graphGL->setSelectedNode(std::numeric_limits<int>::min());

        this->glWidget->layoutThread.dataSet.removeNodeEntity(ln);
        if (batchMode)  // if batchmode==true no other structure is updated
            return;

        PyObject *pyNodeId = PyInt_FromLong(nodeId);
        if ( PyDict_Contains(pyNodesDict,pyNodeId ))
        {  PyDict_DelItem(pyNodesDict,pyNodeId);
        }
        Py_XDECREF(pyNodeId);
        emit __nodeRemoved(); // XXX performance issue!
        return;
    }
    else
    {  throw std::out_of_range("Node " + stringify<int>(nodeId) + " doesn't exist" );
        //return;
    }
}

/**
 * @brief MainWindowDecorator::insertEdge
 * @param source
 * @param target
 * @param weight
 * @return true if the edge has been correctly inserted
 */
void  MainWindowDecorator::insertEdge(int source, int target, double weight)
{
    this->stop();
    GraphLayout *gl = this->glWidget->layoutThread.dataSet.graphGL->g;
    // When inserting a new edge we must discriminate the following situations to send as python exceptions
    // 1) the case in which the requested edge is a self loop
    // 2) the case in which the edge is already there
    // 3) the case in which one of the two nodes is not present
    // Treating the self loop case
    if (source==target)
    {  throw std::logic_error("Asking to insert self loop, skipping it because currently unsupported");
        //return;
    }

    if (!gl->nodeExists(source))
    {  throw std::out_of_range("Can't insert edge because node " + stringify<int>(source)+ " doesn't exist");
        //return;
    }

    if (!gl->nodeExists(target))
    {  throw std::out_of_range("Can't insert edge because node " + stringify<int>(target) +" doesn't exist");
        //return;
    }

    // All the cases have bee analyzed, now if Graph::insertEdge returns false is only because the edge is already there
    if ( gl->hasUndirectedEdge(source,target) )
    {  throw std::logic_error("Can't insert edge because is already existent");
        //return;
    }
    else
    {  this->glWidget->layoutThread.dataSet.graphGL->insertEdge(source,target,weight);
        if (!batchMode)
            emit __edgeInserted();
    }
}

/**
 * @brief MainWindowDecorator::setEdgeWeight
 * @param source
 * @param target
 * @param weight
 */
void MainWindowDecorator::setEdgeWeight(int source, int target, double weight)
{
    this->stop();
    // How to find important connections in graph
    //http://blog.xebia.com/2013/01/21/finding-important-connections-in-a-network-automatically/
    GraphLayout *gl = this->glWidget->layoutThread.dataSet.graphGL->g;
    // When setting an edge weight we must discriminate the following situations to send as python exceptions
    // 1) the case in which the requested edge is a self loop
    // 2) the case in which the edge is already there
    // 3) the case in which one of the two nodes is not present
    // Treating the self loop case
    if (source==target)
    {  throw std::logic_error("Asking to insert self loop, skipping it because currently unsupported");
        //return;
    }

    if (!gl->nodeExists(source))
    {  throw std::out_of_range("Can't set edge weight because node " + stringify<int>(source)+ " doesn't exist");
        //return;
    }

    if (!gl->nodeExists(target))
    {  throw std::out_of_range("Can't set edge weight because node " + stringify<int>(target) +" doesn't exist");
        //return;
    }

    // All the cases have bee analyzed, now if Graph::insertEdge returns false is only because the edge is already there
    if ( gl->hasUndirectedEdge(source,target) )
    {
        gl->forceAPSP_LaplacianComputation=false;
        Node *sourceNode = gl->nodes[source];
        Node *targetNode = gl->nodes[target];
        if (sourceNode->neighbors[target].first->weight!=weight)
        {
            sourceNode->neighbors[target].first->weight = weight;
            gl->forceAPSP_LaplacianComputation=true;
        }
        if (targetNode->neighbors[source].first->weight)
        {
            targetNode->neighbors[source].first->weight = weight;
            gl->forceAPSP_LaplacianComputation=true;
        }

        sourceNode->degree=0.0;
        targetNode->degree=0.0;

        for (NeighborsRand::iterator iter = sourceNode->neighborsRand.begin();iter!=sourceNode->neighborsRand.end();++iter)
        {
            Edge *e = static_cast<Edge*>((*iter)->first);
            sourceNode->degree+=e->weight;
        }
        for (NeighborsRand::iterator iter = targetNode->neighborsRand.begin();iter!=targetNode->neighborsRand.end();++iter)
        {
            Edge *e = static_cast<Edge*>((*iter)->first);
            targetNode->degree+=e->weight;
        }

        if (!batchMode)
            emit __edgeInserted();
    }
    else
    {
        throw std::out_of_range("Can't set edge weight because edge doesn't exist");
    }
}

/**
 * @brief MainWindowDecorator::removeEdge
 * @param source
 * @param target
 */
void  MainWindowDecorator::removeEdge(int source, int target)
{
    this->stop();
    GraphLayout *gl = this->glWidget->layoutThread.dataSet.graphGL->g;
    // When removing an edge we must discriminate the following situations to send as python exceptions
    // 1) the case in which the requested edge is a self loop
    // 2) the case in which the edge is already there
    // 3) the case in which one of the two nodes is not present
    // Treating the self loop case
    if (source==target)
    {  throw std::logic_error("No self loop edges");
        //return;
    }
    if (!gl->nodeExists(source))
        throw std::out_of_range("Can't remove edge because node " + stringify<int>(source)+ " doesn't exist");

    if (!gl->nodeExists(target))
        throw std::out_of_range("Can't remove edge because node " + stringify<int>(target) +" doesn't exist");

    if ( !gl->hasUndirectedEdge(source,target) )
    {  throw std::logic_error("Can't remove edge because is not existent");
        //return;
    }
    // All the cases have bee analyzed, now if Graph::insertEdge returns false is only because the edge is already there
    this->glWidget->layoutThread.dataSet.graphGL->removeEdge(source,target);
    if (!batchMode)
        emit __edgeRemoved();
}

/**
 * @brief MainWindowDecorator::nodesCount
 * @return
 */
int MainWindowDecorator::getNodesCount() const
{
    //    qDebug() << "MinNodeDegree= " << this->glWidget->layoutThread.dataSet.graphGL->statsMinNodeDegree << " MaxNodeDegree="
    //           << this->glWidget->layoutThread.dataSet.graphGL->statsMaxNodeDegree;
    return (int)(this->glWidget->layoutThread.dataSet.graphGL->nodesRand.size());
}

/**
 * @brief MainWindowDecorator::edgesCount
 * @return
 */
int MainWindowDecorator::getEdgesCount() const
{
    return this->glWidget->layoutThread.dataSet.graphGL->statsEdgesCount;
}

/**
 * @brief MainWindowDecorator::getComponentsCount // This method recomputes the component
 * if not already computed, otherwise it gives the count of weakly connected components
 * @return
 */
int MainWindowDecorator::getComponentsCount() const
{
    return this->glWidget->layoutThread.dataSet.graphGL->countConnectedComponents();
}

/**
 * @brief MainWindowDecorator::getNode
 * @param nodeid
 * @return
 */
LNode *MainWindowDecorator::getNode(int nodeid)
{  return static_cast<LNode*>(this->glWidget->layoutThread.dataSet.graphGL->getNode(nodeid));
}

/**
 * @brief MainWindowDecorator::getEdgeWeight
 * @param fromNodeId
 * @param toNodeId
 * @return
 */
double MainWindowDecorator::getEdgeWeight(int fromNode, int toNode)
{
    if (fromNode == toNode )
        throw std::logic_error("No self loop allowed");

    Node *n1 = this->glWidget->layoutThread.dataSet.graphGL->getNode(fromNode);
    if (n1 ==NULL )
        throw std::logic_error("Node " + QString::number(fromNode).toStdString() +" not found");

    Node *n2 = this->glWidget->layoutThread.dataSet.graphGL->getNode(toNode);
    if (n2 ==NULL )
        throw std::logic_error("Node " + QString::number(toNode).toStdString() +" not found");

    return this->glWidget->layoutThread.dataSet.graphGL->getWeight(fromNode,toNode);
}

/**
 * @brief MainWindowDecorator::getNodesDistance
 * @param fromNode
 * @param toNode
 * @return
 */
double MainWindowDecorator::getNodesDistance(int fromNode, int toNode)
{
    if (fromNode == toNode )
        throw std::logic_error("No self loop allowed");

    Node *n1 = this->glWidget->layoutThread.dataSet.graphGL->getNode(fromNode);
    if (n1 ==NULL )
        throw std::logic_error("Node " + QString::number(fromNode).toStdString() +" not found");

    Node *n2 = this->glWidget->layoutThread.dataSet.graphGL->getNode(toNode);
    if (n2 ==NULL )
        throw std::logic_error("Node " + QString::number(toNode).toStdString() +" not found");


    return this->glWidget->layoutThread.dataSet.graphGL->getNodesDistance(n1,n2).first;
}

/**
 * @brief MainWindowDecorator::getShortestDistancePath
 * @param fromNode
 * @param toNode
 * @return
 */
QList<LNode*> MainWindowDecorator::getShortestDistancePath(int fromNode, int toNode)
{
    if (fromNode == toNode )
        throw std::logic_error("No self loop allowed");

    QList<LNode*> vshortestPathList;
    Node *n1 = this->glWidget->layoutThread.dataSet.graphGL->getNode(fromNode);
    if (n1 ==NULL )
        throw std::logic_error("Node " + QString::number(fromNode).toStdString() +" not found");

    Node *n2 = this->glWidget->layoutThread.dataSet.graphGL->getNode(toNode);
    if (n2 ==NULL )
        throw std::logic_error("Node " + QString::number(toNode).toStdString() +" not found");


    std:: vector<Node*> vshortestPath = this->glWidget->layoutThread.dataSet.graphGL->getNodesDistance(n1,n2).second;
    // It needs a cast
    for (NodesRand::const_iterator iter= vshortestPath.begin(); iter!=vshortestPath.end(); ++iter )
    {  vshortestPathList.append(static_cast<LNode*>(*iter));
    }
    return vshortestPathList;
}

/**
 * @brief MainWindowDecorator::sync synchronizes the python data structures
 */
void MainWindowDecorator::sync()
{
    this->stop();
    GraphLayout* gl = this->glWidget->layoutThread.dataSet.graphGL->g;
    // Reallocate the dictionary
    PyDict_Clear(pyNodesDict);

    for (NodesRand::const_iterator iter = gl->nodesRand.begin(); iter!=gl->nodesRand.end(); ++iter)
    {  LNode *n = static_cast<LNode*>(*iter);
        // Fill the Python dictionary, first argument is the dictionary to set items on, second the key of the
        // item, third argument is the LNode converted in PyObject wrapper
        // After creating key and values we have to decrease the reference count of them!
        PyObject *key =  PyInt_FromLong((long int)n->id);
        PyObject *val =  LNodeToPyObject(n);
        if ( PyDict_SetItem(pyNodesDict,key,val) !=0)
        {  qDebug( "unable to set item");
        }
        Py_XDECREF(key);
        Py_XDECREF(val);
    }
}

#ifdef EXPOSE_EDGES
/**
 * @brief MainWindowDecorator::syncEdges
 */
void MainWindowDecorator::syncEdges()
{
    this->stop();
    GraphLayout* gl = this->glWidget->layoutThread.dataSet.graphGL->g;
    PyDict_Clear(this->pyEdgesDict);

    for (NodesRand::const_iterator iter = gl->nodesRand.begin(); iter!=gl->nodesRand.end(); ++iter)
    {
        LNode *n1 = static_cast<LNode*>(*iter);


        for (NeighborsRand::iterator iterNeigh = n1->neighborsRand.begin(); iterNeigh!=n1->neighborsRand.end(); ++iterNeigh)
        {
            LNode *n2 =  static_cast<LNode*>((*iterNeigh)->second);
            Edge *e = static_cast<Edge*>((*iterNeigh)->first);
            PyObject *tuple = PyTuple_New(2);
            PyTuple_SetItem(tuple, 0, LNodeToPyObject(n1));
            PyTuple_SetItem(tuple,1,LNodeToPyObject(n2));
            PyObject *key = tuple;
            PyObject *val =  PyFloat_FromDouble(e->weight);
            if ( PyDict_SetItem(pyEdgesDict,key,val) !=0)
            {  qDebug( "unable to set item");
            }
            Py_XDECREF(key);
            Py_XDECREF(val);
        }
    }
}
#endif

/**
 * @brief MainWindowDecorator::nodes
 * @return
 */
PyObject*  MainWindowDecorator::nodes()
{  // The count returned is generally one higher than you might expect, because it includes the (temporary) reference as an argument to getrefcount(). See Python C API
    // http://stackoverflow.com/questions/7544395/sys-getrefcount-return-value
    return pyNodesDict;
}

/**
 * @brief MainWindowDecorator::edges
 * @return
 */
#ifdef EXPOSE_EDGES
PyObject* MainWindowDecorator::edges()
{
    if (PyDict_Size(this->pyEdgesDict))
        return this->pyEdgesDict;
    else
    {
        syncEdges();
        return this->pyEdgesDict;
    }
}
#endif

/**
 * @brief MainWindowDecorator::nodes Convenience wrapper
 * @param nodeId
 * @return
 */
LNode* MainWindowDecorator::nodes(int nodeId)
{
    return getNode(nodeId);
}

/**
 * @brief MainWindowDecorator::getConnectedComponents Returns a list of lists of the graph components
 * @return The list of list of graph components
 */
PyObject* MainWindowDecorator::getConnectedComponents()
{
    //this->stop();
    GraphLayoutGL *g = this->glWidget->layoutThread.dataSet.graphGL;
    int n = g->countConnectedComponents();
    PyObject *componentsList = PyList_New(n);
    // It's important that the components starts from 0 to n_comp-1 otherwise the list approach fails!
    for (int i=0; i<n; i++)
    {
        PyObject *innerList = PyList_New(0);
        PyList_SetItem(componentsList,i,innerList);
    }

    for (NodesRand::const_iterator iter=g->nodesRand.begin(); iter!=g->nodesRand.end();++iter)
    {
        LNode *n = static_cast<LNode*>(*iter);
        // Get the current inner list at this component
        PyObject *currentComponentsList = PyList_GetItem(componentsList,n->component);
        PyObject *value =  LNodeToPyObject(n);
        PyList_Append(currentComponentsList,value);
        Py_XDECREF(value);
    }
    return componentsList;
}

/**
 * @brief MainWindowDecorator::getAttributes
 * @return
 */
PyObject *MainWindowDecorator::getAttributes()
{
    PyObject *attribIndices;
    attribIndices = PyDict_New();
    for ( int i=0; i<this->glWidget->layoutThread.dataSet.colNames.size(); i++)
    {
        PyObject *key = PyString_FromString( static_cast<const char*>(&(this->glWidget->layoutThread.dataSet.colNames.at(i).at(0))) );
        PyObject *value =  PyInt_FromSize_t((size_t)i);
        PyDict_SetItem(attribIndices, key ,value);
    }
    return attribIndices;
}

/*
void MainWindowDecorator::showHelp()
{
    if (!doc)
        doc = new DocumentationText(NULL);

    QPalette p = doc->palette();
    p.setColor(QPalette::Base, QColor(255,255,165) );
    p.setColor(QPalette::Text, QColor(0, 0,0) );
    doc->setPalette(p);
    doc->setFixedWidth(this->mainwin->width()/3);
    doc->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);

    doc->setContents(":/docs/API.html");
    //doc->setHtml(":/docs/API.html");
    doc->show();
    QDesktopServices::openUrl(QUrl("http://www.graphinsight.com/documentation/python"));
}
*/


#ifdef CUSTOMLABELS
/**
 * @brief MainWindowDecorator::setLabelsBackgroundColor
 * @param r
 * @param g
 * @param b
 * @param alpha
 */
void MainWindowDecorator::setCustomLabelsBackgroundColor(int r, int g, int b, int alpha)
{
    this->glWidget->options.useCustomLabelBackgroundColor=true;
    this->glWidget->options.labelsBackgroundColor.setRgb(r,g,b,alpha);
}

/**
 * @brief MainWindowDecorator::unsetLabelsBackgroundColor
 */
void MainWindowDecorator::unsetCustomLabelsBackgroundColor()
{
    this->glWidget->options.useCustomLabelBackgroundColor=false;
}

/**
 * @brief MainWindowDecorator::setCustomLabelTextColor
 * @param r
 * @param g
 * @param b
 * @param alpha
 */
void MainWindowDecorator::setCustomLabelTextColor(int r, int g, int b, int alpha)
{
    this->glWidget->options.useCustomLabelTextColor=true;
    this->glWidget->options.labelsTextColor.setRgb(r,g,b,alpha);
}

/**
 * @brief MainWindowDecorator::unsetCustomLabelTextColor
 */
void MainWindowDecorator::unsetCustomLabelTextColor()
{
    this->glWidget->options.useCustomLabelTextColor=false;
}

/**
 * @brief MainWindowDecorator::setCustomLabelWidth
 * @param width
 */
void MainWindowDecorator::setCustomLabelWidth(double width)
{
    this->glWidget->options.labelsBorderPenWidth=width;
}

/**
 * @brief MainWindowDecorator::unsetCustomLabelWidth
 */
void MainWindowDecorator::unsetCustomLabelWidth()
{
    this->glWidget->options.labelsBorderPenWidth=1;
}
#endif

/**
 * @brief MainWindowDecorator::exportImage save the framebuffer as file
 * @param filename
 */
void MainWindowDecorator::exportImage(const QString &filename)
{
    QFile file(filename);
    QFileInfo fileinfo(filename);

    this->glWidget->setNightMode(false);
    this->glWidget->setShowGrid(false);
    this->glWidget->setLabelMinNodeDegree(0);
    this->glWidget->setQuality(0);
    this->glWidget->repaint();

    //if ( fileinfo.completeSuffix() == "png" )
    this->glWidget->saveImage(filename);
    Timer timer;
    timer.sleep(100);

    //else
    //throw std::logic_error("Only .png format available");
}
