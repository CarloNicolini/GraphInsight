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

#ifndef _KernelPCA_H
#define _KernelPCA_H

#include <Eigen/Core>
#include <Eigen/Geometry>
#include <Eigen/LU>
#include <Eigen/SVD>
#include <Eigen/Eigenvalues>
#include <vector>
#include <string>
#include <fstream>

#include "Common.h"
#include "DimensionalityReduction.h"

using namespace Eigen;
using namespace std;


typedef enum
{
    LinearKernel = 0,
    GaussianKernel = 1,
    QuadraticKernel = 2
} KernelType;


class KernelPCA : public DimensionalityReduction
{
private:

    KernelType kernel;
	double kernelParam;

    void normalizeKernelMatrix(MatrixXd &K);
    void kernelEigenAnalysis(MatrixXd &K);

public:	
    KernelPCA();
    ~KernelPCA() {}
    void loadObservationMatrix(ifstream &is);
    void computeEmbedding();
    const MatrixXd &getEmbedding();

    void setParameters(double _kernelparam=1.0, KernelType _kernel = LinearKernel );
    double estimateDataMedian();
    void loadSimilarityMatrix(ifstream &);
};

#endif
