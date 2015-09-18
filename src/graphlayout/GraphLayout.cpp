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
// C++ STL headers
#include <algorithm>
#include <functional>
#include <numeric>
#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>
#include <map>
#include <stdexcept>
//Eigen library
#include <Eigen/Core>

#include "Statistic.h"

// General headers
#include "Graph.h"
#include "Solver.h"
#include "GraphLayout.h"

// Layout Methods include (Layout Methods starts with "LM" )
#include "LayoutMethod.h"
#include "LMKamadaKawai.h"
#include "LMFruchtermanReingold.h"
#include "LMFruchtermanReingoldProportional.h"
#include "LMLinLogModel.h"
#include "LMBinaryStress.h"

// Multilevel techniques
#include "LMFruchtermanReingoldMultilevel.h"
#include "LMFruchtermanReingoldProportionalMultilevel.h"
#include "LMLinLogModelMultilevel.h"
#include "LMBinaryStressMultilevel.h"
// Algebraic and other techniques
#include "LMHighDimensionalEmbedder.h"
#include "LMCircular.h"
#include "LMCircularMinEdge.h"
#include "LMCircularMinCross.h"
#include "LMRandom.h"
#include "LMNothing.h"
#include "LMACE.h"
#include "LMStressMajorization.h"

// Needed by indexed techniques (Kamada-Kawai, BinaryStress)
#include "CGSolver.h"
#include "LNode.h"
#include "LEdge.h"

// Utility methods
#include "GraphLayout.h"
#include "Matcher.h"
#include "Common.h"

using namespace std;
using namespace Eigen;

const char * const GraphLayout::layoutMethods[] = { "Current layout","Kamada-Kawai","Fruchterman-Reingold", "Fruchterman-Reingold (proportional)", "LinLog model", "Binary stress", "Fruchterman-Reingold  (multi-level)", "Fruchterman-Reingold Prop (multi-level)", "LinLog model (multi-level)", "Binary stress (multi-level)", "HDE", "Circular", "Random","Laplacian Embedding","StressMajorization","Circular Min Cross",NULL };

GraphLayout::GraphLayout() : Graph() ,
    methodType( GraphLayout::MethodNothing ), minEdgeLength(std::numeric_limits<double>::max()),
    maxEdgeLength( std::numeric_limits<double>::min() ), maxEdgeDegreeSum(std::numeric_limits<double>::min()),
    minEdgeDegreeSum( std::numeric_limits<double>::max() )
{
    //DEBUG_PRINT("Called GraphLayout constructor");
    _init();
}
/**
 * @ingroup GraphLayout
 * @brief GraphLayout::_init
 * Initialize graph variables, logDegreeMax=0, nDimensions=3
 */
void GraphLayout::_init()
{
    lm = NULL;
    g = this;
    logDegreeMax = 0;    // move in updateStatisticsStats ...
    nDimensions = 3;
}

/**
 * @ingroup GraphLayout
 * @brief GraphLayout::GraphLayout Copy constructor, inherits from Graph copy constructor, ignore origin graph
 * @param orig
 */
GraphLayout::GraphLayout(const GraphLayout& orig) : Graph(orig),
    methodType( GraphLayout::MethodNothing ), minEdgeLength(std::numeric_limits<double>::max()),
    maxEdgeLength( std::numeric_limits<double>::min() ), maxEdgeDegreeSum(std::numeric_limits<double>::min()),
    minEdgeDegreeSum( std::numeric_limits<double>::max() )
{
    this->lm=NULL;
    DEBUG_PRINT("called GraphLayout copy constructor");
    _init();
}

/**
 * @ingroup GraphLayout
 * Set random coordinates for px,py,pz of nodes in interval [-10,10]
 * @brief GraphLayout::initRandomCoordinates
 */
