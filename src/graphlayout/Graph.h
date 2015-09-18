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


#ifndef _GRAPH_H
#define _GRAPH_H

#include <Eigen/Core>
#include <Eigen/Sparse>

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <map>
#include <set>
#include "Node.h"
#include "Edge.h"
#include "Common.h"

using namespace std;
using namespace Eigen;

/**
*  @ingroup GraphLayout
*  @class Graph
*  @brief The class Graph is the base class for a graph, it has no information of node positioning or other kind of algorithms of placement.
*  The base data-structure to store nodes and edges is in double form. Nodes are stored as pointers in a vector and in a map, the vector has fast iteration
*  on it, while the map has faster lookup. Some typedefs make life easier, Nodes typedef is the map, NodesRand is the vector, giving fast random access.
*  The algorithms implemented are the typical algorithms needed for graph visit, while efficiency is always considered as first thing.
**/

typedef vector<Edge *> AllEdges;
typedef map<int, Node *> Nodes;
typedef vector<Node *> NodesRand;
typedef pair<Node *, Node *> NodePair;
typedef map<Node *, NodePair> MatchesDown;
typedef map<Node *, Node *> Matches;

class Graph
{
public:
    Graph();
    Graph(const Graph& orig);
    virtual ~Graph();

    virtual Graph* clone() const
    {  return new Graph( *this );
    }

    virtual Node *nodeProvider(int id)
    {  return new Node(id, 1);
    }
    // Inlining the following frequently internally used methods means faster code...
    Node *insertNode();
    Node *insertNode(int id);

    Edge *insertEdge(int id1, int id2, double weight = 1.0);
private:    // this function must be made private becaus
    Edge *insertEdgeAddWeight(int id1, int id2);
public:
    void print();
    void printStats();
    void writeDimacs(ofstream &os);
    void writeGRAPHEUR(ofstream &os);
    void writeDOT(ofstream &os);
    void writeMatches(ofstream &os);
    int getEdgesCount();
    bool  hasUndirectedEdge(int source,int target);
    Edge *getEdge(int source, int target);

    void loadDIMACS(const std::string &filename);
    void loadDIMACS(istream& is);

    Graph * coarsen(int matchingType);

    void unCoarsen();

    void randomize();
    void unmarkAllEdges();
    void unmarkAllNodes();
    Graph *normalizeIds();
    Graph* normalizeIndex();
    void addComponent(Graph *g, Node *parent);
    bool removeNode(int id);
    bool removeEdge(int from, int to);

    const Nodes &getNodes() const;
    Node* getNode(int nodeId);
    bool nodeExists(int nodeId) const;

    void computeAPSPFloydWarshall();
    void computeAPSPJohnson();

    const MatrixXd & getShortestPathMatrix();
    const MatrixXd & getShortestPathMatrixFloydWarshall();
    double getWeight( int source,int target);
    inline double getWeight(Node *n1, Node *n2);
    double getDiameter();
    double getWeightedDegree(Node *n);
    double getTotalEdgeWeight();
    double getWeightUndirected(Node *n1, Node *n2);
    inline bool isEdge(Node *n1, Node *n2);
    const Eigen::SparseMatrix<double> &getSparseLaplacianMatrix();
    const Eigen::SparseMatrix<double> &getSparseAdjacencyMatrix();

    inline void initializeSingleSource(Node *source);
    inline void relax(Node*u, Node*v);
    inline bool bellmanFord(Node *);
    void dijkstra(Node *source,Node *target=NULL);
    std::pair<double,vector<Node*> > getNodesDistance(Node *source,Node *target);
    void bfs(Node *source, int component=-1); // in this method we merge bfs and bfs-component method.

    void dfs(void);
    void dfsVisit(Node *source);

    double getDegreeCentrality(Node *n);
    double getClosenessCentrality(Node *n);

    int countConnectedComponents(void);
    int countConnectedComponents2(void);
    Node* findNodeWithLongestDistanceFromSource(Node *source, set<int> &excludeNode );

    void tokenizeLine(const string& str, vector<string>& tokens, const string& delimiters = " "); // XXX funzione da rivedere

    // Maximal independent set algorithms
    Node* getRandomNode();
    std::vector<int> getMaximalIndependentSet();
    std::vector<int> getMaximalIndependentSetSequential();
    std::vector<int> getMaximalIndependentSetVerticesLuby();
    void  markMaximalIndependentSetSequential();

#define EXPERIMENTAL_FEATURES
#ifdef EXPERIMENTAL_FEATURES
    // Bron-Kerbosh maximal clique
    vector< set<int> > getMaximalCliques(int k);
    void bronKerboshMaximalClique(set<int> &R, set<int> &P, set<int> &X, vector< set<int> > &cliques, unsigned int kLower);

    Node *getHighestDegreeNeighbor(Node *src);

    // Kruskal MST implementation from Sedgewic
    // This method takes a memory conservative approach in building the MST, by only checking as marked the MST edges
    // and returning a list of pair of nodes which creates that MST

    vector< pair<Node*, Node*> > getKruskalMST();
    // This method creates a new MST graph, it's slower because of memory allocations and nodes-edges insertions
    // No need to manually delete the mst subgraph!
    Graph* getKruskalMSTasSubGraph();
    std::vector<Node*> getTreeCentersNodes();
#endif

    // Graph variables
    //AllEdges allEdges; unused
    Nodes nodes;
    NodesRand nodesRand;
    MatrixXd SPmatrix;

    // per coarsening:
    Matches coarseMatches;
    Graph *coarseGraph;

    // for Minimum spanning tree
    Graph *mst;

    int statsNodesCount;
    int statsEdgesCount;
    int statsComponentsCount;
    double statsMinNodeDegree;
    double statsMaxNodeDegree;
    bool hasNegativeWeightCycles;

    bool forceAPSP_LaplacianComputation;
private:

    Eigen::MatrixXd denseLaplacianMatrix;
    Eigen::SparseMatrix<double> sparseLaplacianMatrix;
    Eigen::SparseMatrix<double> sparseAdjacencyMatrix;


    void _init();

};

#endif  /* _GRAPH_H */


