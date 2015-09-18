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


#ifndef LMTreeLayout_H
#define LMTreeLayout_H

#include "LayoutMethod.h"

using namespace std;

/**
@ingroup GraphLayout
@class LMTreeLayout
@brief Layout the graph with using the Kaufmann and Wiese heuristic.

**/
class LMTreeLayout : public LayoutMethod
{
public:

    GraphLayout* g;
    LMTreeLayout() ;
    ~LMTreeLayout();
    void init(GraphLayout *gl, int _nDimensions);
    int steps(int n);

    double gravity;

    unsigned int nstepsDone;
    int nDimensions;

};

bool sortByDegree(Node* n1, Node *n2)
{
    return n1->degree > n2->degree;
}

#endif


