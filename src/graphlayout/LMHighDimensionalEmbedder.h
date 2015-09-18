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



#ifndef LMHighDimensionalEmbedder_H
#define LMHighDimensionalEmbedder_H

#include <Eigen/Core>
#include <Eigen/QR>
#include <Eigen/Eigenvalues>
#include "LayoutMethod.h"
#include <vector>

using namespace Eigen;

/**
* @ingroup GraphLayout
* @class LMHighDimensionalEmbedder
* @brief High dimensional embedding of the graph. It's the fastest layout method because its linear running time, but the results are not very good for real-world graphs.
**/
class LMHighDimensionalEmbedder : public LayoutMethod
{
public:
   LMHighDimensionalEmbedder();
   ~LMHighDimensionalEmbedder();

   void init(GraphLayout *gl, int nDimensions);
   int steps(int n);

protected:
   GraphLayout *g;
   int dimensions; // number of largest eigenvectors to display
   int m;  //embedding Dimension
   int n;  // number of graph nodes
   Matrix<double,Dynamic,Dynamic> Xm;      // principal matrix
   vector <double> d;                      //needed for k-centers problem
   Matrix<double,Dynamic,Dynamic> S;     // covariance matrix
   Matrix<double,Dynamic,Dynamic> XT;                      // transposed of Xm

   bool justComputed;
};

#endif  /* LMHighDimensionalEmbedder_H */


