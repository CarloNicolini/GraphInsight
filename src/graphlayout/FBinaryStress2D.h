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


#ifndef _FBinaryStress2D_h
#define _FBinaryStress2D_h

#include <vector>
#include "CostFunction.h"
#include "Graph.h"

using namespace std;

/**
* @ingroup GraphLayout
* @class FBinaryStress2D
* @brief Binary stress layout implementation. The methods is based on omonym paper of Yehuda Koren
**/
class FBinaryStress2D: public CostFunction
{

   Graph *g;
   double gravity;
   double c;
   double radius;
public:
   FBinaryStress2D( Graph *);
   ~FBinaryStress2D();
   const vector <double> &getGradient(const vector <double> &x);
   void setGravity(double g);

   static const double GradientNorm ;
protected:
   void body(const vector<double> &x) const;

};

#endif /* FBinaryStress2D_h */

