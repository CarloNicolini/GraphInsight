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


#ifndef LMRandom_H
#define LMRandom_H

#include "LayoutMethod.h"
/**
@ingroup GraphLayout
@class LMRandom
@brief LMRandom set the nodes coordinates in random position in [-10,10]
**/
class LMRandom : public LayoutMethod
{
public:


   LMRandom() ;
   ~LMRandom();
   void init(GraphLayout *gl, int nDimensions);
   int steps(int n);


};

#endif


