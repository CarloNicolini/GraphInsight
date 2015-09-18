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

#include "BarnesHutOctree.h"

double BarnesHutOctree::theta = 0.99;
double BarnesHutOctree::epsilon = 1E-6;
vector<LNode*> BarnesHutOctree::renegades;

/**
*  @ingroup GraphLayout
* Constructor of a 3D BarnesHut octree from a GraphLayout pointer, it sets the boundaries of the graph node coordinates and build the recursive space subdivision
**/
BarnesHutOctree::BarnesHutOctree(GraphLayout *g) :
    parent(NULL),
    mass(0.0),
    cm(Vector3d::Zero()),
    xyzmin(Vector3d::Zero()),
    xyzmax(Vector3d::Zero()),
    center(Vector3d::Zero()),
    nparticles(0)
{
    double   xmax=std::numeric_limits<double>::min(),
            xmin=std::numeric_limits<double>::max(),
            ymax=std::numeric_limits<double>::min(),
            ymin=std::numeric_limits<double>::max(),
            zmin=std::numeric_limits<double>::max(),
            zmax=std::numeric_limits<double>::min();

    LNode *n1=NULL;
    for (NodesRand::const_iterator iter1 = g->nodesRand.begin(); iter1 != g->nodesRand.end(); ++iter1)
    {   n1=static_cast<LNode*>(*iter1);
        xmax = std::max(xmax,n1->px);
        xmin = std::min(xmin,n1->px);

        ymax = std::max(ymax,n1->py);
        ymin = std::min(ymin,n1->py);

        zmax = std::max(zmax,n1->pz);
        zmin = std::min(zmin,n1->pz);
    }

    xyzmin << xmin , ymin, zmin ;
    xyzmax << xmax  ,ymax, zmax ;

    center  = xyzmin + (xyzmax-xyzmin)*0.5;

    for (int i=0; i<8; ++i)
        octNode[i]=NULL;

    for (NodesRand::const_iterator iter1 = g->nodesRand.begin(); iter1 != g->nodesRand.end(); ++iter1)
    {   n1=static_cast<LNode*>(*iter1);
        this->insert(n1,0);
    }

    this->computeMassDistribution();
    renegades.clear();
}

/**
*  @ingroup GraphLayout
* Constructor of a 3D BarnesHut octree from a 2 extremal edges of a parallelepiped, it sets the boundaries of the graph node coordinates and build the recursive space subdivision
* @param _xyzmin extremal point of parallelepiped
* @param _xyzmax other extremal point of parallelepiped
* @param _parent Parent node in the tree
**/
BarnesHutOctree::BarnesHutOctree(const Vector3d &_xyzmin, const Vector3d &_xyzmax, BarnesHutOctree *_parent) :
    parent(_parent),
    mass(0.0),
    cm(Vector3d::Zero()),
    xyzmin(_xyzmin),
    xyzmax(_xyzmax),
    nparticles(0)
{

    center  = xyzmin + (xyzmax-xyzmin)*0.5;
    for (int i=0; i<8; ++i)
        octNode[i]=NULL;
}


/**
*  @ingroup GraphLayout
@return True if this leaf is the root
**/
bool BarnesHutOctree::isRoot()
{   return parent==NULL;
}

/**
*  @ingroup GraphLayout
@return True if this leaf is an external leaf
**/
bool BarnesHutOctree::isExternal()
{   return octNode[0]==NULL &&
            octNode[1]==NULL &&
            octNode[2]==NULL &&
            octNode[3]==NULL &&
            octNode[4]==NULL &&
            octNode[5]==NULL &&
            octNode[6]==NULL &&
            octNode[7]==NULL ;
}

