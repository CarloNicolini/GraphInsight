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


#ifndef LMBinaryStressMultilevel_H
#define LMBinaryStressMultilevel_H

#include "LayoutMethod.h"
#include "LMBinaryStress.h"

/**
@ingroup GraphLayout
@class LMBinaryStressMultilevel
@brief Implements a multilevel version of LMBinaryStress, inspired from Y.Koren paper
**/
class LMBinaryStressMultilevel : public LayoutMethod
{
public:
   LMBinaryStressMultilevel();
   ~LMBinaryStressMultilevel();

   void init(GraphLayout *g, int nDim);
   int steps(int n);


   GraphLayout *actualGraph;
private:

   GraphLayout *g;

   vector <GraphLayout *> coarsenedGraphs;

   int nodesThreshold;   //threshold on nodes number
   int n;          // number of graph nodes
   int deeperLevel;    // deeper level of coarsening
   int actualLevel;
   int totalSteps;
   int oldLevel;
   bool goToNextLevel;
   bool optimumReached;
   int nDimensions;
   double gradientNorm;

   void interpolatePositions(void);
   LMBinaryStress *lm2;

   void interpolatePositions(GraphLayout *coarseGraph);
};

#endif  /* LMBinaryStressMultilevel_H */


