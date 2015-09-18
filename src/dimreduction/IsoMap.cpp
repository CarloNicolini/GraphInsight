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

#include <string>
#include <cmath>
#include <vector>
#include <iostream>
#include <fstream>
#include <limits>

#include "IsoMap.h"
#include "Common.h"
#include "DimensionalityReduction.h"

#include <Eigen/Core>


using namespace Eigen;

/*	
	Steps of IsoMap embedding algorithm
	1)  Construct neighborhood graph over all data points by connecting
		points i and j if they are closer than e (e-Isomap), or if i is one of the K
		nearest neighbors of j (K-Isomap). Set edge lengths equal to dX(i,j).
		
	2)	Choose an epsilon such that the graph is connected
	
	3)	Compute all pair shortest path (using johnson's algorithm  ) over the connected component

	4)	Embed the graph in 2 or 3 dimensions
*/

IsoMap::IsoMap()
{
	g = NULL;
	m=0; n=0;
	epsilon = 1;
	kappa = 6;
	isSet = false;
}

void IsoMap::init( int ndim )
{

	nDimensions = ndim;
	if (X.size()<2)
	{
		cerr << "X not initialized" << endl;
		exit(0);
	}
	g = new GraphLayout();
	isSet = false;
	setParameters();
}

void IsoMap::setParameters(double e, int k)
{
	epsilon=e;
	kappa=k;
	// epsilon is the distance between nodes to make an edge
	// kappa is the maximum node degree allowed
	isSet = true;
}

void IsoMap::loadObservationMatrix(istream &is)
{
	// First count the number of objects (nodes) and features
	string line;
	while (getline(is, line))
	{	
		m++;
		vector<string> tokens;
        // split the string using the "(" ")" and "," token
        Common::tokenizeString(line, tokens, " :  \t");
		n = MAX( (tokens.size()-1)/2, n);
	}
	DEBUG_PRINT( "Nrows = " << m << " nfeat = " << n << endl);
	
	// Set size of X observation matrix
	X.resize(m,n);
	X.setZero(m,n);
	// now rewind the stream to beginning
	is.clear();
	is.seekg(0);

	// Now fill the observation matrix with values
	unsigned int row=0;
	// first reading to count max_columns and max_rows
	while (getline(is, line))
	{
        vector<string> tokens;
        // split the string using the "(" ")" and "," token
        Common::tokenizeString(line, tokens, " :  \t");
		
		for (unsigned int token = 1; token < tokens.size(); token+=2)
		{
			istringstream valueString(tokens[token+1]);
			double value;
			valueString >> value;
			X(row,(token-1)/2)=value;
		}
		row++;
	}

}


void IsoMap::findEmbed(void)
{
	if ( !isSet )
	{
		cerr << "First set interal parameters!" << endl;
		exit(0);
	}
	
	// now launch some graph drawing algorithm
	// classic euclidean norm	
	fillEuclideanDistanceMatrix();
	
	for (unsigned int i=0; i<m ; i++)
		g->insertNode(i+1);
		
// 	it could be a suggested first trial		
	if (epsilon <= -std::numeric_limits<double>::max())
		 epsilon = D.mean();	
	
	for (unsigned int i=0; i< m ; i++)
	{
		for (unsigned int j=i+1; j< m ; j++)
		{
			if ( D(i,j) < epsilon  )
			{
			 	if (g->nodes[i+1]->degree < kappa )
					g->insertEdge(i+1,j+1 );
			}
		}
	}
	
	DEBUG_PRINT( "nodes = " << g->nodes.size() << " nedges = " << g->getEdgesCount() << endl);
	int nDimensions=2;
	g->setDimensions(nDimensions);
    g->initRandomCoordinates();
    g->reloadNodeCoordinates(true);
    g->init(GraphLayout::MethodKamadaKawai, nDimensions,true, false);
	for (int i=0; i<1e4; i++)
		g->steps(1);
	
	ofstream os;
	os.open("mapping.dat");
	g->g->writeDimacs(os);

}


void IsoMap::print()
{
	cout << "Observation matrix" << endl << X << endl;
	cout << "Distance Matrix" << D << endl;
}

void IsoMap::fillEuclideanDistanceMatrix( void )
{
	m=X.rows();
	n=X.cols();
	// matrix of distances
	D.resize(m,m);
	D.setZero(m,m);

	double distance=0.0;
	for (unsigned int i=0; i< m; i++)
	{
		for (unsigned int j=i+1; j< m; j++)
		{
			distance=0.0;
			for (unsigned int k=0 ; k<n; k++ )
			{
				distance += pow(X(i,k)-X(j,k),2);
			}
			D(i,j)=D(j,i)=sqrt(distance);
		}
	}
}
