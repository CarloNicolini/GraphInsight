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


#ifndef LMFORCEDIRECTED_H_
#define LMFORCEDIRECTED_H_

#include "LNode.h"
#include "LayoutMethod.h"
#include "GraphLayout.h"
#include "BarnesHutQuadtree.h"
#include "BarnesHutOctree.h"

#include "DaisyFilter.h"
#include <memory>

/**
* @ingroup GraphLayout
* @brief The ForceDirectedMethod class contains calls to static inline member functions to be used inside layout methods.
*/
namespace ForceDirectedMethod
{
//public:
// Prepare steps and finalize step
void InitializeStep(GraphLayout *g,int dimension);
double ApplyStep(GraphLayout *g, double gravity, double speed, int dimension, bool nodeOverlap=false, bool gravityWeight=false, double maxRise=0.5, double softeningFactor=0.1);

// Repulsive Forces
void FruchtermanReingoldRepulsion(LNode *n1, LNode *n2, double repStrenght, int dimension);
void LinLogRepulsion(LNode *n1, LNode *n2, double repStrenght, int dimension );
void FruchtermanReingoldProportionalRepulsion(LNode *n1, LNode *n2, int dimension);
void FruchtermanReingoldProportionalRepulsionNoOverlap(LNode *n1, LNode *n2, int dimension);

// Attraction forces
void LinLogAttraction(LNode *n1, LNode *n2, double attrStrenght, int dimension);
void FruchtermanReingoldAttraction(LNode *n1, LNode *n2, int dimension);
void FruchtermanReingoldProportionalAttraction(LNode *n1, LNode *n2, Edge *e, int dimension);
void FruchtermanReingoldProportionalAttractionNoOverlap(LNode *n1, LNode *n2, Edge *e, int dimension);

// Get the Jitter tolerance dependent on number of graph nodes
double getJitterTolerance(int nodesCount);

}

#endif  /* ForceDirectedMethod */


