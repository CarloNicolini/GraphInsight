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


#ifndef GRAPHLAYOUTGLOPTIONS_H
#define GRAPHLAYOUTGLOPTIONS_H

#include "GraphLayoutGL.h"

class GraphLayoutGL;

class GraphLayoutGLOptions
{
public:
    GraphLayoutGLOptions();
    int FSAA; //fullscreen antialiasing

    double boundingRadius;
    double nodeRadius ;
    double edgeRadius;

    double nodeRadiusFactor;
    double edgeRadiusFactor;

    bool drawEdges;
    bool drawNodes;
    bool drawIsolatedNodes;
    bool drawLinesPoints;
    bool rescaleGraph;

    bool nightMode;

    bool labelShowSelectedItem;
    bool labelShowSelectedItemAdjacent;

    bool showGrid;

    int edgeType;

    int sphereQuality;
    int sphereQualityOrig;
    bool useCustomRGBColorMethod;
    int nodeColorMethodId;
    int edgeColorMethodId;
    int glListId;
    double selectedNodeBigRadius;
    QGLWidget *glWidget;

    int filterMinNodeDegree;
    int labelMinNodeDegree;
    int labelFontSize;
    int labelTextAlignmentOptions;
    static const int baseLabelFontSize = 7;

    // Labels options
    int currentVisibleAttribute;
    int maxLabelsCollisions;
    double labelsBorderPenWidth;
    bool useCustomLabelBackgroundColor;
    bool useCustomLabelBorderColor;
    bool useCustomLabelTextColor;
    int labelsType;
    QColor labelsTextColor;
    QColor labelsBorderColor;
    QColor labelsBackgroundColor;
    QColor labelBaseBackgroundColorNight,labelBaseBackgroundColorDay;
    double roundedLabelsRadius;

    static const int nodeColorMethodGreenToBlack;
    static const int nodeColorMethodGreenToRed;
    static const int nodeColorMethodTransparentToBlack;
    static const int nodeColorMethodRainbow;
    static const int nodeColorMethodSequential;
    static const char * const nodeColorMethods[];

    static const int edgeColorMethodGreenToBlack;
    static const int edgeColorMethodGreenToRed;
    static const char * const edgeColorMethods[];


    static const double baseSphereRadius;
};

#define EDGE_TYPE_UNDIRECTED 0
#define EDGE_TYPE_PIN 1
#define EDGE_TYPE_ARROW 2

// Defines for node coloring method
#define NODECOLOR_METHOD_WHITE 0
#define NODECOLOR_METHOD_GRAY 1
#define NODECOLOR_METHOD_BLACK 2
#define NODECOLOR_METHOD_GREEN2BLACK 3
#define NODECOLOR_METHOD_BLUE2RED_ON_DEGREE 4
#define NODECOLOR_METHOD_TRANSPARENT2BLACK 5
#define NODECOLOR_METHOD_RAINBOW 6
#define NODECOLOR_METHOD_SEQUENTIAL 7
#define NODECOLOR_METHOD_LENGTH 8
#define NODECOLOR_METHOD_COMPONENT 9
#define NODECOLOR_METHOD_CUSTOM_RGB 10

static const int edgeTypeUndirected = EDGE_TYPE_UNDIRECTED;
static const int edgeTypePin = EDGE_TYPE_PIN;
static const int edgeTypeArrow = EDGE_TYPE_ARROW;

// Defines for edges coloring methods
#define EDGECOLOR_METHOD_WHITE 0
#define EDGECOLOR_METHOD_GRAY 1
#define EDGECOLOR_METHOD_BLACK 2
#define EDGECOLOR_METHOD_WIDTH 3
#define EDGECOLOR_METHOD_DEGREE 4
#define EDGECOLOR_METHOD_COMPONENT 5
#define EDGECOLOR_METHOD_CUSTOM_RGB 6

static  const double baseSphereRadius = 0.02f;

#define LABELS_TYPE_VOID 0
#define LABELS_TYPE_ROUNDED 1
#define LABELS_TYPE_RECTANGLE 2

#endif // GRAPHLAYOUTGLOPTIONS_H
