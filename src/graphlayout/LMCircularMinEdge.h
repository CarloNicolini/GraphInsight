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


#ifndef LMCircularMinEdge_H
#define LMCircularMinEdge_H

#include "LayoutMethod.h"

using namespace std;

/**
@ingroup GraphLayout
@class LMCircularMinEdge
@brief Layout nodes along a circle, trying to minimize the edge length using an heuristic approach given in
"Improved Circular Layouts" of Emden R. Gansner and Yehuda Koren.
**/
class LMCircularMinEdge : public LayoutMethod
{
public:

   GraphLayout* g;
   LMCircularMinEdge() ;
   ~LMCircularMinEdge();
   void init(GraphLayout *gl, int _nDimensions);
   int steps(int n);

   double gravity;

   std::vector<LNode *>fixedNodes;
   unsigned int nstepsDone;
   int nDimensions;
private:
   void selectFixedNodes();
};

#endif


