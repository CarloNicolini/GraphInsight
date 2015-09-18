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

#include "BarnesHutQuadtree.h"

double BarnesHutQuadtree::theta = 0.99;
double BarnesHutQuadtree::epsilon = 1E-6;
int BarnesHutQuadtree::quadtreelevel=0;
vector<LNode*> BarnesHutQuadtree::renegades;

/**
*  @ingroup GraphLayout
* Constructor of a 2D  BarnesHut quadtree from a GraphLayout pointer, it sets the boundaries of the graph node coordinates and build the recursive space subdivision
**/
BarnesHutQuadtree::BarnesHutQuadtree(GraphLayout *g) :
    mass(0),
    cm(Vector2d::Zero()),
    xymin(Vector2d::Zero()),
    xymax(Vector2d::Zero()),
    center(Vector2d::Zero()),
    nparticles(0),
    parent(NULL)
{

    double xmax=std::numeric_limits<double>::min(),xmin=std::numeric_limits<double>::max(), ymax=std::numeric_limits<double>::min(), ymin=std::numeric_limits<double>::max();
    LNode *n1=NULL;

    for (NodesRand::const_iterator iter1 = g->nodesRand.begin(); iter1 != g->nodesRand.end(); ++iter1)
    {   n1=static_cast<LNode*>(*iter1);
        xmax = std::max(xmax,n1->px);
        xmin = std::min(xmin,n1->px);

        ymax = std::max(ymax,n1->py);
        ymin = std::min(ymin,n1->py);
    }

    xymin << xmin , ymin ;
    xymax << xmax  ,ymax ;

    center << xymin.coeffRef(0)+( xymax.coeffRef(0)-xymin.coeffRef(0) )*0.5, xymin.coeffRef(1)+( xymax.coeffRef(1) - xymin.coeffRef(1))*0.5;

    quadNode[0]=quadNode[1]=quadNode[2]=quadNode[3]=NULL;

    for (NodesRand::const_iterator iter1 = g->nodesRand.begin(); iter1 != g->nodesRand.end(); ++iter1)
    {   n1=static_cast<LNode*>(*iter1);
        this->insert(n1,0);
    }

    renegades.clear();
    this->computeMassDistribution();
}

/**
*  @ingroup GraphLayout
* Constructor of a 2D  BarnesHut quadtree from a 2 extremal edges of a rectangle, it sets the boundaries of the graph node coordinates and build the recursive space subdivision
* @param _xymin extremal point of rectangle
* @param _xymax other extremal point of rectangle
* @param _parent Parent node in the tree
**/
BarnesHutQuadtree::BarnesHutQuadtree(const Vector2d &_xymin, const Vector2d &_xymax, BarnesHutQuadtree *_parent) :
    mass(0),
    cm(Vector2d::Zero()),
    xymin(_xymin),
    xymax(_xymax),
    center(Vector2d::Zero()),
    nparticles(0),
    parent(_parent)
{
    center = xymin + (xymax-xymin)*0.5;
    quadNode[0]=quadNode[1]=quadNode[2]=quadNode[3]=NULL;
    ++quadtreelevel;
}

/**
*  @ingroup GraphLayout
@return True if this leaf is the root
**/
bool BarnesHutQuadtree::isRoot()
{   return parent==NULL;
}
/**
*  @ingroup GraphLayout
@return True if this leaf is an external leaf
**/
bool BarnesHutQuadtree::isExternal()
{   return quadNode[0]==NULL &&
            quadNode[1]==NULL &&
            quadNode[2]==NULL &&
            quadNode[3]==NULL;
}

