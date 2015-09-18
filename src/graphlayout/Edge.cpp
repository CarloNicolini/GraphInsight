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

#include "Edge.h"

// Initialization constructor is faster
/**
  @ingroup GraphLayout
@brief Constructor, it sets weight = 1 and unmarked edge
**/
Edge::Edge() : weight(1.0), mark(false)
{

}

/**
@ingroup GraphLayout
Destructor, does nothing particular
**/
Edge::~Edge()
{
}

/**
 * @brief Edge::Edge
 * @param w
 */
Edge::Edge(double w) : weight(w), mark(false)
{

}
/**
 * @brief Edge::Edge
 * @param rhs
 */
Edge::Edge(const Edge&rhs) :
    weight(rhs.weight), mark(rhs.mark)
{

}
