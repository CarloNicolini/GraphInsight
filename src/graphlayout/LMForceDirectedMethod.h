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


#ifndef LMFORCEDIRECTED_H_
#define LMFORCEDIRECTED_H_


#include "LNode.h"
#include "LayoutMethod.h"

enum Force
{
    FruchtermanReingold = 0,
    ForceAtlas = 1,
    LinLog = 2
};

/**
@ingroup GraphLayout
@class LMForceDirected
@brief Implementation of the generic methods to layout graph with force directed methods.
**/
class LMForceDirected : public LayoutMethod
{
public:
   LMForceDirected();
   ~LMForceDirected() ;

   void init(GraphLayout *gl, int nDimensions, enum Force);
   int steps(int n);

   void optimum(void);

   double gradientNorm;

   void setGradientNorm(double gnorm)
   {  gradientNorm=gnorm;
   };
   void setGravity(double );


protected:
   void applyStep();

   double gravity,speed;
   unsigned int nDim;

   double optimality,oldOptimality;
   GraphLayout *g;
};

#endif  /* LMFruchtermanReingold_H */


