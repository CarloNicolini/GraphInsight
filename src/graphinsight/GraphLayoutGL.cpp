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
#include <stdexcept>
#include "GraphLayoutGL.h"
#include "Common.h"
#include "Statistic.h"
#include "LabelVisualizer.h"
#include "Timer.h"
#ifdef _WIN32
#define isnan(x) _isnan(x)
#define isinf(x) (!_finite(x))
#define fpu_error(x) (isinf(x) || isnan(x))
#endif

/**
 * @brief GraphLayoutGL::_init
 */
void GraphLayoutGL::_init()
{
    this->scale = 1.0;
    this->selectedNode = NULL;
    this->g = this;
    this->pathName.assign("");
    this->nonIntersectingMode=false;
    this->labels.reserve(g->nodesRand.size());
}

/**
 * @brief GraphLayoutGL::GraphLayoutGL
 */
GraphLayoutGL::GraphLayoutGL() : viewportWidth(640), viewportHeight(480)
{  this->_init();
}

/**
 * @brief GraphLayoutGL::GraphLayoutGL
 * @param orig
 */
GraphLayoutGL::GraphLayoutGL(const GraphLayoutGL& orig) : GraphLayout(orig)
{
    _init();
}

/**
 * @brief GraphLayoutGL::drawSelectedNodeAndEdges
 * @param options
 */
void GraphLayoutGL::drawSelectedNodeAndEdges(GraphLayoutGLOptions *options)
{

    // For Z-buffer problems check http://www.opengl.org/resources/faq/technical/polygonoffset.htm
    options->selectedNodeBigRadius = 1.3;
    if (BESTG->selectedNode == NULL || options->nodeRadius == 0)
        return;
    //if(options->drawEdges)
    {
        if (options->sphereQuality==0)
        {
            glDisable(GL_LIGHTING);
            glDisable(GL_COLOR_MATERIAL);
            glDisable(GL_DEPTH_TEST);
        }
        else
        {
            glEnable(GL_COLOR_MATERIAL);
            glEnable(GL_LIGHTING);
            glEnable(GL_DEPTH_TEST);
        }
        glColor4f(1.0f, 0.3f, 0.0f, 1.0f);
        for (NeighborsRand::iterator iter3 = BESTG->selectedNode->neighborsRand.begin(); iter3!=BESTG->selectedNode->neighborsRand.end();++iter3)
        {
            LNode *lnode = static_cast<LNode*>((*iter3)->second);
            if(this == BESTG && ((int)(lnode->degree) < options->filterMinNodeDegree) )
                continue;
            Neighbor neighborhood = *(*iter3);
            if(options->drawEdges)
                drawEdge(BESTG->selectedNode, neighborhood, options, true);
        }

        if(options->drawNodes)
        {  glColor4f(1.0f, 0.3f, 0.0f, 1.0f);
            for (NeighborsRand::iterator iter3 = BESTG->selectedNode->neighborsRand.begin(); iter3!=BESTG->selectedNode->neighborsRand.end();++iter3)
            {
                LNode *lnode = static_cast<LNode*>((*iter3)->second);
                if(this == BESTG && ((int)lnode->degree) < options->filterMinNodeDegree)
                    continue;
                GLUtils::drawSphereAt((lnode->px + BESTG->offset[0]) * BESTG->scale,
                        (lnode->py + BESTG->offset[1]) * BESTG->scale,
                        (lnode->pz + BESTG->offset[2]) * BESTG->scale,
                        options->nodeRadius * lnode->logDegree * options->selectedNodeBigRadius,
                        options->sphereQuality);
            }
            glColor4f(1.0f, 0.0f, 0.0f, 1.0f);
            GLUtils::drawSphereAt((BESTG->selectedNode->px + BESTG->offset[0]) * BESTG->scale,
                    (BESTG->selectedNode->py + BESTG->offset[1]) * BESTG->scale,
                    (BESTG->selectedNode->pz + BESTG->offset[2]) * BESTG->scale,
                    options->nodeRadius * BESTG->selectedNode->logDegree * options->selectedNodeBigRadius,
                    options->sphereQuality);
        }
    }

}

/**
 * @brief GraphLayoutGL::drawSelectedNodesList
 * @param nodesList
 * @param options
 */
void GraphLayoutGL::drawSelectedNodesList(const vector<LNode *> &nodesList, GraphLayoutGLOptions *options)
{
    glPushAttrib(GL_ALL_ATTRIB_BITS);
    for (vector<LNode*>::const_iterator iter=nodesList.begin();iter!=nodesList.end();++iter)
    {
        LNode *lnode = *iter;
        glColor4f(1.0f,0.3f,0.0f,1.0f);
        GLUtils::drawSphereAt((lnode->px + BESTG->offset[0]) * BESTG->scale,
                (lnode->py + BESTG->offset[1]) * BESTG->scale,
                (lnode->pz + BESTG->offset[2]) * BESTG->scale,
                options->nodeRadius * lnode->logDegree * options->selectedNodeBigRadius*1.5,
                options->sphereQuality);
    }
    glPopAttrib();
}

