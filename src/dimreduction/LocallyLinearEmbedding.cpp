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
#include <Eigen/Eigenvalues>
#include "MatrixLoader.h"
#include "LocallyLinearEmbedding.h"

using namespace Eigen;

LocallyLinearEmbedding::LocallyLinearEmbedding()
{
    isComputed=false;
    embeddingDimensions=2;
}

void LocallyLinearEmbedding::loadObservationMatrix(std::ifstream &is)
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

void LocallyLinearEmbedding::computeEmbedding(void)
{

}

const MatrixXd &LocallyLinearEmbedding::getEmbedding()
{
    if (!isComputed)
        computeEmbedding();
    return embeddedData;
}
