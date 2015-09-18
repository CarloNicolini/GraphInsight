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
#include <string>
#include <cmath>
#include <vector>
#include <iostream>
#include <fstream>
#include <limits>
#include <stdexcept>
#include "RandomProjection.h"
#include "Common.h"
#include "DimensionalityReduction.h"

#include "MatrixLoader.h"
#include <Eigen/Core>


using namespace Eigen;

RandomProjection::RandomProjection()
{
    isComputed=false;
    embeddingDimensions=2;
}

void RandomProjection::loadObservationMatrix(ifstream &is)
{
    try
    {
        MatrixLoader < MatrixXd > M(is);
        data = M.getMatrix().cast<double>();
        datarows = data.rows();
        datacols = data.cols();
        //cout << data << endl;
#ifdef _DEBUG
        //cerr << data << "\n" << m << " " << n << endl;
#endif
    }
    catch (std::exception &e)
    {
        cerr << e.what();
        throw string("Error in loading observation matrix in RandomProjection");
    }

}

void RandomProjection::computeEmbedding(void)
{
    if (data.rows() ==0 || data.cols()==0 )
    {
        throw string("Error, the matrix is empty");
    }

    MatrixXd R(data.cols(),embeddingDimensions);

    double sqrt3 = sqrt(3.0);
    int totalSize = R.cols()*R.rows();
    for (int i=0; i<totalSize; i++)
    {
        double x = Common::unifRand(0.0,1.0);

        // Achilioptas method
        if ( x <= 1.0/6.0 )
        {
            R.coeffRef(i)=sqrt3;
            continue;
        }
        if ( x >= 5.0/6.0 )
        {
            R(i) = -sqrt3;
            continue;
        }
        // Seminal method 50% +1 -- 50% -1
        //
        /*
        if (x>0.5)
            R(i)=1;
        else
            R(i)=-1;
        */
    }

    embeddedData = data*R ;
    isComputed = true;
}

const Eigen::MatrixXd &RandomProjection::getEmbedding()
{
    if (!isComputed)
    {
        computeEmbedding();
    }
    return embeddedData;
}