/**
 * @brief GraphLayoutGL::scaleTranslate
 * @param boundingRadius
 */
void GraphLayoutGL::scaleTranslate(double boundingRadius)
{
    double boundingBox[3][2]= {};
    double boundingBoxCenter[3]= {};

    bool first = true;
    for (NodesRand::const_iterator iter1 = BESTG->nodesRand.begin(); iter1 != BESTG->nodesRand.end(); ++iter1)
    {  LNode *lnode = static_cast<LNode*> (*iter1);

        if(first)
        {  // min,max of x
            boundingBox[0][0] = lnode->px;
            boundingBox[0][1] = lnode->px;

            // min,max of y
            boundingBox[1][0] = lnode->py;
            boundingBox[1][1] = lnode->py;

            // min,max of z
            boundingBox[2][0] = lnode->pz;
            boundingBox[2][1] = lnode->pz;
            first = false;
        }
        else
        {  // min,max of x
            boundingBox[0][0] = std::min(boundingBox[0][0], lnode->px);
            boundingBox[0][1] = std::max(boundingBox[0][1], lnode->px);
            // min,max of y
            boundingBox[1][0] = std::min(boundingBox[1][0], lnode->py);
            boundingBox[1][1] = std::max(boundingBox[1][1], lnode->py);
            // min,max of z
            boundingBox[2][0] = std::min(boundingBox[2][0], lnode->pz);
            boundingBox[2][1] = std::max(boundingBox[2][1], lnode->pz);
        }
    }

    boundingBoxCenter[0] = (boundingBox[0][0] + boundingBox[0][1])/2.0;
    boundingBoxCenter[1] = (boundingBox[1][0] + boundingBox[1][1])/2.0;
    boundingBoxCenter[2] = (boundingBox[2][0] + boundingBox[2][1])/2.0;

    BESTG->offset[0] = -boundingBoxCenter[0];
    BESTG->offset[1] = -boundingBoxCenter[1];
    BESTG->offset[2] = -boundingBoxCenter[2];

    double maxWidth = 0;
    for (int i = 0; i <= 2; i++)
    {  maxWidth = std::max(maxWidth,
                           std::abs(std::max(boundingBox[i][1] - boundingBox[i][0],
                           boundingBox[i][0] - boundingBox[i][1]
                )));
    }
    // Only 1 node -> don't scale but keep current proportion the node will be shown in the center
    if (BESTG->nodes.size()==1)
        maxWidth=1.0;
    BESTG->scale = boundingRadius / maxWidth;
}

// XXX DA FIXARE LE ASSERT NON VANNO BENE IN UN SOFTWARE SERIO!
/**
 * @brief GraphLayoutGL::assertConsistentCoordinates
 */
void GraphLayoutGL::assertConsistentCoordinates()
{
    for (NodesRand::const_iterator iter1 = BESTG->nodesRand.begin(); iter1 != BESTG->nodesRand.end(); ++iter1)
    {  LNode *lnode = static_cast<LNode*>(*iter1);
        {  if (!( !isnan(lnode->px+lnode->py+lnode->pz) && !isinf(lnode->px+lnode->py+lnode->pz) ))
                cerr << "Node " << lnode->id << " has inconsistent coordinates! Check input file" <<  lnode->px << " " << lnode->py << " " << lnode->pz << endl;
            assert( !isnan(lnode->px+lnode->py+lnode->pz) && !isinf(lnode->px+lnode->py+lnode->pz));
        }
        if(lnode->logDegree <= 0)
        {  cerr << "logdegree of " << lnode->id << " is " << lnode->logDegree<<  " and degree=" << lnode->degree << endl;
        }
        assert(lnode->logDegree > 0);
    }
}


/**
 * @brief GraphLayoutGL::draw
 * @param options
 * @param uselist
 * @param update
 * @param select
 */
