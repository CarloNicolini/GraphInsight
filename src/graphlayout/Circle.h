/****************************************************************************
**
** Copyright (C) 2012 Carlo Nicolini (carlo.nicolini@gmail.com)
** All rights reserved.
**
** Warning: This program is protected by copyright law and international
** treaties. Unauthorized reproduction and distribution of this program,
** or any portion of it, may result in severe civil and criminal penalties,
** and will be persecuted to the maximum extent possible under the law.
**
****************************************************************************/

#ifndef _CIRCLE_H_
#define _CIRCLE_H_
#include <set>

/** @ingroup GraphLayout
 *  @brief A simple wrapper for a circle class in 2D, it handles collision with other circles, order comparison, a simple neighbors relation and is templatized
 */
template <typename T>
class Circle
{
public:
    Circle()
    {
        centerx=centery=0;
        radius=10;
    }

    Circle(T _centerx, T _centery, T _radius)
    {
        centerx=_centerx;
        centery=_centery;
        radius=_radius;
        active=true;
    }

    std::set<Circle<T> > neighbors;

    T centerx,centery,radius;
    bool addNeighbor( const Circle<T> &other)
    {
        if ( (neighbors.find(other)!=neighbors.end()) )
        {
            neighbors.insert(other);
            return true;
        }
        else
            return false;
    }

    bool active;
    friend bool operator<(const Circle & a, const Circle & b)
    {
        if ( a.centerx == b.centerx)
            return a.centery < b.centery;
        else
            return a.centerx < b.centerx;
    }

    friend bool operator<=(const Circle & a, const Circle & b)
    {
        if ( a.centerx == b.centerx)
            return a.centery < b.centery;
        else
            return a.centerx <= b.centerx;
    }

    bool checkCollision(const Circle &other, T tolerance)
    {
        if ( ( SQR(centerx -other.centerx) + SQR(centery -other.centery) ) < SQR(radius+other.radius+tolerance) )
            return true;
        else
            return false;
    }
};

#endif
