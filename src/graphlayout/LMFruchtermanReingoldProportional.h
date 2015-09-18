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


#ifndef LMFruchtermanReingoldProportional_H
#define LMFruchtermanReingoldProportional_H
#include "LNode.h"
#include "LayoutMethod.h"

/**
*  @ingroup GraphLayout
*    @class LMFruchtermanReingoldProportional
*    @brief LMFruchtermanReingoldProportional is the implementation of the Fruchterman-Reingold layout method with a modification of energy function to make cluster more visible, this implementation has some advantages on the seminal proposed implementation,
it switchs automatically to O(nlog(n)) force calculation method when graphs are too big.
* It resembles the Force Atlas layout method in Gephi
**/
class LMFruchtermanReingoldProportional : public LayoutMethod
{
public:
   LMFruchtermanReingoldProportional();
   ~LMFruchtermanReingoldProportional() ;

   void init(GraphLayout *gl, int nDimensions);
   int steps(int n);

   double gradientNorm;

   void setGradientNorm(double gnorm)
   {  gradientNorm=gnorm;
   };


   unsigned int nDim,nnodes;
   double coarseningLevel;
   double gravity,speed;


   int step2D();
   int step3D();
    bool preventNodeOverlap;
   double optimality,oldOptimality;
   GraphLayout *g;

};

#endif  /* LMFruchtermanReingoldProportional_H */