/**
*  @ingroup GraphLayout
* @brief Get the octant identifier of a given 3D point with x,y,z coordinates
* @param x x position of a node
* @param y y position of a node
* @param z z position of a node
**/
BarnesHutOctree::Octant BarnesHutOctree::getOctant(double x, double y, double z)
{   if (z >= center.coeffRef(2))
    {   if (x<=center.coeffRef(0) && y<=center.coeffRef(1))
        {   return STW;
        }
        else if (x<=center.coeffRef(0) && y>center.coeffRef(1))
        {   return NTW;
        }
        else if (x>center.coeffRef(0) && y>=center.coeffRef(1))
        {   return NTE;
        }
        else if (x>center.coeffRef(0) && y<center.coeffRef(1))
        {   return STE;
        }
        else if (x>xyzmax.coeffRef(0) || y>xyzmax.coeffRef(1) || x<xyzmin.coeffRef(0) || y<xyzmin.coeffRef(1) )
        {   std::stringstream ss;
            ss << "Can't determine octrant!\n"
               << "particle  : " << "(" << x          << ", " << y          << ")\n"
               << "quadMin   : " << "(" << xyzmin.coeffRef(0)    << ", " << xyzmin.coeffRef(1)    << ")\n"
               << "quadMax   : " << "(" << xyzmax.coeffRef(1)    << ", " << xyzmax.coeffRef(1)    << ")\n"
               << "quadCenter: " << "(" << center.coeffRef(0) << ", " << center.coeffRef(1) << ")\n";
            throw std::runtime_error(ss.str().c_str());
        }
        else
        {   throw std::runtime_error("Can't determine octrant!");
        }
    }
    else// if (z < center.coeffRef(2) )
    {   if (x<=center.coeffRef(0) && y<=center.coeffRef(1))
        {   return SDW;
        }
        else if (x<=center.coeffRef(0) && y>center.coeffRef(1))
        {   return NDW;
        }
        else if (x>center.coeffRef(0) && y>=center.coeffRef(1))
        {   return NDE;
        }
        else if (x>center.coeffRef(0) && y<center.coeffRef(1))
        {   return SDE;
        }
        else if (x>xyzmax.coeffRef(0) || y>xyzmax.coeffRef(1) || x<xyzmin.coeffRef(0) || y<xyzmin.coeffRef(1) )
        {   std::stringstream ss;
            ss << "Can't determine octant!\n"
               << "particle  : " << "(" << x          << ", " << y          << ")\n"
               << "quadMin   : " << "(" << xyzmin.coeffRef(0)    << ", " << xyzmin.coeffRef(1)    << ")\n"
               << "quadMax   : " << "(" << xyzmax.coeffRef(1)    << ", " << xyzmax.coeffRef(1)    << ")\n"
               << "quadCenter: " << "(" << center.coeffRef(0) << ", " << center.coeffRef(1) << ")\n";
            throw std::runtime_error(ss.str().c_str());
        }
        else
        {   throw std::runtime_error("Can't determine octant!");
        }
    }
}

