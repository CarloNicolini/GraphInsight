/****************************************************************************
**
** Copyright (C) 2010 Carlo Nicolini (nicolini.carlo@gmail.com)
** All rights reserved.
**
** Warning: This program is protected by copyright law and international
** treaties. Unauthorized reproduction and distribution of this program,
** or any portion of it, may result in severe civil and criminal penalties,
** and will be persecuted to the maximum extent possible under the law.
**
****************************************************************************/


#include "LNode.h"
#include "Graph.h"
#include "GraphLayout.h"
#include "Common.h"
#include "LabelVisualizer.h"

#include <iostream>
#include <list>

using namespace std;

/**
 * @ingroup GraphLayout
 * @brief LabelVisualizer::LabelVisualizer Standard constructor
 */
LabelVisualizer::LabelVisualizer()
{  g=NULL;
}

/**
 * @ingroup GraphLayout
 * @brief LabelVisualizer::LabelVisualizer Constructor from a graph, it initialize the necessary data structures
 * @param g The graph to work on
 */
LabelVisualizer::LabelVisualizer(GraphLayout *g)
{  init(g);
}

/**
 * @ingroup GraphLayout
 * @brief LabelVisualizer::init Initialize the class, must be called if the object has not been instanciated with the constructor LabelVisualizer::LabelVisualizer(GraphLayout *g)
 * @param gl The graph to work on
 */
void LabelVisualizer::init(GraphLayout *gl)
{  g=gl;
}

/**
 * @ingroup GraphLayout
 * @brief LabelVisualizer::~LabelVisualizer Destructor, does nothing
 */
LabelVisualizer::~LabelVisualizer()
{
}

/**
 * @ingroup GraphLayout
 * @brief LabelVisualizer::setVisibileLabels Main method for the class, it set visible labels exploiting a fast intersection test based on partial ordering and maximal independent set of collision graph for the labels
 * @param labels A vector of nodes, each node containing the label coordinates
 * @param areawidth Visualized area width in pixel
 * @param areaheight Visualization area heigh in pixel
 * @param maxNCollisions Limit the maximum number of collision, the lower, the faster the algorithm but worse results
 * @param labelsBorder A border for the labels, in order to avoid too close labels, typically set to 5 pixel
 * @return 0 If the method applied correctly, 1 otherwise
 */
unsigned int LabelVisualizer::setVisibileLabels(NodesRand &labels, int areawidth, int areaheight, unsigned int maxNCollisions, char labelsBorder)
{
    return checkIntersectionFast(labels,areawidth,areaheight,maxNCollisions,labelsBorder);
}

/**
 * @brief sortLabelByXandY A function to sort labels of nodes by increasing X coordinate and then by increasing Y coordinate
 * @param n1
 * @param n2
 * @return
 */
bool sortLabelByXandY(Node* n1, Node *n2)
{
    if ( static_cast<LNode*>(n1)->labelX == static_cast<LNode*>(n2)->labelX )
        return static_cast<LNode*>(n1)->labelY < static_cast<LNode*>(n2)->labelY;
    else
        return static_cast<LNode*>(n1)->labelX < static_cast<LNode*>(n2)->labelX;
}

/**
 *@ingroup GraphLayout Sort the rectangles according to their low_x().
 *# O(n log n) For each rectangle in sorted array # O(n)
    Finds its highest X point   # O(1)
    Compare it with all rectangles whose low_x() is smaller # O(log n)
        than this.high(x)
 * @brief LabelVisualizer::checkIntersectionFast Is the core method for fast label overlap remotion, it's based on
 * @param labels Vector of nodes with labels to work on (can be a subset of all nodes in the graph)
 * @param width Visualization area width
 * @param height Visualization area height
 * @param nmaxcollisions Limit the number of collisions
 * @param labelsBorder Labels border in pixel to avoid too close labels
 * @return 0 nothing was done, 1 otherwise
 */
