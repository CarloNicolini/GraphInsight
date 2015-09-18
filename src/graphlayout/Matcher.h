/****************************************************************************
**
** Copyright (C) 2010 Michele Dallachiesa (michele.dallachiesa@gmail.com)
** All rights reserved.
**
** Warning: This program is protected by copyright law and international
** treaties. Unauthorized reproduction and distribution of this program,
** or any portion of it, may result in severe civil and criminal penalties,
** and will be persecuted to the maximum extent possible under the law.
**
****************************************************************************/


#ifndef _MATCHER_H
#define _MATCHER_H

#include <iostream>
using namespace std;

#include "Node.h"
#include "Graph.h"

#define MATCHING_RANDOM 0
#define MATCHING_HEAVY_EDGE 1
#define MATCHING_LIGHT_EDGE 2
#define MATCHING_HEAVY_CLIQUE 3
#define MATCHING_LIGHT_NODE 4
#define MATCHING_HEAVY_CONNECTED 5
#define MATCHING_LIGHT_CONNECTED 6

/**
*  @ingroup GraphLayout
*  @class Matcher
*  @brief Matcher is a class needed to create matching of nodes with a particular method, the methods can be
* - MATCHING_RANDOM Matches two random nodes
* - MATCHING_HEAVY_EDGE Matches the nodes belonging to the heavier edge
* - MATCHING_LIGHT_EDGE  Matches the nodes belonging to the lighter edge
* - MATCHING_HEAVY_CLIQUE Matches the node belonging to the heavier clique
* - MATCHING_LIGHT_NODE  Matches the lightest node (the best method so far)
* - MATCHING_HEAVY_CONNECTED Matches the heavier of the connected nodes
* - MATCHING_LIGHT_CONNECTED  Matches the ligher of the connected nodes
* This class is of fundamental importance in Graph coarsening methods.
**/
class Matcher
{
public:
   Matcher();
   Matcher(Graph *graph, int matchingType);
   Matcher(const Matcher& orig);
   Node *find(Node *node);
   virtual ~Matcher();

   Graph *graph;
   int matchingType;



private:
   Node *findRandom(Node *node);
   Node *findLightNode(Node *node);
   Node *findHeavyEdge(Node *node);
   Node *findLightEdge(Node *node);
   Node *findHeavyConnected(Node *node);
   Node *findLightConnected(Node *node);
};

#endif  /* _MATCHER_H */


