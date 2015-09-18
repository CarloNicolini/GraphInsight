/****************************************************************************
**
** Copyright (C) 2010 Michele Dallachiesa (michele.dallachiesa@gmail.com)
** Copyright (C) 2010 Carlo Nicolini (nicolini.carlo@gmail.com)
** All rights reserved.
**
** Warning: This program is protected by copyright law and international
** treaties. Unauthorized reproduction and distribution of this program,
** or any portion of it, may result in severe civil and criminal penalties,
** and will be persecuted to the maximum extent possible under the law.
**
****************************************************************************/

#ifndef LAYOUTMETHOD_H
#define LAYOUTMETHOD_H

class GraphLayout;
#include <vector>
#include <limits>
#include "Graph.h"
#include "GraphLayout.h"

/**
  @ingroup GraphLayout
  @class LayoutMethod
  @brief LayoutMethod is a pure virtual interface from which inherit a generic layout methods, see the LM classes examples on how to implement your own method.
  **/
class LayoutMethod
{

public:

   virtual    void init(GraphLayout *g, int nDimensions) = 0;
   virtual    int steps(int n)  = 0;
   virtual   ~LayoutMethod()   { }

   vector <double> solution;
   int totSteps;
};


#endif  /* LAYOUTMETHOD_H */


