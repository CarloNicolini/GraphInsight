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

#ifndef LMLinLogModelsMultilevel_H
#define LMLinLogModelMultilevel_H
#include "LMLinLogModel.h"
#include "LayoutMethod.h"

/**
* @ingroup GraphLayout
* @class LMLinLogModelMultilevel
* @brief Lin Log model of force directed layout method in its multilevel flavour, has O(nlog(n)) force calculation when the graph is too big.
**/
class LMLinLogModelMultilevel : public LayoutMethod
{
public:
    LMLinLogModelMultilevel();
    ~LMLinLogModelMultilevel();

    void init(GraphLayout *g, int nDim);
    int steps(int n);

    GraphLayout *actualGraph;
private:

    GraphLayout *g;

    vector <GraphLayout *> coarsenedGraphs;
    int coarseningLevel;
    int nDimensions;
    double gradientNorm;
    void interpolatePositions(void);

    LMLinLogModel *lm2;

};

#endif  /* LMLinLogMultilevel_H */


