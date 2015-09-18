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

#ifndef _COSTFUNCTION_H_
#define _COSTFUNCTION_H_


using namespace std;

/**
@ingroup GraphLayout
@class CostFunction
@brief A pure-virtual implementation of a cost function to pass to a solver which minimizes it
**/
class CostFunction
{

protected:
   mutable double Result;
   virtual void body(const vector <double> &x) const = 0;

public:

   virtual ~CostFunction() {};

   double& value()
   {  return Result;
   };
   double& eval (vector<double> &x)
   {  body(x);
      return Result;
   };

   double& operator() ()
   {  return Result;
   };
   double& operator() (vector<double> &x)
   {  return eval(x);
   };

   virtual const vector <double> &getGradient(const vector <double>&) = 0;
   virtual void setGravity(double) = 0 ;

   unsigned int  dimension;
   vector <double> gradient;
   double energy;
};

#endif /* _gfunction_h */

