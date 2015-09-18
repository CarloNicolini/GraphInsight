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



#ifndef _EDGE_H
#define _EDGE_H

#include <iostream>
using namespace std;
class Node;
/**
@ingroup GraphLayout
@class Edge
@brief Implementation of a graph edge, variables needed are weight of the edge and mark if the edge has already been visited
**/
class Edge
{
public:

   Edge();
   Edge(double w );
   Edge(const Edge& orig);
   ~Edge();
   double weight;
   bool mark;
   //Node *sourceNode,*targetNode;
   // no need to save the boolean "variable" direction yet
   // bool direction;
private:

};

#endif  /* _EDGE_H */


