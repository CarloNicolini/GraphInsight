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



#ifndef LMStressMajorization_H
#define LMStressMajorization_H


#include "LayoutMethod.h"
#include <vector>
#include <Eigen/Core>


using namespace Eigen;
/**
@ingroup GraphLayout
@class LMStressMajorization
@brief LMStressMajorization implements the article on E.R.Gansner - Graph layout by stress majorization, it's an algebraic matrix method to find a good embedding of nodes coordinates.
**/
class LMStressMajorization : public LayoutMethod
{
public:
   LMStressMajorization();
   ~LMStressMajorization();

   void init(GraphLayout *gl, int nDimensions);
   int steps(int n);

protected:
   double getStress();
   void updateLaplacianZ();
   GraphLayout *g;
   int dimensions; // number of largest eigenvectors to display
   int m;  //embedding Dimension
   int n;  // number of graph nodes

   // size of laplacian matrix will be determined at runtime
   Matrix<double,Dynamic, Dynamic> Laplacian,LaplacianX,Xnow,Xafter;

   void setLaplacian();

   bool justComputed;
   double currentStress,lastStress;
   //double tolerance;

};

#endif  /* LMStressMajorization_H */


