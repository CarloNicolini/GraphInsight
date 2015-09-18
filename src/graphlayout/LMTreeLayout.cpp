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


#include "LMTreeLayout.h"
#include "GraphLayout.h"
#include <stack>
#include <cmath>
#include <iostream>
#include <Eigen/Core>

#include "Common.h"

/**
 * @ingroup GraphLayout
 * @brief LMTreeLayout::LMTreeLayout Standard constructor, does nothing
 */
LMTreeLayout::LMTreeLayout() : g(NULL), gravity(0.0), nstepsDone(0), nDimensions(3)
{

}

/**
 * @brief LMTreeLayout::~LMTreeLayout Standard destructor, does nothing
 */
LMTreeLayout::~LMTreeLayout()
{
}

/**
 * @brief LMTreeLayout::init Initialize the layout method, actually it lay out the graph on circular coordinates, if you don't want an edge length reduction heuristic
 * @param gl
 * @param _nDimensions
 */
void LMTreeLayout::init(GraphLayout *gl, int _nDimensions)
{  g=gl;
    nDimensions = _nDimensions;
    if ( g->nodesRand.back()->component == 0)
        g->countConnectedComponents();

    g->randomize();
    double radius=1.0;
    unsigned int n=g->nodes.size();
    double maxDegree=0;

    LNode *n1 = NULL;

    for (NodesRand::iterator iter1=g->nodesRand.begin(); iter1!=g->nodesRand.end(); ++iter1)
    {  n1=(LNode*)(*iter1);
        if ( n1->degree > maxDegree )
            maxDegree=n1->degree;
    }

    for (NodesRand::iterator iter1=g->nodesRand.begin(); iter1!=g->nodesRand.end(); ++iter1)
    {  n1=(LNode*)(*iter1);
        radius = 1 - log( (n1->degree +1.)/(maxDegree+1.) );
        n1->px = radius*cos(2*M_PI*(double)n1->index/(double)n);
        n1->py = radius*sin(2*M_PI*(double)n1->index/(double)n);
        nDimensions == 2 ? (n1->pz = 0 ) :( n1->pz = ((double) (n1->component+1)));
    }
}


/**
 * @brief LMTreeLayout::steps Make a step, if you don't want the edge length minimization heuristic (Experimental TUTTEHEURISTIC) then this method always return 1
 * @param n
 * @return
 */
int LMTreeLayout::steps(int n)
{
    //
    /*
        1: Initialise an array order [n], and a stack, S.
        2: Get the vertex with the smallest degree from the given graph, and push it into S.
        3: while (S is not empty) do
        4: Pop a vertex v, from S
        5: if (v is not in order ) then
        6:     Append the vertex v into order.
        7:     Get all adjacent vertices of v; and push those vertices, which are not in order
               into S with descending degree towards the top of the stack (the vertex with
               smallest degree is at top of S).
        8: end if
        9: end while
    */
    vector<Node*> order;
    order.reserve(g->statsNodesCount);
    // Avoid cases when the graph has only 1 or 0 nodes
    if (g->statsNodesCount <2 )
    {
        DEBUG_PRINT("Exiting because the graph has <2 nodes");
        return 1;
    }

    unsigned int minDegree=std::numeric_limits<unsigned int>::max();
    Node* l=NULL;
    for (NodesRand::iterator iter1=g->nodesRand.begin(); iter1!=g->nodesRand.end(); ++iter1)
    {
        if ((*iter1)->neighborsRand.size() < minDegree )
        {
            l=(*iter1);
            minDegree=(*iter1)->neighborsRand.size();
        }
    }

    std::stack<Node*> S;
    S.push(l);
    while (!S.empty())
    {
        Node *v = S.top();
        S.pop();
        // Find if the node v is not in "order" vector
        if ( std::find(order.begin(), order.end(), v) == order.end() )
        {
            order.push_back(v);
            std::vector<Node*> tmp;
            for(NeighborsRand::iterator iter2 = v->neighborsRand.begin(); iter2 != v->neighborsRand.end(); ++iter2)
            {
                Node *k = (*iter2)->second;
                // Find if the node k is not in "order" vector
                if ( std::find(order.begin(), order.end(), k) == order.end() )
                    tmp.push_back(k);
            }
            std::sort(tmp.begin(),tmp.end(),sortByDegree);
            for (NodesRand::iterator iter2 = tmp.begin();iter2!=tmp.end();++iter2)
                S.push(*iter2);
        }
    }

    // At the end the "order" vector contains a node ordering such that the crossing are minimized
    g->bfs(l);
    for (NodesRand::iterator iter1=order.begin(); iter1!=order.end(); ++iter1)
    {

    }
    return 1;
}

