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


#include <cmath>
#include <stdio.h>
#include <iostream>
#include <fstream>

#include "FBinaryStress2D.h"
#include "Graph.h"
#include "LNode.h"
#include "Common.h"

using namespace std;

const double FBinaryStress2D::GradientNorm = 1e-4;

/**
  @ingroup GraphLayout
@param G Graph pointer, set the dimension of the problem to be 2*number of nodes for a 2D layout
**/
FBinaryStress2D::FBinaryStress2D( Graph *G)
{
    dimension=2*G->nodes.size();
    DEBUG_PRINT( "BinaryStress2D 2D " << dimension << " dimensions" );
    g=G;
    gradient.reserve(dimension);
    gradient.assign(dimension,0.0);
    c=100*g->statsNodesCount;
    c=1;
    gravity=1;
    radius=10.;
}

/**
    @ingroup GraphLayout
   Get the gradient of the binary stress layout model by copy
   @param x current vector of nodes position x, passed by reference
   x is composed of alternating x1,y1,x2,y2,...,xN,yN positions of nodes with index starting from 0 to N-1
   @return The current gradient
**/
const vector<double> &FBinaryStress2D::getGradient(const vector <double> &x)
{
    double attr=0, rep=0;
    // Repulsion between all nodes
    for (NodesRand::const_iterator iter1=g->nodesRand.begin(); iter1!=g->nodesRand.end(); ++iter1)
    {
        LNode* n1=(static_cast<LNode*>(*iter1));
        unsigned int i = (n1->index -1)*2;
        gradient[i]=gradient[i+1]=0.0;
        for (NodesRand::const_iterator iter2=g->nodesRand.begin(); iter2!=g->nodesRand.end(); ++iter2)
        {
            if (iter1==iter2)
                continue;
            LNode *n2 = (static_cast<LNode*>(*iter2));
            unsigned int j = (n2->index -1 )*2;
            double d= sqrt(SQR(x[i]-x[j])+SQR(x[i+1]-x[j+1]));
            double deltaD = (d-radius)/(d+1E-9);
            gradient[i] +=  2*(x[i]-x[j])*deltaD;
            gradient[i+1] +=  2*(x[i+1]-x[j+1])*deltaD;
            rep += (d-radius)*(d-radius);
        }
        gradient[i] *= c;
        gradient[i+1]*=c;
    }

    // Attraction between edges
    for (NodesRand::const_iterator iter1=g->nodesRand.begin(); iter1!=g->nodesRand.end(); ++iter1)
    {
        LNode* n1=(static_cast<LNode*>(*iter1));
        unsigned int i = (n1->index -1)*2;
        for(NeighborsRand::const_iterator iter2 = n1->neighborsRand.begin(); iter2 != n1->neighborsRand.end(); ++iter2)
        {
            LNode* n2 = static_cast<LNode*>((*iter2)->second);
            if (n1==n2)
                continue;
            unsigned int j = (n2->index-1)*2;
            gradient[i]   +=  2*(x[i]-x[j]);
            gradient[i+1] +=  2*(x[i+1]-x[j+1]);
            attr+= ( SQR(x[i]-x[j])+SQR(x[i+1]-x[j+1]) );
        }
    }

    energy = (attr + c*rep);
    return gradient;
}

/**
    @ingroup GraphLayout
   Value of the Fruchterman Reingold cost function for graph layout
   x is composed of alternating x1,y1,x2,y2,...,xN,yN positions of nodes with index starting from 0 to N-1
*/
void FBinaryStress2D::body(const vector<double> &x) const
{
    double attr=0,rep=0;

    for (NodesRand::const_iterator iter1=g->nodesRand.begin(); iter1!=g->nodesRand.end(); ++iter1)
    {  LNode* n1=(static_cast<LNode*>(*iter1));
        unsigned int i = (n1->index -1)*2;
        for (NodesRand::const_iterator iter2=iter1; iter2!=g->nodesRand.end(); ++iter2)
        {  if (iter1==iter2)
                continue;
            LNode *n2 = (static_cast<LNode*>(*iter2));
            unsigned int j = (n2->index -1 )*2;
            double d= sqrt(SQR(x[i]-x[j])+SQR(x[i+1]-x[j+1]));
            double deltaD = (d-radius);
            rep += deltaD*deltaD;
        }
    }

    for (NodesRand::const_iterator iter1=g->nodesRand.begin(); iter1!=g->nodesRand.end(); ++iter1)
    {  LNode* n1=static_cast<LNode*>(*iter1);
        unsigned i = (n1->index -1)*2;

        for(NeighborsRand::const_iterator iter2 = n1->neighborsRand.begin(); iter2 != n1->neighborsRand.end(); ++iter2)
        {
            LNode* n2 = static_cast<LNode*>((*iter2)->second);
            if (n1==n2)
                continue;
            unsigned int j = (n2->index-1)*2;
            attr+= (SQR(x[i]-x[j])+SQR(x[i+1]-x[j+1]));
        }
    }

    Result = (attr + c*rep);
}

/**
    @ingroup GraphLayout
   Free all the space required by vectors
**/
FBinaryStress2D::~FBinaryStress2D()
{  gradient.clear();
}

/**
    @ingroup GraphLayout
   Set the central gravity force for the method
   @param factor A gravity empirical factor
**/
void FBinaryStress2D::setGravity(double factor)
{  // 0 < factor < 1
    gravity=pow(10,pow(4,factor));
}

