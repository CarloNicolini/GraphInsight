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


#include "LayoutMethod.h"
#include "LMLinLogModel.h"
#include "LNode.h"
#include "GraphLayout.h"
#include "Common.h"
#include "BarnesHutTree.h"
#include "BarnesHutQuadtree.h"
#include "BarnesHutOctree.h"
#include "ForceDirectedMethod.h"
#include "Timer.h"
using namespace std;

/**
 * @ ingroup GraphLayout
 * @brief LMLinLogModel::LMLinLogModel Default constructor, set speed=1, gradientNorm=1E-6, totSteps=0, repStrength=50, attrStrength=20
 */
LMLinLogModel::LMLinLogModel() : g(NULL), gravity(0.0), nDim(3), gradientNorm(1E-6),speed(1), repStrength(50),attrStrenght(20),optimality(numeric_limits<double>::max()), oldOptimality(0)
{
}

/**
 * @ ingroup GraphLayout
 * @brief LMLinLogModel::~LMLinLogModel Destructor, does nothing
 */
LMLinLogModel::~LMLinLogModel()
{

}

/**
 * @brief LMLinLogModel::init Init the layout method, setting variables to their default values
 * @param gl The graph to layout
 * @param nDimensions Number of dimensions (2 or 3)
 */
void LMLinLogModel::init(GraphLayout *gl, int nDimensions)
{
    g=gl;
    nDim = nDimensions;

    gradientNorm=1E-6;
    speed=1;
    totSteps=0;
    repStrength=50;
    attrStrenght=20;
    gravity= ( g->countConnectedComponents()==1 ) ? 0 : 2*log( (double)g->countConnectedComponents() ) ;
    optimality=numeric_limits<double>::max();
}

/**
 * @ ingroup GraphLayout
 * @brief LMLinLogModel::steps Make one step of the layout method
 * @param nsteps Number of steps (ignored)
 * @return 1 if finished, 0 otherwise
 */
int LMLinLogModel::steps(int nsteps)
{
    //Timer timer; timer.start();
    oldOptimality=optimality;
    optimality=0.0;

    // Setup the steps, zero the displacements
    ForceDirectedMethod::InitializeStep(g,nDim);
    // Repulsive Forces
    if ( g->statsNodesCount < 1000 )
    {  for (NodesRand::const_iterator iter1=g->nodesRand.begin(); iter1!=g->nodesRand.end(); ++iter1)
        {  LNode *n1 = (static_cast<LNode*>(*iter1));
            // Repulsive forces
            for (NodesRand::const_iterator iter2=g->nodesRand.begin(); iter2!=g->nodesRand.end(); ++iter2)
            {
                LNode *n2 = (static_cast<LNode*>(*iter2));
                ForceDirectedMethod::LinLogRepulsion(n1,n2,repStrength,nDim);
            }
        }
    }
    else
    {  // Else use Barnes Hut Schema
        BarnesHutTree* tree;
        if (nDim==2)
            tree = new BarnesHutQuadtree(g->g);
        else if (nDim==3)
            tree = new BarnesHutOctree(g->g);

#pragma omp parallel for schedule(static)
        for ( int i=0; i< g->statsNodesCount; i++)
        {
            LNode* n1 = static_cast<LNode*>(g->nodesRand[i]);
            if (nDim==2)
            {
                Vector2d f = (static_cast<BarnesHutQuadtree*>(tree))->calculateForceLinLog(n1,repStrength);
                n1->dx+=f.x();
                n1->dy+=f.y();
            }
            else if (nDim==3)
            {
                Vector3d f = (static_cast<BarnesHutOctree*>(tree))->calculateForceLinLog(n1,repStrength);
                n1->dx+=f.x();
                n1->dy+=f.y();
                n1->dz+=f.z();
            }
        }
        // Must cast back the tree to Quad or Octree in order to call the right destructor method!
        if (nDim==2)
            delete static_cast<BarnesHutQuadtree*>(tree);
        else if (nDim==3)
            delete static_cast<BarnesHutOctree*>(tree);
    }

    // Attraction between edges
    for (NodesRand::const_iterator iter1=g->nodesRand.begin(); iter1!=g->nodesRand.end(); ++iter1)
    {
        LNode *n1 = (static_cast<LNode*>(*iter1));
        for(NeighborsRand::const_iterator iter2 = n1->neighborsRand.begin(); iter2 != n1->neighborsRand.end(); ++iter2)
        {
            LNode *n2 = static_cast<LNode*>((*iter2)->second);
            //Edge *e = (*iter2)->first;
            ForceDirectedMethod::LinLogAttraction(n1,n2,attrStrenght,nDim);
        }
    }

    optimality = ForceDirectedMethod::ApplyStep(g,gravity,speed,nDim);
    ++totSteps;

    if (totSteps>g->statsNodesCount && (optimality < gradientNorm || (abs(optimality - oldOptimality) < 1E-9)) )
        return 1;

    else
        return 0;
}


