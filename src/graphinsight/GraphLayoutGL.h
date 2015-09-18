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

#ifndef _GRAPHLAYOUTGL_H
#define  _GRAPHLAYOUTGL_H

#include <QGLWidget>
#include <QtOpenGL>
#include <cmath>
#include <cstring>

#include "GraphLayout.h"
#include "GLUtils.h"
#include "GraphLayoutGLOptions.h"
#include "DataSet.h"
#include "LabelVisualizer.h"
#include <string>

#define BESTG (static_cast<GraphLayoutGL *>(this->g))

class DataSet;
class GraphLayoutGLOptions;

class GraphLayoutGL : public GraphLayout
{
public:
    GraphLayoutGL();
    GraphLayoutGL(QGLWidget *qGLWidget);
    GraphLayoutGL(const GraphLayoutGL& orig);
    void setSelectedNode(int id);
    double normalizedCoord(double v, int coord);
    virtual GraphLayoutGL* clone() const
    {
        return new GraphLayoutGL( *this );
    }
    virtual ~GraphLayoutGL();
    void draw(GraphLayoutGLOptions *options, bool uselist, bool update, bool select);
    void drawSelectedNodeAndEdges(GraphLayoutGLOptions *options);
    void scaleTranslate(double boundingRadius);
    LNode *getSelectedNode();
    void setDrawEdges(bool b);
    void detNodeColor(GraphLayoutGLOptions *options, LNode *lnode, double *rgbt);
    void detEdgeColor(GraphLayoutGLOptions *options, LNode *n1, LNode *n2, double *rgbt);
    void drawEdge(LNode *n1, Neighbor &neighbor, GraphLayoutGLOptions *options, bool selected);

    void drawAllNodeLabels(GraphLayoutGLOptions *options, DataSet &dataSet, bool isTopGraph);
    void drawNodeLabel(LNode *lnode, GraphLayoutGLOptions *options, QPainter &painter, DataSet &dataSet);

    void drawLabelsNonIntersectingMode(GraphLayoutGLOptions *options, DataSet &dataSet, bool isTopGraph);
    void drawSelectedNodesList(const vector<LNode*> &nodesList,GraphLayoutGLOptions *options);
    void assertConsistentCoordinates();

    GLfloat scale;
    Eigen::Matrix<GLfloat,3,1> offset;

    string pathName;
    void setWidthAndHeight(int viewportWidth, int viewportHeight); //needed for efficient label viz things

private:
    void _init();
    //int selectedNode;
    LNode *selectedNode;
    NodesRand labels;
    //    double maxdegree ;
    bool nonIntersectingMode;
    int viewportWidth,viewportHeight;

    GLint viewport[4];
    GLdouble modelview[16];
    GLdouble projection[16];
};

#endif   /* _GRAPHLAYOUTGL_H */