void GraphLayout::initRandomCoordinates()
{
    DEBUG_PRINT("initRandomCoordinates !!");
    unsigned int m=solution.size();
    for (unsigned int i = 0; i < m; i++)
    {  solution[i] = Common::unifRand(-10.0,10.0);
    }
    setNodesPosition(solution);
}
/**
 * @brief GraphLayout::setDimensions Set the layout dimension to be 2 or 3
 * @param d Dimension to use
 */
void GraphLayout::setDimensions(int d)
{  DEBUG_PRINT( "attempting to resize to ndims = " << d << " for |V|=" << nodes.size() << " nodes" );
    nDimensions = d;
    solution.clear();
    solution.resize(nDimensions * nodes.size());
}

/**
 * @ingroup GraphLayout
 * @brief GraphLayout::setNodesPosition
 * @param x Vector containing node positions in the following order p1x,p1y,p1z,p2x,p2y,p2z,...,pnx,pny,pnz
 */
void GraphLayout::setNodesPosition(const vector <double> &x)
{
    for (NodesRand::const_iterator iter1 = nodesRand.begin(); iter1 != nodesRand.end(); ++iter1)
    {
        LNode *n = static_cast<LNode*> (*iter1);
        int index= nDimensions*(n->index -1);
        n->px = x[index];
        n->py = x[index+1];
        nDimensions==2 ? (n->pz = 0) : (n->pz=x[index+2] );
    }
}

/**
 * @ingroup GraphLayout
 * @brief GraphLayout::writeGnuplot Write the graph to a file in gnuplot compliant format
 * The graph can then be plot using gnuplot command "plot graph.dat w l"
 * @param graphname Filename of the output file
 * @param withColors Use colors for edges or not
 */
void GraphLayout::writeGnuplot(string graphname, bool withColors)
{  std::ofstream edges_file;
    string edges_file_name;
    unmarkAllEdges();

    edges_file_name = graphname.append(".dat");
    edges_file.open(edges_file_name.c_str());

    double xi=0,xj=0,yi=0,yj=0,zi=0,zj=0,edgelength=0;
    for (Nodes::const_iterator iter1 = nodes.begin(); iter1 != nodes.end(); ++iter1)
    {  for (Neighbors::const_iterator iter2 = iter1->second->neighbors.begin(); iter2 != iter1->second->neighbors.end(); ++iter2)
        {  if (iter2->second.first->mark == false)
            {
                LNode *n = static_cast<LNode*> (iter1->second);
                xi = n->px;
                yi = n->py;
                zi = n->pz;

                xj = n->px;
                yj = n->py;
                zj =n->pz;

                edgelength=SQR(xi-xj)+SQR(yi-yj)+SQR(zi-zj);

                if (withColors)
                {  edges_file << xi << " " << yi << " " << zi << " " << " " << edgelength << endl;
                    edges_file << xj << " " << yj << " " << zj << " " << " " << edgelength << endl;
                    edges_file << endl << endl;
                }
                else
                {  edges_file << xi << " " << yi << " " << zi << " " << endl;
                    edges_file << xj << " " << yj << " " << zj << " " << endl;
                    edges_file << endl << endl;
                }

                iter2->second.first->mark = true;
            }
        }
    }
    edges_file.close();
}

/**
 * @ingroup GraphLayout
 * @brief GraphLayout::writeGnuplot  Write the graph to a file in gnuplot compliant format
 * The graph can then be plot using gnuplot command "plot graph.dat w l"
 * @param edges_file Write to this output string
 * @param withColors  Use colors for edges or not
 */
