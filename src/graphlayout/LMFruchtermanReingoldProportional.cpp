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
#include "BarnesHutQuadtree.h"
#include "BarnesHutOctree.h"
#include "LMFruchtermanReingoldProportional.h"
#include "LNode.h"
#include "GraphLayout.h"
#include "Common.h"
#include "Timer.h"

#include "ForceDirectedMethod.h"

using namespace std;

/**
 * @brief LMFruchtermanReingoldProportional::LMFruchtermanReingoldProportional Standard constructor, set member variables to default
 */
LMFruchtermanReingoldProportional::LMFruchtermanReingoldProportional() : g(NULL),gradientNorm(1E-6),optimality(1E9),oldOptimality(0.0), speed(1),preventNodeOverlap(false),
    nDim(3), nnodes(0),coarseningLevel(0),gravity(0.0)
{
    totSteps=0;
    preventNodeOverlap=false;   // SPERIMENTALE, non repelle veramente la dimensione dei nodi come mostrata a schermo ma il log(degree)
    DEBUG_PRINT("LMFruchtermanReingoldProportional");
}

/**
 * @brief LMFruchtermanReingoldProportional::~LMFruchtermanReingoldProportional Standard destructor, does nothing
 */
LMFruchtermanReingoldProportional::~LMFruchtermanReingoldProportional()
{
    DEBUG_PRINT("LMFruchtermanReingoldProportional");
}

/**
 * @ingroup GraphLayout
 * @brief LMFruchtermanReingoldProportional::init Set variables to their default value, prepares for the step method
 * @param gl The graph to work on
 * @param nDimensions Number of dimensions of the layout (2 or 3)
 */
void LMFruchtermanReingoldProportional::init(GraphLayout *gl, int nDimensions)
{
    g=gl;
    nDim = nDimensions;
    gradientNorm=1E-6;
    optimality=1e9;
    oldOptimality=0;
    totSteps=0;
    speed=1;
    gravity= ( g->countConnectedComponents()==1 ) ? 0 : 2*log( (double)g->countConnectedComponents() ) ;

}

/**
 * @ingroup GraphLayout
 * @brief LMFruchtermanReingoldProportional::steps
 * @param nsteps
 * @return
 */
int LMFruchtermanReingoldProportional::steps(int nsteps)
{
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
                if (!preventNodeOverlap)
                    ForceDirectedMethod::FruchtermanReingoldProportionalRepulsion(n1,n2,nDim);
                else
                    ForceDirectedMethod::FruchtermanReingoldProportionalRepulsionNoOverlap(n1,n2,nDim);
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
                Vector2d f = (static_cast<BarnesHutQuadtree*>(tree))->calculateForceFRProp(n1);
                n1->dx+=f.x();
                n1->dy+=f.y();
            }
            else if (nDim==3)
            {
                Vector3d f = (static_cast<BarnesHutOctree*>(tree))->calculateForceFRProp(n1);
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
            LNode *n2 = (LNode*)(*iter2)->second;
            Edge *e = (*iter2)->first;
            if (!preventNodeOverlap)
                ForceDirectedMethod::FruchtermanReingoldProportionalAttraction(n1,n2,e,nDim);
            else
                ForceDirectedMethod::FruchtermanReingoldProportionalAttractionNoOverlap(n1,n2,e,nDim);
        }
    }

    optimality = ForceDirectedMethod::ApplyStep(g,gravity,speed,nDim);

    ++totSteps;

    if (totSteps>g->statsNodesCount && (optimality < gradientNorm || (abs(optimality - oldOptimality) < 1E-9)) )
        return 1;
    else
        return 0;
}