/**
*  @ingroup GraphLayout
* @brief Create an oct node (not to be confused with graph node, here nodes are the elements of the tree) in this structure, putting in the selected octant
* @param oct Octant where to insert the node
**/
BarnesHutOctree* BarnesHutOctree::createOctNode(Octant oct)
{   switch (oct)
    {
    case STW:
        return new BarnesHutOctree( Vector3d(xyzmin.coeffRef(0),xyzmin.coeffRef(1),center.coeffRef(2)), Vector3d(center.coeffRef(0),center.coeffRef(1),xyzmax.coeffRef(2)) , this);
        break;
    case NTW:
        return new BarnesHutOctree( Vector3d(xyzmin.coeffRef(0),center.coeffRef(1),xyzmin.coeffRef(2)) , Vector3d(center.coeffRef(0),xyzmax.coeffRef(1),center.coeffRef(2)), this);
        break;
    case NTE:
        return new BarnesHutOctree( Vector3d(center.coeffRef(0),center.coeffRef(1),center.coeffRef(2) ) , Vector3d(xyzmax.coeffRef(0),xyzmax.coeffRef(1),xyzmax.coeffRef(2) ) , this);   // OK
        break;
    case STE:
        return new BarnesHutOctree( Vector3d(center.coeffRef(0),xyzmin.coeffRef(1),center.coeffRef(2)), Vector3d(xyzmax.coeffRef(0),center.coeffRef(1),xyzmax.coeffRef(2) ), this);
        break;
    case SDW:
        return new BarnesHutOctree( Vector3d(xyzmin.coeffRef(0),xyzmin.coeffRef(1),xyzmin.coeffRef(2) ), Vector3d(center.coeffRef(0), center.coeffRef(1), center.coeffRef(2) ), this); // OK
        break;
    case NDW:
        return new BarnesHutOctree( Vector3d(xyzmin.coeffRef(0), center.coeffRef(1) ,center.coeffRef(2) ), Vector3d(center.coeffRef(0),xyzmax.coeffRef(1),xyzmax.coeffRef(2) ), this);
        break;
    case NDE:
        return new BarnesHutOctree( Vector3d(center.coeffRef(0),center.coeffRef(1),xyzmin.coeffRef(2)) , Vector3d(xyzmax.coeffRef(0),xyzmax.coeffRef(1),center.coeffRef(2) ) , this);
        break;
    case SDE:
        return new BarnesHutOctree( Vector3d(center.coeffRef(0),xyzmin.coeffRef(1),xyzmin.coeffRef(2) ), Vector3d(xyzmax.coeffRef(0),center.coeffRef(1),center.coeffRef(2) ), this);
        break;

    default:
    {   std::stringstream ss;
        ss << "Can't determine octrant!\n";
        ss << "quadMin   : " << "(" << xyzmin.coeffRef(0)    << ", " << xyzmin.coeffRef(1)    << ")\n"
           << "quadMax   : " << "(" << xyzmax.coeffRef(1)    << ", " << xyzmax.coeffRef(1)    << ")\n"
           << "quadCenter: " << "(" << center.coeffRef(0) << ", " << center.coeffRef(1) << ")\n";

        throw std::runtime_error(ss.str().c_str());
    }
    }
}

/**
*  @ingroup GraphLayout
* @brief Compute the mass distribution in recursive fashion with O(log(depth)) cost
**/
void BarnesHutOctree::computeMassDistribution()
{   if (nparticles==1)
    {
        cm << particle.px, particle.py ,particle.pz;
        mass=1;
    }
    else
    {   mass = 0;
        cm.setZero();
        for (int i=0; i<8; ++i)
        {   if (octNode[i])
            {   octNode[i]->computeMassDistribution();
                mass += octNode[i]->mass;
                cm += octNode[i]->cm*octNode[i]->mass;
            }
        }
        cm /=( this->mass);
    }
}

/**
*  @ingroup GraphLayout
* @brief Calculate the acceleration due to a pair of graph nodes with Fruchterman Reingold model recurring in depth over the tree
* @param n1 Node 1
* @param n2 Node 2
* @return The 3 component FruchtermanReingold acceleration
**/
Vector3d BarnesHutOctree::calculateAccelerationFR(LNode *n1, LNode *n2)
{   if (n1 ==n2 )
    {
        return Vector3d::Zero();
    }

    double d2= SQR(n1->px - n2->px)+SQR(n1->py-n2->py)+SQR(n1->pz-n2->pz)+epsilon;
    double c  = 1.0/d2;

    Vector3d acc( ( n1->px - n2->px), ( n1->py - n2->py), ( n1->pz - n2->pz) ) ;
    acc*=c;
    return acc;
}

/**
*  @ingroup GraphLayout
* @brief Calculate the acceleration due to a pair of graph nodes with Fruchterman Reingold Proportional model recurring in depth over the tree
* @param n1 Node 1
* @param n2 Node 2
* @return The 3 component FruchtermanReingold Proportional acceleration
**/
Vector3d BarnesHutOctree::calculateAccelerationFRProp(LNode *n1, LNode *n2)
{   if (n1 ==n2 )
    {
        return Vector3d::Zero();
    }

    double d2= SQR(n1->px - n2->px)+SQR(n1->py-n2->py)+SQR(n1->pz-n2->pz)+epsilon;
    double c  = (n2->degree+1.0)/d2;

    Vector3d acc( ( n1->px - n2->px), ( n1->py - n2->py), ( n1->pz - n2->pz) ) ;
    acc*=c;
    return acc;
}

