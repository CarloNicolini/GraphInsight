/****************************************************************************
**
** Copyright (C) 2012 Carlo Nicolini (nicolini.carlo@gmail.com)
** All rights reserved.
**
** Warning: This program is protected by copyright law and international
** treaties. Unauthorized reproduction and distribution of this program,
** or any portion of it, may result in severe civil and criminal penalties,
** and will be persecuted to the maximum extent possible under the law.
**
****************************************************************************/

#ifndef _DISJOINT_SET_H_
#define _DISJOINT_SET_H_
#include <map>
#include "Graph.h"

/**
 * @ingroup GraphLayout
 * @class DisjointSet
 * @brief an implementation of a Union-find data structure for disjoint set. See Sedgewick Introduction to algorithms book for details
 */
class DisjointSet
{
private:
    std::map<int,int> id;     // access to component id (site indexed)

public:
    DisjointSet(int N);
    DisjointSet(Graph *g);

    bool connected(int p, int q);
    int find(int p);
    void merge(int p, int q);

    int count;    // number of components
};

#endif
