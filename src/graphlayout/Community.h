#ifndef COMMUNITY_H
#define COMMUNITY_H

#include "GraphLayout.h"

/**
@ingroup GraphLayout
@class Community
@brief A temptative prototypical implementation of community detection
**/
class Community
{
public:
    Community(Graph *_g);
    Community(Graph *gc, int nbp, double minm);

    void init(Graph *g);

    double getModularity();

    void insertNodeInCommunity(Node *n, int community);
    void removeNodeFromCommunity(Node *n, int community);

    void updateModularity(Node *n);

    Graph *g;


};

#endif // COMMUNITY_H
