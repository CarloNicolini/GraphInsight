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

#ifndef _BarnesHutOctree_H
#define _BarnesHutOctree_H
#include <vector>
#include <Eigen/Core>

#include <stdexcept>
#include "BarnesHutTree.h"
#include "LNode.h"
#include "GraphLayout.h"

using namespace std;
using namespace Eigen;

/**
*  @class BarnesHutOctree
*  @ingroup GraphLayout
*  @brief This class helps to divide recursively the Euclidean space in order to make faster calculation.
* The scheme of force calculation is the one adopted in Barnes-Hut seminal paper on galactic force calculation as explained in their Nature.
**/
class BarnesHutOctree : public BarnesHutTree
{
public:

    enum Octant
    {  NTE = 0,
        NTW,
        STW,
        STE,
        NDE ,
        NDW,
        SDW,
        SDE,
        NONE
    };

    BarnesHutOctree(GraphLayout *g);
    BarnesHutOctree(const Vector3d &xyzmin, const Vector3d &xyzmax, BarnesHutOctree *parent=NULL);
    ~BarnesHutOctree();

    bool isRoot();
    bool isExternal();

    void insert(LNode *n, int level);
    Octant getOctant(double x,double y,double z);
    BarnesHutOctree *createOctNode(Octant quad);

    void computeMassDistribution();
    Vector3d calculateForceFR(LNode *n);
    Vector3d calculateForceFRProp(LNode *n);
    Vector3d calculateForceLinLog(LNode *n, double repstrength);
    void writeNode(int quad, int level);

private:
    BarnesHutOctree *parent;
    BarnesHutOctree *octNode[8];
    double mass;
    Vector3d cm; //center of mass
    Vector3d xyzmin,xyzmax,center;   //lower left corner, upper right corner
    int nparticles;   // number of LNodes inside this leaf

    static double theta;
    static double epsilon;
    static vector<LNode*> renegades;

    Vector3d calculateAccelerationFR(LNode *n1, LNode *n2);
    Vector3d calculateAccelerationFRProp(LNode *n1, LNode *n2);
    Vector3d calculateAccelerationLinLog(LNode *n1, LNode *n2);

    Vector3d calculateTreeForceFR(LNode *n);
    Vector3d calculateTreeForceFRProp(LNode *n);
    Vector3d calculateTreeForceLinLog(LNode *n);

    LNode particle;

    // This is needed to keep fixed size vectorizable objects Eigen-compatible
public:
    EIGEN_MAKE_ALIGNED_OPERATOR_NEW
};

#endif
