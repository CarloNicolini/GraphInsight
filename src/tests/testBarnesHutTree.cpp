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

#include "Timer.h"
#include "BarnesHutQuadtree.h"

using namespace std;

void randomizeSeed(void)
{   int stime;
    long ltime;
    ltime = time(NULL);
    stime = (unsigned) ltime / 2;
    srand(stime);
}

int main(int argc, char *argv[])
{
    //randomizeSeed();

    ifstream is;
    is.open(argv[1]);
    //is.open("../graph/data/Grid20x20.dimacs");
    GraphLayout *g = new GraphLayout();
    g->loadDimacs(is);

    int method = atoi(argv[2]);
    int nDimensions = 2;//atoi(argv[3]);
    
    g->init(method, nDimensions, true, false);

    for (int i=0; i<200; i++)
    {
        cerr << i << endl;
         g->steps(1);
    }

    ofstream prova("nodes.dat");
    double totdeg=0;
    for (NodesRand::iterator iter = g->nodesRand.begin();iter!=g->nodesRand.end();++iter)
    {
        prova << static_cast<LNode*>(*iter)->px  << " " << static_cast<LNode*>(*iter)->py << endl;
    }
/*
    BarnesHutQuadtree q(g);
    q.computeMassDistribution();
    q.writeNode(0,-1);
*/
    g->writeGnuplot("prova",false);

    delete g;
    is.close();

    return 0;
}

