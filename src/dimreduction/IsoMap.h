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

#ifndef _ISOMAP_H
#define _ISOMAP_H

#include <limits>
#include <vector>
#include <string>
#include <fstream>
#include "Common.h"
#include <Eigen/Core>
#include "DimensionalityReduction.h"

using namespace Eigen;
using namespace std;

class IsoMap : public DimensionalityReduction
{
	
private:
	GraphLayout *g;
	double epsilon;		// create an edge iff ||x_i - x_j|| < epsilon
	int kappa;				// choose the K-nearest neighbors
	void fillEuclideanDistanceMatrix( void );
	int nDimensions;
	MatrixXd D;
	bool isSet;
public:
	
	IsoMap(void );
	virtual ~IsoMap() {};
	void init(int ndim);
	void setParameters(double e=-std::numeric_limits<double>::max(), int k=6);
	void loadSimilarityMatrix(ifstream &);
	void loadObservationMatrix(istream &);
	void print();
	
	void findEmbed(void);
	
	
};

#endif
