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


#ifndef _FKamadaKawai2D_h
#define _FKamadaKawai2D_h

#include <vector>
#include <Eigen/Core>

#include "CostFunction.h"
#include "Graph.h"

using namespace std;
using namespace Eigen;

/**
* @ingroup GraphLayout
* @class FKamadaKawai2D
* @brief Kamada Kawai graph layout implementation. The method need N^2 storage size because it minimize the stress based on graph-theoretic distances.
* Because of its high cost both in terms of running time and memory storage, it is disabled for graph with > 2000 nodes in GraphInsight.
**/
class FKamadaKawai2D: public CostFunction
{
   Graph *g;
public:

   double length,nedges,nnodes,limit;
   FKamadaKawai2D( Graph *G);
   ~FKamadaKawai2D();
   const vector <double> &getGradient(const vector <double> &x);

   static const double GradientNorm ;
   void setGravity(double);
protected:
   void body(const vector<double> &x) const;

};

#endif /* FKamadaKawai2D_h */

