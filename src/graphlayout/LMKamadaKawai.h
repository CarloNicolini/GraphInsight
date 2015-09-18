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



#ifndef LMKamadaKawai_H
#define LMKamadaKawai_H

#include "LayoutMethod.h"
#include <vector>

/**
@ingroup GraphLayout
@class LMKamadaKawai
@brief Kamada Kawai layout method for graph, also known as stress-minimization
**/
class LMKamadaKawai : public LayoutMethod
{
public:
   LMKamadaKawai();
   ~LMKamadaKawai();
   void init(GraphLayout *gl, int nDimensions);
   int steps(int n);


   CostFunction *f;
protected:
   GraphLayout *g;
   CGSolver *solCG;
   double gradientNorm;

};

#endif  /* LMKamadaKawai_H */


