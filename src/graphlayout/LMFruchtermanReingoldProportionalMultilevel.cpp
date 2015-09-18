/****************************************************************************
**
** Copyright (C) 2010 Carlo Nicolini (nicolini.carlo@gmail.com)
** Copyright (C) 2010 Michele Dallachiesa (michele.dallachiesa@gmail.com)
** All rights reserved.
**
** Warning: This program is protected by copyright law and international
** treaties. Unauthorized reproduction and distribution of this program,
** or any portion of it, may result in severe civil and criminal penalties,
** and will be persecuted to the maximum extent possible under the law.
**
****************************************************************************/



#include "LMFruchtermanReingoldProportionalMultilevel.h"
#include "LMFruchtermanReingold.h"
#include "Matcher.h"
#include <vector>
#include <cstdio>
#include "Common.h"

using namespace std;

/**
* @ingroup GraphLayout
 * @brief LMFruchtermanReingoldProportionalMultilevel::LMFruchtermanReingoldProportionalMultilevel Standard constructor
 */
LMFruchtermanReingoldProportionalMultilevel::LMFruchtermanReingoldProportionalMultilevel() : coarseningLevel(0),nDimensions(3), gradientNorm(1E-4)
{
    g=NULL;
    lm2=NULL;
    DEBUG_PRINT("LMFruchtermanReingoldProportionalMultilevel");
}

/**
 * @ingroup GraphLayout
 * @brief LMFruchtermanReingoldProportionalMultilevel::~LMFruchtermanReingoldProportionalMultilevel Destructor
 */
LMFruchtermanReingoldProportionalMultilevel::~LMFruchtermanReingoldProportionalMultilevel()
{
    if (lm2!=NULL)
    {  delete lm2;
        lm2=NULL;
    }
    g->unCoarsen();
    DEBUG_PRINT("LMFruchtermanReingoldProportionalMultilevel");
}

/**
 * @brief LMFruchtermanReingoldProportionalMultilevel::init Init the layout method
 * @param gl The graph to lay out
 * @param nDim Number of dimensions of the layout
 */
void LMFruchtermanReingoldProportionalMultilevel::init(GraphLayout *gl, int nDim )
{
    g=gl;
    // Set the original graph nodes to random positions, VERY important!
    for (NodesRand::const_iterator iter1=g->nodesRand.begin(); iter1!=g->nodesRand.end(); ++iter1)
    {
        LNode *n1 = (static_cast<LNode*>(*iter1));
        n1->px = 0.1*(2*rand()/(double)RAND_MAX)-0.1;
        n1->py =  0.1*(2*rand()/(double)RAND_MAX)-0.1;
        n1->pz =  0.1*(2*rand()/(double)RAND_MAX)-0.1;
    }
    g->g=g;

    nDimensions = nDim;
    gradientNorm=1E-5;

    coarsenedGraphs.push_back(gl);
    // In search of a coarsening rule
    coarseningLevel=0;
    try
    {
        while ( true )
        {
            GraphLayout *coarseGraph = static_cast<GraphLayout*>(coarsenedGraphs.back()->coarsen(MATCHING_LIGHT_NODE));
            bool nodesRule = coarseGraph->statsNodesCount != coarsenedGraphs.back()->statsNodesCount;
            bool nodesPercentRule = double(coarseGraph->statsNodesCount) < double((coarsenedGraphs.back()->statsNodesCount))*0.9;
            bool minNodesRule = double(coarseGraph->statsNodesCount) > 2*coarseGraph->countConnectedComponents();
            bool maxLevelsRule = coarsenedGraphs.size() < 100;
            bool edgesRule = (coarseGraph->statsEdgesCount) >= 1;
            // max allowed memory is 3 Giga for coarsening
            size_t memoryFootPrint=0;
            for (unsigned int i=0; i<coarsenedGraphs.size(); i++)
                memoryFootPrint+=coarsenedGraphs.at(i)->getMemoryFootprintInBytes();

            bool maxMemoryRule = memoryFootPrint < 3E9; //3 Gigabyte
            //cerr << "Level: " << coarseningLevel << "(V,E) = (" << coarsenedGraphs.back()->statsNodesCount << ", "  << coarsenedGraphs.back()->statsEdgesCount << ")" << endl;

            if ( maxMemoryRule && maxLevelsRule && nodesRule && nodesPercentRule && edgesRule && minNodesRule)
            {
                // It must randomize the nodes of the coarse graph!!!
                for (NodesRand::const_iterator iter1=coarseGraph->nodesRand.begin(); iter1!=coarseGraph->nodesRand.end(); ++iter1)
                {
                    LNode *n1 = static_cast<LNode*>(*iter1);
                    n1->px =  0.1*(2*rand()/(double)RAND_MAX)-0.1;
                    n1->py =  0.1*(2*rand()/(double)RAND_MAX)-0.1;
                    n1->pz =  0.1*(2*rand()/(double)RAND_MAX)-0.1;
                }
                coarsenedGraphs.push_back(coarseGraph);
            }
            else
            {
                //cerr << "Coarsening finished because: " << "nodesRule=" << nodesRule << " nodesPercentRule=" << nodesPercentRule << " minNodesRule=" << minNodesRule << " maxLevelsRule=" << maxLevelsRule << " edgesRule=" << edgesRule << " maxMemoryRule=" << maxMemoryRule << endl;
            break;
            }

            coarseningLevel++;
        }
        //coarseningLevel=coarsenedGraphs.size()-1;
       // coarsenedGraphs.at(coarseningLevel)->init(GraphLayout::MethodRandom, nDimensions,true,true);
        lm2 = new LMFruchtermanReingoldProportional();
        lm2->init(coarsenedGraphs.at(coarseningLevel),nDimensions);
        lm2->setGradientNorm(gradientNorm);
    }
    catch(std::exception &ex)
    {
        cerr << ex.what() << " in LMFruchtermanReingoldProportionalMultilevel::init()" << endl;
    }
    g->g = coarsenedGraphs.at(coarseningLevel);
}

