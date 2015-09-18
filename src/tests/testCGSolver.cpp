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


#include <vector>
#include <iostream>
#include <fstream>
#include "Timer.h"
#include "CGSolver.h"
#include "CostFunction.h"

using namespace std;

class TestFunction: public CostFunction
{

public:
    TestFunction(int d);
    ~TestFunction();

    const vector <double> &getGradient(const vector <double> &x);

    void setGravity(double g)
    {

    }

protected:
    void body(const vector<double> &x) const;
};

TestFunction::TestFunction(int d)
{
    dimension=d;
    gradient.resize(d);
}

TestFunction::~TestFunction()
{

}

const vector <double> &TestFunction::getGradient(const vector <double> &x)
{
    energy=0.0;
    for (int i=0; i<dimension;i++)
    {
        this->gradient[i]=2*x[i];
        energy+=x[i]*x[i];
    }

    return gradient;
}

void TestFunction::body(const vector<double> &x) const
{
    double t=0.0;
    for (int i=0; i<dimension;i++)
    {
        t +=x[i]*x[i];
    }
    Result = t;
}

#include <numeric>
#include <algorithm>
int main(int argc, char*argv[])
{

    /*
    TestFunction f(2000);
    CGSolver solver(f);
    solver.randomRestart();
    Timer timer;
    timer.start();
    for (int i=0; i<1000; i++)
    {
        solver.next();
        vector<double> best = solver.getSolution();
    }
    cerr << timer.getElapsedTimeInMicroSec() << "[ms]" << endl;
*/
    vector<int> nn(1E6);
    vector<int> xx(1E6);
    for (unsigned int i=0; i<1E6; ++i)
        nn[i] = xx[i] = i;

    Timer timer;
    timer.start();
    double t1,t2;
    double tt = std::inner_product(nn.begin(), nn.end(), xx.begin(),0.0);
    t1 = timer.getElapsedTimeInMicroSec();

    timer.start();
    double dot = 0;
    for (unsigned int i=0; i<1E6; ++i)
        dot +=nn[i] * xx[i];
    t2 = timer.getElapsedTimeInMicroSec();
    cerr << t1 << " " << t2 << " " <<  tt << dot << endl;


    return 0;

}

