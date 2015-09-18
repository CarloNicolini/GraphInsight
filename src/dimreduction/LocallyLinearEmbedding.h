/****************************************************************************
**
** Copyright (C) 2012 Carlo Nicolini (nicolini.carlo@gmail.com)
** All rights reserved.
**
** Warning: This program is protected by copyright law and international
** treaties. Unauthorized reproduction and distribution of this program,
** or any portion of it, may result in severe civil and criminal penalties,
** and will be persecuted to the maximum extent possible under the law.
**
****************************************************************************/

#ifndef LOCALLYLINEAREMBEDDING_H
#define LOCALLYLINEAREMBEDDING_H

#include "DimensionalityReduction.h"
#include <iostream>
#include <fstream>
/*
 * http://www.cs.nyu.edu/~roweis/lle/algorithm.html
 *
Input X: D by N matrix consisting of N data items in D dimensions.
Output Y: d by N matrix consisting of d < D dimensional embedding coordinates for the input points.

    Find neighbours in X space [b,c].
            for i=1:N
              compute the distance from Xi to every other point Xj
              find the K smallest distances
              assign the corresponding points to be neighbours of Xi
            end

    Solve for reconstruction weights W:
            for i=1:N
              create matrix Z consisting of all neighbours of Xi [d]
              subtract Xi from every column of Z
              compute the local covariance C=Z'*Z [e]
              solve linear system C*w = 1 for w [f]
              set Wij=0 if j is not a neighbor of i
              set the remaining elements in the ith row of W equal to w/sum(w);
            end

        Compute embedding coordinates Y using weights W.
            create sparse matrix M = (I-W)'*(I-W)
            find bottom d+1 eigenvectors of M
              (corresponding to the d+1 smallest eigenvalues)
            set the qth ROW of Y to be the q+1 smallest eigenvector
              (discard the bottom eigenvector [1,1,1,1...] with eigenvalue zero)
 */
using std::ifstream;

class LocallyLinearEmbedding : public DimensionalityReduction
{

public:
    LocallyLinearEmbedding();
    ~LocallyLinearEmbedding() {}
    void loadObservationMatrix(std::ifstream &is);
    void computeEmbedding();
    const Eigen::MatrixXd &getEmbedding();
};

#endif // LOCALLYLINEAREMBEDDING_H
