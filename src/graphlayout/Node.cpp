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


#include "Node.h"
#include "Graph.h"

Node::Node() :  id(0),
    index(0),
    component(0),
    //community(_id),
    degree(0.0),
    weight(1.0),
    mark(false),
    distance(0.0),
    color(0),
    ptrEntity(NULL)
{
    //DEBUG_PRINT("Calling default constructor");
}

/**
 * @ingroup GraphLayout
 * @brief Node::Node Standard constructor, set id and index=1, degree=0, component=0,mark=false,distance=0, color=0
 * @param _id The id of the node
 * @param _weight The weight of the node, default 1
 */
Node::Node(int _id, double _weight) :
    mark(false),
    id(_id),
    index(1),
    component(0),
    degree(0.0),
    weight(_weight),
    distance(0.0),
    color(0),
    ptrEntity(NULL)
{

}
/**
 * @ingroup GraphLayout
 * @brief Node::Node
 * @param orig
 */
Node::Node(const Node& orig) :
    mark(false),
    id(orig.id),
    index(1),
    component(0),
    degree(0.0),
    weight(orig.weight),
    distance(0.0),
    color(0),
    ptrEntity(NULL)
{

}

/**
 * @ingroup GraphLayout
 * @brief Node::~Node Destructor, it cleans up its neighbors list and the edges associated to it
 */
Node::~Node()
{
    for (Neighbors::iterator iter = neighbors.begin(); iter != neighbors.end(); ++iter)
    {
        iter->second.second->neighbors.erase(this->id); // delete this node ID from the other neighbors NeighborsMap
        delete iter->second.first;  // then delete the Edge*
    }
    neighbors.clear();
    neighborsRand.clear();

    if (ptrEntity)
    {
        delete ptrEntity;
        ptrEntity=NULL;
    }
}
