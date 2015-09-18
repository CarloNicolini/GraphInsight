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


#ifndef LMLabelAdjust_H
#define LMLabelAdjust_H


#include "LNode.h"
#include "LayoutMethod.h"

/**
*  @ingroup GraphLayout
*  @class LMLabelAdjust
*  @brief NOT YET IMPLEMENTED
**/
class LMLabelAdjust : public LayoutMethod
{
public:
   LMLabelAdjust();
   ~LMLabelAdjust() ;

   void init(GraphLayout *gl, int nDimensions);
   int steps(int n);

protected:
   bool twoNodeLabelsIntersect(LNode *n1, LNode *n2);
   bool repulse(LNode *n1, LNode *N2);
   unsigned int nDim;

   GraphLayout *g;

};

#endif  /* LMLabelAdjust_H */