/**
*  @ingroup GraphLayout
* @brief Get the quadrant identifier of a given 2D  point with x,y coordinates
* @param x x position of a node
* @param y y position of a node
**/
BarnesHutQuadtree::Quadrant BarnesHutQuadtree::getQuadrant(double x, double y)
{
    if (x<=center.coeffRef(0) )
    {
        if (y<=center.coeffRef(1))
            return SW;
        else
            return NW;
    }
    else
    {
        if (y<=center.coeffRef(1))
            return SE;
        else
            return NE;
    }
}
/**
*  @ingroup GraphLayout
* @brief Create an quad node (not to be confused with graph node, here nodes are the elements of the tree) in this structure, putting in the selected quadrant
* @param quad quadrant where to insert the node
**/
BarnesHutQuadtree* BarnesHutQuadtree::createQuadNode(Quadrant quad)
{
    switch (quad)
    {
    case SW:
        return new BarnesHutQuadtree(xymin, center, this);
        break;
    case NW:
        return new BarnesHutQuadtree(Vector2d(xymin.coeffRef(0), center.coeffRef(1)),
                                     Vector2d(center.coeffRef(0), xymax.coeffRef(1)),
                                     this);
        break;
    case NE:
        return new BarnesHutQuadtree(center, xymax, this);
        break;
    case SE:
        return new BarnesHutQuadtree(Vector2d(center.coeffRef(0), xymin.coeffRef(1)),
                                     Vector2d(xymax.coeffRef(0), center.coeffRef(1)),
                                     this);
        break;
    default:
    {
        std::stringstream ss;
        ss << "Can't determine quadrant in BarnesHutQuadtree::createQuadNode !\n";
        ss << "quadMin   : " << "(" << xymin.coeffRef(0)    << ", " << xymin.coeffRef(1)    << ")\n"
           << "quadMax   : " << "(" << xymax.coeffRef(1)    << ", " << xymax.coeffRef(1)    << ")\n"
           << "quadCenter: " << "(" << center.coeffRef(0) << ", " << center.coeffRef(1) << ")\n";

        throw std::runtime_error(ss.str().c_str());
    }
    }
}

