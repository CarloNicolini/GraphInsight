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
#include "Timer.h"

using namespace std;

int main(int argc, char *argv[])
{
    // Test of Graph API
    GraphLayout *gl = new GraphLayout();

    gl->insertNode(1);
    gl->insertNode(2);
    gl->insertNode(3);

    gl->insertEdge(1,2,10);
    gl->insertEdge(2,3,5);
    /*
    gl->removeNode(1);
    gl->insertEdge(3,4);

    gl->removeEdge(1,2);
    gl->removeEdge(2,3);
    gl->removeEdge(3,4);

    gl->removeNode(1);
    gl->removeNode(2);
    gl->removeNode(3);
    */
    cerr << gl->getEdge(10,2) << endl;
    cerr << gl->getEdge(2,1) << endl;
    cerr << gl->getEdge(2,1) << endl;
    //gl->print();
    delete gl;

    return 0;
}