void GraphLayout::writeGnuplot(ofstream &edges_file, bool withColors)
{

    unmarkAllEdges();

    double xi=0,xj=0,yi=0,yj=0,zi=0,zj=0,edgelength=0;
    for (Nodes::const_iterator iter1 = nodes.begin(); iter1 != nodes.end(); ++iter1)
    {  for (Neighbors::const_iterator iter2 = iter1->second->neighbors.begin(); iter2 != iter1->second->neighbors.end(); ++iter2)
        {  if (iter2->second.first->mark == false)
            {
                LNode *n = static_cast<LNode*>(iter1->second);
                xi = n->px;
                yi =n->py;
                zi = n->pz;
                xj = n->px;
                yj = n->py;
                zj = n->pz;
                edgelength=SQR(xi-xj)+SQR(yi-yj)+SQR(zi-zj);
                if (withColors)
                {  edges_file << xi << " " << yi << " " << zi << " " << " " << edgelength << endl;
                    edges_file << xj << " " << yj << " " << zj << " " << " " << edgelength << endl;
                    edges_file << endl << endl;
                }
                else
                {  edges_file << xi << " " << yi << " " << zi << " " << endl;
                    edges_file << xj << " " << yj << " " << zj << " " << endl;
                    edges_file << endl << endl;
                }
                iter2->second.first->mark = true;
            }
        }
    }
}
/**
 * @ingroup GraphLayout
 * @brief GraphLayout::getAverageLength Return the average length of edges
 * @return Return the average length of edges
 */
double GraphLayout::getAverageLength()
{  double totalEdgeLenght=0;
    unmarkAllEdges();
    double xi=0,xj=0,yi=0,yj=0,zi=0,zj=0,edgelength=0;
    LNode *n1=NULL, *n2=NULL;
    int nedges=0;

    for (NodesRand::const_iterator iter1=nodesRand.begin(); iter1!=nodesRand.end(); ++iter1)
    {
        n1=(static_cast<LNode*>(*iter1));
        for(NeighborsRand::const_iterator iter2 = n1->neighborsRand.begin(); iter2 != n1->neighborsRand.end(); ++iter2)
        {  n2 = static_cast<LNode*>((*iter2)->second);
            if ((*iter2)->first->mark == false)
            {  xi = n1->px;
                yi = n1->py;
                zi = n1->pz;

                xj = n2->px;
                yj = n2->py;
                zj = n2->pz;

                edgelength = sqrt(pow(xi - xj, 2) + pow(yi - yj, 2) + pow(zi - zj, 2));
                totalEdgeLenght+=edgelength;
                nedges++;
                //edgelengthVector.push_back(edgelength);
            }
            (*iter2)->first->mark = true;
        }
    }
    return totalEdgeLenght/(double)nedges;
}

/**
 * @ingroup GraphLayout
 * @brief GraphLayout::printSolution Print the current solution of the layout optimization problem (only for methods based on CGSolver)
 */
void GraphLayout::printSolution()
{  for (unsigned int i = 0; i < solution.size(); i++)
    {  cerr << solution.at(i) << endl;
    }
}
/**
 * @ingroup GraphLayout
 * @brief GraphLayout::reloadNodeCoordinates Copy node coordinates from nodes to solution
 * @param randomize True if coordinates have to be randomized by a little amount
 */
void GraphLayout::reloadNodeCoordinates(bool randomize)
{  LNode *lnode1=NULL;
    int index = 0;
    solution.resize(nDimensions * nodes.size());
    if (nDimensions==0)
    {
        throw std::range_error("Error, solution must be 2 or 3");
    }
    for (NodesRand::const_iterator iter1=nodesRand.begin(); iter1!=nodesRand.end(); ++iter1)
    {  lnode1 = static_cast<LNode*> (*iter1);
        index = nDimensions*(lnode1->index -1);

        solution[index]     = lnode1->px;
        solution[index + 1] = lnode1->py;
        if ( nDimensions==3 )
            solution[index + 2] = lnode1->pz + randomize* Common::unifRand(-0.5,0.5);
    }
}

/**
 * @ingroup GraphLayout
 * @brief GraphLayout::shakeZ Randomize the z coordinate of nodes by a small amount, needed to avoid infinity or nan when nodes are too close in multilevel methods
 */
