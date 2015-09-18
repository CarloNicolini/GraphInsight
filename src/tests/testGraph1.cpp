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

#include "GraphLayout.h"
#include "Matcher.h"
#include "Node.h"
#include "Timer.h"

#include <vector>
#include <iostream>
#include <fstream>

using namespace std;


int main(int argc, char*argv[])
{
    srand(time(0));
    ifstream is;
    is.open(argv[1]);
    //is.open("../graph/data/Grid20x20.dimacs");
    GraphLayout *g = new GraphLayout();
    g->loadDimacs(is);
    cerr << "graph loaded" << endl;
    Timer timer;
    timer.start();
     g->markMaximalIndependentSetSequential();
    cout << timer.getElapsedTimeInMilliSec() << endl;
    cout << "MARK MAXIMAL INDEPENDENT SET VERTICES" << endl;
    for (NodesRand::iterator iter = g->nodesRand.begin(); iter!=g->nodesRand.end(); ++iter)
    {
        Node *n = (*iter);
        if ( n->mark )  //is in the MIS
            cout << n->id << endl;
    }

   cout << "GET MAXIMAL INDEPENDENT SET VERTICES " << endl;
    std::vector<int> mis = g->getMaximalIndependentSetSequential();
   for (std::vector<int>::iterator iter = mis.begin(); iter!=mis.end(); ++iter)
   {
    cout << (*iter) << endl;
   }
   cout << "MIS END" << endl;


    delete g;

    return 0;

}

