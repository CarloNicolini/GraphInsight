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

#ifndef _LNODE_H
#define _LNODE_H

#include <vector>
#include <Eigen/Core>
#include "Node.h"

/**
@ingroup GraphLayout
@class LNode
@brief LNode extends Node class and adds coordinates and velocity to nodes of a graph
**/
class LNode : public Node
{
public:
   LNode(int id = 0, int weight = 1);

   // LNode position on x,y,z axis
   double px;
   double py;
   double pz;
   // LNode displacements
   double dx;
   double dy;
   double dz;
   double oldDx;
   double oldDy;
   double oldDz;//,freeze;

   double logDegree;
   bool labelVisible;
   int labelWidth,labelHeight,labelX,labelY;
   int colorRed,colorGreen,colorBlue;
};

#endif

