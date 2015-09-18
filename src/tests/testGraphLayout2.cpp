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
#include <iostream>
#include <fstream>
#include <string>

#include "Graph.h"
#include "GraphLayout.h"
#include "LNode.h"

#include "Statistic.h"
#include "Matcher.h"
#include "Common.h"

#include "LabelVisualizer.h"
#include "LMStressMajorization.h"
#include "Timer.h"
#include "BarnesHutQuadtree.h"
#include "BarnesHutOctree.h"

using namespace std;

/* METODI DI LAYOUT POSSIBILI:
MethodNothing = 0;
MethodKamadaKawai = 1;
MethodFruchtermanReingold = 2;
MethodFruchtermanReingoldProportional = 3;
MethodLinLogModel = 4;
MethodBinaryStress = 5;

MethodFruchtermanReingoldMultilevel=6
MethodFruchtermanReingoldProportionalMultilevel = 7;
MethodLinLogModelMultilevel = 8;
MethodBinaryStressMultilevel = 9;

MethodHighDimensionalEmbedder = 10;
MethodCircularLayout = 11;
MethodRandom = 12;
MethodACE = 13;
MethodCurvedEdges = 14;
MethodStressMajorization = 15;
*/
#include "DaisyFilter.h"
#include "LayoutOptions.h"

void randomizeSeed(void)
{  int stime;
    long ltime;
    ltime = time(NULL);
    stime = (unsigned) ltime / 2;
    srand(stime);
}

GraphLayout *pruneGraph(GraphLayout *g, double weightThreshold)
{
    GraphLayout *h = new GraphLayout();
    for (NodesRand::const_iterator iter1=g->nodesRand.begin(); iter1!=g->nodesRand.end(); ++iter1)
    {
        LNode *n1 = (static_cast<LNode*>(*iter1));
        h->insertNode(n1->id);
    }

    for (NodesRand::const_iterator iter1=g->nodesRand.begin(); iter1!=g->nodesRand.end(); ++iter1)
    {
        LNode *n1 = (static_cast<LNode*>(*iter1));
        for(NeighborsRand::const_iterator iter2 = n1->neighborsRand.begin(); iter2 != n1->neighborsRand.end(); ++iter2)
        {
            LNode *n2 = (LNode*)(*iter2)->second;
            Edge *e = (*iter2)->first;
            if (e->weight > weightThreshold)
            {
                h->insertEdge(n1->id,n2->id,e->weight);
            }
        }
    }
    if (h->countConnectedComponents() == 1)
        return h;
    else
        cerr << "Graph has more than 1 connected component" << endl;
}

int main(int argc, char *argv[])
{
    randomizeSeed();
    ifstream graphFile1(argv[1]);

    GraphLayout *g1 = new GraphLayout();
    g1->loadDimacs(graphFile1);

    g1->init(GraphLayout::MethodLinLogModel,2,true,false);

    for (int i=0; i<1E4;i++)
    {
        g1->steps(1);
    }

    std::string outputFile(argv[1]);
    cerr << "Writing output to " << outputFile+".dat" << endl;
    g1->writeGnuplot(outputFile,false);

    delete g1;

    return 0;
}

