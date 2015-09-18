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


#include "LMCircularMinCross.h"
#include "GraphLayout.h"
#include <cmath>
#include <algorithm>
#include <list>
#include <stack>
#include <iostream>
#include "Common.h"

/**
 * @ingroup GraphLayout
 * @brief LMCircularMinCross::LMCircularMinCross Standard constructor, does nothing
 */
LMCircularMinCross::LMCircularMinCross() : g(NULL), gravity(0.0), nstepsDone(0), nDimensions(3)
{
    singletonNodes=0;
}

/**
 * @brief LMCircularMinCross::~LMCircularMinCross Standard destructor, does nothing
 */
LMCircularMinCross::~LMCircularMinCross()
{
}

bool sortByDegree(Node* n1, Node *n2)
{
    return (n1)->degree > (n2)->degree;
}

bool sortByNumberOfNodes( const  NodesRand&s1,  const NodesRand&s2)
{
    return s1.size()  > s2.size();
}

/**
 * @brief LMCircularMinCross::init Initialize the layout method
 * @param gl
 * @param _nDimensions
 */
void LMCircularMinCross::init(GraphLayout *gl, int _nDimensions)
{
    g=gl;
    nDimensions = _nDimensions;
    g->countConnectedComponents();
    subgraphs.resize(g->statsComponentsCount);

    for (NodesRand::const_iterator iter1=g->nodesRand.begin(); iter1!=g->nodesRand.end(); ++iter1)
    {
        Node *n = *iter1;
        if (n->neighborsRand.empty())
            this->singletonNodes++;
        else
            subgraphs.at(n->component).push_back(n);
    }
    // Sort the subgraphs for the number of nodes
    std::sort(subgraphs.begin(),subgraphs.end(),sortByNumberOfNodes);
}

/**
 * @brief LMCircularMinCross::steps Make a step. This algorithm is the implementation of "New Circular Drawing Algorithms" from Hongmei He and Ondrej Sykora
 * This is the "Adjacent Vertex with Smallest Degree First" algorithm: It finds an ordering of nodes such that edges crossing is minimized
 * Has a very little cost, its O(|E|) for its greedy phase. It's modified to cope with disconnected components
 * @param n
 * @return
 */
int LMCircularMinCross::steps(int n)
{
    /*
        1: Initialise an array order [n], and a stack, S.
        2: Get the vertex with the smallest degree from the given graph, and push it into S.
        3: while (S is not empty) do
        4: Pop a vertex v, from S
        5: if (v is not in order ) then
        6:     Append the vertex v into order.
        7:     Get all adjacent vertices of v; and push those vertices, which are not in order
               into S with descending degree towards the top of the stack (the vertex with
               smallest degree is at top of S).
        8: end if
        9: end while
    */
    for (unsigned int i=0; i<(unsigned int)g->statsComponentsCount; i++)
    {
        vector<Node*> order;
        // Avoid cases when the graph has only 1 or 0 nodes
        if (subgraphs.at(i).size() <2 )
        {
            continue;
        }
        unsigned int minDegree=std::numeric_limits<unsigned int>::max();
        Node* l=NULL;
        for (NodesRand::const_iterator iter1=subgraphs.at(i).begin(); iter1!=subgraphs.at(i).end(); ++iter1)
        {
            if ((*iter1)->neighborsRand.size() < minDegree )
            {
                l=(*iter1);
                minDegree=(*iter1)->neighborsRand.size();
            }
        }
        std::stack<Node*> S;
        S.push(l);
        while (!S.empty())
        {
            Node *v = S.top();
            S.pop();
            // Find if the node v is not in "order" vector
            if ( std::find(order.begin(), order.end(), v) == order.end() )
            {
                order.push_back(v);
                std::vector<Node*> tmp;
                for(NeighborsRand::const_iterator iter2 = v->neighborsRand.begin(); iter2 != v->neighborsRand.end(); ++iter2)
                {
                    Node *k = (*iter2)->second;
                    // Find if the node k is not in "order" vector
                    if ( std::find(order.begin(), order.end(), k) == order.end() )
                        tmp.push_back(k);
                }
                std::sort(tmp.begin(),tmp.end(),sortByDegree);
                for (NodesRand::const_iterator iter2 = tmp.begin();iter2!=tmp.end();++iter2)
                    S.push(*iter2);
            }
        }
        // At the end the "order" vector contains a node ordering such that the crossing are minimized
        subgraphs.at(i)=order;// for commodity.
    }
    DispositionMethod method=SquareArray;
    std::pair<Vector2d,Vector2d> corners = subplacementOfComponents(method,subgraphs);

    // Put the 0 degree nodes on a circle around the already made layout
    double radius = (corners.first-corners.second).norm();
    double angle=0.0;
    for (NodesRand::const_iterator iter1=g->nodesRand.begin(); iter1!=g->nodesRand.end(); ++iter1)
    {
        LNode *n = static_cast<LNode*>(*iter1);
        n->pz = 0.0;
        if (n->neighborsRand.size()==0)
        {
            n->px = 0.5*(corners.second-corners.first).x() + radius*cos(angle);
            n->py = 0.5*(corners.second-corners.first).x() + radius*sin(angle);
            angle+=2*M_PI/singletonNodes;
        }
    }
    return 1;
}