/**
 * @brief LMFruchtermanReingoldProportionalMultilevel::steps Make one step of the layout algorithm
 * @param nsteps Number of steps (ignored)
 * @return 1 if the layout method has finished,0 otherwise
 */
int LMFruchtermanReingoldProportionalMultilevel::steps(int nsteps)
{
    g->g = coarsenedGraphs.at(coarseningLevel);
    lm2->steps(1);

    bool proceed=  (lm2->optimality < this->gradientNorm/(coarseningLevel+1) );
    if ( proceed  && (coarseningLevel==0) )
        return 1;
    else if  ( proceed )
    {
        //cerr << "Coarsening level= " << coarseningLevel << endl;
        coarseningLevel--;
        interpolatePositions();

        delete lm2;

        lm2 = new LMFruchtermanReingoldProportional();
        lm2->init(coarsenedGraphs.at(coarseningLevel),nDimensions);
        lm2->setGradientNorm(gradientNorm);

    }

    return 0;
}

/**
 * @ingroup GraphLayout
 * @brief LMFruchtermanReingoldProportionalMultilevel::interpolatePositions Interpolate the positions of nodes from previous to the current coarsening level. It put the nodes in the barycenter of their neighbors
 */
void LMFruchtermanReingoldProportionalMultilevel::interpolatePositions()
{
    GraphLayout *actualGraph = coarsenedGraphs.at(coarseningLevel);
    GraphLayout* coarseGraph = static_cast<GraphLayout*>(coarsenedGraphs.at(coarseningLevel)->coarseGraph);
    DEBUG_PRINT( "Interpolate with graphs " << actualGraph->statsNodesCount << ", " << coarseGraph->statsNodesCount << endl);

    // Imposta le posizioni del grafo Fine sulle stesse dei grafi Coarse
    double coarseGraphNodes = actualGraph->statsNodesCount;
    double thisGraphNodes = coarseGraph->statsNodesCount;

    double scale = sqrt(thisGraphNodes/coarseGraphNodes);
    for (int iteration=0; iteration<10; ++iteration)
    {
        for(Matches::iterator iter = actualGraph->coarseMatches.begin(); iter != actualGraph->coarseMatches.end(); ++iter)
        {
            LNode *n1 = static_cast<LNode*>(iter->first);

            n1 -> px =  scale*(static_cast<LNode*>(iter->second))->px ;
            n1 -> py =  scale*(static_cast<LNode*>(iter->second))->py ;
            n1 -> pz =  scale*(static_cast<LNode*>(iter->second))->pz  ;

            double sumX=0,sumY=0,sumZ=0,deg=n1->degree;
            for (NeighborsRand::iterator iter2 = n1->neighborsRand.begin(); iter2 != n1->neighborsRand.end(); ++iter2)
            {
                LNode *n2 = (static_cast<LNode*>((*iter2)->second));
                sumX += n2->px;
                sumY += n2->py;
                sumZ += n2->pz;
            }

            if (deg>0)
            {
                n1->px = 0.5*( n1->px + sumX/deg);
                n1->py = 0.5*( n1->py + sumY/deg);
                n1->pz = 0.5*( n1->pz + sumZ/deg);
            }
        }
    }

}

