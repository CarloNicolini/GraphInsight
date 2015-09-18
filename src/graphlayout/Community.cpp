#include "Community.h"

Community::Community(Graph *_g)
{
    init(_g);
}

void Community::init(Graph *_g)
{
    g=_g;
}

Community::Community(Graph *gc, int nbp, double minm)
{
  g = gc;
  //unsigned int size = g->nodesRand.size();
}

/*
 *i=0
For v in V:
    comm[v]=i++

noImprovement=0
while ( noImprovement )
For v in V:
    For u in N(v):
        if modularityGain > 0
            comm[v]=comm[u]
 */
double Community::getModularity()
{
    double modularityQ=0.0;
    double m2 = 2*g->getTotalEdgeWeight();
    for (NodesRand::iterator iter = g->nodesRand.begin(); iter!=g->nodesRand.end(); ++iter)
    {
        Node *u = (*iter);
        double degi = u->degree;
        for (NeighborsRand::iterator iter2 = u->neighborsRand.begin(); iter2!=u->neighborsRand.end();++iter2)
        {
            Node *v = (*iter2)->second;
            if ( v->community==u->community )
            {
                double wij = ((*iter2)->first)->weight;
                double degj= v->degree;
                modularityQ+=(wij-degj*degi)/m2;
            }
        }
    }

    return modularityQ/m2;
}
