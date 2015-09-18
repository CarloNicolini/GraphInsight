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


#include <Eigen/Core>
#include <Eigen/QR>
#include <Eigen/Eigenvalues>
#include <set>
#include <vector>
#include "LMStressMajorization.h"
#include "Node.h"
#include "Graph.h"
#include "GraphLayout.h"
#include "Common.h"

using namespace std;
using namespace Eigen;

/**
 * @ingroup GraphLayout
 * @brief LMStressMajorization::LMStressMajorization Constructor
 * here we follow the paper
 *   Graph Drawing by Stress Majorization
 * Emden R. Gansner, Yehuda Koren and Stephen North
* http://www.graphviz.org/Documentation/GKN04.pdf
 */
LMStressMajorization::LMStressMajorization() : g(NULL), dimensions(3), m(50), n(0), justComputed(false), currentStress(0.0), lastStress(0.0)
{
    DEBUG_PRINT("LMStressMajorization constructor");
}

/**
 * @brief LMStressMajorization::~LMStressMajorization Destructor
 */
LMStressMajorization::~LMStressMajorization()
{
    DEBUG_PRINT("LMStressMajorization destructor");
}

/**
 * @brief LMStressMajorization::init Init the layout method
 * @param gl The graph to layout
 * @param nDimensions Number of dimensions of layout (2 or 3)
 */
void LMStressMajorization::init(GraphLayout *gl, int nDimensions)
{  g = gl;

    dimensions=nDimensions;
    n = g->nodes.size();

    setLaplacian();
    LaplacianX.setZero(n,n);

    //g->randomize();

    Xafter.setRandom(n,nDimensions);
    Xnow.setRandom(n,nDimensions);

    // Fill Xnow matrix
    LNode *n1=NULL;
    for (NodesRand::const_iterator iter1=g->nodesRand.begin(); iter1!=g->nodesRand.end(); ++iter1)
    {  n1=static_cast<LNode*>(*iter1);
        Xnow(n1->index-1,0)=n1->px;
        Xnow(n1->index-1,1)=n1->py;
        if ( nDimensions==3)
            Xnow(n1->index-1,2)=n1->pz;
    }

    updateLaplacianZ();

}
/**
 * @ingroup GraphLayout
 * @brief LMStressMajorization::updateLaplacianZ Update the laplacian matrix of the graph
 */
void LMStressMajorization::updateLaplacianZ()
{
    const MatrixXd &Dij = g->getShortestPathMatrix();

    if ( LaplacianX.rows() != g->nodesRand.size() )
    {
        LaplacianX.setZero(g->nodesRand.size(),g->nodesRand.size());
    }

    LaplacianX.diagonal().setZero();
    for (NodesRand::const_iterator iter1=g->nodesRand.begin(); iter1!=g->nodesRand.end(); ++iter1)
    {
        LNode *n1=( static_cast<LNode*>(*iter1));
        unsigned int i=n1->index -1;
        for (NodesRand::const_iterator iter2=g->nodesRand.begin(); iter2!=g->nodesRand.end(); ++iter2)
        {
            LNode *n2 = (static_cast<LNode*>(*iter2));
            unsigned int j=n2->index - 1;
            double deltaij=   1.0/Dij(i,j);
            if ( n1!=n2 )
                LaplacianX(i,j) = -deltaij/( (Xnow.row(i)-Xnow.row(j)).norm() );
            else
                LaplacianX(i,j) = 0;
        }
    }

    // another pass to fill the diagonal
    for (NodesRand::const_iterator iter1=g->nodesRand.begin(); iter1!=g->nodesRand.end(); ++iter1)
    {
        LNode *n1=(static_cast<LNode*>(*iter1));
        unsigned i=n1->index -1;
        LaplacianX(i,i)=-LaplacianX.col(i).sum();
    }
}

/**
 * @ingroup GraphLayout
 * @brief LMStressMajorization::setLaplacian Generate the Laplacian matrix of the graph (see LMAce::setLaplacian() for details of the algorithm)
 */
void LMStressMajorization::setLaplacian(void)
{
    if ( Laplacian.rows()!=g->nodesRand.size() )
        this->Laplacian = g->getSparseLaplacianMatrix().toDense();
}

/**
 * @ingroup GraphLayout
 * @brief LMStressMajorization::steps Make one step of the layout method
 * @param nsteps Number of steps (ignored)
 * @return 1 when layout finished, 0 otherwise
 */
int LMStressMajorization::steps(int nsteps)
{
    lastStress=currentStress;
    updateLaplacianZ();
    // Solve a linear system for every dimension
    for (int i=0; i<dimensions; i++)
    {  // LLT acts only on positive and negative definite matrices and its the fastest in the case that the graph has not many components
        // See http://eigen.tuxfamily.org/dox/TopicLinearAlgebraDecompositions.html for a complete reference of the best methods
        Xafter.col(i) = Laplacian.colPivHouseholderQr().solve(LaplacianX*Xnow.col(i));
    }

    Xnow=Xafter;

    // Copy back the values in the graph
    for (NodesRand::const_iterator iter1=g->nodesRand.begin(); iter1!=g->nodesRand.end(); ++iter1)
    {
        LNode *n1=static_cast<LNode*>(*iter1);
        int i = n1->index-1;
        if ( !isnan(Xnow.row(i).sum() ) )
        {  n1->px = Xnow(i,0);
            n1->py = Xnow(i,1);
            if ( dimensions==3)
                n1->pz = Xnow(i,2);
            else
                n1->pz=0;
        }
        else
        {  return 1;
        }
        //assert( !isnan(n1->px+n1->py+n1->pz) && !isinf(n1->px+n1->py+n1->pz));
    }
    currentStress = getStress();

    if ( abs( (currentStress-lastStress)/currentStress )  < 1E-4 )
        return 1;
    else
        return 0;
}

/**
 *@ingroup GraphLayout
 * @brief LMStressMajorization::getStress Get the stress as sum of node-node stress \f$ \sum_{i<j}( w_{ij} ||X_i − X_j || − d_{ij} )^2)\f$
 * @return The stress scalar
 */
double LMStressMajorization::getStress()
{
    const MatrixXd &Dij = g->getShortestPathMatrix();

    double stress=0.0;
    for (int i=0; i<n; ++i)
    {
        for (int j=0; j<n; ++j)
        {
            if (i!=j)
            {  double dist = (Xnow.row(i)-Xnow.row(j)).norm();
                stress+= pow(dist-Dij(i,j)/Dij(i,j),2);
            }
        }
    }
    //cerr << stress << endl;
    return stress;
}
