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

#ifndef _DIMENSIONALITYREDUCTION_H
#define _DIMENSIONALITYREDUCTION_H

#include <iostream>
#include <vector>
#include <Eigen/Core>
#include <Eigen/Sparse>
/**
  @brief DimensionalityReduction class, is a pure virtual interface
**/
class DimensionalityReduction
{
public:
    virtual ~DimensionalityReduction(){};
    //virtual void loadSimilarityMatrix(std::ifstream &) = 0;
    virtual void loadObservationMatrix(std::ifstream &) = 0;
    virtual void computeEmbedding(void) = 0;
    virtual const Eigen::MatrixXd &getEmbedding() = 0;

    // Pure virtual methods to override in every derived class

    virtual const Eigen::MatrixXd &getDataMatrix()
    {
        return data;
    }
    const Eigen::SparseMatrix<double> &getSparseDataMatrix ()
    {
        return sparseData;
    }
protected:
    unsigned int embeddingDimensions;
    unsigned int datarows,datacols;
    bool isSparse, isComputed;

    Eigen::MatrixXd data;
    Eigen::MatrixXd embeddedData;
    Eigen::SparseMatrix<double> sparseData;
};

#endif