void GraphLayoutGL::draw(GraphLayoutGLOptions *options, bool uselist, bool update, bool select)
{
    glPushAttrib(GL_ALL_ATTRIB_BITS);
    //glDisable(GL_DITHER);
    if(options->sphereQuality == 0)
    {   glDisable(GL_LIGHTING);
        glDisable(GL_DEPTH_TEST);
    }
    else
    {
        glEnable(GL_LIGHTING);
        glEnable(GL_DEPTH_TEST);
    }

    if (!select && uselist && !update)
    {  glCallList(options->glListId);
        return;
    }

    if (options->rescaleGraph)
        BESTG->scaleTranslate(options->boundingRadius); // XXX we should redraw only when new layout steps are done
    if (!select && uselist)
    {  glNewList(options->glListId, GL_COMPILE_AND_EXECUTE);
    }
    glPushMatrix();

    // Save the current MVP matrix
    glGetDoublev(GL_MODELVIEW_MATRIX, modelview);
    glGetDoublev(GL_PROJECTION_MATRIX, projection);
    glGetIntegerv(GL_VIEWPORT, viewport);

    // We don't need to visualize edges when in selection mode

    // START DRAWING EDGES
    if (!select && options->drawEdges)
    {
        for (NodesRand::const_iterator iter1 = BESTG->nodesRand.begin(); iter1 != BESTG->nodesRand.end(); ++iter1)
        {
            LNode *n1 =  static_cast<LNode*>(*iter1);
            for (NeighborsRand::iterator iterNeigh = n1->neighborsRand.begin(); iterNeigh!=n1->neighborsRand.end(); ++iterNeigh)
            {
                LNode *n2 =  static_cast<LNode*>((*iterNeigh)->second);
                Edge *e = static_cast<Edge*>((*iterNeigh)->first);
                if( n1 == n2 )   // Skip self loops
                    continue;
                if( n1 == BESTG->selectedNode || n2 == BESTG->selectedNode)
                    continue; // we draw it later, in red.

                if(this == BESTG && ( ((int)n1->degree) <  options->filterMinNodeDegree || ((int)n2->degree) < options->filterMinNodeDegree))
                    continue;

                double rgb[4]={0,0,0,0};
                BESTG->detEdgeColor(options, n1, n2, rgb);
                glColor4dv(&rgb[0]);
                Neighbor neighborhood = *(*iterNeigh);
                if ( !e->mark )
                {
                    drawEdge( n1, neighborhood, options, false);
                    e->mark=true;
                }
                else
                    e->mark=false;
            }
        }
    }

    // START DRAWING NODES
    if(options->drawNodes)
    {
        for (NodesRand::const_iterator iter1 = BESTG->nodesRand.begin(); iter1 != BESTG->nodesRand.end(); ++iter1)
        {
            LNode *lnode = static_cast<LNode*>(*iter1);
            if( (this == BESTG) && (lnode->degree < options->filterMinNodeDegree)  )
            {
                continue;
            }
            if (select)
                glPushName(lnode->id);
            double rgb[4];
            BESTG->detNodeColor(options, lnode, rgb);
            if (!select)
            {  glColor4dv(&rgb[0]);
            }
            // BESTG->scale is set to constant when only 1 node is present
            GLUtils::drawSphereAt((lnode->px + BESTG->offset[0]) * BESTG->scale,
                    (lnode->py + BESTG->offset[1]) * BESTG->scale,
                    (lnode->pz + BESTG->offset[2]) * BESTG->scale,
                    options->nodeRadius * (lnode->logDegree), options->sphereQuality);
            if (select)
                glPopName();
        }
    }

    glPopMatrix();
    if (uselist && !select)
        glEndList();
    glPopAttrib();
}

/**
 * @brief GraphLayoutGL::drawEdge
 * @param n1
 * @param neighbor
 * @param options
 * @param selected
 */
void GraphLayoutGL::drawEdge(LNode *n1, Neighbor &neighbor, GraphLayoutGLOptions *options, bool selected)
{
    LNode *tmp;
    Edge *edge = (Edge *)(neighbor.first);
    LNode *n2 = (LNode *)(neighbor.second);
    bool direction = n1->id > n2->id ;//XXX edge->direction non serviva memorizzarla per ora...
    if(options->edgeType != 0)
    {
        if(n1->id < n2->id)
            direction = !direction;
        if(!direction)
        {
            tmp = n1;
            n1 = n2;
            n2 = tmp;
        }
    }

    double radius = options->edgeRadius * (selected ? options->selectedNodeBigRadius : 1)*(log(edge->weight*2.7183+1.0));
    double minNodeRadius = std::min(n1->logDegree, n2->logDegree) * options->nodeRadius * (selected ? options->selectedNodeBigRadius : 1);

    if(options->nodeRadius > 0 && radius >= minNodeRadius * 0.8)
    {
        radius = minNodeRadius * 0.8;
    }

    GLUtils::drawCylinder(radius,
                          (n1->px + BESTG->offset[0]) * BESTG->scale,
            (n1->py + BESTG->offset[1]) * BESTG->scale,
            (n1->pz + BESTG->offset[2]) * BESTG->scale,
            (n2->px + BESTG->offset[0]) * BESTG->scale,
            (n2->py + BESTG->offset[1]) * BESTG->scale,
            (n2->pz + BESTG->offset[2]) * BESTG->scale,
            options->sphereQuality > 0 ? 3 : 0, options->edgeType);
}

/**
 * @brief GraphLayoutGL::setSelectedNode
 * @param id
 */
void GraphLayoutGL::setSelectedNode(int id)
{
    if ( BESTG->nodes.find(id)!=BESTG->nodes.end() && id>=0)
    {  BESTG->selectedNode = static_cast<LNode*>(BESTG->nodes[id]);
    }
    else
        BESTG->selectedNode = NULL;
}

/**
 * @brief GraphLayoutGL::normalizedCoord
 * @param v
 * @param coord
 * @return
 */
double  GraphLayoutGL::normalizedCoord(double v, int coord)
{  return (v+BESTG->offset[coord]) * BESTG->scale;
}

/**
 * @brief GraphLayoutGL::getSelectedNode
 * @return
 */
LNode *GraphLayoutGL::getSelectedNode()
{  return BESTG->selectedNode;
}

/**
 * @brief GraphLayoutGL::detNodeColor
 * @param options
 * @param lnode
 * @param rgbt
 */
