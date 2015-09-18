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


#ifndef LMFruchtermanReingold_H
#define LMFruchtermanReingold_H


#include "LNode.h"
#include "LayoutMethod.h"

/**
*  @ingroup GraphLayout
*    @class LMFruchtermanReingold
*    @brief LMFruchtermanReingold is the implementation of the Fruchterman-Reingold layout method, this implementation has some advantages on the seminal proposed implementation,
it switchs automatically to O(nlog(n)) force calculation method when graphs are too big.
**/
class LMFruchtermanReingold : public LayoutMethod
{
public:
   LMFruchtermanReingold();
   ~LMFruchtermanReingold() ;

   void init(GraphLayout *gl, int nDimensions);
   int steps(int n);

   double gradientNorm;

   void setGradientNorm(double gnorm)
   {  gradientNorm=gnorm;
   };

   double gravity,speed;
   unsigned int nDim;

   double optimality,oldOptimality;
   GraphLayout *g;

};

#endif  /* LMFruchtermanReingold_H */


