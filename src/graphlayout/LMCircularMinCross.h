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


#ifndef LMCircularMinCross_H
#define LMCircularMinCross_H

#include "LayoutMethod.h"

using namespace std;

/**
@ingroup GraphLayout
@class LMCircularMinCross
@brief Layout nodes along a circle, trying to minimize the edge length using an heuristic approach given in
"Improved Circular Layouts" of Emden R. Gansner and Yehuda Koren.
**/

enum DispositionMethod
{
    LinearArray=0,
    SquareArray=1,
    OnCircle=2,
    SpaceFilling=3
};

class LMCircularMinCross : public LayoutMethod
{
public:

   GraphLayout* g;
   LMCircularMinCross() ;
   ~LMCircularMinCross();
   void init(GraphLayout *gl, int _nDimensions);
   int steps(int n);

   double gravity;
   vector< NodesRand > subgraphs;
   unsigned int nstepsDone;
   int nDimensions;
private:
    std::pair<Vector2d,Vector2d> subplacementOfComponents(DispositionMethod method, vector<NodesRand> &subgraphs);
    int singletonNodes;
};

#endif


