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

#include <limits>
#include <Eigen/Core>
#include <Eigen/QR>
#include <Eigen/Eigenvalues>
#include <set>
#include <vector>
#include "LMHighDimensionalEmbedder.h"
#include "GraphLayout.h"
#include "Common.h"

using namespace std;
using namespace Eigen;

/**
 * @ingroup GraphLayout
 * @brief LMHighDimensionalEmbedder::LMHighDimensionalEmbedder Standard constructor, does nothing
 */
LMHighDimensionalEmbedder::LMHighDimensionalEmbedder() : g(NULL), dimensions(3), m(50), n(0), justComputed(false)
{
    DEBUG_PRINT("LMHighDimensionalEmbedder");
}

/**
 * @ ingroup GraphLayout
 * @brief LMHighDimensionalEmbedder::~LMHighDimensionalEmbedder Destructor, clear the distance vector
 */
LMHighDimensionalEmbedder::~LMHighDimensionalEmbedder()
{  d.clear();
    DEBUG_PRINT("~LMHighDimensionalEmbedder");
}

/**
 * @ ingroup GraphLayout
 * @brief LMHighDimensionalEmbedder::init
 * @param gl The graph to layout
 * @param nDimensions Number of layout dimensions
 */
void LMHighDimensionalEmbedder::init(GraphLayout *gl, int nDimensions)
{  //cerr << "LMHighDimensionalEmbedder init" << endl;
    g = gl;
    justComputed=false;
    if (nDimensions !=2 && nDimensions != 3)
    {  //cerr << "nDimensions must be 2 or 3" << endl;
        //exit(0);
    }
    dimensions=nDimensions;
    n = g->nodes.size();

    if (n >= 100)
        m = 50;
    if ( n < 100 && n> 1 )
    {  m = n;
        //cerr << "High dimensional embedder is useful on bigger graphs, we try a N=num of nodes dimensional embedding" << endl;
    }

    Xm.resize(m,n);
    Xm.setZero(m,n);

    S.resize(m,m);
    S.setZero(m,m);

    XT.resize(n,m);
    XT.setZero(n,m);


    justComputed=false;
}

/**
 * @ ingroup GraphLayout
 * @brief LMHighDimensionalEmbedder::steps
 * @param nsteps Number of steps (ignored)
 * @return 1 if layout finished
 */
int LMHighDimensionalEmbedder::steps(int nsteps)
{
    if (g->countConnectedComponents()>1)
        return 1;
    if ( justComputed==true )
        return 1;

    justComputed=true;
    /* Now we solve the m-center problem with a 2-approximation
   * The first vertex is selected at random, and then each of the remaining centers
   * is chosen as the farthest vertex from the previously selected centers. In other words,
   * if j centers have been selected, cj+1  is the vertex whose shortest graph distance to the j
   * centers is larger than or equal to the shortest graph distance of all the other vertices
   * to the j centers.
   *
   GONZALEZ's K-centers 2-approximation
   //
   1) for i  1 to n
   2)    d[i]=std::numeric_limits<double>::max();  //equivalent to a big value
   3) c1  <- p1
   4) for j 1 to k
   5)    rj <- 0  // rj is the maximum distance of
   6)    for i 1 to n
   7)       di <- min{di , dist(pi,cj)
   8)       if rj < di
   9)          rj  <- di ; cj+1 <- pi
   10)   return {c1, c2, . . . , ck}
   */
    //cerr << "Compute k-centers approximation" << endl;

    Node *p = g->nodes.begin()->second;
    d.assign(n,std::numeric_limits<double>::max());
    vector <Node*> pivots;
    pivots.push_back(p);

    // XXX this algorithm will crash when negative weight edges are present
    double r=0;
    for (int i=0; i<m; i++)
    {  // Use dijkstra for weighted graphs, otherwise use BFS because it's faster
        //g->bfs( pivots.back() );
        g->dijkstra(pivots.back());
        r = 0;
        for (NodesRand::const_iterator iter1 = g->nodesRand.begin(); iter1 != g->nodesRand.end(); ++iter1)
        {  int j = (*iter1)->index -1 ;
            Xm( i, j ) = (*iter1)->distance;
            d[j] = std::min(d[j], (*iter1)->distance);
            if ( r < d[j] )
            {  r = d[j];
                pivots.push_back( *iter1 );
            }

        }
    }
    pivots.clear();
    d.clear();

    // Now double center matrix X
    // Now substract the mean on columns from each row element
    double mean=0.0;
    int col = Xm.cols();
    int row = Xm.rows();
    for ( int i=0; i<row ; i++)
    {  mean=0;
        for (  int j=0; j < col ; j++)
            mean+= Xm.coeffRef(i,j)/Xm.cols();

        for (  int j=0; j < col ; j++)
            Xm.coeffRef(i,j)-=mean;
    }

    // Covariance matrix
    XT=Xm.transpose();
    S = Xm*XT;
    SelfAdjointEigenSolver<MatrixXd> eigenSolver(m);
    eigenSolver.compute(S);
    MatrixXd eigenVectors = eigenSolver.eigenvectors();

    // Now we follow the HDE algorithm described in Harel-Koren Graph drawing by high dimensional embedding

    Matrix<double, Dynamic,Dynamic> Y;
    Y.setZero(dimensions,n);

    int k=0;
    // here we choose the eigenvectors related to largest eigenvalues, at the end of matrix
    for (int i=m-1; i>=(m-dimensions); i--)
    {  Y.row(k) =(XT * eigenVectors.col(i));
        k++;
    }


    // Recover node positions
    int index=0;
    LNode *n1=NULL;
    for (NodesRand::const_iterator iter1=g->nodesRand.begin(); iter1 != g->nodesRand.end(); ++iter1)
    {  n1 = static_cast<LNode*>(*iter1);
        index = n1->index -1;
        n1->px = Y(0,index);
        n1->py = Y(1,index);
        if (dimensions == 3)
            n1->pz = Y(2,index);
        else
            n1->pz = 0.0;
    }


    return 1;
}

