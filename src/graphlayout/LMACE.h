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



#ifndef LMACE_H
#define LMACE_H


#include "LayoutMethod.h"
#include <vector>
#include <Eigen/Core>

using namespace Eigen;
/**
@ingroup GraphLayout
@class LMACE
@brief LMACE class implements laplacian embedding, it uses eigenvalues of graph laplacian matrix as coordinates of nodes.
Has N^2 storage cost and N^3 running time, so use it only for small graphs
**/
class LMACE : public LayoutMethod
{
public:
   LMACE();
   ~LMACE();

   void init(GraphLayout *gl, int nDimensions);
   int steps(int n);
   void optimum(void);

protected:
   GraphLayout *g;
   int dimensions; // number of largest eigenvectors to display
   int m;  //embedding Dimension
   int n;  // number of graph nodes

   // size of laplacian matrix will be determined at runtime
   Matrix<double,Dynamic, Dynamic> Laplacian;
   VectorXd Masses;

   void setLaplacian();

   bool alreadyComputed;
   //double tolerance;

   //unsigned int ncomponents;
   // Private methods

};

#endif  /* LMACE_H */


