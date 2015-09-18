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

#include <Eigen/Core>
#include <Eigen/Sparse>
#include <Eigen/Geometry>
#include <Eigen/LU>
#include <Eigen/SVD>
#include <Eigen/Eigenvalues>

#include <vector>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <stdexcept>

#include "Common.h"
#include "Timer.h"
#include "MatrixLoader.h"
#include "RandomProjection.h"
#include "KernelPCA.h"

#define INFO_LOG

using namespace std;
using namespace Eigen;
/*
    template <typename Derived, typename OtherDerived>
    void covarianceMatrix(const MatrixBase<Derived>& x, const MatrixBase<Derived>& y, MatrixBase<OtherDerived> const & C)
    {
    typedef typename Derived::Scalar Scalar;
    typedef typename internal::plain_row_type<Derived>::type RowVectorType;
    const Scalar num_observations = static_cast<Scalar>(x.rows());
    const RowVectorType x_mean = x.colwise().sum() / num_observations;
    const RowVectorType y_mean = y.colwise().sum() / num_observations;
    const_cast< MatrixBase<OtherDerived>& >(C) =
    (x.rowwise() - x_mean).transpose() * (y.rowwise() - y_mean) / num_observations;
    }
*/
template < typename Derived,  typename OtherDerived>
double powerIteration(const MatrixBase<Derived>& X, MatrixBase<OtherDerived>  & w)
{
    typedef typename Derived::Scalar Scalar;
    typedef typename internal::plain_row_type<Derived>::type RowVectorType;

    RowVectorType v(X.cols());
    v.setRandom(X.cols());

    Scalar lambda;
    for (unsigned int i=0; i<5; i++)
    {
        w = X*v.transpose();
        lambda = w.blueNorm();
        v=w/lambda;
    }
    return lambda;
}
/*
function [domVal domVec error counter] = powerIteration(A, tolerance, numTimes)
    appx = ones(length(A),1);
    counter = 0;
    epsilon = tolerance;
    error = 100;
    while (counter < numTimes) && (error > epsilon)
        temp = appx;
        appx = A*appx / norm(A*appx, 2);
        error = norm(temp-appx,2);
        counter = counter + 1;
    end
    domVec = appx;
    domVal = appx'*A*appx;
end
*/

template < typename Derived,  typename OtherDerived>
/**
 * @brief powerIteration Compute the dominant eigenvalue and its relative eigenvector of a square matrix
 * @param A The input matrix
 * @param eigenVector The eigenvector
 * @param tolerance Maximum tolerance
 * @param nIterations Number of iterations
 * @return The dominant eigenvalue
 */
typename Derived::Scalar powerIteration2(const MatrixBase<Derived>& A, MatrixBase<OtherDerived>  & eigenVector, typename Derived::Scalar tolerance,  int nIterations)
{
    typedef typename Derived::Scalar Scalar;

    OtherDerived approx(A.cols());
    approx.setRandom(A.cols());
    int counter = 0;
    Scalar error=100;
    while (counter < nIterations && error > tolerance  )
    {
        OtherDerived temp = approx;
        approx = (A*temp).normalized();
        error = (temp-approx).stableNorm();
        counter++;
    }
    eigenVector = approx;

    Scalar dominantEigenvalue = approx.transpose()*A*approx;
#ifdef INFO_LOG
    cerr << "Power Iteration:" << endl;
    cerr << "\tTotal iterations= " << counter << endl;
    cerr << "\tError= " << error << endl;
    cerr << "\tDominant Eigenvalue= " << dominantEigenvalue << endl;
    cerr << "\tDominant Eigenvector= [" << eigenVector.transpose()<< "]" << endl;
#endif
    return dominantEigenvalue;
}

template < typename Derived>
void orthonormalize( MatrixBase<Derived>& X)
{
    // This function follows a simplified implementation of Matlab orth.m function
    typedef typename Derived::Scalar Scalar;
    JacobiSVD<  MatrixXd > svd( X, ComputeThinU );
    svd.computeU();
    //    Scalar tolerance = std::max<unsigned int>(X.cols(),X.rows())*svd.singularValues().maxCoeff()*std::numeric_limits<Scalar>::epsilon();
    X = svd.matrixU();
}



/**
 * @brief subspaceIteration This method computes the n largest in magnitude eigenvalue and their corresponding eigenvectors
 * @param A
 * @param eigenVectors The eigenvectors of A to be computed
 * @param eigenValues The eigenvalues of A to be computed (given as vector of size numOfEigenValues )
 * @param numOfEigenValues Number of eigenvalues to be computed
 * @param tolerance Maximum error in computation before stopping
 * @param nIterations Maximum number of iterations
 */