void GraphLayout::shakeZ()
{  LNode *n=NULL;
    double factor = pow(log((double)nodes.size()),2);
    //cerr << "SHAKE FACTOR = " << factor << endl;
    for (NodesRand::const_iterator iter1=nodesRand.begin(); iter1!=nodesRand.end(); ++iter1)
    {  n=static_cast<LNode*>(*iter1);
        n->pz += Common::unifRand(-factor,factor);
    }
}

/**
 * @ingroup GraphLayout
 * @brief GraphLayout::~GraphLayout Destructor, clear all memory and uncoarsen graph
 */
GraphLayout::~GraphLayout()
{

    //DEBUG_PRINT( "Called Destructor of GraphLayout" );
    if (lm)
    {  delete lm;
        lm=NULL;
    }
    solution.clear();
    //DEBUG_PRINT( "Exit from GraphLayout destructor" );
}


/**
 * @ingroup GraphLayout
 * @brief GraphLayout::loadTrueDimacs Load a graph in dimacs format (this method is better than the one implemented in Graph)
 * @param is
 */
void GraphLayout::loadTrueDimacs(ifstream &is)
{  string line;
    if (is==NULL)
    {  cerr << "Invalid file, select a file" << endl;
        //exit(0);
    }

    while (getline(is, line))
    {  if (line.size() == 0)
            continue;


        stringstream str(line);

        if (str.get() != 'e')
            continue;

        int nodeId1, nodeId2;

        Common::skipSpaces(str);
        str >> nodeId1;
        Common::skipSpaces(str);
        str >> nodeId2;

        insertNode(nodeId1);
        insertNode(nodeId2);
        insertEdge(nodeId1, nodeId2, 1.0);

    }

    for (Nodes::const_iterator iter1 = nodes.begin(); iter1 != nodes.end(); ++iter1)
    {  LNode *n = static_cast<LNode*>(iter1->second);
        n->degree = 0;
        for (Neighbors::const_iterator iter2 = n->neighbors.begin(); iter2 != n->neighbors.end(); ++iter2)
        {  n->degree += iter2->second.first->weight;
        }

    }

    DEBUG_PRINT(  "(|V|,|E|) = (" << nodes.size() << "," << getEdgesCount() << ")");
}

/**
 * @ingroup GraphLayout
 * @brief GraphLayout::updateLogDegree Update the logarithm of the nodes degree stored in logDegree variable for every node
 */
void GraphLayout::updateLogDegree()
{
    logDegreeMax = 0;
    for (NodesRand::const_iterator iter1=nodesRand.begin(); iter1!=nodesRand.end(); ++iter1)
    {
        LNode *lnode = static_cast<LNode*>(*iter1);
        lnode->logDegree = log(lnode->degree+2.0); // +2 because we want all spheres to be visible, and log(2) > 0.
        //  cerr << "lnode id = " << lnode->id << " logdegree = " << lnode->logDegree << "\n";
        logDegreeMax = std::max(logDegreeMax,lnode->logDegree);
    }
    //cerr << "logDegreeMax" << logDegreeMax << endl;

    if  (coarseGraph)
    {  (static_cast<GraphLayout*>(coarseGraph))->updateLogDegree();
    }
}
/**
 * @ingroup GraphLayout
 * @brief GraphLayout::loadDimacs Load a graph file in dimacs format
 * @param is Input file stream
 */
