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

#ifndef LMFruchtermanReingoldMultilevel_H
#define LMFruchtermanReingoldMultilevel_H
#include "LMFruchtermanReingold.h"
#include "LayoutMethod.h"

/**
*  @ingroup GraphLayout
*    @class LMFruchtermanReingoldMultilevel
*    @brief LMFruchtermanReingoldMultilevel is the implementation of the Fruchterman-Reingold layout method with a multilevel paradigm.
*    It's one of the fastest layout method and may be used for huge graphs.
**/
class LMFruchtermanReingoldMultilevel : public LayoutMethod
{
public:
   LMFruchtermanReingoldMultilevel();
   ~LMFruchtermanReingoldMultilevel();

   void init(GraphLayout *g, int nDim);
   int steps(int n);

protected:
   GraphLayout *g;

   vector <GraphLayout *> coarsenedGraphs;
   int coarseningLevel;

   int nDimensions;
   double gradientNorm;
   void interpolatePositions(void);
   LMFruchtermanReingold *lm2;

};

#endif  /* LMFruchtermanReingoldMultilevel_H */


