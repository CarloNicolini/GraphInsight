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


#include <vector>
#include <cmath>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <Eigen/Core>

#include "FKamadaKawai3D.h"
#include "Graph.h"
#include "Common.h"

using namespace std;
using namespace Eigen;

const double FKamadaKawai3D::GradientNorm = 1e-4;

/**
@ingroup GraphLayout
Constructor of Kamada Kawai cost function object
@param G GraphLayout object, set the dimension of the problem to be 3*number of nodes for a 2D layout
**/
FKamadaKawai3D::FKamadaKawai3D( Graph *G)
{
    dimension=3*G->nodes.size();
    gradient.reserve(dimension);
    gradient.assign(dimension,0.0);
    g=G;
    /// Set the all-pair shortest path matrix used for the model
    DEBUG_PRINT( "Kamada-Kawai3D " << dimension << " dimensions" );

    nnodes=g->nodes.size();
    nedges=g->getEdgesCount();

    //length= ((GraphLayout*) g)->getAverageLength()*nedges;
    length=13.2*nedges;
    if (g->countConnectedComponents() > 1)
    {
        // here we assume that ((GraphLayout*) g)->getAverageLength()=13.2 ( justified by examples )
        length=13.2*nedges;
        limit=(length)/((double)nedges+sqrt((double)nnodes)+1.);
        limit*=sqrt(limit);
    }
    else
        limit=numeric_limits<double>::max();

}

/**
@ingroup GraphLayout
Get the gradient of the Kamada Kawai layout model by reference
*  @param x current vector of nodes position x, passed by reference
*  x is composed of alternating x1,y1,x2,y2,...,xN,yN positions of nodes with index starting from 0 to N-1
* @return The current gradient
**/
const vector<double> &FKamadaKawai3D::getGradient(const vector <double> &x)
{
    const Eigen::MatrixXd &SP = g->getShortestPathMatrix();
    double attr=0;
    for (NodesRand::const_iterator iter1=g->nodesRand.begin(); iter1!=g->nodesRand.end(); ++iter1)
    {
        Node *n1 = (*iter1);
        unsigned int i = (n1->index -1)*3;
        gradient[i]=gradient[i+1]=gradient[i+2]=0.0;
        for (NodesRand::const_iterator iter2=g->nodesRand.begin(); iter2!=g->nodesRand.end(); ++iter2)
        {  if (iter1==iter2)
                continue;
            Node *n2 = (*iter2);
            unsigned int j = (n2->index -1 )*3;
            double path = std::max(std::min(SP.coeffRef(n1->index-1, n2->index-1),limit),1E-3);
            double dx =(x[i] -x[j]);
            double dy = (x[i+1] -x[j+1]);
            double dz = (x[i+2] -x[j+2]);

            double d = sqrt(dx*dx+dy*dy+dz*dz);
            double dpath2=path*path*d;
            double nn = 2*(d-path)/dpath2;
            gradient[i]     +=  nn * dx ;
            gradient[i+1]   +=  nn * dy ;
            gradient[i+2]   +=  nn * dz ;
            attr +=  SQR( path-d )/(path*path);
        }
    }

    energy=attr;

    return gradient;
}

/**
  @ingroup GraphLayout
   The body of the Kamada Kawai cost function for GraphLayout layout
   @param x is composed of alternating x1,y1,x2,y2,...,xN,yN positions of nodes with index starting from 0 to N-1
**/
void FKamadaKawai3D::body(const vector<double> &x) const
{
    double attr=0.0;
    const Eigen::MatrixXd &SP = g->getShortestPathMatrix();

    for (NodesRand::const_iterator iter1=g->nodesRand.begin(); iter1!=g->nodesRand.end(); ++iter1)
    {
        Node *n1 = (*iter1);
        unsigned int i = (n1->index -1)*3;
        for (NodesRand::const_iterator iter2=iter1; iter2!=g->nodesRand.end(); ++iter2)
        {  if (iter1==iter2 )
                continue;
            Node *n2 = (*iter2);
            unsigned int j = (n2->index -1 )*3;
            double path = std::max( std::min(SP.coeffRef(n1->index-1, n2->index-1),limit),1E-3);
            double d = sqrt((x[i] -x[j])*(x[i] - x[j])+(x[i+1] -x[j+1])*(x[i+1] - x[j+1])+ (x[i+2] -x[j+2])*(x[i+2] - x[j+2]));
            attr +=  SQR( path-d )/(path*path);
        }
    }
    Result = attr;
}

/**
  @ingroup GraphLayout
  Destructor, does nothing
  **/

FKamadaKawai3D::~FKamadaKawai3D()
{
}

/**
  @ingroup GraphLayout
  Sets the gravity central force for the model
**/
void FKamadaKawai3D::setGravity(double factor)
{  double oldLimit = (length)/((double)nedges+sqrt((double)nnodes)+1.);
    oldLimit*=sqrt(oldLimit);
    if (factor==0.0)
        limit=oldLimit;
    else
        limit=oldLimit-10*factor;

}