std::pair<Vector2d,Vector2d> LMCircularMinCross::subplacementOfComponents(DispositionMethod method, vector<NodesRand> &subgraphs)
{
    Vector2d cornerMin,cornerMax;
    if (method==LinearArray)
    {
        for (int i=0; i<g->statsComponentsCount; i++)
        {
            double  nnodesForThisComponent = (double)subgraphs.at(i).size();
            double angle=0.0;
            for (NodesRand::const_iterator iter1=subgraphs.at(i).begin(); iter1!=subgraphs.at(i).end(); ++iter1)
            {
                (static_cast<LNode*>(*iter1))->px = 2.5*i+cos(angle);
                (static_cast<LNode*>(*iter1))->py = sin(angle);
                angle+=(2*M_PI/nnodesForThisComponent);
            }
        }
    }

    if (method==SquareArray)
    {
		int edgex = std::floor(std::sqrt((double)g->statsComponentsCount));
		int edgey = std::ceil(std::sqrt((double)g->statsComponentsCount));
        int debugCounter=0;
        for (int i=0; i<edgex; i++)
        {
            for (int j=0; j<edgey; j++)
            {
                debugCounter++;
                double angle=0.0;
                double  nnodesForThisComponent = (double)subgraphs.at(i*edgex+j).size();
                Vector2d baseCenter(2.5*i,2.5*j);
                for (NodesRand::const_iterator iter1=subgraphs.at(i*edgex+j).begin(); iter1!=subgraphs.at(i*edgex+j).end(); ++iter1)
                {
                    (static_cast<LNode*>(*iter1))->px =baseCenter.x() + cos(angle);
                    (static_cast<LNode*>(*iter1))->py = baseCenter.y() + sin(angle);
                    angle+=(2*M_PI/nnodesForThisComponent);
                }
            }
        }

        // Draw the remaining nodes
        for (int k=edgex*edgey; k<g->statsComponentsCount;k++)
        {
            double angle=0.0;
            double  nnodesForThisComponent = (double)subgraphs.at(k).size();
            Vector2d baseCenter(2.5*(k-edgex*edgey+1),2.5*edgey);
            for (NodesRand::const_iterator iter1=subgraphs.at(k).begin(); iter1!=subgraphs.at(k).end(); ++iter1)
            {
                (static_cast<LNode*>(*iter1))->px =baseCenter.x() + cos(angle);
                (static_cast<LNode*>(*iter1))->py = baseCenter.y() + sin(angle);
                angle+=(2*M_PI/nnodesForThisComponent);
            }
            debugCounter++;
        }
        // For this algorithm to be completely correct must be c==ncomponents so we are sure every component is drawn
    }

    // Get the corners for non singleton components
    double xmax=std::numeric_limits<double>::min(),xmin=std::numeric_limits<double>::max(),
            ymax=std::numeric_limits<double>::min(), ymin=std::numeric_limits<double>::max();
    for (unsigned int i=0; i<subgraphs.size(); i++)
    {
        for (NodesRand::const_iterator iter1 = subgraphs.at(i).begin(); iter1 != subgraphs.at(i).end(); ++iter1)
        {   LNode *n1=(LNode*)(*iter1);
            xmax = std::max(xmax,n1->px);
            xmin = std::min(xmin,n1->px);
            ymax = std::max(ymax,n1->py);
            ymin = std::min(ymin,n1->py);
        }
    }

    cornerMin << xmin,ymin;
    cornerMax << xmax,ymax;

    return std::pair<Vector2d,Vector2d>(cornerMin,cornerMax);
}
