/****************************************************************************
**
** Copyright (C) 2010 Carlo Nicolini (nicolini.carlo@gmail.com)
** All rights reserved.
**
** Warning: This program is protected by copyright law and international
** treaties. Unauthorized reproduction and distribution of this program,
** or any portion of it, may result in severe civil and criminal penalties,
** and will be persecuted to the maximum extent possible under the law.
**
****************************************************************************/


#ifndef LMCircular_H
#define LMCircular_H

#include "LayoutMethod.h"

using namespace std;

/**
@ingroup GraphLayout
@class LMCircular
@brief Layout nodes along a circle, it doesn't try to optimize edge lengths or similar, just linear displacement of nodes. Inner nodes have higher degree, outer nodes lower degree.
When used in 3D it puts nodes connected component as 3rd coordinate, producing an helicoidal layout.
**/
class LMCircular : public LayoutMethod
{
public:

   GraphLayout* g;
   LMCircular() ;
   ~LMCircular();
   void init(GraphLayout *gl, int _nDimensions);
   int steps(int n);

   double gravity;

   unsigned int nstepsDone;
   int nDimensions;

};

#endif


