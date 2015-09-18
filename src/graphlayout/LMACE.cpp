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
#include "LMACE.h"
#include "Node.h"
#include "Graph.h"
#include "GraphLayout.h"
#include "Common.h"

using namespace std;
using namespace Eigen;

/**
* @ingroup GraphLayout
 * @brief LMACE::LMACE Standard constructor for Spectral Embedder (Hall algorithm) layout method, set the justComputed flag to false
 */
LMACE::LMACE() : g(NULL), dimensions(3), m(50), n(0), alreadyComputed(false)
{
}

/**
* @ingroup GraphLayout
 * @brief LMACE::LMACE Standard destructor for Spectral Layout layout method
 */
LMACE::~LMACE()
{

}

/**
 * @brief LMACE::init Initialize the method with a graph and a given number of dimensions
 * @param gl The graph to layout
 * @param nDimensions Number of dimensions for the embedding
 */
void LMACE::init(GraphLayout *gl, int nDimensions)
{  //cerr << "LMACE init" << endl;
    g = gl;
    dimensions=nDimensions;
    n = g->nodesRand.size();
    alreadyComputed=false;
    setLaplacian();
}

/**
 * @ingroup GraphLayout
 * @brief LMACE::setLaplacian Compute the Laplacian matrix of the graph, the Laplacian matrix is L = A - D where A is the adjacency matrix, D is a diagonal matrix with the degree of the node i as diagonal elements at the i-th row. Has N^2 storage cost.
 */
void LMACE::setLaplacian(void)
{
    unsigned int nnodes= g->nodes.size();
    Laplacian = g->getSparseLaplacianMatrix().toDense();
    Masses.setZero(nnodes);
    // Fill the masses matrix
    for (NodesRand::iterator iter = g->nodesRand.begin(); iter!=g->nodesRand.end();++iter)
        Masses((*iter)->index-1) = (*iter)->degree;
}

/**
 * @brief LMACE::steps Do a single step of the algorithm, this method is ignored if the layout has been already computed
 * @param nsteps Number of steps (ignored)
 * @return Always 1
 */
int LMACE::steps(int nsteps)
{
    if (g->countConnectedComponents()>1)
        return 0;

    if (alreadyComputed==false)
    {
        int nnodes = g->nodes.size();
        int ncomponents = g->countConnectedComponents();
        GeneralizedSelfAdjointEigenSolver<MatrixXd> eigenSolver(nnodes);
        eigenSolver.compute(Laplacian, Masses.asDiagonal());

        MatrixXd eigenVectors = eigenSolver.eigenvectors();

        for ( int k=0; k<nnodes; k++)
        {
            ( static_cast<LNode*>(g->nodesRand[k]))->px = eigenVectors(k,ncomponents);
            ( static_cast<LNode*>(g->nodesRand[k]))->py = eigenVectors(k,ncomponents+1);
            if (dimensions==2)
                ( static_cast<LNode*>(g->nodesRand[k]))->pz = 0.0;
            else
                ( static_cast<LNode*>(g->nodesRand[k]))->pz =  eigenVectors(k,ncomponents+2);
        }

        alreadyComputed=true;
        return 1;

    }
    return 1;
}