/**
*  @ingroup GraphLayout
* @brief Calculate the acceleration due to a pair of graph nodes with LinLog model recurring in depth over the tree
* @param n1 Node 1
* @param n2 Node 2
* @return The 3 component FruchtermanReingold acceleration
**/
Vector3d BarnesHutOctree::calculateAccelerationLinLog(LNode *n1, LNode *n2)
{   if (n1==n2)
    {   return Vector3d::Zero();
    }

    double d2= SQR(n1->px - n2->px)+SQR(n1->py-n2->py)+SQR(n1->pz-n2->pz)+epsilon;

    Vector3d acc( ( n1->px - n2->px), ( n1->py - n2->py), ( n1->pz - n2->pz) ) ;
    acc/=d2;
    return acc;
}

/**
*  @ingroup GraphLayout
* @brief Calculate the force exerted on a node from all other nodes with Fruchterman-Reingold model recurring in depth over the tree
* This method also includes possible renegades node not present in the space decomposition
* @param n1 Node 1
* @return The 3 component Fruchterman-Reingold force
**/
Vector3d BarnesHutOctree::calculateForceFR(LNode *n1)
{
    Vector3d acc = calculateTreeForceFR(n1);
    if (!renegades.empty())
    {   size_t totrenegades = renegades.size();
        for (std::size_t i=0; i<totrenegades; ++i)
        {   acc+=calculateAccelerationFR(n1, renegades[i]);
        }
    }
    return acc;
}


/**
*  @ingroup GraphLayout
* @brief Calculate the force exerted on a node from all other nodes with Fruchterman-Reingold Proportional model recurring in depth over the tree
* This method also includes possible renegades node not present in the space decomposition
* @param n1 Node 1
* @return The 3 component Fruchterman-Reingold Proportional force
**/
Vector3d BarnesHutOctree::calculateForceFRProp(LNode *n1)
{
    Vector3d acc = calculateTreeForceFRProp(n1);
    if (!renegades.empty())
    {   size_t totrenegades = renegades.size();
        for (std::size_t i=0; i<totrenegades; ++i)
        {   acc+=calculateAccelerationFRProp(n1, renegades[i]);
        }
    }
    return acc;
}

/**
*  @ingroup GraphLayout
* @brief Calculate the force exerted on a node from all other nodes with Lin-Log model recurring in depth over the tree
* This method also includes possible renegades node not present in the space decomposition
* @param n1 Node 1
* @param repstrength Repulsion strenght of the model
* @return The 3 component Lin-Log force
**/
Vector3d BarnesHutOctree::calculateForceLinLog(LNode *n1, double repstrength)
{
    Vector3d acc = calculateTreeForceLinLog(n1);
    if (!renegades.empty())
    {   size_t totrenegades = renegades.size();
        for (std::size_t i=0; i<totrenegades; ++i)
        {   Vector3d renacc = calculateAccelerationLinLog(n1, renegades[i]);
            acc+=repstrength*renacc;
        }
    }

    return acc;
}

/**
*  @ingroup GraphLayout
* @brief Calculate the force exerted on a node from all other nodes with Fruchterman-Reingold model recurring in depth over the tree
* @param n1 Node 1
* @return The 3 component Fruchterman-Reingold force
**/
Vector3d BarnesHutOctree::calculateTreeForceFR(LNode *n1)
{
    Vector3d acc = Vector3d::Zero();
    double r2 = SQR(n1->px - cm.coeffRef(0) ) +  SQR(n1->py - cm.coeffRef(1) ) + SQR(n1->pz - cm.coeffRef(2) );
    double cellsize2 = SQR(xyzmax.coeffRef(0)-xyzmin.coeffRef(0));

    particle.px = cm.coeffRef(0);
    particle.py = cm.coeffRef(1);
    particle.pz = cm.coeffRef(2);

    if ( cellsize2 <=  (theta*theta)*r2 )
        acc = (this->mass)*calculateAccelerationFR(n1,&particle);
    else
    {   for (int q=0; q<8; ++q)  // for all child nodes
        {   if (octNode[q]) // if node exists
                acc+=octNode[q]->calculateTreeForceFR(n1);
        }
    }
    return acc;
}