unsigned int LabelVisualizer::checkIntersectionFast( NodesRand &labels, int width, int height, unsigned int nmaxcollisions,char labelsBorder)
{
    if (labels.empty())
        return 0;
    /*
    // At first it must consider only the nodes which are inside the viewport area
    std::vector<LNode*> labels;
    for (NodesRand::iterator iter1=g->nodesRand.begin(); iter1!=g->nodesRand.end(); ++iter1)
    {
        LNode *n1 = (LNode*)(*iter1);
        //n1->labelVisible=true; // preset all nodes as visible
        // The rectangles must be in the visible area!!!
        if (  ((n1->labelX+n1->labelWidth) >=0) &&
              (n1->labelY+n1->labelHeight)>=0 &&
              n1->labelX <= width &&
              n1->labelY <= height &&
              n1->mark)
        {
            labels.push_back(n1);
        }
    }
    */
    // first sort by increasing x ( O(n log(n))

    std::sort(labels.begin(),labels.end(), sortLabelByXandY);

    // Then start pairwise comparison (a very smart algorithm, it's O(n log(n) )
    // Put the collided nodes in the collisions graph
    unsigned int n=labels.size();

    Graph *collisionGraph = new Graph();

    for (unsigned int i=0; i<n;  ++i)
    {
        unsigned int j=i;
        LNode *ni = static_cast<LNode*>( labels.at(i));
        int Li =  ni->labelWidth + ni->labelX;
        // "j counter" reaches the labels with x > right border of i-th label
        while ( j<n && static_cast<LNode*>(labels.at(j))->labelX <= Li )
            ++j;

        for (unsigned int k=i+1; (k<=j && k<n) ; ++k)
        {
            LNode *nk = static_cast<LNode*>(labels.at(k));
            if  (collisionGraph->statsNodesCount <nmaxcollisions  )
            {
                if ( twoNodeLabelsIntersect(ni,nk,labelsBorder) )
                {
                    collisionGraph->insertNode(ni->id);
                    collisionGraph->insertNode(nk->id);
                    collisionGraph->insertEdge(ni->id, nk->id);
                    ni->labelVisible =nk->labelVisible = false;
                }
            }
        }
    }

    // This is needed to mark the vertices of a maximal independent set in the collision graph
    // This algorithm is quite fast and there is no need of further optimization while the previous collision detection is much slower
    collisionGraph->markMaximalIndependentSetSequential();
    for (NodesRand::iterator iter = collisionGraph->nodesRand.begin(); iter!=collisionGraph->nodesRand.end();++iter)
    {
        Node *fakeNode = (*iter);
        if ( fakeNode->mark )   //is in the maximal independent set of the collision graph
        {
            int id = fakeNode->id;
            if (g->nodes.find(id)!=g->nodes.end())
            {
                static_cast<LNode*>(g->nodes[id])->labelVisible=true;
            }
        }
    }

    unsigned int collisionCount = collisionGraph->nodesRand.size();
    delete collisionGraph;
    return collisionCount ;
}

/**
 * @ingroup GraphLayout
 * @brief LabelVisualizer::twoNodeLabelsIntersect Check if the rectangular labels of two given nodes intersect
 * @param n1 Node 1
 * @param n2 Node 2
 * @param labelsBorder Labels border to consider when checking intersection
 * @return True if collide, False otherwise
 */
inline bool LabelVisualizer::twoNodeLabelsIntersect(LNode *n1, LNode *n2, int labelsBorder)
{
    if (n1==n2)
        return false;
    int x1 = n1->labelX-labelsBorder;
    int x2 = n2->labelX-labelsBorder;

    int y1 = n1->labelY-labelsBorder;
    int y2 = n2->labelY-labelsBorder;

    int w1 = n1->labelWidth+labelsBorder;
    int w2 = n2->labelWidth+labelsBorder;

    int h1 = n1->labelHeight+labelsBorder;
    int h2 = n2->labelHeight+labelsBorder;

    bool xOverlap = ( x2 <= (x1+w1)) && ( x2 >= x1 ) || ( x1 <= (x2+w2)) && ( x1 >= x2 );
    bool yOverlap = ( y2 <= (y1+h1)) && ( y2 >= y1 ) || ( y1 <= (y2+h2)) && ( y1 >= y2 );

    return xOverlap && yOverlap ;
}
