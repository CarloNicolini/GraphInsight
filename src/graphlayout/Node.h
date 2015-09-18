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


#ifndef _NODE_H
#define _NODE_H

#include <map>
#include <vector>
#include <iostream>
#include "Entity.h"
#include "Edge.h"

#define WHITE   0
#define GRAY  1
#define BLACK   2

using namespace std;
class Node;

typedef pair<Edge *, Node *> Neighbor;
typedef map<int, Neighbor> Neighbors;
typedef vector<Neighbor *> NeighborsRand;

/**
* @ingroup GraphLayout
* @class Node
* @brief The node class has some builtin variables,
* - mark True if the node was already visited
* - id which is an unique identifier needed for fast lookup
* - index which is a linearly increasing integer to identify the node
* - component is the connected component identifier of the node
* - degree is a double which contains the node degree (sum of in-degree and out-degree)
* - weight is the weight of the node, needed in some algorithms as matching and coarsening of graph
* - distance is the stored distance of this node from another node where bfs or dijkstra algorithm started
* - color is a variable to store the visit status (needed in BellmanFord algorithm and other visit algorithm)
* - neighbors is a map containing the neighbors nodes of this node
* - neighborsrand is a random access vector containing the neighbors nodes of this node
**/
class Node
{
public:
   Node();
   Node(const Node& orig);
   Node(int id, double weight);
   virtual ~Node();

   bool mark;
   int id;
   int index;
   int component;
   double degree;
   double weight;
   // Variables needed for graph visit algorithms (BFS, DFS, Johnson, Bellman-Ford, Dijkstra)
   // DO NOT DELETE!
   double distance; //this variables represents the distance of a node from other nodes
   int color;               // this variable is an indicator variable, can be WHITE, GRAY or BLACK

   Neighbors neighbors;
   NeighborsRand neighborsRand;

   Entity *ptrEntity;
};

#endif  /* _NODE_H */