/**
*  @ingroup GraphLayout
* @brief Calculate the force exerted on a node from all other nodes with Fruchterman-Reingold Proportional model recurring in depth over the tree
* @param n1 Node 1
* @return The 3 component Fruchterman-Reingold Proportional force
**/
Vector3d BarnesHutOctree::calculateTreeForceFRProp(LNode *n1)
{
    Vector3d acc = Vector3d::Zero();
    double r2 = SQR(n1->px - cm.coeffRef(0) ) +  SQR(n1->py - cm.coeffRef(1) ) + SQR(n1->pz - cm.coeffRef(2) );
    double cellsize2 = SQR(xyzmax.coeffRef(0)-xyzmin.coeffRef(0));

    particle.px = cm.coeffRef(0);
    particle.py = cm.coeffRef(1);
    particle.pz = cm.coeffRef(2);

    if ( cellsize2 <=  (theta*theta)*r2 )
        acc = (this->mass)*calculateAccelerationFRProp(n1,&particle);
    else
    {   for (int q=0; q<8; ++q)  // for all child nodes
        {   if (octNode[q]) // if node exists
                acc+=octNode[q]->calculateTreeForceFRProp(n1);
        }
    }
    return acc;
}

/**
*  @ingroup GraphLayout
* @brief Calculate the force exerted on a node from all other nodes with LinLog model recurring in depth over the tree
* @param n1 Node 1
* @return The 3 component LinLog Proportional force
**/
Vector3d BarnesHutOctree::calculateTreeForceLinLog(LNode *n1)
{
    Vector3d acc = Vector3d::Zero();
    double r2 = SQR(n1->px - cm.coeffRef(0) ) +  SQR(n1->py - cm.coeffRef(1) ) +  SQR(n1->pz - cm.coeffRef(2) );
    double cellsize2 = SQR(xyzmax.coeffRef(0)-xyzmin.coeffRef(0));
    particle.px = cm.coeffRef(0);
    particle.py = cm.coeffRef(1);
    particle.pz = cm.coeffRef(2);

    if ( cellsize2 <=  theta*theta*r2) // a faster way to evaluate d/r <= theta is to compute d^2 <= (theta*r)^2
        acc = (this->mass)*calculateAccelerationLinLog(n1,&particle);
    else
    {   for (int q=0; q<8; ++q)  // for all child nodes
        {   if (octNode[q]) // if node exists
                acc+=octNode[q]->calculateTreeForceLinLog(n1);
        }
    }
    return acc;
}

