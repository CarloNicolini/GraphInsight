/****************************************************************************
**
** Copyright (C) 2012 Carlo Nicolini (nicolini.carlo@gmail.com)
** All rights reserved.
**
** Warning: This program is protected by copyright law and international
** treaties. Unauthorized reproduction and distribution of this program,
** or any portion of it, may result in severe civil and criminal penalties,
** and will be persecuted to the maximum extent possible under the law.
**
****************************************************************************/

#include "DisjointSet.h"
#include <iostream>
using namespace std;

/**
  @ingroup GraphLayout
  @brief Initialize the disjoint set data structure (also called union-find) with dimension N
  @param N Dimension of the data structure
**/
DisjointSet::DisjointSet(int N)
{  // Initialize component id array.
    count = N;
    for (int i = 1; i <= N; i++)
        id[i] = i;
}

/**
  @ingroup GraphLayout
  @brief Initialize the disjoint set data structure (also called union-find) with a graph as initialization method
  @param g The pointer to the graph needed to inizialize the structure using ids as identifier of nodes in the union-find
**/

DisjointSet::DisjointSet(Graph *g)
{  // Initialize component id array.
    count = g->statsNodesCount;
    for (NodesRand::const_iterator iter=g->nodesRand.begin(); iter!=g->nodesRand.end();++iter)
    {
        int nodeId = (*iter)->id;
        id[nodeId] = nodeId;
    }
}

/**
  @ingroup GraphLayout
  @brief True if two nodes are reachable in the data structure
  @param p node to start from
  @param q node to reach to
  @return True if the two nodes are connected
**/
bool DisjointSet::connected(int p, int q)
{
    return find(p) == find(q);
}

/**
@ingroup GraphLayout
@param p The node id to search
@return The node with given id p
**/
int DisjointSet::find(int p)
{
    return id[p];
}

/**
@ingroup GraphLayout
@brief Merge two disconnected nodes in the UF data structure
@param p The node p to merge
@param q The other node to merge
**/
void DisjointSet::merge(int p, int q)
{
    // Put p and q into the same component.
    int pID = find(p);
    int qID = find(q);
    // Nothing to do if p and q are already
    //in the same component.
    if (pID == qID)
        return;
    // Rename p’s component to q’s name.
    int size = (int)id.size();
    for (int i = 0; i < size; i++)
    {
        if (id[i] == pID)
            id[i] = qID;
    }
    count--;
}
