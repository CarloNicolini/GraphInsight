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
****************************************************************************
*/

#include <iostream>
#include <cmath>
#include <fstream>
#include <limits>
#include "CGSolver.h"
#include "CostFunction.h"
#include "Statistic.h"

using namespace std;

/**
* @ingroup GraphLayout
* @brief CGSolver::CGSolver
* Init all vectors to the given dimension and set the search direction to be the opposite of the gradient
* @param f The cost function to extremize
**/
CGSolver::CGSolver(CostFunction &f)
    : Solver(f),
      max_alpha(1.),
      dimension(f.dimension),
      y(dimension),
      p(dimension),
      grad(dimension),
      x(dimension),
      grad_old(dimension),
      gfunction(f)
{
    //    cerr << "Conjugate Gradient Solver with random start: dimension " << dimension << endl;
    y.reserve(dimension);
    y.assign(dimension,0.0);
    p.reserve(dimension);
    p.assign(dimension,0.0);
    grad.reserve(dimension);
    grad.assign(dimension,0.0);
    x.reserve(dimension);
    x.assign(dimension,0.0);
    grad_old.reserve(dimension);
    grad_old.assign(dimension,0.0);
    randomRestart();
    best_point=x;
    grad = f.getGradient(x);
    currentValue = f.energy;//   here because gradient has just been computed;

    for (unsigned int i=0; i<dimension; ++i)
        p[i] = -grad[i];
    best_value = optimality = 1e30;
}

/**
@ingroup GraphLayout
 * @brief CGSolver::CGSolver
* @param f The cost function to extremize
* @param positions The coordinates of current solution
**/
CGSolver::CGSolver(CostFunction &f, vector <double> &positions)
    : Solver(f),
      max_alpha(1.),
      dimension(f.dimension),
      y(dimension),
      p(dimension),
      grad(dimension),
      x(dimension),
      grad_old(dimension),
      gfunction(f)
{
    // cerr << "Conjugate Gradient Solver guessed start dimension " << dimension << endl;//" positions.size()= " << positions.size() << endl;
    // Starts from the given positions instead of random start
    y.reserve(dimension);
    y.assign(dimension,0.0);
    p.reserve(dimension);
    p.assign(dimension,0.0);
    grad.reserve(dimension);
    grad.assign(dimension,0.0);
    x.reserve(dimension);
    x.assign(dimension,0.0);
    grad_old.reserve(dimension);
    grad_old.assign(dimension,0.0);
    if (positions.size()!=0)
    {  x = positions;
        best_point=positions;
    }
    grad = f.getGradient(x);
    currentValue = f.energy;//f.eval(x);

    for (unsigned int i=0; i<dimension; ++i)
    {  p[i] = -grad[i];
    }

    best_value = optimality = 1e30;
}

/**
@ingroup GraphLayout
 * @brief CGSolver::~CGSolver Destructor, it clears all the stored variables
**/
CGSolver::~CGSolver(void)
{  y.clear();
    p.clear();
    grad.clear();
    x.clear();
    grad_old.clear();
}

/**
  @ingroup GraphLayout
 * @brief CGSolver::randomRestart Set the position to random value in range [-10,10]
* @return A reference to the current randomize solution
**/
const vector<double> &CGSolver::randomRestart(void)
{
    for (unsigned int i=0; i<dimension; ++i)
    {  x[i] = Common::unifRand(-10.0,10.0);
    }

    return x;
}

/**
  @ingroup GraphLayout
 * @brief CGSolver::restartDirection  Restart the search direction to the opposite of gradient
 */
void CGSolver::restartDirection(void)
{
    for (unsigned int i=0; i<dimension; ++i)
        p[i] = -grad[i];
}

/**
 *  @ingroup GraphLayout
 * @brief CGSolver::dot Euclidean dot product between two vector with lenght dimension
* @param a vector a
* @param b vector b
* @return dot product of the two vectors
**/
double CGSolver::dot(const vector <double> &a, const vector <double> &b)
{  double dot = 0;
    for (unsigned int i=0; i<dimension; ++i)
        dot += a[i] * b[i];

    return dot;
}

/**
 * @brief CGSolver::lineSearchInterpolation
 * @ingroup GraphLayout
* The line search procedure
* Here we minimize the function \f$\phi(\alpha) = f(x_k + \alpha p_k) \f$ in order to find
* the best alpha, i.e. the optimal stepsize. All the details of the procedure are available in the book, Jorge Nocedal, Stephen Wright "Numerical Optimization", Springer 2003
* at chapter 3 - Line search
 * @return The stepsize
 */