/**
  @ingroup GraphLayout
  @brief Save the node borders to standard output
  @param oct Node octant
  @param level Level of depth
**/
void BarnesHutOctree::writeNode(int oct, int level)
{
    // Print the list of edges for debug purposes
    // Total of 12 edges for a cube
    cout << xyzmin.transpose()  << endl;
    cout << xyzmax.coeffRef(0) << " " << xyzmin.coeffRef(1) << " " <<  xyzmin.coeffRef(2) << endl;
    cout << endl << endl;

    cout << xyzmin.transpose() << endl;
    cout << xyzmin.coeffRef(0) << " " << xyzmin.coeffRef(1) << " " <<  xyzmax.coeffRef(2) << endl;
    cout << endl << endl;

    cout << xyzmin.transpose()  << endl;
    cout << xyzmin.coeffRef(0) << " " << xyzmax.coeffRef(1) << " " <<  xyzmin.coeffRef(2) << endl;
    cout << endl << endl;

    cout << xyzmax.transpose() << endl;
    cout << xyzmin.coeffRef(0) << " " << xyzmax.coeffRef(1) << " " <<  xyzmax.coeffRef(2) << endl;
    cout << endl << endl;

    cout << xyzmax.transpose() << endl;
    cout << xyzmax.coeffRef(0) << " " << xyzmax.coeffRef(1) << " " <<  xyzmin.coeffRef(2) << endl;
    cout << endl << endl;

    cout << xyzmax.transpose() << endl;
    cout << xyzmax.coeffRef(0) << " " << xyzmin.coeffRef(1) << " " <<  xyzmax.coeffRef(2) << endl;
    cout << endl << endl;

    cout << xyzmax.coeffRef(0) << " " << xyzmin.coeffRef(1) << " " <<  xyzmax.coeffRef(2) << endl;
    cout << xyzmax.coeffRef(0) << " " << xyzmin.coeffRef(1) << " " <<  xyzmin.coeffRef(2) << endl;
    cout << endl << endl;

    cout << xyzmax.coeffRef(0) << " " << xyzmin.coeffRef(1) << " " <<  xyzmax.coeffRef(2) << endl;
    cout << xyzmax.coeffRef(0) << " " << xyzmin.coeffRef(1) << " " <<  xyzmax.coeffRef(2) << endl;
    cout << endl << endl;

    cout << xyzmin.coeffRef(0) << " " << xyzmin.coeffRef(1) << " " <<  xyzmax.coeffRef(2) << endl;
    cout << xyzmax.coeffRef(0) << " " << xyzmin.coeffRef(1) << " " <<  xyzmax.coeffRef(2) << endl;
    cout << endl << endl;


    cout << xyzmax.coeffRef(0) << " " << xyzmin.coeffRef(1) << " " <<  xyzmin.coeffRef(2) << endl;
    cout << xyzmax.coeffRef(0) << " " << xyzmax.coeffRef(1) << " " <<  xyzmin.coeffRef(2) << endl;
    cout << endl << endl;


    cout << xyzmax.coeffRef(0) << " " << xyzmax.coeffRef(1) << " " <<  xyzmin.coeffRef(2) << endl;
    cout << xyzmin.coeffRef(0) << " " << xyzmax.coeffRef(1) << " " <<  xyzmin.coeffRef(2) << endl;
    cout << endl << endl;

    cout << xyzmin.coeffRef(0) << " " << xyzmax.coeffRef(1) << " " <<  xyzmin.coeffRef(2) << endl;
    cout << xyzmin.coeffRef(0) << " " << xyzmax.coeffRef(1) << " " <<  xyzmax.coeffRef(2) << endl;
    cout << endl << endl;

    cout << xyzmin.coeffRef(0) << " " << xyzmin.coeffRef(1) << " " <<  xyzmax.coeffRef(2) << endl;
    cout << xyzmin.coeffRef(0) << " " << xyzmax.coeffRef(1) << " " <<  xyzmax.coeffRef(2) << endl;
    cout << endl << endl;

    for (int i=0; i<8; ++i)
    {   if (octNode[i])
        {   octNode[i]->writeNode(i, level+1);
        }
    }
}

/**
*  @ingroup GraphLayout
*   @brief Insert a graph node inside the octree at given level
* @param n1 Graph node to insert
* @param level Depth level of the octree
**/
void BarnesHutOctree::insert(LNode *n1, int level)
{
    if (nparticles==0)
    {   particle.px = n1->px;
        particle.py = n1->py;
        particle.pz = n1->pz;
        particle.degree = n1->degree;
        mass = 1;
    }
    if (nparticles==1)
    {
        // There is already a particle
        // subdivide the node and relocate that particle

        Octant oct = getOctant(particle.px, particle.py, particle.pz);
        if ( octNode[oct]==NULL )
        {
            octNode[oct]=createOctNode(oct);
            octNode[oct]->insert(&particle,level+1);
        }

        particle.px = particle.py = particle.pz= 0;
        oct = getOctant(n1->px, n1->py, n1->pz);
        if ( !octNode[oct] )
        {
            octNode[oct]=createOctNode(oct);
            octNode[oct]->insert(n1,level+1);
        }
    }
    if (nparticles>1)
    {   Octant oct = getOctant(n1->px, n1->py, n1->pz);
        if ( !octNode[oct] )
        {   octNode[oct] = createOctNode(oct);
        }
        octNode[oct]->insert(n1,level+1);
    }
    ++nparticles;
}

/**
* @ingroup GraphLayout
* @brief BarnesHutOctree destructor, it clears all the newed memory, it is recursively called when destroying the object on every node and leaf
**/
BarnesHutOctree::~BarnesHutOctree()
{   for (int i=0; i<8; ++i)
    {   delete octNode[i];
        octNode[i]=NULL;
    }
    renegades.clear();
}
