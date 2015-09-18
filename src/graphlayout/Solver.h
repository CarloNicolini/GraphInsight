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

#ifndef _solver_h
#define _solver_h

#include <vector>
#include <limits>
#include "CostFunction.h"

using namespace std;
/**
* @ingroup GraphLayout
* @class Solver
* @brief A pure virtual interface for the implementation of a solver
**/
class Solver
{
protected:
   CostFunction &gfunction;

public:
   inline Solver(CostFunction &f);
   inline virtual ~Solver();

   virtual inline const vector<double> &next(void) = 0;

   vector<double> best_point;

   double best_value;
};

inline Solver::Solver(CostFunction &f)
   : gfunction(f),
     best_value(std::numeric_limits<double>::max())
{
}

inline Solver::~Solver()
{
}

#endif


