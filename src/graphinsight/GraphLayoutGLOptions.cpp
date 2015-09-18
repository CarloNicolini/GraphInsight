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


#include "GraphLayoutGLOptions.h"


const char * const GraphLayoutGLOptions::nodeColorMethods[] = { "White", "Gray", "Black", "Black to green on degree", "Blue to red on degree", "Blue to red with transparency on degree", "Rainbow", "Sequential on id", "Red to blue on length", "Rainbow on component","Custom RGB",NULL};
const char * const GraphLayoutGLOptions::edgeColorMethods[] = { "White", "Gray", "Black", "Red to blue on length","Blue to red on degree", "Rainbow on component","Custom RGB",NULL};
/**
 * @brief GraphLayoutGLOptions::GraphLayoutGLOptions
 */
GraphLayoutGLOptions::GraphLayoutGLOptions()
{
    FSAA = 4;
    nodeRadiusFactor = 0.02f;
    edgeRadiusFactor = 0.01f;

    nodeRadius = nodeRadiusFactor;
    edgeRadius = edgeRadiusFactor/2.0f;
    boundingRadius = 1.5f;
    rescaleGraph=true;

    edgeType = EDGE_TYPE_UNDIRECTED;

    filterMinNodeDegree = 0;
    labelMinNodeDegree = -1;
    labelFontSize = 1;

    selectedNodeBigRadius = 2.0;

    showGrid = false;

    drawLinesPoints = false;
    drawEdges = true;
    drawNodes = true;
    drawIsolatedNodes=true;
    sphereQualityOrig = 4;
    sphereQuality = 4; // slices usato per sfere e cilindri
    nodeColorMethodId = 0;
    edgeColorMethodId = 0;
    useCustomRGBColorMethod = false; //by default no customRGB color method is possible until setColorRGB is called
    glListId = -1;
    labelShowSelectedItem = false;
    labelShowSelectedItemAdjacent = false;

    // Default Options for labels visualization
    currentVisibleAttribute=0;
    maxLabelsCollisions=1E4;
    labelsBorderPenWidth=1.0;
    useCustomLabelBackgroundColor=false;
    useCustomLabelBorderColor=false;
    useCustomLabelTextColor=false;
    labelsTextColor=Qt::white;
    labelsBorderColor=Qt::black;
    labelsBackgroundColor=Qt::black;
    labelBaseBackgroundColorNight=QColor(50,50,50,200);
    labelBaseBackgroundColorDay=QColor(255,255,255,200);
    labelTextAlignmentOptions = Qt::AlignHCenter | Qt::AlignVCenter; // Qt::TextWordWrap splits words on more lines
    labelsType=LABELS_TYPE_RECTANGLE;

    roundedLabelsRadius=25.0; // percentage of curvature

    glWidget = NULL;
    nightMode = false;
}
