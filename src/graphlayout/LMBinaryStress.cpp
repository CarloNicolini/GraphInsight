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

#include "LMBinaryStress.h"
#include "FBinaryStress2D.h"
#include "FBinaryStress3D.h"
#include "CGSolver.h"
#include "GraphLayout.h"
#include "Common.h"

using namespace std;

/**
 * @ingroup GraphLayout
 * @brief LMBinaryStress::LMBinaryStress Standard constructor
 */
LMBinaryStress::LMBinaryStress() : g(NULL),
    solCG(NULL), f(NULL), coarseningLevel(std::numeric_limits<double>::max()), gradientNorm(1E-3)
{  g=NULL;
   solCG=NULL;
   f=NULL;
   coarseningLevel=1E30;
}

/**
 * @ingroup GraphLayout
 * @brief LMBinaryStress::LMBinaryStress Standard destructor, clears instances of solver and cost function
 */
LMBinaryStress::~LMBinaryStress()
{

   delete solCG;
   delete f;
   solution.clear();

}

/**
 * * @ingroup GraphLayout
 * @brief LMBinaryStress::init Initialize the layout method
 * @param gl The graph to work on
 * @param nDimensions Number of dimensions of the layout (2 or 3)
 */
void LMBinaryStress::init(GraphLayout *gl, int nDimensions)
{  DEBUG_PRINT( "LMBinaryStress init with dimension " << gl->nodes.size()*nDimensions );
   g = gl;
   solution = gl->solution;
   DEBUG_PRINT( "(|V|,|E|) = (" << g->nodes.size() << "," << g->getEdgesCount() << ")" );
   if(f)
   {  delete f;
      f = NULL;
   }
   if (solCG)
   {  delete solCG;
      solCG  = NULL;
   }


   gradientNorm = 1E-3;

   switch(nDimensions)
   {  case 2:
         f = new FBinaryStress2D( g );
         solCG = new CGSolver(*f, solution);
         break;

      case 3:
         f = new FBinaryStress3D( g );
         solCG = new CGSolver(*f, solution);
         break;

      default:
      {  cerr << "Dimension can be 2 or 3 only!" << endl;
      }
   }
}

/**
 * @brief LMBinaryStress::steps Step method to advance the layout of 1 step, must be called once per frame
 * @param n ignored
 * @return 0 if the step is made, 1 if not
 */
int LMBinaryStress::steps(int n)
{
    solCG->makeSteps(n, gradientNorm);
    //solution = solCG->best_point;
    g->setNodesPosition( solCG->best_point);

    if (solCG->optimality < gradientNorm)
    {  solCG->optimality = std::numeric_limits<double>::max();
       return 1;
    }

    return 0;
}


