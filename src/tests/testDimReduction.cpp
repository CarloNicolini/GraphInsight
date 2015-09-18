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

using namespace std;
using namespace Eigen;

int main(int argc, char*argv[])
{
    char* name = argv[1];

    int method = atoi(argv[2]);


    ifstream is(name);
    try
    {
        switch (method)
        {
        case 0:
        {
            RandomProjection r;
            r.loadObservationMatrix(is);
            r.getEmbedding() ;
        }
            break;
        case 1:
        {
            KernelPCA k;
            k.loadObservationMatrix(is);
            k.setParameters(1,GaussianKernel);
           cout << k.getEmbedding() << endl;
        }
            break;
        }
    }
    catch (std::exception &e)
    {
        cerr << e.what() << endl;
    }

    return 0;

}

