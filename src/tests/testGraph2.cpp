/****************************************************************************
**
** Copyright (C) 2010 Michele Dallachiesa (michele.dallachiesa@gmail.com)
** Copyright (C) 2010 Carlo Nicolini (nicolini.carlo@gmail.com)
** All rights reserved.
**
** Warning: This program is protected by copyright law and international
** treaties. Unauthorized reproduction and distribution of this program,
** or any portion of it, may result in severe civil and criminal penalties,
** and will be persecuted to the maximum extent possible under the law.
**
****************************************************************************/

#include "Graph.h"
#include "GraphLayout.h"
#include "Matcher.h"
#include "Node.h"
#include "Timer.h"

#include <vector>
#include <iostream>
#include <fstream>
#include "LabelVisualizer.h"
using namespace std;

int main(int argc, char*argv[])
{
    GraphLayout *g = new GraphLayout();

    g->insertNode(1);
    g->insertNode(20);
    g->insertNode(3);

    g->insertEdge(1,20,1);
    g->insertEdge(1,3,1);
    g->insertEdge(20,3,-1);


    for (int i=0; i<3;i++)
        cout << g->nodesRand[i]->index << endl;

    g->init(GraphLayout::MethodKamadaKawai,2,1,1);
    g->steps(1);

    cout << g->getShortestPathMatrix() << endl;

    delete g;

    return 0;

}