void GraphLayoutGL::detNodeColor(GraphLayoutGLOptions *options, LNode *lnode, double *rgbt)
{  double hsv[3]= {0.0,0.0,0.0}, v=0;
    switch(options->nodeColorMethodId)
    {  case NODECOLOR_METHOD_BLUE2RED_ON_DEGREE:
    case NODECOLOR_METHOD_GREEN2BLACK:
    case NODECOLOR_METHOD_TRANSPARENT2BLACK:
        v = (lnode->degree-this->g->statsMinNodeDegree) / (this->g->statsMaxNodeDegree-this->g->statsMinNodeDegree);
        if(isnan(v) || isinf(v) ) // se min == max ...
            v = 0.5;
        break;
    case NODECOLOR_METHOD_RAINBOW:
    case NODECOLOR_METHOD_SEQUENTIAL:
        v = (double)lnode->index/(double)nodesRand.size();
        break;

    case NODECOLOR_METHOD_COMPONENT:
        v = (double)lnode->component/(double)BESTG->countConnectedComponents();
        break;
    default:
        break;
    }

    switch(options->nodeColorMethodId)
    {  case NODECOLOR_METHOD_WHITE:
    {  rgbt[0] = 1.0;
        rgbt[1] = 1.0;
        rgbt[2] = 1.0;
        rgbt[3] = 1.0;
        break;
    }
    case NODECOLOR_METHOD_GRAY:
    {  rgbt[0] = 0.5;
        rgbt[1] = 0.5;
        rgbt[2] = 0.5;
        rgbt[3] = 1.0;
        break;
    }
    case NODECOLOR_METHOD_BLACK:
    {  rgbt[0] = 0.0;
        rgbt[1] = 0.0;
        rgbt[2] = 0.0;
        rgbt[3] = 1.0;
        break;
    }
    case NODECOLOR_METHOD_BLUE2RED_ON_DEGREE:
    {  hsv[0] = (1.0-v) * 240.0f;
        hsv[1] = 1.0f;
        hsv[2] = 1.0f;
        GLUtils::HSVtoRGB(&rgbt[0], &rgbt[1], &rgbt[2], hsv[0], hsv[1], hsv[2]);
        rgbt[3] = 1.0f;
        break;
    }
    case NODECOLOR_METHOD_GREEN2BLACK:
    {  rgbt[0] = 0;
        rgbt[1] = v;
        rgbt[2] = 0;
        rgbt[3] = 1.0f;
        break;
    }
    case NODECOLOR_METHOD_TRANSPARENT2BLACK:
    {  hsv[0] = (1.0-v) * 240.0f;
        hsv[1] = 1.0f;
        hsv[2] = 1.0f;
        GLUtils::HSVtoRGB(&rgbt[0], &rgbt[1], &rgbt[2], hsv[0], hsv[1], hsv[2]);
        rgbt[3] = lnode->logDegree/BESTG->logDegreeMax ;
        break;
    }
    case NODECOLOR_METHOD_RAINBOW:
    {  hsv[0] = (1.0-v) * 360.0f;
        hsv[1] = 1.0f;
        hsv[2] = 1.0f;
        GLUtils::HSVtoRGB(&rgbt[0], &rgbt[1], &rgbt[2], hsv[0], hsv[1], hsv[2]);
        rgbt[3] = 1.0f;
        break;
    }
    case NODECOLOR_METHOD_CUSTOM_RGB:
    {  rgbt[0] = ((double)lnode->colorRed)/255.0;
        rgbt[1] = ((double)lnode->colorGreen)/255.0;
        rgbt[2] = ( (double)lnode->colorBlue)/255.0;
        rgbt[3] = 1.0f;
        break;
    }
    case  NODECOLOR_METHOD_COMPONENT:
    {  hsv[0] = (1.0-v) * 240.0f;
        hsv[1] = 1.0f;
        hsv[2] = 1.0f;
        GLUtils::HSVtoRGB(&rgbt[0], &rgbt[1], &rgbt[2], hsv[0], hsv[1], hsv[2]);
        rgbt[3] = 1.0f;
        break;
    }
    case NODECOLOR_METHOD_SEQUENTIAL:
    {  GLUtils::hsv2rgb(1,v,1-v, &rgbt[0], &rgbt[1],&rgbt[2]);
        rgbt[3] = 1.0f;
        break;
    }
    case NODECOLOR_METHOD_LENGTH:
    {  if( !lnode->neighborsRand.empty() )
        {  LNode *n1 = lnode;
            LNode *n2 = static_cast<LNode*>(lnode->neighborsRand[0]->second);
            v = (sqrt(  SQR(n1->px - n2->px) + SQR(n1->py - n2->py) + SQR(n1->pz - n2->pz))-minEdgeLength) / (maxEdgeLength-minEdgeLength);
            if(isnan(v) || isinf(v)) // se min == max ...
                v = 0.5;
        }
        else
        {  v = 0.5;
        }
        hsv[0] = (v) * 240.0f;
        hsv[1] = 1.0f;
        hsv[2] = 1.0f;
        GLUtils::HSVtoRGB(&rgbt[0], &rgbt[1], &rgbt[2], hsv[0], hsv[1], hsv[2]);
        rgbt[3] = 1.0f;
        break;
    }
    default:
        throw std::out_of_range("Coloring method not known");
    }

    if(BESTG->selectedNode)
    {  GLUtils::RGBtoHSV(rgbt[0], rgbt[1], rgbt[2], &hsv[0], &hsv[1], &hsv[2]);
        hsv[1] /= 2.0; // reduce saturation
        GLUtils::HSVtoRGB(&rgbt[0], &rgbt[1], &rgbt[2], hsv[0], hsv[1], hsv[2]);
        rgbt[3] = 0.5f;
    }
}

