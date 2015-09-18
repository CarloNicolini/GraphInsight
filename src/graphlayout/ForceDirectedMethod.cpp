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

#include "ForceDirectedMethod.h"
#include "LayoutOptions.h"


/**
  @ingroup GraphLayout
    @brief Initialize the static variables needed to proceed to a new layout step, copies current positions of nodes to old positions and update displacements
    @param g GraphLayout pointer to work on
    @param dimension Number of dimension to initialize
**/
void ForceDirectedMethod::InitializeStep(GraphLayout *g, int dimension)
{
    // Record old displacements
    for (NodesRand::const_iterator iter1=g->nodesRand.begin(); iter1!=g->nodesRand.end(); ++iter1)
    {
        LNode *n1 = (static_cast<LNode*>(*iter1));
        n1->oldDx=n1->dx;
        n1->oldDy=n1->dy;
        n1->oldDz=n1->dz;

        n1->dx = 0;
        n1->dy = 0;
        n1->dz = 0;
    }
}

/**
  @ingroup GraphLayout
    @brief Compute and apply LinLog repulsion to a pair of nodes
    @param n1 node 1
    @param n2 node 2
    @param repStrength repulsion strength of the model
    @param dimension Number of dimension to initialize
**/
void ForceDirectedMethod::LinLogRepulsion(LNode *n1, LNode *n2, double repStrength, int dimension)
{
    if (n1==n2)
        return;
    else
    {
        double k= repStrength*(1.0+n1->degree)*( 1.0+ n2->degree)/(SQR(n1->px - n2->px)+SQR(n1->py-n2->py)+int(dimension==3)*SQR(n1->pz - n2->pz)+1E-9);

        n1->dx += (n1->px-n2->px)*k;
        n1->dy += (n1->py-n2->py)*k;
        if (dimension==2) return;
        n1->dz += (n1->pz-n2->pz)*k;
    }
}

/**
  @ingroup GraphLayout
    @brief Compute and apply FruchtermanReingold repulsion to a pair of nodes
    @param n1 node 1
    @param n2 node 2
    @param repStrenght repulsion strength of the model
    @param dimension Number of dimension to initialize
**/

void ForceDirectedMethod::FruchtermanReingoldRepulsion(LNode *n1, LNode *n2, double repStrenght, int dimension)
{
    if (n1==n2)
        return;
    else
    {
        double dx = n1->px-n2->px,dy = n1->py-n2->py,dz=n1->pz-n2->pz;
        // Si potrebbe mettere la radice quadrata alla distanza per avere un'altro tipo di repulsione, preferisco senza, è più veloce e da layout più belli
        double k= 1.0/(SQR(dx)+SQR(dy)+int(dimension==3)*SQR(dz)+1E-9);
        n1->dx += k*(dx);
        n1->dy += k*(dy);
        if (dimension==2) return;
        n1->dz += k*(dz);
    }
}

/**
  @ingroup GraphLayout
    @brief Compute and apply FruchtermanReingold Proportional repulsion to a pair of nodes
    @param n1 node 1
    @param n2 node 2
    @param dimension Number of dimension to initialize
**/
void ForceDirectedMethod::FruchtermanReingoldProportionalRepulsion(LNode *n1, LNode *n2, int dimension)
{
    if (n1==n2)
        return;
    else
    {
        double dx = n1->px-n2->px,dy = n1->py-n2->py,dz=n1->pz-n2->pz;
        //double degreeFactor = (1.0+n1->degree)*( 1.0+ n2->degree);
        // Si potrebbe mettere la radice quadrata alla distanza per avere un'altro tipo di repulsione, preferisco senza, è più veloce e da layout più belli
        double k= (1.0+n1->degree)*( 1.0+ n2->degree)/(SQR(dx)+SQR(dy)+int(dimension==3)*SQR(dz)+1E-9);

        //double c = degreeFactor/d2;
        n1->dx += k*(dx);
        n1->dy += k*(dy);
        if (dimension==2) return;
        n1->dz += k*(dz);
    }
}

/**
  @ingroup GraphLayout
    @brief Compute and apply FruchtermanReingold Proportional repulsion to a pair of nodes, considering no overlap (infinite force within a given radius)
    @param n1 node 1
    @param n2 node 2
    @param dimension Number of dimension to initialize
**/
void ForceDirectedMethod::FruchtermanReingoldProportionalRepulsionNoOverlap(LNode *n1, LNode *n2, int dimension)
{
    if (n1==n2)
        return;
    else
    {
        double dx = n1->px-n2->px,dy = n1->py-n2->py,dz=n1->pz-n2->pz;
        double d = sqrt(SQR(dx)+SQR(dy)+int(dimension==3)*SQR(dz)+1E-9);
        double doverlap = (d-n1->logDegree- n2->logDegree);
        if (doverlap>0)
        {
            //double degreeFactor = (1.0+n1->degree)*( 1.0+ n2->degree);
            double k= (1.0+n1->degree)*( 1.0+ n2->degree)/(doverlap);

            //double c = degreeFactor/d2;
            n1->dx += k*(dx);
            n1->dy += k*(dy);
            if (dimension==2) return;
            n1->dz += k*(dz);
        }
        else //means overlap
        {
            n1->dx += (1.0+n1->degree)*( 1.0+ n2->degree)*(dx);
            n1->dy += (1.0+n1->degree)*( 1.0+ n2->degree)*(dy);
            if (dimension==2) return;
            n1->dz +=(1.0+n1->degree)*( 1.0+ n2->degree)*(dz)/d;
        }
    }
}

