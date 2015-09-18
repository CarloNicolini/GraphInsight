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

#include "KernelPCA.h"

#include <iostream>
#include <fstream>
#include "Statistic.h"
#include "MatrixLoader.h"

using namespace std;
using namespace Eigen;

KernelPCA::KernelPCA()
{
    isComputed=false;
    embeddingDimensions=2;
    kernel=LinearKernel;	//linear kernel
}


void KernelPCA::setParameters(double _kernelparam, KernelType _kernel )
{
    kernel = _kernel;
    kernelParam=_kernelparam;

    kernelParam = estimateDataMedian();
}

void KernelPCA::loadObservationMatrix(ifstream &is)
{
    try
    {
        MatrixLoader < MatrixXd > M(is);
        data = M.getMatrix();
        datarows = data.rows();
        datacols = data.cols();
#ifdef _DEBUG
        //cerr << data << "\n" << m << " " << n << endl;
#endif
    }
    catch (std::exception &e)
    {
        cerr << e.what();
    }
}


void KernelPCA::computeEmbedding(void)
{

    if (data.rows() ==0 || data.cols()==0 )
    {
        throw string("Error, the matrix is empty");
    }

    // Now double center the matrix
    const RowVectorXd dataRowMean = data.colwise().sum() / datarows;
    data.rowwise() -= dataRowMean;

    const VectorXd dataColMean = data.rowwise().sum() / datacols;
    data.colwise()-=dataColMean;

    switch ( kernel )
    {
    case LinearKernel:
    {
        //cerr << "Doing Principal components directly on data using linear kernel and SVD " << endl;
        // In the case of linear kernel we can simply use SVD instead of eigenanalysis of covariance matrix
        JacobiSVD<MatrixXd> svd(data, ComputeThinV );
        svd.computeV();
#ifdef _DEBUG
        JacobiSVD<MatrixXd> svdtest(data, ComputeThinV | ComputeThinU );
        svdtest.computeV();
        double reconstructionError  = (data - (svdtest.matrixU()*svdtest.singularValues().asDiagonal()*svdtest.matrixV().transpose() ) ).norm();
        cerr << "SVD reconstruction error is " << reconstructionError << endl;
#endif
        embeddedData =( data*svd.matrixV() ) .leftCols(embeddingDimensions);
    }
        break;

        //Gaussian RBF Kernel
    case GaussianKernel:
    {
        /// XXX Criticità nel calcolo dell'esponenziale può essere molto lento
        //cerr << "Doing Principal components on Gaussian kernel (gram matrix) " << endl;
        // K is the kernel
        MatrixXd K(datarows,datarows);
        double sigma2=kernelParam*kernelParam;

        for (unsigned int i=0; i<datarows; i++)
        {
            for (unsigned int j=0; j<datarows; j++)
            {
                K(i,j) = exp( - (( data.row(i) - data.row(j) ).squaredNorm())/(2*sigma2) );

            }
        }
        // XXX criticità nella normalizzazione del kernel
        normalizeKernelMatrix(K);
        kernelEigenAnalysis(K);
    }
        break;

        //Quadratic polynomial Kernel
    case QuadraticKernel:
    {	// K is the kernel
        //cerr << "Doing Principal components on Quadratic kernel (gram matrix) " << endl;
        MatrixXd K(datarows,datarows);
        double gamma=kernelParam;

        K = data*data.transpose();
        K.array() += gamma;
        K=K.array().square();

        normalizeKernelMatrix(K);
        kernelEigenAnalysis(K);
    }
        break;
    }
}

void KernelPCA::normalizeKernelMatrix( MatrixXd &K)
{
    MatrixXd I = K.colwise().mean();

    for (unsigned int i=0; i<datarows; i++)
        K.row(i) = K.row(i) - I;

    for (unsigned int i=0; i<datarows; i++)
        K.col(i) = K.col(i) - I.transpose();

    double mean = I.mean();
    K.array() += mean;
}


void KernelPCA::kernelEigenAnalysis(MatrixXd &K)
{
    if (isComputed)
        return;
    // EigenAnalysis of kernel matrix
    SelfAdjointEigenSolver<MatrixXd> eigenSolver(datarows);
    eigenSolver.compute(K);
    // Biggest eigenvalues are in the bottom-right corners, the same for related eigenvectors
    MatrixXd eigenVectors = eigenSolver.eigenvectors().bottomRightCorner(datarows,embeddingDimensions);
    MatrixXd eigenValues =  eigenSolver.eigenvalues().asDiagonal();

    MatrixXd sqrtEigenvalues = eigenValues.bottomRightCorner(embeddingDimensions,embeddingDimensions).cwiseSqrt();

    embeddedData = (sqrtEigenvalues*eigenVectors.transpose()).transpose();
    isComputed=true;
}

const MatrixXd &KernelPCA::getEmbedding()
{
    if (!isComputed)
        computeEmbedding();
    return embeddedData;
}

double KernelPCA::estimateDataMedian()
{
    vector <double> vals(datarows*datarows);

    for (unsigned int i=0; i<datarows; i++)
    {
        for (unsigned int j=0; j<datarows; j++)
        {
            vals.at(i*datarows+j) =  ( data.row(i) - data.row(j)).squaredNorm()  ;
        }
    }
    std::sort(vals.begin(), vals.end());

    unsigned int lenght=vals.size();

    double median=0;
    if (vals.size() % 2 )
        median = vals.at((lenght)/2);
    else
        median = ( (vals.at(lenght/2-1) + vals.at(lenght/2)) /2.0 );

    return median;
}