/**
 * @brief GraphLayoutGL::detEdgeColor
 * @param options
 * @param n1
 * @param n2
 * @param rgb
 */
void GraphLayoutGL::detEdgeColor(GraphLayoutGLOptions *options, LNode *n1, LNode *n2, double *rgb)
{  double hsv[3]= {1.0,1.0,1.0};
    double v=0.5;

    switch(options->edgeColorMethodId)
    {  case EDGECOLOR_METHOD_WIDTH:
    {  v = (sqrt(  SQR(n1->px - n2->px) + SQR(n1->py - n2->py) + SQR(n1->pz - n2->pz))-minEdgeLength) / (maxEdgeLength-minEdgeLength);
        if(isnan(v) || isinf(v)) // se min == max ...
            v = 0.5;
        hsv[0] = (v) * 240.0f;
        hsv[1] = 1.0f;
        hsv[2] = 1.0f;
        GLUtils::HSVtoRGB(&rgb[0], &rgb[1], &rgb[2], hsv[0], hsv[1], hsv[2]);
        rgb[3] = 1.0f;
        break;
    }
    case EDGECOLOR_METHOD_WHITE:
    {  rgb[0] = 1.0f;
        rgb[1] = 1.0f;
        rgb[2] = 1.0f;
        rgb[3] = 1.0f;
        break;
    }
    case EDGECOLOR_METHOD_GRAY:
    {  rgb[0] = 0.5f;
        rgb[1] = 0.5f;
        rgb[2] = 0.5f;
        rgb[3] = 1.0f;
        break;

    }
    case EDGECOLOR_METHOD_BLACK:
    {  rgb[0] = 0.0f;
        rgb[1] = 0.0f;
        rgb[2] = 0.0f;
        rgb[3] = 1.0f;
        break;
    }
        //XXX
    case EDGECOLOR_METHOD_DEGREE:
    {
        // 2 because is the average scaled
        v = abs(n1->degree+n2->degree)/2;
        v = abs(v - this->statsMinNodeDegree) / (abs(this->statsMaxNodeDegree - this->statsMinNodeDegree));
        if(isnan(v) || isinf(v)) // se min == max ...
            v = 0.5;

        hsv[0] = (1.0-v) * 240.0f;
        hsv[1] = 1.0f;
        hsv[2] = 1.0f;
        GLUtils::HSVtoRGB(&rgb[0], &rgb[1], &rgb[2], hsv[0], hsv[1], hsv[2]);
        rgb[3] = 1.0f;

        break;
    }
    case EDGECOLOR_METHOD_COMPONENT:
    {  // This is true because if there is an edge between two nodes they share the same connected component!
        v = (double)n1->component/(double)BESTG->countConnectedComponents();
        if(isnan(v) || isinf(v)) // se min == max ...
            v = 0.5;
        // Use the same coloring rule as the one used in detNodeColor for the NODECOLOR_METHOD_COMPONENT case
        hsv[0] = (1.0-v) * 240.0f;
        hsv[1] = 1.0f;
        hsv[2] = 1.0f;
        GLUtils::HSVtoRGB(&rgb[0], &rgb[1], &rgb[2], hsv[0], hsv[1], hsv[2]);
        rgb[3] = 1.0f;
        break;
    }
    case EDGECOLOR_METHOD_CUSTOM_RGB:
    {
        rgb[0]=(n1->colorRed+n2->colorRed)/(2*255.0);
        rgb[1]=(n1->colorRed+n2->colorGreen)/(2*255.0);
        rgb[2]=(n1->colorRed+n2->colorBlue)/(2*255.0);
        rgb[3] = 1.0f;
        break;
    }
    default:
    {  std::logic_error("Not supported edge color method");
        break;
    }
    }


    if(BESTG->selectedNode)
    {  GLUtils::RGBtoHSV(rgb[0], rgb[1], rgb[2], &hsv[0], &hsv[1], &hsv[2]);
        hsv[1] /= 2.0; // reduce saturation
        GLUtils::HSVtoRGB(&rgb[0], &rgb[1], &rgb[2], hsv[0], hsv[1], hsv[2]);
        rgb[3] = 0.5;
    }
}

/**
 * @brief GraphLayoutGL::drawLabel Draw the label of the current node *lnode. XXX this call is faster if the text relative to the node
 * is passed as argument instead of being extracted via entitiesMap!
 * @param lnode
 * @param options
 * @param painter
 * @param dataSet
 */