/**
  @ingroup GraphLayout
    @brief Compute and apply LinLog attraction to a pair of nodes
    @param n1 node 1
    @param n2 node 2
    @param attrStrenght attraction strength of the model
    @param dimension Number of dimension to initialize
**/
void ForceDirectedMethod::LinLogAttraction(LNode *n1, LNode *n2, double attrStrenght, int dimension)
{
    if (n1==n2)
        return;
    else
    {
        double dx=n1->px - n2->px, dy=n1->py - n2->py, dz = n1->pz - n2->pz;
        double d2= SQR(dx)+SQR(dy)+int(dimension==3)*SQR(dz)+1E-9;
        double k = log(1+sqrt(d2));//attrStrenght/sqrt(d2);

        n1->dx -= k*(dx);
        n2->dx += k*(dx);

        n1->dy -= k*(dy);
        n2->dy += k*(dy);

        if (dimension==2)
            return;
        n1->dz -= k*(dz);
        n2->dz += k*(dz);
    }
}

/**
  @ingroup GraphLayout
    @brief Compute and apply Fruchterman Reingold attraction to a pair of nodes
    @param n1 node 1
    @param n2 node 2
    @param dimension Number of dimension to initialize
**/
void ForceDirectedMethod::FruchtermanReingoldAttraction(LNode *n1, LNode *n2, int dimension)
{
    if ( n1==n2 )
        return;
    else
    {
        double dx=n1->px - n2->px, dy=n1->py - n2->py, dz = n1->pz - n2->pz;
        double d2= SQR(dx)+SQR(dy)+int(dimension==3)*SQR(dz);
        double d=0.01*sqrt(d2);

        dx*=d;
        dy*=d;

        n1->dx -=  dx ;
        n1->dy -=  dy ;
        n2->dx += dx ;
        n2->dy += dy ;
        if (dimension==2)
            return;
        dz*=d;
        n1->dz -= dz;
        n2->dz += dz ;
    }
}

/**
  @ingroup GraphLayout
    @brief Compute and apply FruchtermanReingold attraction to a pair of nodes
    @param n1 node 1
    @param n2 node 2
    @param e Edge to consider the weight
    @param dimension Number of dimension to initialize
**/
void ForceDirectedMethod::FruchtermanReingoldProportionalAttraction(LNode *n1, LNode *n2, Edge *e, int dimension)
{
    if ( n1==n2 )
        return;
    else
    {
        double weight = e->weight;
        double degreeFactor = abs(1+n1->degree);
        double dx=n1->px - n2->px, dy=n1->py - n2->py, dz = n1->pz - n2->pz;
        double d2= SQR(dx)+SQR(dy)+int(dimension==3)*SQR(dz);
        double d=sqrt(d2);
        double c = 0.01*weight*d/degreeFactor;

        if (c<0)
            return;

        n1->dx -= dx*c ;
        n1->dy -= dy*c ;

        n2->dx += dx*c ;
        n2->dy += dy*c ;
        if (dimension==2)
            return;
        n1->dz  -= dz*c ;
        n2->dz += dz*c ;
    }
}

/**
  @ingroup GraphLayout
    @brief Compute and apply Fruchterman Reingold attraction to a pair of nodes, considering no overlap model
    @param n1 node 1
    @param n2 node 2
    @param e Edge to consider the weight
    @param dimension Number of dimension to initialize
**/
void ForceDirectedMethod::FruchtermanReingoldProportionalAttractionNoOverlap(LNode *n1, LNode *n2, Edge *e, int dimension)
{
    if ( n1==n2 )
        return;
    else
    {
        double weight = e->weight;
        double degreeFactor = abs(1+n1->degree);
        double dx=n1->px - n2->px, dy=n1->py - n2->py, dz = n1->pz - n2->pz;
        double d2= SQR(dx)+SQR(dy)+int(dimension==3)*SQR(dz);
        double d=sqrt(d2);
        double c = 0.01*weight*d/degreeFactor;

        if (c<0)
            return;
        if (d - n1->logDegree - n2->logDegree > 0)
        {
            n1->dx -= dx*c ;
            n1->dy -= dy*c ;

            n2->dx += dx*c ;
            n2->dy += dy*c ;
            if (dimension==2)
                return;
            n1->dz  -= dz*c ;
            n2->dz += dz*c ;
        }
        else //means overlap
        {
            return;
        }
    }
}

