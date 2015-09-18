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


#ifndef LMBinaryStress_H
#define LMBinaryStress_H

#include "LayoutMethod.h"
#include <vector>

/**
@ingroup GraphLayout
@class LMBinaryStress
@brief LMBinaryStress is the wrapper of FBinaryStress layout method, implements LayoutMethod
**/
class LMBinaryStress : public LayoutMethod
{
public:
   LMBinaryStress();
   ~LMBinaryStress() ;

   void init(GraphLayout *gl, int nDimensions);
   int steps(int n);

   double gradientNorm;

   void setCoarseningLevel(double level)
   {  coarseningLevel = level;
   }
   void setGradientNorm(double gnorm)
   {  gradientNorm=gnorm;
   }

protected:
   GraphLayout *g;
   CGSolver *solCG;
   CostFunction *f;
   double coarseningLevel;

};

#endif  /* LMBinaryStress_H */


