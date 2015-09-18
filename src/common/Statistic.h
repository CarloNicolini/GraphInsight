/****************************************************************************
**
** Copyright (C) 2010 Michele Dallachiesa (michele.dallachiesa@gmail.com)
** Copyright (C) 2010 Carlo Nicolini (nicolini.carlo@gmail.com)
** All rights reserved.
**
** Warning: This program is protected by copyright law and international
** treaties. Unauthorized reproduction and distribution of this program,
** or any portion of it, may result in severe civil and criminal penalties,
** and will be persecuted to the maximum extent possible under the law.
**
****************************************************************************/


#ifndef _STATISTIC_H
#define	_STATISTIC_H

#include <algorithm>
#include <vector>
#include <iostream>
#include <Eigen/Core>

#ifdef _WIN32
#include <windows.h>
#ifndef NOMINMAX
#define NOMINMAX
#endif
#endif

// Try to substitute the nano sleep function of the unix operating systems with a Win32 compatible
#ifdef _WIN32
inline void usleepwin32(int waitTime){
__int64 time1 = 0, time2 = 0, sysFreq = 0;

QueryPerformanceCounter((LARGE_INTEGER *)&time1);
QueryPerformanceFrequency((LARGE_INTEGER *)&sysFreq);
do{
QueryPerformanceCounter((LARGE_INTEGER *)&time2);

//  }while((((time2-time1)*1.0)/sysFreq)<waitTime);
  }while( (time2-time1) <waitTime);
}
#endif

#ifndef MIN
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#endif

#ifndef MAX
#define MAX(a, b) ((a) < (b) ? (b) : (a))
#endif

#ifndef ABS
#define ABS(x) ((x) < 0 ? -(x) : (x))
#endif

#ifndef POW2
#define POW2(x) (x*x)
#endif

/**
  \ingroup Common
  \namespace statistic
  \brief This namespace contains some simple implementations of statistic functions
**/
namespace statistic
{
    double average(std::vector <double> &);
    double stddev(std::vector <double> &);
    double interquartileRange(std::vector <double> &);
    double median(std::vector <double> &);


    using namespace Eigen;
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
}

#endif
