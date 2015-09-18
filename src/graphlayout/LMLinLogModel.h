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


#ifndef LMLinLogModel_H
#define LMLinLogModel_H

#include "LNode.h"
#include "LayoutMethod.h"

/**
* @ingroup GraphLayout
* @class LMLinLogModel
* @brief Lin Log model of force directed layout method
**/
class LMLinLogModel : public LayoutMethod
{
public:
   LMLinLogModel();
   ~LMLinLogModel() ;

   void init(GraphLayout *gl, int nDimensions);
   int steps(int n);

   double gradientNorm;

   void setGradientNorm(double gnorm)
   {  gradientNorm=gnorm;
   };


   double gravity,speed;
   double repStrength,attrStrenght;
   unsigned int nDim;

   int step2D();
   int step3D();

   double optimality,oldOptimality;
   GraphLayout *g;

};

#endif  /* LMLinLogModel_H */


