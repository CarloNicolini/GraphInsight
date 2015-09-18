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


#ifndef LabelVisualizer_H
#define LabelVisualizer_H

#include "LNode.h"

#include <vector>
#include <iostream>
#include "Graph.h"

/**
@ingroup GraphLayout
@class LabelVisualizer
@brief LabelVisualizer is the class deputate to the fast algorithms needed for labels on-line remotion. It uses a very clever scheme of analysis based on collision graph and maximum independent set
**/
class LabelVisualizer
{
public:
   LabelVisualizer();
   LabelVisualizer(GraphLayout *g);
   void init(GraphLayout *gl);
   ~LabelVisualizer() ;

   unsigned int setVisibileLabels( NodesRand &labels, int w, int h, unsigned int maxNCollisions, char labelsBorder=5 );

protected:
   unsigned int  checkIntersectionFast( NodesRand &labels, int width, int height, unsigned int nmaxcollisions, char labelsBorder=5);
      //Returns whether two labels collide
   bool twoNodeLabelsIntersect(LNode *n1, LNode *n2, int labelsBorder=0);

   GraphLayout *g;

};

#endif  /* LabelVisualizer_H */


