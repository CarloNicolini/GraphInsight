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

#include "LMLabelAdjust.h"
#include "LNode.h"
#include "GraphLayout.h"
#include "Common.h"
#include "ForceDirectedMethod.h"
#include "BarnesHutOctree.h"
#include "BarnesHutQuadtree.h"
#include <list>

using namespace std;

LMLabelAdjust::LMLabelAdjust() : g(NULL),nDim(3)
{
}


LMLabelAdjust::~LMLabelAdjust()
{

}


void LMLabelAdjust::init(GraphLayout *gl, int nDimensions)
{  g=gl;
    nDim = nDimensions;
}

int LMLabelAdjust::steps(int nsteps)
{
    ForceDirectedMethod::InitializeStep(g,nDim);

    int xmax=std::numeric_limits<int>::min(),xmin=std::numeric_limits<int>::max(), ymax=std::numeric_limits<int>::min(), ymin=std::numeric_limits<int>::max();
    LNode *n1=NULL;

    for (NodesRand::const_iterator iter1 = g->nodesRand.begin(); iter1 != g->nodesRand.end(); ++iter1)
    {   n1=static_cast<LNode*>(*iter1);
        xmax = std::max(xmax,n1->labelX);
        xmin = std::min(xmin,n1->labelX);

        ymax = std::max(ymax,n1->labelY);
        ymin = std::min(ymin,n1->labelY);
    }

    std::vector<LNode*> correctNodes;
    for (NodesRand::const_iterator iter1 = g->nodesRand.begin(); iter1 != g->nodesRand.end(); ++iter1)
    {
        n1=static_cast<LNode*>(*iter1);
        Vector2d center = Vector2d(n1->labelX+n1->labelWidth/2, n1->labelY+n1->labelHeight/2);
        //double radius = (Vector2d(n1->labelX,n1->labelY) - center).norm();

        if ( n1->labelX>0 && n1->labelY>0 )
        {
            correctNodes.push_back(n1);
        }
    }

    if (correctNodes.empty())
        return 1;

    // Try first with the pairwise implementation
    bool someCollision=false;
    for (std::vector<LNode*>::const_iterator iter1 = correctNodes.begin(); iter1!=correctNodes.end();++iter1)
    {
        LNode *n1=static_cast<LNode*>(*iter1);
        for (std::vector<LNode*>::const_iterator iter2 = correctNodes.begin(); iter2!=correctNodes.end();++iter2)
        {
            LNode *n2=static_cast<LNode*>(*iter2);
            if (n1>n2)
                someCollision = someCollision || twoNodeLabelsIntersect(n1,n2);
        }
    }

    if (!someCollision)
        return 1;

    for (std::vector<LNode*>::const_iterator iter1 = correctNodes.begin(); iter1!=correctNodes.end();++iter1)
    {
        LNode *n1=static_cast<LNode*>(*iter1);
        n1->px+=1;
        //n1->labelY+=5;
    }

    // Apply forces to nodes in a way such that labels don't collide
    /*
    for (std::vector<LNode*>::const_iterator iter1 = correctNodes.begin(); iter1!=correctNodes.end();++iter1)
    {
        LNode *n1=static_cast<LNode*>(*iter1);
        n1->labelX += n1->dx;
        n1->labelY += n1->dy;
    }
    */
    return 0;
}


bool LMLabelAdjust::twoNodeLabelsIntersect(LNode *n1, LNode *n2)
{
    int x1 = n1->labelX;
    int x2 = n2->labelX;
    int y1 = n1->labelY;
    int y2 = n2->labelY;

    int w1 = n1->labelWidth;
    int w2 = n2->labelWidth;
    int h1 = n1->labelHeight;
    int h2 = n2->labelHeight;

    bool xOverlap = (( x2 <= (x1+w1)) && ( x2 >= x1 )) || (( x1 <= (x2+w2)) && ( x1 >= x2 ));
    bool yOverlap = (( y2 <= (y1+h1)) && ( y2 >= y1 )) || (( y1 <= (y2+h2)) && ( y1 >= y2 ));
    return xOverlap && yOverlap;
}

bool LMLabelAdjust::repulse(LNode *n1, LNode *n2)
{
    bool collision=false;

    int n1x = n1->labelX;
    int n2x = n2->labelX;
    int n1y = n1->labelY;
    int n2y = n2->labelY;

    int n1w = n1->labelWidth;
    int n2w = n2->labelWidth;
    int n1h = n1->labelHeight;
    int n2h = n2->labelHeight;


    double n1xmin = n1x - 0.5 * n1w;
    double n2xmin = n2x - 0.5 * n2w;
    double n1ymin = n1y - 0.5 * n1h;
    double n2ymin = n2y - 0.5 * n2h;
    double n1xmax = n1x + 0.5 * n1w;
    double n2xmax = n2x + 0.5 * n2w;
    double n1ymax = n1y + 0.5 * n1h;
    double n2ymax = n2y + 0.5 * n2h;



    double upDifferential = n1ymax - n2ymin;
    double downDifferential = n2ymax - n1ymin;
    double labelCollisionXleft = n2xmax - n1xmin;
    double labelCollisionXright = n1xmax - n2xmin;


    if (upDifferential > 0 && downDifferential > 0)
    {
        // Potential collision
        if (labelCollisionXleft > 0 && labelCollisionXright > 0)
        {
            // Collision
            if (upDifferential > downDifferential)
            {
                // N1 pushes N2 up
                n2->dy =  (n2->dy - 0.02 * n1h * (0.8 + 0.4 * rand()/(double)RAND_MAX));
                collision = true;
            }
            else
            {
                // N1 pushes N2 down
                n2->dy =  (n2->dy + 0.02 * n1h * (0.8 + 0.4 * rand()/(double)RAND_MAX));
                collision = true;
            }
            if (labelCollisionXleft > labelCollisionXright)
            {
                // N1 pushes N2 right
                n2->dx =  (n2->dx + 0.01 * (n1h * 2) * (0.8 + 0.4 * rand()/(double)RAND_MAX));
                collision = true;
            } else
            {
                // N1 pushes N2 left
                n2->dx =  (n2->dx - 0.01 * (n1h * 2) * (0.8 + 0.4 * rand()/double(RAND_MAX)));
                collision = true;
            }
        }
    }

    return collision;
}