void GraphLayout::loadDimacs(ifstream &is)
{  if (is==NULL)
    {  cerr << "Invalid file, select a file" << endl;
        throw std::runtime_error(std::string("Invalid file, select another file"));
        //exit(0);
    }
    string line;
    while (getline(is, line))
    {  if (line.size() == 0)
            continue;

        stringstream str(line);

        int nodeId1, nodeId2;

        double weight;
        double coordinates[] = {0.0, 0.0, 0.0};
        int nodesCount;

        str >> nodeId1;
        Common::skipSpaces(str);
        if ( Common::iSkipSpacesReadChar(str, '(')==1)
        {  cerr << "at line=" << line << endl;
        }
        str >> coordinates[0];
        if ( Common::iSkipSpacesReadChar(str, ',')==1)
        {  cerr << "at line=" << line << endl;
        }
        str >> coordinates[1];
        Common::skipSpaces(str);
        if ( Common::iNextChar(str) == ',')
        {
            if ( Common::iSkipSpacesReadChar(str, ',')==1 )
            {  cerr << "at line=" << line << endl;
            }
            str >> coordinates[2];
        }
        if ( Common::iSkipSpacesReadChar(str, ')')==1)
        {  cerr << "at line=" << line << endl;
        }

        str >> nodesCount;

        LNode *n1 = static_cast<LNode*>(insertNode(nodeId1));
        n1->px = coordinates[0];
        n1->py = coordinates[1];
        n1->pz = coordinates[2];

        if (nodesCount==0)
        {  // ignore the next things until a new line begins
            str.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        for (int i = 0; i < nodesCount; i++)
        {  str >> nodeId2;

            if (str.get() == ':')
            {  str >> weight;
            }
            else
            {  str.unget();
                weight = 1;
            }
            insertNode(nodeId2);
            insertEdge(nodeId1, nodeId2, weight);
        }
    }

    for (Nodes::const_iterator iter1 = nodes.begin(); iter1 != nodes.end(); ++iter1)
    {  LNode *n = static_cast<LNode*>(iter1->second);
        n->degree = 0;
        for (Neighbors::const_iterator iter2 = n->neighbors.begin(); iter2 != n->neighbors.end(); ++iter2)
        {  n->degree += iter2->second.first->weight;
        }
    }

    DEBUG_PRINT(  "(|V|,|E|) = (" << nodes.size() << "," << getEdgesCount() << ")");
}

/**
 * @ingroup GraphLayout
 * @brief GraphLayout::loadDimacs Load a graph file in dimacs format
 * @param is Input file stream
 */
void GraphLayout::loadDimacs( const std::string &filename )
{
    ifstream is(filename.c_str());
    if (!is.good())
    {

        return;
    }
    else
        loadDimacs(is);
}

/**
 * @ingroup GraphLayout
 * @brief GraphLayout::writeDimacs Write the graph with node coordinates in dimacs format
 * @param os Output file stream to write on
 */
void GraphLayout::writeDimacs(ofstream &os)
{  for (Nodes::const_iterator iter1 = nodes.begin(); iter1 != nodes.end(); ++iter1)
    {  LNode *n = static_cast<LNode*>(iter1->second);
        os << n->id << " ( " << n->px << " , " << n->py << " , " << n->pz << " ) " << n->neighbors.size() << " ";
        for (Neighbors::const_iterator iter2 = iter1->second->neighbors.begin(); iter2 != iter1->second->neighbors.end(); ++iter2)
        {  os << iter2->first << ":" << iter2->second.first->weight << " ";
        }
        os << endl;
    }

}
/**
 * @ingroup GraphLayout
 * @brief GraphLayout::print Print method, for debug purpose
 */
void GraphLayout::print()
{

    for (Nodes::const_iterator iter1 = nodes.begin(); iter1 != nodes.end(); ++iter1)
    {  LNode *n = static_cast<LNode*>(iter1->second);

        DEBUG_PRINT( "Node id=" << iter1->first << " " << n->id << " index=" << n->index << " deg=" << n->degree << " ");
        DEBUG_PRINT( "\tNeighbors list= ");
        for (Neighbors::const_iterator iter2 = n->neighbors.begin(); iter2 != n->neighbors.end(); ++iter2)
        {  DEBUG_PRINT( iter2->second.second->id << ":" << iter2->second.first->weight << " ");
        }
    }
    /*
    for (int i = 1; i <= (int )nodes.size(); i++)
    {  Nodes::iterator iter;

        if ((iter = nodes.find(i)) == nodes.end())
        {  DEBUG_PRINT( "err !! missing id = " << i << "\n");
            DEBUG_PRINT("Nodes.size() = " << nodes.size() );
        }
    }
*/
}
/**
 * @ingroup GraphLayout
 * @brief GraphLayout::init
 * @param _methodType
 * @param nDim Number of dimensions to layout the graph
 * @param randomize True if node coordinates have to be randomized by a certain amount
 * @param shake True if node coordinate z has to be randomized of a certain amount
 * @return
 */
int GraphLayout::init(int _methodType, int nDim, bool randomize, bool shake)
{
    methodType=_methodType;
    g = this; // reset the viz graph

    if( lm!=NULL )
    {
        delete lm;
        lm = NULL;
    }
    this->nDimensions = nDim;
    setDimensions(nDimensions);

    if(randomize)
        initRandomCoordinates(); // fill solution with random number

    reloadNodeCoordinates(shake);
    setNodesPosition(solution);  // copy numbers from solution to nodes

    switch(methodType)
    {
    // NON multilevel techniques
    case MethodKamadaKawai:
    {
        lm = static_cast<LayoutMethod*>( new LMKamadaKawai());
        break;
    }
    case MethodFruchtermanReingold:
    {  lm = static_cast<LayoutMethod*>(new LMFruchtermanReingold());
        break;
    }
    case MethodFruchtermanReingoldProportional:
    {  lm =static_cast<LayoutMethod*>( new LMFruchtermanReingoldProportional());
        break;
    }
    case MethodLinLogModel:
    {  lm = static_cast<LayoutMethod*>(new LMLinLogModel());
        break;
    }
    case MethodBinaryStress:
    {  lm = static_cast<LayoutMethod*>( new LMBinaryStress());
        break;
    }
    case MethodFruchtermanReingoldMultilevel:
    {
        lm = static_cast<LayoutMethod*>(new LMFruchtermanReingoldMultilevel());
        break;
    }
        // Multilevel techniques
    case MethodFruchtermanReingoldProportionalMultilevel:
    {
        lm = static_cast<LayoutMethod*>( new LMFruchtermanReingoldProportionalMultilevel());
        break;
    }
    case MethodLinLogModelMultilevel:
    {  lm = static_cast<LayoutMethod*>( new LMLinLogModelMultilevel());
        break;
    }
    case MethodBinaryStressMultilevel:
    {  lm = static_cast<LayoutMethod*>( new LMBinaryStressMultilevel());
        break;
    }
        // Algebraic and other techniques
    case MethodHighDimensionalEmbedder:
    {  lm =static_cast<LayoutMethod*>(new LMHighDimensionalEmbedder());
        break;
    }
    case MethodCircularLayout:
    {
        lm = static_cast<LayoutMethod*>( new LMCircular());
        break;
    }
    case MethodRandom:
    {  lm = static_cast<LayoutMethod*>( new LMRandom());
        break;
    }

    case MethodNothing:
    {  lm = static_cast<LayoutMethod*>( new LMNothing());
        break;
    }
    case MethodACE:
    {  lm = static_cast<LayoutMethod*>( new LMACE());
        break;
    }
    case MethodStressMajorization:
    {  lm = static_cast<LayoutMethod*>( new LMStressMajorization());
        break;
    }
    case MethodCircularLayoutMinCross:
    {
        DEBUG_PRINT( "YES I KNOW THIS FEATURE IS EXPERIMENTAL");
        // XXX Experimental feature
        lm = static_cast<LayoutMethod*> (new LMCircularMinCross());
        break;
    }
    default:
    {
        throw std::range_error("Layout method not valid");
    }
    }

    lm->init(this,nDimensions);

    updateLogDegree();
    return 0;
}

/**
 * @ingroup GraphLayout
 * @brief GraphLayout::steps This method makes a step for the selected layout algorithm, it must be called once per frame in a simulation
 * @param n Number of steps to do (ignored)
 * @return 0 if the step was successfull, -1 otherwise (if you didn't initialized the layout method)
 */
int GraphLayout::steps(int n)
{
    DEBUG_PRINT("Steps...");
    int res=0;
    if (lm!=NULL)
    {  (statsNodesCount == 0) ? (res=1) : (res=lm->steps(n));
    }
    else
    {
        //    cerr << "First init LayoutMethod!" << endl;
        return -1;
    }

    return res;
}

/**
 * @ingroup GraphLayout
 * @brief GraphLayout::normalizeCoordinates Normalize the coordinates values in [0,1] interval
 */
void GraphLayout::normalizeCoordinates()
{  double max = 0;
    LNode *n1=NULL;

    for (NodesRand::const_iterator iter1 = nodesRand.begin(); iter1 != nodesRand.end(); ++iter1)
    {  n1 = static_cast<LNode*>(*iter1);
        max = MAX(max, MAX(n1->px,MAX(n1->py,n1->pz)));
    }

    double invMax = 1./max;

    for (NodesRand::const_iterator iter1 = nodesRand.begin(); iter1 != nodesRand.end(); ++iter1)
    {  n1= static_cast<LNode*>(*iter1);
        n1->px *= invMax;
        n1->py *= invMax;
        n1->pz *= invMax;
    }
}

/**
 * @ingroup GraphLayout
 * @brief GraphLayout::updateStaticStats Update the graph statistics, max node degree, minimum node degree, linear running time in # of nodes
 */
void GraphLayout::updateStaticStats()
{
    // This function must NOT iterate on every node, we must only keep two pairs of nodeIndex->maxDegree, nodeIndex2->minDegree
    // and update them for every edge insertion - remotion
    this->statsMaxNodeDegree = 0;
    this->statsMinNodeDegree = 1E9;
    for (NodesRand::const_iterator iter1 = nodesRand.begin(); iter1 != nodesRand.end(); ++iter1)
    {
        Node *n1=(*iter1);
        statsMaxNodeDegree = std::max(statsMaxNodeDegree,n1->degree);
        statsMinNodeDegree = std::min(statsMinNodeDegree,n1->degree);
    }
}
/**
 * @ingroup GraphLayout
 * @brief GraphLayout::updateDynamicStats Update the dynamic stats of the graphs, max edge length, min edge length, degree sum
 */
void GraphLayout::updateDynamicStats()
{
    minEdgeLength = std::numeric_limits<double>::max();
    maxEdgeLength = std::numeric_limits<double>::min();
    //maxEdgeDegreeSum = std::numeric_limits<double>::min();
    //minEdgeDegreeSum =  std::numeric_limits<double>::max();
    for (NodesRand::const_iterator iter1=nodesRand.begin(); iter1!=nodesRand.end(); ++iter1)
    {
        LNode *n1=static_cast<LNode*>(*iter1);

        for(NeighborsRand::const_iterator iter2 = n1->neighborsRand.begin(); iter2 != n1->neighborsRand.end(); ++iter2)
        {
            LNode *n2 = static_cast<LNode*>((*iter2)->second);
            if (n1->index > n2->index)
            {
                double  d = sqrt(SQR(n1->px - n2->px) + SQR(n1->py - n2->py) + SQR(n1->pz - n2->pz));
                maxEdgeLength = std::max(maxEdgeLength,d);
                minEdgeLength = std::min(minEdgeLength,d);
                //sum =  n1->degree + n2->degree;
                //maxEdgeDegreeSum = std::max(maxEdgeDegreeSum,sum);
                //minEdgeDegreeSum = std::min(minEdgeDegreeSum,sum);
            }
        }
    }
    // cerr << "maxEdgeLength=" << maxEdgeLength << "\n";
    // if  (coarseGraph) {
    //    ((GraphLayout *)coarseGraph)->updateDynamicStats();
    // }
}

/**
 * @brief GraphLayout::lmOk A method to check if the layout can be computed given some boundaries on running time and storage size
 * @param lmIndex The layout method to use
 * @return True if the layout method for the graph can be computed without too slow running time (avoid N^3 time cost for huge graphs, and N^2 storage for big graphs)
 */
bool GraphLayout::lmOk(int lmIndex)
{
    bool isMultiComponent = (countConnectedComponents()>1);
    // A variable that is true if |V|^2 cost computation are feasible both in terms of memory and cpu
    bool canAffordNsquaredComputations = (statsNodesCount < 2000);
    // A variable that is true if |V|^3 cost computation are feasible both in terms of memory and cpu
    bool canAffordNcubeComputations = (statsNodesCount<2000);
    bool returnValue=false;
    switch (lmIndex)
    {
    case MethodNothing:
    {
        returnValue=true;
    }
        break;
    case  MethodKamadaKawai:
    {
        returnValue = canAffordNsquaredComputations && statsEdgesCount!=0 && !hasNegativeWeightCycles;
    }
        break;
        // FORCE DIRECTED METHODS
    case MethodFruchtermanReingold:
    case MethodFruchtermanReingoldProportional:
    case MethodLinLogModel:
    {
        returnValue = true;
    }
        break;
    case MethodBinaryStress:
    {
        returnValue = canAffordNsquaredComputations;
    }
        break;
        // MULTILEVEL METHODS
    case MethodFruchtermanReingoldMultilevel :
    case MethodFruchtermanReingoldProportionalMultilevel :
    case MethodLinLogModelMultilevel:
    {
        returnValue = true;
    }
        break;
    case MethodBinaryStressMultilevel:  //because here we don't have a barnes-hut schema
    {
        returnValue = statsNodesCount< (250000);
    }
        break;
        // ALGEBRAIC AND OTHERS
    case MethodHighDimensionalEmbedder :
    {
        returnValue = !isMultiComponent;
    }
        break;
    case MethodCircularLayout :
    case MethodCircularLayoutMinCross:
    case MethodRandom :
    {
        returnValue=true;
    }
        break;
    case MethodACE :
    case MethodStressMajorization :
    {
        returnValue = canAffordNcubeComputations && !isMultiComponent;
    }
        break;
    default:
        cerr << "GraphLayout::lmOK error: Method not contempled" << endl;
    }

    return returnValue;
}

/**
 *  @ingroup GraphLayout
 * @brief GraphLayout::checkNans Check if the node coordinates have NaN or Infinities, it's for debug purpose. If nans are detected an error message is printed
 */
void GraphLayout::checkNans()
{  LNode *n=NULL;

    for ( NodesRand::const_iterator iter = nodesRand.begin(); iter!=nodesRand.end(); ++iter)
    {  n=static_cast<LNode*>(*iter);
        if ( isnan(n->px) || isnan(n->py) || isnan(n->pz)  )
        {  cerr << "Nan/Inf detected at " << n->id << endl;
        }
        if ( isinf(n->px) || isinf(n->py) || isinf(n->pz) )
            cerr << "Inf detected at " << n->id << endl;
    }
}

/**
 * @ingroup GraphLayout
 * @brief GraphLayout::getMemoryFootprintInBytes Estimate the total memory size of this graph in bytes
 * @return The memory footprint of the graph as sum of nodes and edges and other variables contained in the class, useful to limit multilevel methods
 */
unsigned int GraphLayout::getMemoryFootprintInBytes()
{
    unsigned int memoryFootPrint=0;
    memoryFootPrint+=sizeof(*this);
    memoryFootPrint+=sizeof(LNode)*statsNodesCount;
    memoryFootPrint+=sizeof(LEdge)*statsEdgesCount*2;
    memoryFootPrint+=sizeof(Matches)*sizeof(LNode*)*statsNodesCount;
    memoryFootPrint+=sizeof(LNode*)*statsNodesCount;
    memoryFootPrint+=sizeof(double)*solution.size();

    return memoryFootPrint;
}

