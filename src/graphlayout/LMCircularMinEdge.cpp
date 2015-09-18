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


#include "LMCircularMinEdge.h"
#include "GraphLayout.h"
#include <cmath>
#include <iostream>

#include <Eigen/Core>
#include <Eigen/Sparse>
#include <Eigen/Geometry>
#include <Eigen/LU>
#include <Eigen/SVD>
#include <Eigen/Eigenvalues>

#include "Common.h"

/**
 * @ingroup GraphLayout
 * @brief LMCircularMinEdge::LMCircularMinEdge Standard constructor, does nothing
 */
LMCircularMinEdge::LMCircularMinEdge() : g(NULL), gravity(0.0), nstepsDone(0), nDimensions(3), fixedNodes(std::vector<LNode*>(3) )
{
}

/**
 * @brief LMCircularMinEdge::~LMCircularMinEdge Standard destructor, does nothing
 */
LMCircularMinEdge::~LMCircularMinEdge()
{
}

/**
 * @brief sortNodeByXandY A function to sort nods coordinates by increasing X coordinate and then by increasing Y coordinate
 * @param n1
 * @param n2
 * @return
 */
bool sortNodesByX(Node* n1, Node *n2)
{
    return static_cast<LNode*>(n1)->px < static_cast<LNode*>(n2)->px;
}

bool sortNodesByY(Node* n1, Node *n2)
{
    return static_cast<LNode*>(n1)->py < static_cast<LNode*>(n2)->py;
}

void LMCircularMinEdge::selectFixedNodes()
{
    // The first fixed node is set at random
    NodesRand tmp = g->nodesRand;
    std::sort(tmp.begin(),tmp.end(),sortNodesByX);
    fixedNodes[0] =static_cast<LNode*>(tmp.front());
    fixedNodes[1] = static_cast<LNode*>(tmp.back());

    std::sort(tmp.begin(),tmp.end(),sortNodesByY);

    if ( fixedNodes[1]->py > 0 )
    {
        fixedNodes[2] =static_cast<LNode*>(tmp.back());
    }
    else
    {
        fixedNodes[2] =static_cast<LNode*>(tmp.front());
    }
}

/**
 * @brief LMCircularMinEdge::init Initialize the layout method, actually it lay out the graph on circular coordinates, if you don't want an edge length reduction heuristic
 * @param gl
 * @param _nDimensions
 */
void LMCircularMinEdge::init(GraphLayout *gl, int _nDimensions)
{  g=gl;
    nDimensions = _nDimensions;
    if ( g->nodesRand.back()->component == 0)
        g->countConnectedComponents();
    nstepsDone=0;

    for (NodesRand::const_iterator iter1=g->nodesRand.begin(); iter1!=g->nodesRand.end(); ++iter1)
    {
        LNode *n1=static_cast<LNode*>(*iter1);
        n1->px = Common::unifRand(-1.0,1.0);
        n1->py = Common::unifRand(-1.0,1.0);
        double d = sqrt( SQR(n1->px) + SQR(n1->py) );
        n1->px/=d;
        n1->py/=d;
    }
    selectFixedNodes();
    //cout << g->getLaplacianMatrix() << endl;
}

/**
 * @brief LMCircularMinEdge::steps Make a step, if you don't want the edge length minimization heuristic (Experimental TUTTEHEURISTIC) then this method always return 1
 * @param n
 * @return
 */
int LMCircularMinEdge::steps(int n)
{
    if (nstepsDone%10==0)
    {
        selectFixedNodes();
    }

    for (NodesRand::const_iterator iter1=g->nodesRand.begin(); iter1!=g->nodesRand.end(); ++iter1)
    {
        LNode *n1 =(LNode*)(*iter1);
        if (n1!=fixedNodes[0] && n1!=fixedNodes[1] && n1!=fixedNodes[2])
        {
            double xj=0.0,yj=0.0;
            double deg=n1->neighborsRand.size();
            for(NeighborsRand::const_iterator iter2 = n1->neighborsRand.begin(); iter2 != n1->neighborsRand.end(); ++iter2)
            {
                LNode *n2 = (LNode*)(*iter2)->second;
                xj += n2->px;
                yj += n2->py;
            }
            n1->px = xj/(deg);
            n1->py = yj/(deg);

            double d = sqrt( SQR(xj/deg) +SQR( yj/deg) );
            n1->px /=d;
            n1->py /=d;
        }
    }
    nstepsDone++;

    if ( nstepsDone > g->nodesRand.size() )
        return 1;
    else
        return 0;

}