void GraphLayoutGL::drawNodeLabel(LNode *lnode, GraphLayoutGLOptions *options, QPainter &painter, DataSet &dataSet)
{
    // First of all we must discard nodes with coordinates lying outside the viewport, this increase speed
    double projX=0.0;
    double projY=0.0;
    double projZ=0.0;
    GLUtils::projectWithMVP( (lnode->px + BESTG->offset[0]) * BESTG->scale,
            (lnode->py + BESTG->offset[1]) * BESTG->scale,
            (lnode->pz + BESTG->offset[2]) * BESTG->scale,
            this->modelview,this->projection,this->viewport,
            &projX,&projY,&projZ);
    lnode->labelX = projX;
    lnode->labelY = projY;

    // This optimization ensures that labels of nodes outside visualization area are not drawn!
    bool nodeInsideArea = ( (projX >=0 && projX <=  options->glWidget->width() ) && (projY>=0  &&projY <= options->glWidget->height()));
    if (!nodeInsideArea)
        return;

    QFont currentFont= options->glWidget->font();
    double fontSize = options->labelFontSize*lnode->logDegree;
    if(fontSize <= 0.0)
        return;

    currentFont.setPointSizeF((double)GraphLayoutGLOptions::baseLabelFontSize+fontSize);
    Entity *e = lnode->ptrEntity;
    QString str;
    if (e->attributes.empty())
        str = QString::number(lnode->id);
    else
    {
        if (!e->attributes[(options->currentVisibleAttribute)]->valueString.empty())
            str =  QString::fromStdString(e->attributes[(options->currentVisibleAttribute)]->valueString);
        else
            str = QString::number(lnode->id);
    }

    double rgbt[4]={0.0,0.0,0.0,0.0};

    if(options->labelShowSelectedItem && BESTG->selectedNode == lnode)
    {
        rgbt[0] = 1.0;
        rgbt[1] = 0.0;
        rgbt[2] = 0.0;
        rgbt[3] = 1.0;
    }
    else
    {
        BESTG->detNodeColor(options, lnode,rgbt);
    }

    painter.setFont(currentFont);
    // use the background color of labels specified in graphlayout options
    if ( options->useCustomLabelBackgroundColor )
    {
        // Label border color
        painter.setPen(QPen(options->labelsBorderColor,options->labelsBorderPenWidth,Qt::SolidLine));
        // Label background color
        painter.setBrush(options->labelsBackgroundColor);
    }
    else // use the standard color related of the node color
    {
        painter.setPen(QPen(QColor(rgbt[0]*255,rgbt[1]*255,rgbt[2]*255,rgbt[3]*255),1,Qt::SolidLine));
        // If it's night make the label more transparent, if the background is white make it darker
        if (options->nightMode)
            painter.setBrush(options->labelBaseBackgroundColorNight);
        else
            painter.setBrush(  options->labelBaseBackgroundColorDay     );
    }

    // Create the rectangle which contains the labels text, the color of background has been already set
    QRectF boundingBox = painter.boundingRect(projX,projY,0,0,options->labelTextAlignmentOptions,str);
    //QFontMetrics fontMetric = painter.fontMetrics();
    // Center the rectangular label on node
    //r.translate(-fontMetric.width(str)*0.5,-fontMetric.height()*0.5);
    // Draw the rectangle
    switch (options->labelsType)
    {
    case  LABELS_TYPE_VOID:
        break;
    case LABELS_TYPE_ROUNDED:
        painter.drawRoundedRect(boundingBox,options->roundedLabelsRadius,options->roundedLabelsRadius,Qt::RelativeSize);
        break;
    case LABELS_TYPE_RECTANGLE:
        painter.drawRect(boundingBox);
        break;
    }
    // Save the width and height of the drawing rectangle
    lnode->labelWidth=boundingBox.width();
    lnode->labelHeight=boundingBox.height();

    if ( options->useCustomLabelTextColor )
    {
        painter.setPen(QPen(options->labelsTextColor,options->labelsBorderPenWidth,Qt::SolidLine));
    }
    else
    {
        if (options->nightMode)
            painter.setPen(QPen(Qt::white,1,Qt::SolidLine));
        else
            painter.setPen(QPen(Qt::black,1,Qt::SolidLine));
    }
    //cerr << "NORMAL " << str.toStdString() << endl;
    painter.drawText(boundingBox,str);
}

/**
 * @brief GraphLayoutGL::drawLabels
 * @param options
 * @param dataSet
 * @param isTopGraph
 */
