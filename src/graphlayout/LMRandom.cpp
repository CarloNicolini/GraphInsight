/****************************************************************************
**
** Copyright (C) 2010 Michele Dallachiesa (michele.dallachiesa@gmail.com)
** All rights reserved.
**
** Warning: This program is protected by copyright law and international
** treaties. Unauthorized reproduction and distribution of this program,
** or any portion of it, may result in severe civil and criminal penalties,
** and will be persecuted to the maximum extent possible under the law.
**
****************************************************************************/


#include "LMRandom.h"
#include "GraphLayout.h"

using namespace std;

/**
 * @ingroup GraphLayout
 * @brief LMRandom::LMRandom
 */
LMRandom::LMRandom()
{
    DEBUG_PRINT("LMRandom constructor");
}

/**
 * @ingroup GraphLayout
 * @brief LMRandom::~LMRandom
 */
LMRandom::~LMRandom()
{
        DEBUG_PRINT("LMRandom destructor");
}

/**
 * @brief LMRandom::init Init the node coordinates in random interval (see GraphLayout::initRandomCoordinates() )
 * @param gl
 * @param nDimensions
 */
void LMRandom::init(GraphLayout *gl, int nDimensions)
{

   gl->initRandomCoordinates();
}

/**
 * @brief LMRandom::steps Make a step, i.e. makes nothing
 * @param n
 * @return Always 1
 */
int LMRandom::steps(int n)
{  return 1;
}
