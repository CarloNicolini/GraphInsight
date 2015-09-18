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

#ifndef LMFruchtermanReingoldProportionalMultilevel_H
#define LMFruchtermanReingoldProportionalMultilevel_H
#include "LMFruchtermanReingoldProportional.h"
#include "LayoutMethod.h"
#include "LMFruchtermanReingold.h"

/**
*  @ingroup GraphLayout
*    @class LMFruchtermanReingoldProportionalMultilevel
*    @brief LMFruchtermanReingoldProportionalMultilevel is the implementation of the Fruchterman-Reingold layout method with a modification of energy function to make cluster more visible but in its multilevel flavour
*   This implementation has some advantages on the seminal proposed implementation, it switchs automatically to O(nlog(n)) force calculation method when graphs are too big.
* It resembles the Force Atlas layout method in Gephi
**/
class LMFruchtermanReingoldProportionalMultilevel : public LayoutMethod
{
public:
   LMFruchtermanReingoldProportionalMultilevel();
   ~LMFruchtermanReingoldProportionalMultilevel();

   void init(GraphLayout *g, int nDim);
   int steps(int n);

protected:
   GraphLayout *g;

   vector <GraphLayout *> coarsenedGraphs;
   int coarseningLevel;

   int nDimensions;
   double gradientNorm;
   void interpolatePositions(void);
   LMFruchtermanReingoldProportional *lm2;


};

#endif  /* LMFruchtermanReingoldProportionalMultilevel_H */