void GraphLayoutGL::drawAllNodeLabels(GraphLayoutGLOptions *options, DataSet &dataSet, bool isTopGraph)
{
    glPushAttrib(GL_ALL_ATTRIB_BITS);
    // Important to make possible overpainting!!!
    // See the example Overpainting in Qt Creator examples
    glShadeModel(GL_FLAT);
    glDisable(GL_CULL_FACE);
    glDisable(GL_DEPTH_TEST);
    glDisable(GL_LIGHTING);

    QPainter painter(options->glWidget);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setRenderHint(QPainter::TextAntialiasing);
    painter.save();

    if(options->labelMinNodeDegree != -1 && isTopGraph && options->drawNodes)
    {
        for (NodesRand::const_iterator iter1 = BESTG->nodesRand.begin(); iter1 != BESTG->nodesRand.end(); ++iter1)
        {
            LNode *lnode = static_cast<LNode*> (*iter1);
            if(this == BESTG && ( std::floor(lnode->degree) ) < options->filterMinNodeDegree)
                continue;

            if(BESTG->selectedNode == lnode)
            {
                continue;
            }
            else
            {
                if(!(options->labelMinNodeDegree != -1 && options->labelFontSize > 0 && (std::floor(lnode->degree)) >= options->labelMinNodeDegree))
                    continue;
            }
            drawNodeLabel(lnode, options, painter, dataSet);
        }

        // Draw unsaturated labels over
        if(BESTG->selectedNode && options->labelShowSelectedItem)
        {   if(options->labelShowSelectedItemAdjacent)
            {
                for (NeighborsRand::iterator iter = BESTG->selectedNode->neighborsRand.begin(); iter!=BESTG->selectedNode->neighborsRand.end(); ++iter)
                {
                    LNode *lnode = static_cast<LNode*>((*iter)->second);
                    // XXXXXX
                    //if ((int)lnode->degree < options->filterMinNodeDegree || lnode->degree < options->labelMinNodeDegree )
                    //continue;
                    drawNodeLabel(lnode,options,painter,dataSet);
                }
            }
            drawNodeLabel(BESTG->selectedNode, options, painter, dataSet);
        }
    }
    painter.restore();
    painter.end();
    glPopAttrib();
}

/**
 * @brief GraphLayoutGL::drawLabelsNonIntersectingMode
 * @param options
 * @param dataSet
 * @param isTopGraph
 */
