/****************************************************************************
**
** Copyright (C) 2012 Carlo Nicolini (nicolini.carlo@gmail.com)
** All rights reserved.
**
** Warning: This program is protected by copyright law and international
** treaties. Unauthorized reproduction and distribution of this program,
** or any portion of it, may result in severe civil and criminal penalties,
** and will be persecuted to the maximum extent possible under the law.
**
****************************************************************************/

#ifndef MAINWINDOWDECORATOR_H_
#define MAINWINDOWDECORATOR_H_

#include <QMetaType>
#include <QObject>
#include <QMap>
#include <QTimer>
#include <QList>
#include "MainWindow.h"
#include "LNode.h"
#include "LNodeWrapper.h"
#include "BackgroundLayoutThread.h"
#include "DocumentationText.h"
#define PYTHON_NODES_AS_DICTIONARY_SUPPORT

Q_DECLARE_METATYPE(LNode*)

class MainWindowDecorator : public QObject
{  Q_OBJECT
private:
    MainWindow *mainwin;
    GLWidget *glWidget;
    QTableWidget *tableWidget;
    QTimer userIdleTimer;
    int currentLayoutMethod,currentLayoutDimension;
    bool isLayoutMethodChanged;
    QMutex stepsMutex;
    //About QPointer http://doc-snapshot.qt-project.org/4.8/qpointer.html
    QPointer<QThread> workerThread; //QPointer behaves like normal pointer except that they are zeroed on deleteLater calls
    QPointer<BackgroundLayoutThread> backgroundStepper; //QPointer behaves like normal pointer except that they are zeroed on deleteLater calls

    bool stopRequested;
    bool batchMode;// If batchMode==true then the dataset table is not updated
    // when new nodes are inserted/removed, but a ::finalize method must be called to update all the structures
    PyObject *pyNodesDict;
#ifdef EXPOSE_EDGES
    PyObject *pyEdgesDict;
#endif
    PyObject *LNodeToPyObject(LNode *n);
    QPointer<DocumentationText> doc;

public:
    explicit MainWindowDecorator(QObject *parentWin);
    ~MainWindowDecorator();
signals:
    void __hasAttributes(bool);
    void __batchModeSet(bool);
    void __graphLoaded();
    void __qualityChanged(int qualityLevel);
    void __nodeRadiusChanged(int);
    void __tableWidgetCleared();
    void __tableWidgetChanged();

    void __nodeInserted();
    void __nodeInserted(int nodeIndex);

    void __nodeRemoved();
    void __nodeRemoved(int nodeIndex);

    void __edgeInserted();
    void __edgeInserted(int,int);

    void __edgeRemoved();
    void __edgeRemoved(int,int);

    void __updateOpenGLStatus();

    void __layoutMethodChanged(int layoutIndex);
    void __layoutDimensionChanged(int dimension);
    void __graphLayoutStatusChanged();

    void __stopLayoutRequested();

private slots:
    void setCurrentLayoutMethod(int layoutMethod);
    void setCurrentLayoutDimension(int layoutDimension);

public slots:

    // Graphlayout methods
    void setBatchMode(bool batchMode);

    void initEmpty();
    void loadGraph(const QString &str);
    void addAttribute(const QString &attributeName);
    void removeAttribute(const QString &attributeName);
    void removeAttribute(int attributeIndex);
    void initLayout(int layoutMethod,int dimensions, bool randomize=false, bool shakeZ=false);
    void steps(int nsteps);
    void stepsBlocking(int nsteps);
    void stop();

    // Graph Methods
    void insertNode(int nodeId);
    void insertNode(int nodeId, const QStringList &nodeProperties);
    void insertNode(int nodeId, const QString &nodeProperty);
    void removeNode(int nodeId);

    void insertEdge(int source, int target, double weight=1.0);
    void setEdgeWeight(int source, int target, double weight);
    void removeEdge(int source, int target);

    int getNodesCount() const;
    int getEdgesCount() const ;
    int getComponentsCount() const;
    PyObject *getConnectedComponents();

    LNode *getNode(int nodeid);
    double getNodesDistance(int fromNode, int toNode);
    double getEdgeWeight(int fromNodeId, int toNodeId);
	//void runDepthFirstSearch(int source);
	//void runBreadthFirstSearch(int source);
    QList<LNode *> getShortestDistancePath(int fromNode, int toNode);

    // Get a python dictionary of attributes
    PyObject* getAttributes();
    // Synchronize python and C++ structures
    void sync();
#ifdef EXPOSE_EDGES
	void syncEdges();
#endif
    // return the python dictionary of nodes
    PyObject* nodes();
#ifdef EXPOSE_EDGES
	PyObject* edges();
#endif
	LNode* nodes(int);

    // Graph appearance modifiers
#define CUSTOMLABELS
#ifdef CUSTOMLABELS
    void setCustomLabelsBackgroundColor(int r, int g, int b, int alpha=255);
    void unsetCustomLabelsBackgroundColor();

    void setCustomLabelTextColor(int r, int g, int b,int alpha=255);
    void unsetCustomLabelTextColor();

    void setCustomLabelWidth(double width);
    void unsetCustomLabelWidth();
#endif

    void exportImage(const QString &filename);
};

#endif //MAINWINDOWDECORATOR_H_