/**
*  @ingroup GraphLayout
* @brief Compute the mass distribution in recursive fashion with O(log(depth)) cost
**/
void BarnesHutQuadtree::computeMassDistribution()
{
    if (nparticles==1)
    {
        cm << particle.px, particle.py ;
        mass=1;
    }
    else
    {   mass = 0;
        cm.setZero();
        for (int i=0; i<4; i++)
        {   if (quadNode[i])
            {   quadNode[i]->computeMassDistribution();
                mass += quadNode[i]->mass;
                cm += quadNode[i]->cm*quadNode[i]->mass;
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
* @return The 2 components FruchtermanReingold acceleration
**/
Vector2d BarnesHutQuadtree::calculateAccelerationFR(LNode *n1, LNode *n2)
{   if (n1 ==n2)
    {
        return Vector2d::Zero();
    }

    double d2= (SQR(n1->px - n2->px)+SQR(n1->py-n2->py))+epsilon;

    double k = 1.0/d2;

    return Vector2d(k*(n1->px - n2->px), k*(n1->py - n2->py));
}

/**
*  @ingroup GraphLayout
* @brief Calculate the acceleration due to a pair of graph nodes with Fruchterman Reingold Proportional model recurring in depth over the tree
* @param n1 Node 1
* @param n2 Node 2
* @return The 2 components FruchtermanReingold Proportional acceleration
**/
Vector2d BarnesHutQuadtree::calculateAccelerationFRProp(LNode *n1, LNode *n2)
{   if (n1 ==n2)
    {
        return Vector2d::Zero();
    }

    double d2= (SQR(n1->px - n2->px)+SQR(n1->py-n2->py))+epsilon;

    double k = (n1->degree+1)/d2;

    return Vector2d(k*(n1->px - n2->px), k*(n1->py - n2->py));
}

/**
*  @ingroup GraphLayout
* @brief Calculate the acceleration due to a pair of graph nodes with LinLog model recurring in depth over the tree
* @param n1 Node 1
* @param n2 Node 2
* @return The 2 components FruchtermanReingold acceleration
**/
Vector2d BarnesHutQuadtree::calculateAccelerationLinLog(LNode *n1, LNode *n2)
{   if (n1 == n2 )
    {
        return Vector2d::Zero();
    }

    double d2= (SQR(n1->px - n2->px)+SQR(n1->py-n2->py))+epsilon;
    return Vector2d(n1->px - n2->px, n1->py - n2->py)/d2;
}

/**
*  @ingroup GraphLayout
* @brief Calculate the force exerted on a node from all other nodes with Fruchterman-Reingold model recurring in depth over the tree
* This method also includes possible renegades node not present in the space decomposition
* @param n1 Node 1
* @return The 2 components Fruchterman-Reingold force
**/
Vector2d BarnesHutQuadtree::calculateForceFR(LNode *n1)
{
    Vector2d acc = calculateTreeForceFR(n1);
    if (!renegades.empty())
    {
        size_t totrenegades = renegades.size();
        cerr << "renegades= " << totrenegades  << endl;

        for (std::size_t i=0; i<totrenegades; i++)
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
* @return The 2 components Fruchterman-Reingold Proportional force
**/
Vector2d BarnesHutQuadtree::calculateForceFRProp(LNode *n1)
{
    Vector2d acc = calculateTreeForceFRProp(n1);
    if (!renegades.empty())
    {
        size_t totrenegades = renegades.size();
        cerr << "renegades= " << totrenegades  << endl;

        for (std::size_t i=0; i<totrenegades; i++)
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
* @param repStrenght Repulsion strenght of the model
* @return The 2 components Lin-Log force
**/
Vector2d BarnesHutQuadtree::calculateForceLinLog(LNode *n1, double repStrenght)
{
    Vector2d acc = Vector2d::Zero();
    if (!renegades.empty())
    {
        size_t totrenegades = renegades.size();
        for (std::size_t i=0; i<totrenegades; ++i)
        {   Vector2d renacc = calculateAccelerationLinLog(n1, renegades[i]);
            acc+=renacc;
        }
    }

    return calculateTreeForceLinLog(n1);
}

/**
*  @ingroup GraphLayout
* @brief Calculate the force exerted on a node from all other nodes with Fruchterman-Reingold model recurring in depth over the tree
* @param n1 Node 1
* @return The 2 components Fruchterman-Reingold force
**/
Vector2d BarnesHutQuadtree::calculateTreeForceFR(LNode *n1)
{
    Vector2d acc = Vector2d::Zero();
    double r2 = SQR(n1->px - cm.coeffRef(0) ) +  SQR(n1->py - cm.coeffRef(1) );

    double cellSize2 = SQR(xymax.coeffRef(0)-xymin.coeffRef(0));
    particle.px = cm.coeffRef(0);
    particle.py = cm.coeffRef(1);

    if ( cellSize2 <=  theta*theta*r2) // a faster way to evaluate d/r <= theta is to compute d^2 <= (theta*r)^2
        acc = (this->mass)*calculateAccelerationFR(n1,&particle);
    else
    {   for (int q=0; q<4; q++)  // for all child nodes
        {   if (quadNode[q]) // if node exists
                acc+=quadNode[q]->calculateTreeForceFR(n1);
        }
    }
    return acc;
}

/**
*  @ingroup GraphLayout
* @brief Calculate the force exerted on a node from all other nodes with Fruchterman-Reingold Proportional model recurring in depth over the tree
* @param n1 Node 1
* @return The 2 components Fruchterman-Reingold Proportional force
**/

Vector2d BarnesHutQuadtree::calculateTreeForceFRProp(LNode *n1)
{
    Vector2d acc = Vector2d::Zero();
    double r2 = SQR(n1->px - cm.coeffRef(0) ) +  SQR(n1->py - cm.coeffRef(1) );
    //double d2 = SQR( std::max(xymax.coeffRef(0) - xymin.coeffRef(0),xymax.coeffRef(1) - xymin.coeffRef(1)) ) ;
     double  cellSize2 = SQR(xymax.coeffRef(0)-xymin.coeffRef(0));
    particle.px = cm.coeffRef(0);
    particle.py = cm.coeffRef(1);

    if ( cellSize2 <=  theta*theta*r2) // a faster way to evaluate d/r <= theta is to compute d^2 <= (theta*r)^2
        acc = (this->mass)*calculateAccelerationFRProp(n1,&particle);
    else
    {   for (int q=0; q<4; q++)  // for all child nodes
        {   if (quadNode[q]) // if node exists
                acc+=quadNode[q]->calculateTreeForceFRProp(n1);
        }
    }
    return acc;
}

/**
*  @ingroup GraphLayout
* @brief Calculate the force exerted on a node from all other nodes with LinLog model recurring in depth over the tree
* @param n1 Node 1
* @return The 2 components LinLog Proportional force
**/
Vector2d BarnesHutQuadtree::calculateTreeForceLinLog(LNode *n1)
{
    Vector2d acc = Vector2d::Zero();
    double r2 = SQR(n1->px - cm.coeffRef(0) ) +  SQR(n1->py - cm.coeffRef(1) );
    //double d2 = SQR( std::max(xymax.coeffRef(0) - xymin.coeffRef(0),xymax.coeffRef(1) - xymin.coeffRef(1)) ) ;
     double    cellSize2 = SQR(xymax.coeffRef(0)-xymin.coeffRef(0));
    particle.px = cm.coeffRef(0);
    particle.py = cm.coeffRef(1);

    if ( cellSize2 <=  theta*theta*r2) // a faster way to evaluate d/r <= theta is to compute d^2 <= (theta*r)^2
        acc = (this->mass)*calculateAccelerationLinLog(n1,&particle);
    else
    {   for (int q=0; q<4; q++)  // for all child nodes
        {   if (quadNode[q]) // if node exists
                acc+=quadNode[q]->calculateTreeForceLinLog(n1);
        }
    }
    return acc;
}

/**
  @ingroup GraphLayout
  @brief Save the node borders to standard output
  @param quad node quadrant
  @param level Level of depth
**/
void BarnesHutQuadtree::writeNode(int quad, int level)
{   cout << xymin.transpose()  << endl;
    cout << xymin.coeffRef(0) << " " << xymax.coeffRef(1) << endl;
    cout << endl << endl;

    cout << xymin.coeffRef(0) << " " << xymax.coeffRef(1) << endl;
    cout << xymax.transpose() << endl;
    cout << endl << endl;

    cout << xymax.transpose() << endl;
    cout << xymax.coeffRef(0) << " " << xymin.coeffRef(1) << endl;
    cout << endl << endl;

    cout << xymax.coeffRef(0) << " " << xymin.coeffRef(1) << endl;
    cout << xymin.transpose() << endl;
    cout << endl << endl;

    cerr << "Level= " << level << " Leaf= " << quad << " Nparticles= " << nparticles << " Inside mass= " << mass << endl;
    for (int i=0; i<4; i++)
    {   if (quadNode[i])
        {   quadNode[i]->writeNode(i, level+1);
        }
    }
}

/**
*  @ingroup GraphLayout
*   @brief Insert a graph node inside the quadtree at given level
* @param n1 Graph node to insert
* @param level Depth level of the quadtree
**/
void BarnesHutQuadtree::insert(LNode *n1, int level)
{
#ifdef DEBUG
    /*
    if (n1->px < xymin.coeffRef(0) || n1->px > xymax.coeffRef(0) || n1->py < xymin.coeffRef(1) || n1->py > xymax.coeffRef(1) )
    {   cerr << "Particle position (" << n1->px << ", " << n1->py << ")" << " is outside" << endl;
        cerr << "Inserting node " << n1->id << " in leaf " << this << " Quadrant: " << this->getQuadrant(n1->px, n1->py) ;
        cerr <<  " depth= " << this->nparticles << " " << this-> mass << " " << this->cm.transpose() << endl;
    }
    */
#endif

    if (nparticles==0)
    {   particle.px = n1->px;
        particle.py = n1->py;
        particle.degree = n1->degree;
        mass = 1;
    }
    if (nparticles==1)
    {
        // There is already a particle
        // subdivide the node and relocate that particle
        Quadrant quad = getQuadrant(particle.px, particle.py);
        if ( quadNode[quad]==NULL )
        {
            quadNode[quad]=createQuadNode(quad);
        quadNode[quad]->insert(&particle,level+1);
        }
        particle.px = particle.py = 0;
        quad = getQuadrant(n1->px, n1->py);
        if ( !quadNode[quad] )
        {
            quadNode[quad]=createQuadNode(quad);
        quadNode[quad]->insert(n1,level+1);
        }
    }
    if (nparticles>1)
    {   Quadrant quad = getQuadrant(n1->px, n1->py);
        if ( !quadNode[quad] )
        {   quadNode[quad] = createQuadNode(quad);
        }
        quadNode[quad]->insert(n1,level+1);
    }
    nparticles++;
}

/**
* @ingroup GraphLayout
* @brief BarnesHutQuadtree destructor, it clears all the newed memory, it is recursively called when destroying the object on every node and leaf
**/
BarnesHutQuadtree::~BarnesHutQuadtree()
{   for (int i=0; i<4; i++)
    {   delete quadNode[i];
        quadNode[i]=NULL;
    }
    renegades.clear();
    --quadtreelevel;
}
