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
** DESCRIPTION
**
** Conjugate Gradient Solver, implements the Conjugate gradient solver
** for generic differentiable functions Using the Polak-Ribiere method
**
****************************************************************************/

#ifndef _CGSolver_h_
#define _CGSolver_h_

#include <vector>
#include <cstdlib>
#include "Common.h"
#include "Solver.h"
#include "CostFunction.h"
#include "limits.h"

using namespace std;

/**
*  @ingroup GraphLayout
*  @class CGSolver
*  @brief A conjugate gradient solver with Polar-Riebke scheme for step-size choose
**/
class CGSolver : public Solver
{
protected:
   // This is the upper limit on step size, set default to 1
   double max_alpha;
   unsigned int dimension;
   double currentValue;
   // Vectors needed for optimization procedure
   vector <double> y, p, grad, x, grad_old;
   // Reference to function with its gradient
   CostFunction &gfunction;

public:
   CGSolver(CostFunction&);
   CGSolver(CostFunction&, vector <double> &);

   virtual ~CGSolver();
   inline const vector<double> &next(void );
   const vector<double> &makeSteps(int steps = 5, double tolerance = 1E-4, double alpha_max = 1.);
   const vector <double> &minimize(int maxSteps = INT_MAX, double tolerance = 1E-4, double alpha_max = 1. );

   inline double dot(const vector <double>&, const vector <double>&);

   double lineSearchInterpolation(void);

   void restartDirection(void);
   const vector<double> &randomRestart(void);

   void loadSolution(const vector <double> &);
   const vector<double> &getSolution();

   double optimality;
};


#endif