void GraphLayoutGL::drawLabelsNonIntersectingMode(GraphLayoutGLOptions *options, DataSet &dataSet, bool isTopGraph)
{
    glPushAttrib(GL_ALL_ATTRIB_BITS);
    // Important to make possible overpainting!!!
    glShadeModel(GL_FLAT);
    glDisable(GL_CULL_FACE);
    glDisable(GL_DEPTH_TEST);
    glDisable(GL_LIGHTING);

    QPainter painter(options->glWidget);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setRenderHint(QPainter::TextAntialiasing);
    painter.save();
    this->viewportWidth=options->glWidget->width();
    this->viewportHeight = options->glWidget->height();

    labels.clear(); // IMPORTANT TO CLEAR THE LABELS AT EVERY STEP!!!

    if(options->labelMinNodeDegree != -1 && isTopGraph && options->drawNodes )
    {  // First fill the labels vector for the drawing
        QFont fnt= options->glWidget->font();
        for (NodesRand::const_iterator iter1 = BESTG->nodesRand.begin(); iter1 != BESTG->nodesRand.end(); ++iter1)
        {
            LNode *lnode = static_cast<LNode*>( *iter1);
            lnode->labelVisible=true;
            double fontSize = options->labelFontSize*lnode->logDegree;
            if(fontSize <= 0)
            {
                continue;
            }
            double projX=0.0,projY=0.0,projZ=0.0;
            GLUtils::projectWithMVP( (lnode->px + BESTG->offset[0]) * BESTG->scale,
                    (lnode->py + BESTG->offset[1]) * BESTG->scale,
                    (lnode->pz + BESTG->offset[2]) * BESTG->scale,
                    this->modelview,this->projection,this->viewport,
                    &projX,&projY,&projZ);
            if ( std::floor(lnode->degree)  < options->filterMinNodeDegree)
                continue;
            fnt.setPointSizeF((double)GraphLayoutGLOptions::baseLabelFontSize+fontSize);
            Entity * e = lnode->ptrEntity;
            QString str;
            if (e->attributes.empty())
                str = QString::number(lnode->id);
            else
            {
                if (!e->attributes[(options->currentVisibleAttribute)]->valueString.empty())
                    str =  QString::fromStdString(e->attributes[(options->currentVisibleAttribute)]->valueString);
                else
                    str = QString::number(lnode->id);
            }

            painter.setFont(fnt);
            painter.setPen(QPen(QColor(0,0,0,0),1,Qt::SolidLine));
            painter.setBrush(options->labelBaseBackgroundColorNight);

            // Compute the dimension (width,height) of the rectangular labels for this node
            QFontMetrics fm = painter.fontMetrics();
            int labelWidth = fm.width(str);
            int labelHeight  = fm.height();
            // Set the labelWidth and height as LNode attributes, together with projected coordinates
            lnode->labelWidth =labelWidth;
            lnode->labelHeight = labelHeight;
            lnode->labelX = projX;
            lnode->labelY = projY;
            //qDebug() << projX << " " << projY << " " << labelWidth << " " << labelHeight ;
            //  PUT THE RULES FOR THE NODES VISUALIZATION HERE
            bool conditionInside = ((lnode->labelX+lnode->labelWidth/2) >=0) && (lnode->labelY+lnode->labelHeight/2)>=0 && ( lnode->labelX-lnode->labelWidth/2) <= viewportWidth &&  (lnode->labelY - lnode->labelHeight/2) <= viewportHeight;
            bool conditionOnDegreeFilter = lnode->degree >= options->labelMinNodeDegree;
            if (conditionInside && conditionOnDegreeFilter)
                labels.push_back(lnode);
        }

        // This is a special case, this node has ALWAYS to be shown independently from filtering
        if (BESTG->selectedNode!=NULL && options->labelShowSelectedItem )
        {  labels.push_back(BESTG->selectedNode);
            if ( options->labelShowSelectedItemAdjacent)
            {  for (NeighborsRand::iterator iter = BESTG->selectedNode->neighborsRand.begin(); iter!=BESTG->selectedNode->neighborsRand.end(); ++iter)
                {  LNode *neigh = static_cast<LNode*>( (*iter)->second);
                    labels.push_back(neigh);
                }
            }
        }

        // Then creates the maximal indendent set of rectangles to draw
        LabelVisualizer lv(BESTG);
        int labelsBorder = 0; //pixels
        unsigned int maxLabelsCollisions = options->maxLabelsCollisions; // this limits both memory and CPU consuption during navigation, the MIS computation is faster
        lv.setVisibileLabels(labels,viewportWidth,viewportHeight,maxLabelsCollisions,labelsBorder);

        // Finally draws them only if are set as visible
        for (NodesRand::const_iterator iter = labels.begin(); iter!=labels.end(); ++iter)
        {  LNode *lnode = static_cast<LNode*> (*iter);
            if (lnode->labelVisible)
            {  double rgbt[4];
                if(options->labelShowSelectedItem && BESTG->selectedNode == lnode)
                {  rgbt[0] = 1;
                    rgbt[1] = 0;
                    rgbt[2] = 0;
                    rgbt[3] = 1;
                }
                else
                {
                    BESTG->detNodeColor(options, lnode,rgbt);
                }
                double fontSize = options->labelFontSize*lnode->logDegree;
                QFont fnt= options->glWidget->font();
                fnt.setPointSizeF((double)GraphLayoutGLOptions::baseLabelFontSize+fontSize);

                QString str;
                Entity *e = lnode->ptrEntity;
                if (e->attributes.empty())
                    str = QString::number(lnode->id);
                else
                {
                    if (!e->attributes[(options->currentVisibleAttribute)]->valueString.empty())
                        str =  QString::fromStdString(e->attributes[(options->currentVisibleAttribute)]->valueString);
                    else
                        str = QString::number(lnode->id);
                }

                painter.setFont(fnt);
                if ( !options->useCustomLabelBackgroundColor )
                {
                    painter.setPen(QPen(QColor(rgbt[0]*255,rgbt[1]*255,rgbt[2]*255,rgbt[3]*255),1,Qt::SolidLine));
                    // If it's night make the label more transparent, if the background is white make it darker
                    if (options->nightMode)
                        painter.setBrush(options->labelBaseBackgroundColorNight);
                    else
                        painter.setBrush(options->labelBaseBackgroundColorDay);
                }
                else    // use the background color of labels specified in graphlayout options
                {
                    // Label border color
                    painter.setPen(QPen(options->labelsBorderColor,options->labelsBorderPenWidth,Qt::SolidLine));
                    // Label background color
                    painter.setBrush(options->labelsBackgroundColor);
                }

                QRectF boundingBox = painter.boundingRect(lnode->labelX,lnode->labelY,0,0,options->labelTextAlignmentOptions ,str);
                // Translate the bounding box to the node center
                switch (options->labelsType)
                {
                case  LABELS_TYPE_VOID:
                    break;
                case LABELS_TYPE_ROUNDED:
                    painter.drawRoundedRect(boundingBox,options->roundedLabelsRadius,options->roundedLabelsRadius,Qt::RelativeSize);
                    break;
                case LABELS_TYPE_RECTANGLE:
                    painter.drawRect(boundingBox);
                    break;
                }
                if ( options->useCustomLabelTextColor )
                {
                    painter.setPen(QPen(options->labelsTextColor,options->labelsBorderPenWidth,Qt::SolidLine));
                }
                else
                {
                    if (options->nightMode)
                        painter.setPen(QPen(Qt::white,1,Qt::SolidLine));
                    else
                        painter.setPen(QPen(Qt::black,1,Qt::SolidLine));
                }
                //cerr << "NONINTERSECTING " << str.toStdString() << endl;
                painter.drawText(boundingBox,str);
            }
        }
        // Force drawing of selected node if there is one and is set as non visible by MIS filtering
        if (selectedNode!=NULL && static_cast<LNode*>(selectedNode)->labelVisible==false  && options->labelShowSelectedItem )
            drawNodeLabel(selectedNode,options,painter,dataSet);
    }
    painter.restore();
    painter.end();
    glPopAttrib();
}

/**
 * @brief GraphLayoutGL::setWidthAndHeight
 * @param _width
 * @param _height
 */
void GraphLayoutGL::setWidthAndHeight(int _width, int _height)
{  this->viewportWidth=_width;
    this->viewportHeight=_height;
}

/**
 * @brief GraphLayoutGL::~GraphLayoutGL
 */
GraphLayoutGL::~GraphLayoutGL()
{
}

