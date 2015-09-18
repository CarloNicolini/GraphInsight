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


#include "LMNothing.h"
#include "GraphLayout.h"

using namespace std;

/**
 * @ingroup GraphLayout
 * @brief LMNothing::LMNothing
 */
LMNothing::LMNothing()
{
}

/**
 * @ingroup GraphLayout
 * @brief LMNothing::~LMNothing
 */
LMNothing::~LMNothing()
{
}

/**
 * @ingroup GraphLayout
 * @brief LMNothing::init Does nothing
 * @param gl
 * @param nDimensions
 */
void LMNothing::init(GraphLayout *gl, int nDimensions)
{

}

/**
 * @ingroup GraphLayout
 * @brief LMNothing::steps
 * @param n
 * @return
 */
int LMNothing::steps(int n)
{  return 1;
}


