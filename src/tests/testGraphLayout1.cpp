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

using namespace std;

int main(int argc, char *argv[])
{
    ifstream graphFile1(argv[1]);

    GraphLayout *g1 = new GraphLayout();
    g1->loadDimacs(graphFile1);

    cout << g1->getSparseAdjacencyMatrix().toDense() << endl;

    delete g1;

    return 0;
}

