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

#ifndef _BarnesHutQuadtree_H
#define _BarnesHutQuadtree_H
#include <vector>
#include <Eigen/Core>
#include <stdexcept>

#include "BarnesHutTree.h"
#include "LNode.h"
#include "GraphLayout.h"

using namespace std;
using namespace Eigen;

/**
*  @class BarnesHutQuadtree
*  @ingroup GraphLayout
*  @brief This class helps to divide recursively the Euclidean plane in order to make faster calculation.
* The scheme of force calculation is the one adopted in Barnes-Hut seminal paper on galactic force calculation as explained in their Nature.
**/
class BarnesHutQuadtree : public BarnesHutTree
{
public:
    /**
     * @brief The Quadrant enum Contains the quadrant as an integer in NorthEast quadrant = 0, NorthWest = 1, South West = 2, South East = 3
     */
    enum Quadrant
    {  NE = 0,
        NW = 1,
        SW = 2,
        SE = 3
    };

    BarnesHutQuadtree(GraphLayout *g);
    BarnesHutQuadtree(const Vector2d &xymin, const Vector2d &xymax, BarnesHutQuadtree *parent=NULL);
    ~BarnesHutQuadtree();

    bool isRoot();
    bool isExternal();

    void insert(LNode *n, int level);
    Quadrant getQuadrant(double x,double y);
    BarnesHutQuadtree *createQuadNode(Quadrant quad);

    void computeMassDistribution();

    Vector2d calculateForceFR(LNode *n);
    Vector2d calculateForceFRProp(LNode *n);
    Vector2d calculateForceLinLog(LNode *n,double repStrength);
    void writeNode(int quad, int level);

private:
    BarnesHutQuadtree *parent;
    BarnesHutQuadtree *quadNode[4];
    double mass;
    Vector2d cm; //center of mass
    Vector2d xymin,xymax,center;  //lower left corner, upper right corner
    int nparticles;   // number of LNodes inside this leaf


    static double theta;
    static double epsilon;
    static vector<LNode*> renegades;


    inline Vector2d calculateAccelerationFR(LNode *n1, LNode *n2);
    inline Vector2d calculateAccelerationFRProp(LNode *n1, LNode *n2);
    inline Vector2d calculateAccelerationLinLog(LNode *n1, LNode *n2);
    inline Vector2d calculateAccelerationBinaryStress(LNode *n1, LNode *n2, double radius);

    inline Vector2d calculateTreeForceFR(LNode *n);
    inline Vector2d calculateTreeForceFRProp(LNode *n);
    inline Vector2d calculateTreeForceLinLog(LNode *n);

    LNode particle;
    static int quadtreelevel;
    static const int maxTreeLevel=10;

    // This is needed to keep fixed size vectorizable objects Eigen-compatible
public:
    EIGEN_MAKE_ALIGNED_OPERATOR_NEW

};

#endif
