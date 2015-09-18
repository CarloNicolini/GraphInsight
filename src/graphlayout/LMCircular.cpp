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


#include "LMCircular.h"
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
 * @brief LMCircular::LMCircular Standard constructor, does nothing
 */
LMCircular::LMCircular() : g(NULL), gravity(0.0), nstepsDone(0), nDimensions(3)
{

}

/**
 * @brief LMCircular::~LMCircular Standard destructor, does nothing
 */
LMCircular::~LMCircular()
{
}

/**
 * @brief LMCircular::init Initialize the layout method, actually it lay out the graph on circular coordinates, if you don't want an edge length reduction heuristic
 * @param gl
 * @param _nDimensions
 */
void LMCircular::init(GraphLayout *gl, int _nDimensions)
{
    g=gl;
    nDimensions = _nDimensions;
    g->countConnectedComponents();

    g->randomize();
    double radius=1.0;
    unsigned int n=g->nodes.size();
    double maxDegree=0;

    LNode *n1 = NULL;

    for (NodesRand::const_iterator iter1=g->nodesRand.begin(); iter1!=g->nodesRand.end(); ++iter1)
    {  n1=static_cast<LNode*>(*iter1);
        if ( n1->degree > maxDegree )
            maxDegree=n1->degree;
    }

    for (NodesRand::const_iterator iter1=g->nodesRand.begin(); iter1!=g->nodesRand.end(); ++iter1)
    {  n1=static_cast<LNode*>(*iter1);
        radius = 1 - log( (n1->degree +1.)/(maxDegree+1.) );
        n1->px = radius*cos(2*M_PI*(double)n1->index/(double)n);
        n1->py = radius*sin(2*M_PI*(double)n1->index/(double)n);
        nDimensions == 2 ? (n1->pz = 0 ) :( n1->pz = ((double) (n1->component+1)));
    }
}


/**
 * @brief LMCircular::steps Make a step, if you don't want the edge length minimization heuristic (Experimental TUTTEHEURISTIC) then this method always return 1
 * @param n
 * @return
 */
int LMCircular::steps(int n)
{
    return 1;
}

