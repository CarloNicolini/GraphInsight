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



#include "LMBinaryStressMultilevel.h"
#include "LMBinaryStress.h"
#include "Matcher.h"
#include "Common.h"
#include <vector>
using namespace std;

/**
 * @ingroup GraphLayout
 * @brief LMBinaryStressMultilevel::LMBinaryStressMultilevel Standard constructor, init member variables to default values
 */
LMBinaryStressMultilevel::LMBinaryStressMultilevel()
{  DEBUG_PRINT( "Calling LMBinaryStressMultilevel CONSTRUCTOR");
   nodesThreshold=3;
   g=NULL;
   actualGraph=NULL;
   lm2=NULL;
   goToNextLevel=false;
}

/**
 * @ingroup GraphLayout
 * @brief LMBinaryStressMultilevel::~LMBinaryStressMultilevel Ddestructor, clear all memory and uncoarsen the graph
 */
LMBinaryStressMultilevel::~LMBinaryStressMultilevel()
{  DEBUG_PRINT( "Calling LMBinaryStressMultilevel destructor");

   if (lm2!=NULL)
   {  delete lm2;
      lm2=NULL;
   }

   g->unCoarsen();
}

/**
 * * @ingroup GraphLayout
 * @brief LMBinaryStressMultilevel::init
 * @param gl The graph to work on
 * @param nDim Number of dimensions (2 or 3)
 */
void LMBinaryStressMultilevel::init(GraphLayout *gl, int nDim )
{

   GraphLayout *tmpGraph = NULL;

   tmpGraph = gl;
   g=gl;
   nDimensions = nDim;
   // Creates the hierarchy of graphs to keep in this object LMBinaryStressMultilevel

   unsigned int nComponents = g->countConnectedComponents();
   if (nComponents==1) nodesThreshold=3;
   else
      nodesThreshold = nComponents;

   while (  tmpGraph->getEdgesCount() > nodesThreshold  )
   {  coarsenedGraphs.push_back(tmpGraph);
      tmpGraph->coarsen(MATCHING_LIGHT_NODE);
      tmpGraph = (GraphLayout*)tmpGraph->coarseGraph;
   }

   coarsenedGraphs.push_back(tmpGraph);

   deeperLevel=coarsenedGraphs.size()-1;
   actualLevel = deeperLevel;

   gradientNorm=0.004/nDimensions;

   actualGraph = coarsenedGraphs[actualLevel];
   actualGraph->init(GraphLayout::MethodBinaryStress, nDimensions,true,false);
   actualGraph->initRandomCoordinates();

   lm2 = new LMBinaryStress();
   lm2->init(actualGraph,nDimensions);
   lm2->setGradientNorm(gradientNorm);

   g->g=actualGraph;
   actualLevel--;
   goToNextLevel=true;
}

/**
 * @ingroup GraphLayout
 * @brief LMBinaryStressMultilevel::steps Make a step for the layout method, automagically switch level of coarsening
 * @param nsteps (ignored)
 * @return 1 if the layout is finished, 0 otherwise
 */
int LMBinaryStressMultilevel::steps(int nsteps)
{

   if (actualLevel==-1)
   {  actualGraph = (coarsenedGraphs.back());
      return 1;
   }

   if (goToNextLevel==true)
   {  if (lm2!=NULL)
         delete lm2;
      lm2=NULL;
      lm2 = new LMBinaryStress();

      actualGraph = coarsenedGraphs.at(actualLevel);
      actualGraph->setDimensions(nDimensions);
      actualGraph->reloadNodeCoordinates(nDimensions==2 ? false: true);
      interpolatePositions(coarsenedGraphs.at(actualLevel));

      actualLevel--;
      int nstepsSuggested = 99.3*log(2.6*actualLevel + 19) - 290;
      lm2->init(actualGraph,nDimensions);
      lm2->setGradientNorm(gradientNorm);
      goToNextLevel=(lm2->steps(nsteps < nstepsSuggested ? nsteps : nstepsSuggested )==1);
      g->g = actualGraph;
      g->g->reloadNodeCoordinates(nDimensions==2 ? false: true);
      return 0;
   }
   else
   {  int nstepsSuggested = 99.3*log(2.6*actualLevel + 19) - 290;
      goToNextLevel=(lm2->steps(nsteps < nstepsSuggested ? nsteps : nstepsSuggested)==1);
      g->g = actualGraph;
      return 0;
   }
}

/**
 * @ingroup GraphLayout
 * @brief LMBinaryStressMultilevel::interpolatePositions Interpolate the positions of nodes from previous to the current coarsening level. It put the nodes in the barycenter of their neighbors
 * @param coarseGraph where to start with interpolation positions
 */
void LMBinaryStressMultilevel::interpolatePositions(GraphLayout *coarseGraph)
{
   double coarseGraphNodes = actualGraph->coarseGraph->nodes.size();
   double thisGraphNodes = actualGraph->nodes.size();
   //DEBUG_PRINT( "==> coarse graph has " << coarseGraphNodes << " thisgraph has " << thisGraphNodes);
   double sumX=0,sumY=0,sumZ=0,deg=0;
   double scale = sqrt(thisGraphNodes/coarseGraphNodes);

   // Each node is moved toward the barycenter of its neighbors iteratively
   int k=0;
   if (nDimensions==2)
   {  k=10;
      while ( --k )
      {  for(Matches::iterator iter = actualGraph->coarseMatches.begin(); iter != actualGraph->coarseMatches.end(); ++iter)
         {  LNode *n1 = (LNode*)iter->first;
            n1 -> px =  scale*((LNode*)iter->second)->px;
            n1 -> py =  scale*((LNode*)iter->second)->py;

            sumX=0,sumY=0;
            deg=0;
            for (NeighborsRand::iterator iter2 = n1->neighborsRand.begin(); iter2 != n1->neighborsRand.end(); ++iter2)
            {  sumX += ((LNode*)(*iter2)->second)->px;
               sumY += ((LNode*)(*iter2)->second)->py;
               deg++;
            }
            if (n1->neighbors.empty())
                deg=1.0;
            n1->px += sumX/deg;
            n1->py += sumY/deg;
            n1->px/=2.;
            n1->py/=2.;
         }
      }
   }
   if (nDimensions==3)
   {  k=40;
      while ( --k )
      {  for(Matches::iterator iter = actualGraph->coarseMatches.begin(); iter != actualGraph->coarseMatches.end(); ++iter)
         {  LNode *n1 = (LNode*)iter->first;
            n1 -> px =  scale*((LNode*)iter->second)->px;
            n1 -> py =  scale*((LNode*)iter->second)->py;
            n1 -> pz =  scale*((LNode*)iter->second)->pz;

            sumX=0,sumY=0,sumZ=0;
            deg=0;
            for (NeighborsRand::iterator iter2 = n1->neighborsRand.begin(); iter2 != n1->neighborsRand.end(); ++iter2)
            {  sumX += ((LNode*)(*iter2)->second)->px;
               sumY += ((LNode*)(*iter2)->second)->py;
               sumZ += ((LNode*)(*iter2)->second)->pz;
               deg++;
            }
            if (n1->neighbors.empty())
                deg=1.0;

            n1->px += sumX/deg;
            n1->py += sumY/deg;
            n1->pz += sumZ/deg;
            n1->px/=2.;
            n1->py/=2.;
            n1->pz/=2.;
         }
      }
   }
   actualGraph->reloadNodeCoordinates(true);
}

