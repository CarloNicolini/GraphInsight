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

#ifndef _BarnesHutTree_H
#define _BarnesHutTree_H
#include <vector>
#include <Eigen/Core>
#include <stdexcept>
#include "BarnesHutTree.h"

#include "GraphLayout.h"

using namespace std;
using namespace Eigen;

/**
@ingroup GraphLayout
@class BarnesHutTree
@brief Base class for tree recursive decomposition of space
The crucial idea in speeding up the brute force n-body algorithm is to group nearby bodies and approximate them as a single body.
If the group is sufficiently far away, we can approximate its gravitational effects by using its center of mass.
The center of mass of a group of bodies is the average position of a body in that group, weighted by mass.
The Barnes-Hut algorithm is a clever scheme for grouping together bodies that are sufficiently nearby. It recursively divides the set of bodies into groups by storing them in a quad-tree. A quad-tree is similar to a binary tree, except that each node has 4 children (some of which may be empty). Each node represents a region of the two dimensional space.
See http://arborjs.org/docs/barnes-hut for further informations
**/
class BarnesHutTree 
{
public:
};

#endif
