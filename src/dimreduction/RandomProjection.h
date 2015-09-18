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

#ifndef _RandomProjection_H
#define _RandomProjection_H

#include <limits>
#include <vector>
#include <string>
#include <fstream>
#include "Common.h"
#include <Eigen/Core>
#include "DimensionalityReduction.h"

using namespace Eigen;
using namespace std;

/*
Random Projection (RP)

We summarize below the main ideas behind RP. Let us suppose that we are given a set of vectors Γi,i = 1,2,...,M, in a p-dimensional space. RP can be used to transform Γi to a lower dimension d, with d<<p, via the following transformation:

\tilde{\Gamma}_{i}=R\Gamma _{i}
where R is orthonormal and its columns are realizations of independent and identically distributed (i.i.d.) zero-mean normal variables, scaled to have unit length. RP is motivated by the Johnson-Lindenstrauss lemma [6] that states that a set of M points in a high dimensional Euclidean space can be mapped down onto a d \geq O(logM/ \epsilon ^{2}) dimensional subspace such that the distances between the points are approximately preserved (i.e., not distorted more than a factor of 1 \pm \epsilon, for any 0 < ε < 1). There is experimental evidence suggesting that the lower bound for d is not very tight and that, in practice, lower d values give good results.
The entries of the matrix R can be calculated using the following algorithm:
Step 1. Set each entry of the matrix to an i.i.d. N(0; 1) value.
Step 2. Orthogonalize the d rows of the matrix (e.g., using Gram-Schmidt orthogonalization algorithm).
Step 3. Normalize the rows of the matrix to unit length (i.e., important for preserving similarities in the low dimensional space).
Orthogonalizing the random vectors is required to preserve the similarities between the original vectors in the low-dimensional space. In high enough dimensions, however, it is possible to save computation time by avoiding the orthogonalization step without affecting much the quality of the projection matrix. This is because, in high-dimensional spaces, there exist a much larger number of almost orthogonal vectors than orthogonal vectors. Therefore, high-dimensional vectors having random directions are very likely to be close to orthogonal.
A simpler algorithm has been proposed by Achlioptas [7] or approximating the random matrix, yielding significant computational savings during the computation of R and the projections RΓi. The algorithm produces a sparse random matrix with elements belonging in -1, 0, 1, therefore, simplifying the computations considerably.
RP has been applied on various types of problems including information retrieval, machine learning and optimization (see [5] ). Although it is based on a simple idea, RP has demonstrated good performance in a number of applications, yielding results comparable to conventional dimensionality reduction techniques, such as PCA, while having much lower computational requirements.
*/

class RandomProjection : public DimensionalityReduction
{
public:

    RandomProjection();
    ~RandomProjection() {};

    void loadObservationMatrix(ifstream &);
    void computeEmbedding();
    const Eigen::MatrixXd& getEmbedding();
};

#endif
