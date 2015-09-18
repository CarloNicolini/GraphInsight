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

#include "Statistic.h"
#include <limits>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <functional>

using namespace std;

//////// CARLO NICOLINI ////////////
namespace statistic
{

/**
@ingroup Common
@return Return the average value of an input vector of double
@param x input vector
**/
double average(std::vector <double> &x)
{
    double sum = std::accumulate(x.begin(),x.end(),0);
    return sum/x.size();
}

/**
@ingroup Common
@return Return the standard deviation of a vector of double
@param x vector to evaluate standard deviation
**/

double stddev(std::vector <double> &x)
{
    unsigned int length=x.size();
    double avg=average(x);
    double error=0;
    double devstd=0;

    for (unsigned int i=0; i<length; i++)
        error+= pow( (x[i]-avg),2);

    devstd=sqrt(error/length);

    return devstd;
}

/**
@ingroup Common
@return Get the interquartile range i.e. Q3-Q1  of the vector
@param x vector to evaluate interquartile range
**/
double interquartileRange(std::vector <double> &x)
{
    unsigned int length=x.size();
    vector<double> xx = x;
    std::sort(xx.begin(), xx.end());
    double Q1=xx.at(length/4);
    double Q3=xx.at(length/4);

    return Q3-Q1;
}

/**
@ingroup Common
@return Get the median of the vector
@param x vector to evaluate median
**/
double median(std::vector <double> &x)
{
    unsigned int length=x.size();
    vector<double> xx = x;
    std::sort(xx.begin(), xx.end());
    double Q2=xx.at(length/2);

    return Q2;
}
}