double CGSolver::lineSearchInterpolation(void)
{  double alpha_zero = max_alpha;
    double c1 = 1E-4;

    double alpha = alpha_zero;
    // The quadratic interpolant minimizer
    double alpha_one=0;
    // The cubic interpolant minimizer
    double alpha_two=0;

    vector <double> xpost(dimension,0.0);
    vector <double> gradpost(dimension,0.0);

    for (unsigned int i=0; i<dimension; ++i)
        xpost[i] = x[i] + alpha_zero * p[i];

    gradpost = gfunction.getGradient(xpost);

    double phi_alpha_zero = gfunction.energy;// here because the gradient has just been evaluated and energy is computed
    double phi_zero = gfunction.eval(x); //phi(0) = f(x_k)
    double dPhi_zero = dot(grad, p); // phi'(0) = <grad(f(x_k)) , p>


    if (phi_alpha_zero <= (phi_zero + c1 * alpha_zero * dPhi_zero))
    {
        alpha = alpha_zero;
        return (alpha);
    }
    else
    {  // Try a quadratic interpolation
        alpha_one = -(dPhi_zero * alpha_zero * alpha_zero) / (2. * (phi_alpha_zero - phi_zero - dPhi_zero * alpha_zero));
        double phi_alpha_one=0;
        for (unsigned int i=0; i<dimension; ++i)
            xpost[i] = x[i] + alpha_one * p[i];
        phi_alpha_one = gfunction.eval(xpost);
        if (phi_alpha_one <= (phi_zero + c1 * alpha_one * dPhi_zero))
        {

            alpha = alpha_one;

            return (alpha);
        }// else try a cubic interpolant and find the minimizer of the cubic
        else
        {  double a=0, b=0, denom=0;
            denom = 1. / (pow(alpha_zero*alpha_one, 2.) *(alpha_one - alpha_zero));
            a = denom * (pow(alpha_zero, 2)*(phi_alpha_one - phi_zero - dPhi_zero * alpha_one)
                         - pow(alpha_one, 2)*(phi_alpha_one - phi_alpha_zero - dPhi_zero * alpha_one));
            b = denom * (-alpha_zero * alpha_zero * alpha_zero * (phi_alpha_one - phi_zero - dPhi_zero * alpha_one)
                         + alpha_one * alpha_one * alpha_one * (phi_alpha_zero - phi_zero - dPhi_zero * alpha_zero));
            alpha_two = (-b + sqrt(b * b - 3. * a * dPhi_zero)) / (3. * a);
            alpha = alpha_two;
            return (alpha);
        }
    }
}

/**
 * @ingroup GraphLayout
 * * @brief CGSolver::next Next step method. Here first we compute the correct stepsize, alfa, then move in the direction given by vector search direction called "p".
* The first time the method is called, the search direction is set to -gradient(f).
* The restart is done automatically by the macro MAX(0,beta). If beta<0 then search direction is the opposite of gradient.
* We use the Polak-Ribiere choice for the beta term.
@return current solution
**/
inline const vector<double> &CGSolver::next(void )
{  double alfa = lineSearchInterpolation();

    for (unsigned int i=0; i<dimension; ++i)
    {  x[i] += alfa * p[i];
        grad_old[i] = grad[i];
    }

    grad = gfunction.getGradient(x);

    //  Fletcher - Reeves method
    //   double beta = dot (grad,grad)/(dot(grad_old,grad_old));

    /// Polak - Ribier i.e. the most efficient conjugate gradient method
    for (unsigned int i=0; i<dimension; ++i)
        y[i] = grad[i] - grad_old[i];

    double beta = dot(grad, y) / (dot(grad, grad));

    // Update the search direction
    for (unsigned int i=0; i<dimension; ++i)
        p[i] = -grad[i] + std::max(0.0, beta) * p[i];

    currentValue = gfunction.energy;   //x doesn't vary among these lines, so currentValue was just computed when computing gradient!

    if (currentValue < best_value)
    {  best_value = currentValue;
        best_point = x;
        return best_point;
    }
    else
        return x;
}

/**
 * @ingroup GraphLayout
 * @brief CGSolver::minimize Minimize method
* @param max_trials maximum number of iterations before the minimizer will stop
* @param tolerance is the normalized value of norm of the gradient (default 1E-3)
* @param alpha_max is the maximum (initial) stepsize (default 1).
*@return The minimum solution
**/
const vector <double> &CGSolver::minimize(int max_trials, double tolerance, double alpha_max)
{

    int k = 0;
    max_alpha = alpha_max;
    double dotgrad = dot(grad, grad) / (dimension * dimension);

    while (dotgrad > tolerance && k < max_trials)
    {  //    cerr << "E = " << currentValue << "\t||g|| " << dotgrad << endl;
        best_point = next();
        dotgrad = dot(grad, grad) / (dimension * dimension);
        k++;
    }
    return best_point;
}

/**
 * @ingroup GraphLayout
 * @brief CGSolver::loadSolution Load a solution from vector
 * @param actualSolution The solution to load
 */
void CGSolver::loadSolution(const vector <double> &actualSolution)
{  best_value = 1e18;
    best_point = actualSolution;
    optimality = std::numeric_limits<double>::max();

    x = best_point;
}

/**
 * @ingroup GraphLayout
 * @brief CGSolver::makeSteps
 * @param steps Number of steps to iterate
 * @param tolerance Tolerance to stop
 * @param alpha_max Maximum alpha for the line search procedure
 * @return The solution after one step
 */
const vector<double> &CGSolver::makeSteps(int steps, double tolerance, double alpha_max)
{

    int k = 0;
    max_alpha = alpha_max;

    double dotgrad = dot(grad, grad) / (dimension * dimension);

    while (dotgrad > tolerance && k < steps)
    {
        DEBUG_PRINT("E = " << currentValue << "\t||g|| " << dotgrad );
        best_point = next();
        dotgrad = dot(grad, grad) / (dimension * dimension);
        k++;
        //cout << "E = " << currentValue << "\t||g|| " << dotgrad << endl;
    }

    optimality = dotgrad;
    return best_point;
}

/**
 * @brief CGSolver::getSolution
 * @return
 */
const vector<double> &CGSolver::getSolution()
{
    return best_point;
}

