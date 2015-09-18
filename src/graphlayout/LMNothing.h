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


#ifndef LMNothing_H
#define LMNothing_H

#include "LayoutMethod.h"

/**
*  @ingroup GraphLayout
*  @class LMNothing
*  @brief It makes nothing on graph but is needed to switch 2D to 3D or viceversa
**/
class LMNothing : public LayoutMethod
{
public:


   LMNothing() ;
   ~LMNothing();
   void init(GraphLayout *gl, int nDimensions);
   int steps(int n);


};

#endif