/**
  @ingroup GraphLayout
    @brief Apply the displacement step at the end of every call of GraphLayout::steps
    @param g GraphLayout pointer
    @param gravity The gravity to use
    @param speed The speed factor. Higher speed makes convergence faster but less precise.
    @param dimension Number of dimension of the layout
    @param preventNodeOverlap True if you want to prevent node overlap
    @param gravityWeight A multiplicative factor for gravity field
    @param maxRise Max increment of speed of a node when displaced
    @param softneningFactor A factor to reduce node swinging
**/
double ForceDirectedMethod::ApplyStep(GraphLayout *g, double gravity, double speed, int dimension,bool preventNodeOverlap, bool gravityWeight, double maxRise, double softneningFactor)
{
    double totalSwinging=0.0,totalEffectiveTraction=0.0;
    double optimality=0.0;
    double jitterTolerance = getJitterTolerance(g->statsNodesCount);

    // Apply speed and gravity
    for (NodesRand::const_iterator iter1=g->nodesRand.begin(); iter1!=g->nodesRand.end(); ++iter1)
    {  LNode*n1 = (static_cast<LNode*>(*iter1));
        double d2=SQR(n1->px)+SQR(n1->py)+ int(dimension==3)*SQR(n1->pz);
        double d= sqrt(d2);
        if (d>0 && gravity>0 && g->countConnectedComponents()>0 )
        {
            double dGravity=gravity/d;
            if (gravityWeight)
                dGravity*=(n1->logDegree+1);

            n1->dx -=  speed*dGravity*n1->px;
            n1->dy -=  speed*dGravity*n1->py;
            n1->dz -=  speed*dGravity*n1->pz;
        }

        double swinging = std::sqrt(SQR(n1->oldDx-n1->dx)+SQR(n1->oldDy-n1->dy)+ int(dimension==3)*SQR(n1->oldDz - n1->dz));
        totalSwinging += (n1->degree+1) * swinging;   // If the node has a burst change of direction, then it's not converging.
        totalEffectiveTraction += (n1->degree+1) * 0.5 * sqrt(SQR(n1->oldDx + n1->dx) + SQR(n1->oldDy + n1->dy)+ int(dimension==3)*SQR(n1->oldDz + n1->dz));
    }
    // We want that swingingMovement < tolerance * convergenceMovement
    double targetSpeed =   SQR(jitterTolerance)* totalEffectiveTraction / totalSwinging;
    // But the speed shoudn't rise too much too quickly, since it would make the convergence drop dramatically.

    // Max rise suggested by Gephi is  50% we keep it higher
    speed = speed + std::min(targetSpeed - speed, maxRise * speed);

    // XXX modify softening factor to 0.5  when the graph swings (graphs with high degree nodes w.r.t. other nodes)
    // Seems that 0.1 can be a good factor, but slows down computations
    //double totswing=0.0;
    for (NodesRand::const_iterator iter1=g->nodesRand.begin(); iter1!=g->nodesRand.end(); ++iter1)
    {  LNode *n1=(static_cast<LNode*>(*iter1));
        // Adaptive auto-speed: the speed of each node is lowered
        // when the node swings.
        double swinging = std::sqrt(SQR(n1->oldDx - n1->dx) + SQR(n1->oldDy - n1->dy)+  int(dimension==3)*SQR(n1->oldDz - n1->dz) );
        //totswing+=swinging;
        double factor= softneningFactor*speed / (1.0 + speed * std::sqrt(swinging));
        // the 0.5 factor is important to prevent MEGA swinging of nodes with very very high degree;
        if (preventNodeOverlap)
        {
            double df = sqrt(SQR(n1->dx ) + SQR(n1->dy));
            factor = std::min(factor * df, 10.) / df;
        }
        n1->px += n1->dx*factor;
        n1->py += n1->dy*factor;
        n1->pz += n1->dz*factor;

        optimality += SQR(n1->dx*factor)+SQR(n1->dy*factor)+ int(dimension==3)*SQR(n1->dz*factor);
    }
    optimality/=SQR(g->statsNodesCount);
    //totswing/=SQR(g->statsNodesCount); no need of this assignment (see cppcheck)

    static DaisyFilter* filter1 = (DaisyFilter::MovingAverageFilter(10));
    static int nstep=0;

    double filteredOptimality = filter1->Calculate(optimality);
    //cout << optimality << "\t" << filteredOptimality << endl;
    if (nstep++<10)
        return  optimality;
    else
        return  filteredOptimality;
}

/**
  @ingroup GraphLayout
  @brief A stepwise function to get the tolerance to swinging of nodes when applying displacemente steps
  The values are set empirically
  @param nodesCount Total number of graph nodes
**/
double ForceDirectedMethod::getJitterTolerance(int nodesCount)
{  // Performance
    if (nodesCount >= 50000)
    {  return 10;
    }
    else if (nodesCount >= 5000)
    {  return 1;
    }
    else
    {  return 0.1;
    }
}

