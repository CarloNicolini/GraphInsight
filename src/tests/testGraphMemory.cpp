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

int main(int argc, char *argv[])
{
    ifstream is;
    is.open(argv[1]);
    Node n;
    LNode ln;
    Edge e;
    Graph g;
    GraphLayout gl;
    gl.loadDimacs(is);

    int nodesThreshold=3;
    unsigned int nComponents = gl.countConnectedComponents();
    cerr << "nComponents= " << nComponents << endl;

    if (nComponents==1)
    	nodesThreshold=3;
    else
        nodesThreshold = nComponents*2;
	cerr << "nodesThreshold= " << nodesThreshold << endl;
    vector <GraphLayout *> coarsenedGraphs;
    GraphLayout *tmpGraph = &gl;

    cerr << "Start coarsening" << endl;
    cout << "#Nodes memory(GB)" << endl;
    while (  tmpGraph->getEdgesCount() > nodesThreshold  )
    {   coarsenedGraphs.push_back(tmpGraph);
        tmpGraph->coarsen(MATCHING_LIGHT_NODE);
        tmpGraph = (GraphLayout*)tmpGraph->coarseGraph;
    	float totalsize=0;
    	for (int i=0; i<coarsenedGraphs.size(); i++)
    	{
    		totalsize+=(float)sizeof(*coarsenedGraphs.at(i)) ;
    		totalsize+=(float)coarsenedGraphs.at(i)->nodesRand.size()*sizeof(ln);
    		totalsize+=(float)coarsenedGraphs.at(i)->nodesRand.size()*sizeof(n);
    		totalsize+=(float)coarsenedGraphs.at(i)->nodesRand.size()*sizeof(int);
    		totalsize+=(float)coarsenedGraphs.at(i)->coarseMatches.size()*sizeof(ln);
    		totalsize+=(float)coarsenedGraphs.at(i)->coarseMatches.size()*sizeof(std::pair<Node*,Node*>);
    		totalsize+=(float)coarsenedGraphs.at(i)->nodes.size()*sizeof(std::pair<int*,LNode*>);
    		
    		totalsize+=(float)coarsenedGraphs.at(i)->nodes.size()*sizeof(int)*2;
    		totalsize+=(float)coarsenedGraphs.at(i)->getEdgesCount()*sizeof(e);
    		totalsize+=(float)coarsenedGraphs.at(i)->getEdgesCount()*sizeof(int)*2;
    	}
    	//cout << tmpGraph->nodesRand.size() << " " << totalsize/(1024.0*1024*1024) << " GB" << endl;
    	
        //cin.ignore(1E6,'\n');
    }
    
    cerr << "end coarsening" << endl;

    cerr << "Sizeof Node " << sizeof(n) << endl;
    cerr << "Sizeof LNode " << sizeof(ln) << endl;
    cerr << "Sizeof Edge " << sizeof(e) << endl;
    cerr << "Sizeof Graph " << sizeof(g) << endl;
    cerr << "Sizeof GraphLayout " << sizeof(gl) << endl;

    //while ( true );
    
    return 0;
}
