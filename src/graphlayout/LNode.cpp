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

#include "LNode.h"


using namespace std;

/**
 * @ingroup GraphLayout
 * @brief LNode::LNode
 * @param id
 * @param weight
 */
LNode::LNode(int id, int weight) : Node(id, weight) ,
   px(0.0),
   py(0.0),
   pz(0.0),
   dx(0.0),
   dy(0.0),
   dz(0.0),
   oldDx(0.0),
   oldDy(0.0),
   oldDz(0.0),
   logDegree(1.0),
   labelVisible(true),
   labelWidth(2),
   labelHeight(1),
   labelX(0),
   labelY(0),
   colorRed(0),
   colorGreen(0),
   colorBlue(0)
{

}