template < typename Derived,  typename OtherDerived>
void subspaceIteration(const MatrixBase<Derived>& A,  MatrixBase<OtherDerived>  & eigenVectors, typename internal::plain_col_type<Derived>::type eigenValues, const unsigned int numOfEigenValues, const typename Derived::Scalar tolerance, const unsigned int nIterations)
{
    if (A.rows()!=A.cols())
    {
        throw std::runtime_error( std::string("Error in subspaceIteration: Can't apply Krylov subspace iteration to non-square matrices"));
        return;
    }
    if (numOfEigenValues>A.rows())
    {
        throw std::runtime_error( std::string("Error in subspaceIteration: You are asking for more eigenvalues than matrix size"));
        return;
    }
    typedef typename internal::plain_col_type<Derived>::type ColVectorType;
    typedef typename internal::plain_col_type<Derived>::type OtherColVectorType;
    OtherDerived X = eigenVectors;
    X.setRandom(X.rows(),numOfEigenValues);
    orthonormalize<  Derived > (X);
    ColVectorType Lambda;
    for (unsigned int k=0; k<nIterations; k++)
    {
        OtherDerived W = A*X;
        Lambda = W.rowwise().stableNorm();
        for  (unsigned  int j=0; j<numOfEigenValues; j++ )
        {
            X.col(j) << W.col(j)/Lambda(j);
        }
        orthonormalize<Derived>(X);
    }
    eigenVectors << X;
    eigenValues = (eigenVectors.transpose()*A*eigenVectors).diagonal();
#ifdef INFO_LOG
    cerr << "Subspace Iteration:" << endl;
    cerr << "\tTotal Iterations= " << nIterations << endl;
    cerr << "\tEigenpairs=" << endl ;
    for  ( unsigned int j=0; j<numOfEigenValues; j++ )
    {
        cerr << setprecision(5) << "\tL" << j << " = " << eigenValues(j) << "\t-> [" << eigenVectors.col(j).transpose() << " ]" << endl;
    }
#endif
}

template < typename Derived,  typename OtherDerived>
typename Derived::Scalar rayleighQuotientIteration(const MatrixBase<Derived>& A, MatrixBase<OtherDerived> &eigenVector, typename Derived::Scalar tolerance, int nIterations )
{
    typedef typename Derived::Scalar Scalar;
    typedef typename internal::plain_row_type<Derived>::type RowVectorType;
    typedef typename internal::plain_col_type<Derived>::type ColVectorType;
    int counter=0;
    // rcondition=rcond(A)
    // Get a first approximation of eigenvalue with poweIteration until convergence is around 1
    // then the approximation is good enough to start rayleigh iteration
    Scalar error=100.0;
    OtherDerived approx = eigenVector;

    powerIteration2< Derived, OtherDerived >(A,approx,0,nIterations);

    Derived I=Derived::Identity(A.rows(),A.cols());
    while ( (counter < nIterations ))
    {
        ColVectorType temp = approx;
        Scalar rq = (temp.transpose()*A*temp);
        rq/=(temp.dot(temp));
        FullPivLU<Derived> lu((A-rq*I));
        ColVectorType C = lu.solve(approx);
        approx = C.normalized();
        error = (temp-approx).stableNorm();
        counter++;
    }
    eigenVector=approx;
#ifdef INFO_LOG
    cerr << "RayleighQuotientIteration" << endl;
    cerr << "\tTotal iterations= " << counter << endl;
    cerr << "\tError= " << error << endl;
    cerr << "\tDominant Eigenvalue= " << ((approx.transpose()*A)*approx) << endl;
    cerr << "\tDominant EigenVector= [" << approx.transpose() << " ]" << endl;
#endif
    return ((approx.transpose()*A)*approx);
}

template < typename Derived,  typename OtherDerived>
typename Derived::Scalar inverseIteration(const MatrixBase<Derived>& A,
                                          MatrixBase<OtherDerived>  &eigenVector,
                                          const typename Derived::Scalar shift,
                                          const typename Derived::Scalar tolerance,
                                          const unsigned int nIterations)
{
    typedef typename Derived::Scalar Scalar;
    typedef typename internal::plain_row_type<Derived>::type RowVectorType;
    typedef typename internal::plain_col_type<Derived>::type ColVectorType;

    typedef typename internal::plain_matrix_type<Derived>::type MatrixType;

    MatrixType I = MatrixType::Identity(A.rows(),A.cols());

    FullPivLU<Derived> lu(A-shift*I);
    OtherDerived v(A.cols());
    v.setRandom(A.cols());
    v.normalize();
    ColVectorType w ;

    for (unsigned int k=0; k<nIterations; k++)
    {
        w = lu.solve(v);
        Scalar lambda = w.stableNorm();
        cerr << lambda << endl;
        v=w/lambda;
    }

}


int main(int argc, char*argv[])
{
    char* name = argv[1];

    try
    {
        MatrixLoader< MatrixXd > M(name);
        MatrixXd L = M.getMatrix();
        unsigned int nEigenVectors = 6;
        MatrixXd eigenVectors;
        eigenVectors.setRandom(L.rows(),nEigenVectors);

        double error=0;
        VectorXd dominantEigenVector(L.cols());
        VectorXd eigenValues;
        eigenVectors.setRandom(L.rows(),nEigenVectors);

        powerIteration2<MatrixXd, VectorXd> (L,dominantEigenVector, 1E-3, 10);

        subspaceIteration<MatrixXd, MatrixXd>(L,eigenVectors,eigenValues,nEigenVectors,1E-7,10);

        //powerIteration2 < MatrixXd , VectorXd >(L,eigenVectors,numeric_limits<double>::epsilon(),error,10);
        rayleighQuotientIteration< MatrixXd, VectorXd >(L,dominantEigenVector, 1E-10, 10);
        //inverseIteration<MatrixXd, MatrixXd>(L);
        //cout << eigenVectors << endl;
    }
    catch( std::exception &e)
    {
        cerr << e.what() << endl;
    }

    //timer.start();
    //SelfAdjointEigenSolver<MatrixXd> eigenSolver(M.getMatrix().rows());
    //eigenSolver.compute(M.getMatrix());
    //cout << timer.getElapsedTimeInMilliSec() << " [ms] " << endl;
    //cout << "\n***\n" << eigenSolver.eigenvectors() << endl;

    return 0;

}

