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
#include "LMKamadaKawai.h"
#include "FKamadaKawai2D.h"
#include "FKamadaKawai3D.h"
#include "CGSolver.h"
#include "GraphLayout.h"
#include "Common.h"

using namespace std;

/**
 * @ ingroup GraphLayout
 * @brief LMKamadaKawai::LMKamadaKawai Standard constructor
 */
LMKamadaKawai::LMKamadaKawai() : gradientNorm(5*1E-4)
{  g=NULL;
   solCG=NULL;
   f=NULL;
   DEBUG_PRINT("LMKamadaKawai");
}

/**
 * @ ingroup GraphLayout
 * @brief LMKamadaKawai::~LMKamadaKawai Destructor, clear CostFunction and CGSolver instances
 */
LMKamadaKawai::~LMKamadaKawai()
{  DEBUG_PRINT( "LMKamadaKawai Destructor");
   delete f;
   delete solCG;
}

/**
 * @brief LMKamadaKawai::init Init the layout method, randomize the start solution
 * @param gl The graph to layout
 * @param nDimensions Number of dimensions of the layout (2 or 3)
 */
void LMKamadaKawai::init(GraphLayout *gl, int nDimensions)
{  DEBUG_PRINT( "LMKamadaKawai init");
   g = gl;

   solution.reserve(g->nodes.size()*nDimensions);
   //g->initRandomCoordinates();
   solution = gl->solution;

   if(f!=NULL)
   {  delete f;
      f = NULL;
   }
   if (solCG!=NULL)
   {  delete solCG;
      solCG  = NULL;
   }

//    cerr << "gradientNorm= " << gradientNorm << endl;
   switch(nDimensions)
   {  case 2:
         f = new FKamadaKawai2D(g);
         gradientNorm = FKamadaKawai2D::GradientNorm;
         solCG = new CGSolver(*f, solution);
         break;

      case 3:
         f = new FKamadaKawai3D(g);
         gradientNorm = FKamadaKawai3D::GradientNorm;
         solCG = new CGSolver(*f, solution);
         break;

      default:
      {  cerr << "Dimension can be 2 or 3 only!" << endl;
      }
   }
}

/**
 * @ ingroup GraphLayout
 * @brief LMKamadaKawai::steps Make one step of the layout method
 * @param n Number of steps, ignored
 * @return 1 if the method finished, 0 otherwise
 */
int LMKamadaKawai::steps(int n)
{

   solCG->makeSteps(n, gradientNorm);
   solution = solCG->best_point;
   g->setNodesPosition(solution);

   if (solCG->optimality < gradientNorm)
   {  solCG->optimality = std::numeric_limits<double>::max();
      return 1;
   }

   return 0;
}
