/****************************************************************************
**
** Copyright (C) 2010,2011,2012 Michele Dallachiesa (michele.dallachiesa@gmail.com)
** Copyright (C) 2010,2011,2012 Carlo Nicolini (nicolini.carlo@gmail.com)
** All rights reserved.
**
** Warning: This program is protected by copyright law and international
** treaties. Unauthorized reproduction and distribution of this program,
** or any portion of it, may result in severe civil and criminal penalties,
** and will be persecuted to the maximum extent possible under the law.
**
****************************************************************************/

#include <Eigen/Core>

#include <fstream>
#include <vector>
#include <list>
#include <queue>
#include <sstream>
#include <string>
#include <limits>
#include <iterator>
#include <stdexcept>

#include "limits.h"
#include "Graph.h"
#include "Matcher.h"
#include "Common.h"
#include "Timer.h"
#include "DisjointSet.h"

using namespace std;
using namespace Eigen;

/**
 * @ingroup GraphLayout
 * @brief The CompareDistance class
 * Needed as functor object when ordering nodes for Dijkstra algorithm
 * Key the nodes by their ID, if the distance is the same, key by their ID
 */
class CompareDistance
{
public:

    bool operator()(Node* n1, Node* n2) // Returns true if n1.distance
    {  if (n1->distance > n2->distance)
        {  // cout << "node " << n1->id << " d= " << n1->distance << " node " << n2->id << " d= " << n2->distance << endl;
            return true;
        }
        if (n1->distance == n2->distance)
        {  if (n1->id > n2->id)
                return true;
            return false;
        }
        else
            return false;
    }
};
/**
 * @ingroup GraphLayout
 * @brief Graph::_init set some graph statistics to zero (# of nodes, edges and components)
 */
void Graph::_init()
{
    this->statsNodesCount = 0;
    this->statsEdgesCount = 0;
    this->statsComponentsCount=0;
    this->statsMinNodeDegree = 0;
    this->statsMaxNodeDegree = 0;
    this->coarseGraph = NULL;
    this->mst=NULL;
    this->hasNegativeWeightCycles=false;
    this->forceAPSP_LaplacianComputation=false;
}
/**
 * @ingroup GraphLayout
 * @brief Graph::Graph Default constructor
 */
Graph::Graph()
{
    DEBUG_PRINT("called Graph constructor");
    _init();

}
/**
 * @ingroup GraphLayout
 * @brief Graph::Graph Copy constructor, ignores original graph
 * @param orig original graph
 */
Graph::Graph(const Graph& orig)
{  DEBUG_PRINT("called Graph copy constructor");
    _init();
}

/**
 * @ingroup GraphLayout
 * @brief Graph::printStats Print graph statistics (only in debug mode)
 */
void Graph::printStats()
{  DEBUG_PRINT("printStats: (|V|,|E|) = (" << nodes.size() << ","  << statsEdgesCount << ")");
    for (NodesRand::iterator iter1 = nodesRand.begin(); iter1 != nodesRand.end(); ++iter1)
    {
        Node *u=(*iter1);
        DEBUG_PRINT("Nodes: " << u->id );
    }
}

/**
 * @ingroup GraphLayout
 * @brief Graph::~Graph
 * Graph destructor, deletes all the nodes in nodesRand container, the coarseGraph and the minimal spanning tree if created
 */
Graph::~Graph()
{
    DEBUG_PRINT("Called Graph destructor");
    unCoarsen();

    for(unsigned int i = 0; i < nodesRand.size(); i++)
    {  if ( nodesRand[i]!=NULL)
            delete nodesRand[i];
    }
    if (mst)
        delete mst;
    DEBUG_PRINT("Exit from Graph destructor");
}

/**
 * @ingroup GraphLayout
 * @brief Graph::insertNode
 * Insert a node with given ID. If the nodes is already present return its pointer, otherwise allocate new space.
 * Node is put in the map and vector containers parallely.
 * @param id
 * @return A pointer to newly allocated Node
 */
Node *Graph::insertNode(int id)
{  Nodes::iterator iter;
    if ((iter = nodes.find(id)) != nodes.end())
    {  return iter->second;
    }
    else
    {  Node *nid =  nodeProvider(id);
        // XXX valgrind when runned from GraphInsight says possibly lost block
        nodes[id]=nid;
        nid->index=++statsNodesCount;
        nodesRand.push_back(nid);
        // Reset the stats nodes count so that it must be recomputed
        statsComponentsCount=0;
        // The minimum node degree is 0 now because the node has no neighbors!
        this->statsMinNodeDegree=0;
        return nid;
    }
    // TODO per neighbors: http://stackoverflow.com/questions/2311881/c-how-to-insert-pair-into-map
}

/**
 * @ingroup GraphLayout
 * @brief Graph::randomize
 * Randomize vector<Node*> and neighborsRand for every node with std::random_shuffle
 */
void Graph::randomize()
{
    random_shuffle(nodesRand.begin(), nodesRand.end());
    for (NodesRand::iterator iter1 = nodesRand.begin(); iter1 != nodesRand.end(); ++iter1)
    {  Node *node = *iter1;
        random_shuffle(node->neighborsRand.begin(), node->neighborsRand.end());
    }
}

/**
 * @ingroup GraphLayout
 * @brief Graph::insertEdge Insert an edge in the graph, but before ensure that the edge is not already present.
 * If the nodes of the edge are not already in the graph, they are added
 * @param id1
 * @param id2
 * @param weight
 * @return A pointer to newly allocated edge, NULL if the edge can't be added
 */
Edge *Graph::insertEdge(int id1, int id2, double weight)
{
    // Avoid inserting loops
    if (id1==id2)
        return NULL;

    // First search if the selected nodes exist, if they don't exist create them
    Node *node1 = NULL; //nodes[id1];
    Node *node2 = NULL; //nodes[id2];

    Nodes::iterator iter1,iter2;
    if ((iter1 = nodes.find(id1)) != nodes.end())
        node1 = iter1->second;
    else
        node1 = insertNode(id1);

    if ((iter2 = nodes.find(id2)) != nodes.end())
        node2 = iter2->second;
    else
        node2 = insertNode(id2);

    Neighbors::iterator iter;
    // If the id2 is not found in the neighbors map of node1
    if ( (iter = node1->neighbors.find(id2)) != node1->neighbors.end() )
    {
        return iter->second.first;
    }

    if ( (iter = node2->neighbors.find(id1)) != node2->neighbors.end() )
    {
        return iter->second.first;
    }

    Edge *edge = new Edge(weight);
    //edge->direction = id1 > id2; commented until we ignore edge direction

    // XXX valgrind when runned from GraphInsight says possibly lost block
    node1->neighbors[id2] = Neighbor(edge, node2);
    node2->neighbors[id1] = Neighbor(edge, node1);

    node1->neighborsRand.push_back(&node1->neighbors[id2]);
    node2->neighborsRand.push_back(&node2->neighbors[id1]);

    node1->degree+=weight;
    node2->degree+=weight;

    statsEdgesCount++;
    // Reset the stats components count so that it must be recomputed
    // This operation can be avoided by deeply thinking when we really have to RECOMPUTE component
    statsComponentsCount=0;

    return edge;
}

/**
 * @ingroup GraphLayout
 * @brief Graph::insertEdgeAddWeight
 * Insert and edge, update the nodes weight/degree
 * @param id1
 * @param id2
 * @return A pointer to newly allocated edge
 */
Edge *Graph::insertEdgeAddWeight(int id1, int id2)
{  Neighbors::iterator iter;

    Node *node1 = nodes[id1];
    if ((iter = node1->neighbors.find(id2)) != node1->neighbors.end())
    {
        (*iter).second.first->weight++;
        //   LOG(1,1,"id1=%d id2=%d doing edge weight inc", id1, id2);
        return iter->second.first;
    }

    // LOG(1,1,"id1=%d id2=%d adding edge", id1, id2);
    return insertEdge(id1, id2);
}

/**
 * @ingroup GraphLayout
 * @brief Graph::unmarkAllEdges
 * Sets the boolean variable "mark" false for every edge
 */
void Graph::unmarkAllEdges()
{
    for (NodesRand::iterator iter1 = nodesRand.begin(); iter1 != nodesRand.end(); ++iter1)
    {
        Node *u=(*iter1);
        if (u->neighborsRand.empty())
            continue;
        for (NeighborsRand::iterator iter2 = u->neighborsRand.begin(); iter2 != u->neighborsRand.end(); ++iter2)
        {
            (*iter2)->first->mark=false;
        }
    }
}

/**
 * @ingroup GraphLayout
 * @brief Graph::unmarkAllNodes
 * Set the boolean variable "mark" false for every node
 */
void Graph::unmarkAllNodes()
{  for (NodesRand::iterator iter1 = nodesRand.begin(); iter1 != nodesRand.end(); ++iter1)
    {  (*iter1)->mark = false;
    }
}
/**
 * @ingroup GraphLayout
 * @brief Graph::print Print all the graph nodes with their inner variables, id, index, degree, component and neighbors list
 */
void Graph::print()
{  for (Nodes::iterator iter1 = nodes.begin(); iter1 != nodes.end(); ++iter1)
    {
        DEBUG_PRINT("Node ID = " << iter1->second->id << " Index= " << iter1->second->index << " : deg = " << iter1->second->degree << " ComponentID= " << iter1->second->component);
        DEBUG_PRINT("Neighbors -> ");
        for (Neighbors::iterator iter2 = iter1->second->neighbors.begin(); iter2 != iter1->second->neighbors.end(); ++iter2)
        {  DEBUG_PRINT(iter2->first << ":" << iter2->second.first->weight << " ");
        }
    }
}

/**
 * @ingroup GraphLayout
 * @brief Graph::writeDimacs
 * Save nodes to file in DIMACS compatible format
 * @param os ouput file stream to write on
 */
void Graph::writeDimacs(ofstream &os)
{  for (Nodes::iterator iter1 = nodes.begin(); iter1 != nodes.end(); ++iter1)
    {  os << (iter1->second->id) << " ( 0.0, 0.0 ) " << (iter1->second->neighbors.size()) << " ";
        for (Neighbors::iterator iter2 = iter1->second->neighbors.begin(); iter2 != iter1->second->neighbors.end(); ++iter2)
        {  os << iter2->first << " ";
        }
        os << endl;
    }
}

/**
 * @ingroup GraphLayout
 * @brief Graph::writeDOT
 * Save nodes to file in .dot compatible format (a very simple version of it )
 * @param os ouput file stream to write on
 */
void Graph::writeDOT(ofstream &os)
{  os << "graph graphname {\n";
    unmarkAllEdges();
    for (Nodes::iterator iter1 = nodes.begin(); iter1 != nodes.end(); ++iter1)
    {  for (Neighbors::iterator iter2 = iter1->second->neighbors.begin(); iter2 != iter1->second->neighbors.end(); ++iter2)
        {  if (iter2->second.first->mark == false)
            {  const char *s = " [ shape=point   ] ;";
                os << (iter1->second->id) << s << "\n";
                os << iter2->first << s << "\n";
                os << (iter1->second->id) << " -- " << iter2->first << ";\n";
            }
            iter2->second.first->mark = true;
        }
    }
    os << "}" << endl;
}

/**
 * @ingroup GraphLayout
 * @brief Graph::writeMatches Write the nodes matching (useful to check graph coarsening algorithms)
 * @param os output file stream to write on
 */
void Graph::writeMatches(ofstream &os)
{  for(Matches::iterator iter = coarseMatches.begin(); iter != coarseMatches.end(); ++iter)
    {  os << iter->first->id << " " << iter->second->id << "\n";
    }
}

/**
 * @ingroup GraphLayout
 * @brief Graph::writeGRAPHEUR
 * Save output for GRAPHEUR format
 * @param os output file stream to write on
 */
void Graph::writeGRAPHEUR(ofstream &os)
{  os << "Order,x,y,Name,G-distances\n";

    for (Nodes::iterator iter1 = nodes.begin(); iter1 != nodes.end(); ++iter1)
    {
        os << (iter1->second->id) << ",0.000000,0.000000,node " << (iter1->second->neighbors.size());
        for (Neighbors::iterator iter2 = iter1->second->neighbors.begin(); iter2 != iter1->second->neighbors.end(); ++iter2)
        {  os << "," << iter2->first << ":1.000000";
        }
        os << "\n";
    }
}

/**
 * @ingroup GraphLayout
 * @brief Graph::getEdgesCount
 * Count the number of edges, only if they are not already been counted.
 * @return number of edges
 */
int Graph::getEdgesCount()
{   
    if ( this->statsEdgesCount ==0 )
    {
        int count = 0;
        unmarkAllEdges();
        for (NodesRand::iterator iter1 = nodesRand.begin(); iter1 != nodesRand.end(); ++iter1)
        {
            Node *u=(*iter1);
            if (u->neighborsRand.empty())
                continue;
            for (NeighborsRand::iterator iter2 = u->neighborsRand.begin(); iter2 != u->neighborsRand.end(); ++iter2)
            {
                Edge *e = (*iter2)->first;
                if (!e->mark)
                    ++count;
                e->mark=true;
            }
        }
        statsEdgesCount=count;
    }
    return statsEdgesCount;
}

/**
 * @brief Graph::hasUndirectedEdge
 * @param source
 * @param target
 * @return true if the edge is on both source and target neighbors list, false otherwise
 */
bool Graph::hasUndirectedEdge(int source, int target)
{
    if (source==target)
        return false;

    // First search if the selected nodes exist, if they don't exist create them
    Node *node1 = NULL;
    Node *node2 = NULL;

    Nodes::iterator iter1,iter2;
    if ((iter1 = nodes.find(source)) != nodes.end())
        node1 = iter1->second;
    else
        return false;

    if ((iter2 = nodes.find(target)) != nodes.end())
        node2 = iter2->second;
    else
        return false;

    // THIS BLOCK IS MARKED AS Variable 'iter' is assigned a value that is never used. Why???
    Neighbors::iterator iter;
    // If the id2 is not found in the neighbors map of node1
    if ( !((iter = node1->neighbors.find(target)) != node1->neighbors.end()) )
        return false;

    // If the id2 is not found in the neighbors map of node1
    if ( !((iter = node2->neighbors.find(source)) != node2->neighbors.end()) )
        return false;

    return true;
}

/**
 * @brief Graph::getEdge
 * @param source
 * @param target
 * @return
 */
Edge * Graph::getEdge(int source, int target)
{
    if (source==target)
        return NULL;

    // First search if the selected nodes exist, if they don't exist create them
    Node *node1 = NULL;

    Nodes::iterator iter1;
    if ((iter1 = nodes.find(source)) != nodes.end())
    {
        node1 = iter1->second;
         Neighbors::iterator iter;
         if ( ((iter = node1->neighbors.find(target)) != node1->neighbors.end()) )
             return iter->second.first;
         else
             return NULL;
    }
    else
        return NULL;

}

/**
 * @ingroup GraphLayout
 * @brief Graph::coarsen
 * Coarse the current graph, it creates a new memory area containing the coarse graph, can be called as Graph::coarsegraph
 *@param matchingType Typically set to MATCHING_LIGHT_NODE
 * @return A pointer to new coarsened graph
 */
Graph* Graph::coarsen(int matchingType)
{  Matcher matcher(this, matchingType);

    if(coarseGraph) // coarse version già presente! XXX potrebbe essere variato il tipo di matching... al momento comunque usiamo sempre LIGHT_NODE.
        return coarseGraph;

    // randomize();
    unmarkAllNodes();
    // qui viene clonato l'oggetto dinamico Graph, che potrebbe essere esteso.
    // nel nostro caso lo è ed è GraphLayoutGL.
    coarseGraph = this->clone() ;
    int nextNodeId = 1;

    for (NodesRand::iterator iter = nodesRand.begin(); iter != nodesRand.end(); ++iter)
    {
        Node *node = *iter;
        if (!node->mark)
        {  Node *node1 = node;
            Node *node2 = matcher.find(node1);
            Node *newNode = coarseGraph->insertNode(nextNodeId);
            newNode->weight = node1->weight;
            // newGraph->matchesDown[newNode].first = node1;
            coarseMatches[node1] = newNode;
            if (node2)
            {  coarseMatches[node2] = newNode;
                // newGraph->matchesDown[newNode].second = node2;

                newNode->weight += node2->weight;
                node2->mark = true;
            }
            else
            {  //newGraph->matchesDown[newNode].second = NULL;
            }
            node1->mark = true;
            nextNodeId++;
        }
    }

    for (Nodes::iterator iter1 = nodes.begin(); iter1 != nodes.end(); ++iter1)
    {  for (Neighbors::iterator iter2 = iter1->second->neighbors.begin(); iter2 != iter1->second->neighbors.end(); ++iter2)
        {  if (coarseMatches[iter1->second] != coarseMatches[iter2->second.second])
                coarseGraph->insertEdgeAddWeight(coarseMatches[iter1->second]->id, coarseMatches[iter2->second.second]->id);
        }
    }

    DEBUG_PRINT( "(|V|,|E|) = ( " << coarseGraph->nodes.size() << " , " << coarseGraph->getEdgesCount() <<
                 " ), lowerbound is |V| = " << nodes.size() / 2 << ", diff = " <<
                 coarseGraph->nodes.size() - nodes.size() / 2 );
    return coarseGraph;
}

/**
 * @ingroup GraphLayout
 * @brief Graph::normalizeIds
 * Makes the ids sequential from 1 to N
* @return The pointer to current graph
 */
Graph *Graph::normalizeIds()
{  map<int, int> mapping;

    Graph *graph = this->clone() ; //new Graph();

    int i = 0;
    for (Nodes::iterator iter = nodes.begin(); iter != nodes.end(); ++iter)
    {  mapping[iter->first] = ++i;
    }

    for (Nodes::iterator iter1 = nodes.begin(); iter1 != nodes.end(); ++iter1)
    {  graph->insertNode(mapping[iter1->first]);
        for (Neighbors::iterator iter2 = iter1->second->neighbors.begin(); iter2 != iter1->second->neighbors.end(); ++iter2)
        {  graph->insertNode(mapping[iter2->first]);
            graph->insertEdge(mapping[iter1->first], mapping[iter2->first]);
        }
    }
    return graph;
}

/**
 * @brief Graph::normalizeIndex Normalize the nodes indices from 1 to N
 * @return A pointer to the normalized graph
 */
Graph* Graph::normalizeIndex()
{

    Graph *graph = this->clone() ; //new Graph();

    for (Nodes::iterator iter1 = nodes.begin(); iter1 != nodes.end(); ++iter1)
    {  graph->insertNode(iter1->second->id);

        for (Neighbors::iterator iter2 = iter1->second->neighbors.begin(); iter2 != iter1->second->neighbors.end(); ++iter2)
        {  graph->insertNode(iter2->second.second->id);
            graph->insertEdge(iter1->second->id, iter2->second.second->id);
        }
    }
    return graph;
}
/**
 * @ingroup GraphLayout
 * @brief Graph::tokenizeLine
 * @param str string to tokenize
 * @param tokens tokens as vector of strings
 * @param delimiters The delimiter to use, given as string of char
 */
void Graph::tokenizeLine(const string& str, vector<string>& tokens, const string& delimiters)
{  // Skip delimiters at beginning.
    string::size_type lastPos = str.find_first_not_of(delimiters, 0);
    // Find first "non-delimiter".
    string::size_type pos = str.find_first_of(delimiters, lastPos);

    while (string::npos != pos || string::npos != lastPos)
    {  // Found a token, add it to the vector.
        tokens.push_back(str.substr(lastPos, pos - lastPos));
        // Skip delimiters.  Note the "not_of"
        lastPos = str.find_first_not_of(delimiters, pos);
        // Find next "non-delimiter"
        pos = str.find_first_of(delimiters, lastPos);
    }
}

/**
 * @ingroup GraphLayout
 * @brief Graph::loadDIMACS Load a graph from input file stream in DIMACS format
 * The dimacs file format specifics is simple: on every row you specify node id, position, degree and then list of neighbors nodes, for example
 * node with id=1, position x=0.5, y=0.3, degree 2 and with nodes 2 with weight 0.2 and node 3 with weight 1.1  as neighbors has the following corresponding line
 *\code
1 (0.5,0.3) 2 2:0.2 3:1.1
2 (0.0,0.0) 3 1:1 3:10.1 4:1
3 (0.0,0.0) 3 1:1 2:10.1 4:1
4 (0.0,0.0) 2 2:1 3:1
5 (0.0,0.0) 1 6:1
6 (0.0,0.0) 1 5:1
7 (0.0,0.0) 1 8:1
8 (0.0,0.0) 1 7:1
 *\endcode
 * @param is Filename to load
 */
void Graph::loadDIMACS(const string &filename)
{
    ifstream is(filename.c_str());
    if (!is.good())
    {

        return;
    }
    else
        this->loadDIMACS(is);
}

/**
 * @ingroup GraphLayout
 * @brief Graph::loadDIMACS Load a graph from input file stream in DIMACS format
 * The dimacs file format specifics is simple: on every row you specify node id, position, degree and then list of neighbors nodes, for example
 * node with id=1, position x=0.5, y=0.3, degree 2 and with nodes 2 with weight 0.2 and node 3 with weight 1.1  as neighbors has the following corresponding line
 *\code
1 (0.5,0.3) 2 2:0.2 3:1.1
2 (0.0,0.0) 3 1:1 3:10.1 4:1
3 (0.0,0.0) 3 1:1 2:10.1 4:1
4 (0.0,0.0) 2 2:1 3:1
5 (0.0,0.0) 1 6:1
6 (0.0,0.0) 1 5:1
7 (0.0,0.0) 1 8:1
8 (0.0,0.0) 1 7:1
 *\endcode
 * @param is Input file stream
 */
void Graph::loadDIMACS(istream& is)
{  string line;
    while (getline(is, line))
    {  vector<string> tokens;
        // split the string using the "(" ")" and "," token
        tokenizeLine(line, tokens, "( ) , :  \t");
        int nodeID;
        int nodeneigh;
        double degree;
        double x, y;
        double weightSum = 0;
        // Read the nodeID, its position, and its degree
        istringstream nodeStr(tokens[0]);
        istringstream posX(tokens[1]);
        istringstream posY(tokens[2]);
        istringstream deg(tokens[3]);
        nodeStr >> nodeID;
        insertNode(nodeID);
        posX >> x;
        posY >> y;
        deg >> degree;

        if ((int) (tokens.size() - 4) == degree)
        {  for (vector<string>::iterator iToken = tokens.begin() + 4; iToken != tokens.end(); ++iToken)
            {  istringstream car(*iToken);

                car >> nodeneigh;
                insertNode(nodeneigh);
                insertEdge(nodeID, nodeneigh);

                weightSum += 1;
            }
        }
        else
        {
            for (vector<string>::iterator iToken = tokens.begin() + 4; iToken != tokens.end(); iToken = iToken + 2)
            {  istringstream car(*iToken);
                istringstream w(*(iToken + 1));
                double weight = 0.0;
                car >> nodeneigh;
                w >> weight;
                insertNode(nodeneigh);
                insertEdge(nodeID, nodeneigh, weight);
                weightSum += weight;
                //cerr << "Neighbors -> " << nodeneigh << " weight " << weight << " " << endl;
            }
        }

        if (degree != weightSum)
        {  DEBUG_PRINT("WARNING: Check that sum(weights)=degree for node " << nodeID);
        }
    }
    DEBUG_PRINT("(|V|,|E|) = (" << nodes.size() << " , " << getEdgesCount() << " ) " << "|C| = " << countConnectedComponents() );
}

/**
 * @ingroup GraphLayout
 * @brief Graph::addComponent Add a full graph as separate component, after having added the component g, puts an edge between nodes of g and parent graph
 * @param g the full graph component to add to this
 * @param parent node
 */
void Graph::addComponent(Graph *g, Node *parent = NULL)
{  int maxId = 0;
    for (Nodes::iterator iter1 = nodes.begin(); iter1 != nodes.end(); ++iter1)
    {  if (maxId < iter1->second->id)
            maxId = iter1->second->id;
    }
    //int first = 1;
    for (Nodes::iterator iter1 = g->nodes.begin(); iter1 != g->nodes.end(); ++iter1)
    {    insertNode(maxId + iter1->second->id);
        for (Neighbors::iterator iter2 = iter1->second->neighbors.begin(); iter2 != iter1->second->neighbors.end(); ++iter2)
        {  insertNode(maxId + iter2->first);
            insertEdge(maxId + iter1->second->id, maxId + iter2->first);
            // non occorre considerare il parent per il multilevel anche qui, perchè tutti i nodi vengono comunque passati anche nel punto precedente.
        }
    }
}

/**
 * @ingroup GraphLayout
 * @brief Graph::getLaplacianMatrix
 * @return Get the sparse laplacian matrix of the graph
 */
const Eigen::SparseMatrix<double> &Graph::getSparseLaplacianMatrix()
{
    sparseLaplacianMatrix.resize(statsNodesCount,statsNodesCount);
    sparseLaplacianMatrix.reserve(statsEdgesCount);
    for (NodesRand::iterator iter1=nodesRand.begin(); iter1!=nodesRand.end(); ++iter1)
    {
        int i=(*iter1)->index -1;
        double deg = (*iter1)->degree;
        sparseLaplacianMatrix.insert(i,i) = deg;

        for(NeighborsRand::const_iterator iter2 = (*iter1)->neighborsRand.begin(); iter2 != (*iter1)->neighborsRand.end(); ++iter2)
        {
            int j=(*iter2)->second->index - 1;
            // Edge weight
            sparseLaplacianMatrix.insert(i,j) = - (*iter2)->first->weight;
        }
    }
    sparseLaplacianMatrix.makeCompressed();
    return sparseLaplacianMatrix;
}

/**
 * @ingroup GraphLayout
 * @brief Graph::getAdjacencyMatrix
 * @return Get the sparse adjacency matrix of the graph
 */
const Eigen::SparseMatrix<double> &Graph::getSparseAdjacencyMatrix()
{
    sparseAdjacencyMatrix.resize(statsNodesCount,statsNodesCount);
    sparseAdjacencyMatrix.reserve(statsEdgesCount);
    for (NodesRand::iterator iter1=nodesRand.begin(); iter1!=nodesRand.end(); ++iter1)
    {
        unsigned int i=(*iter1)->index -1;
        for(NeighborsRand::const_iterator iter2 = (*iter1)->neighborsRand.begin(); iter2 != (*iter1)->neighborsRand.end(); ++iter2)
        {
            unsigned j=(*iter2)->second->index - 1;
            // Edge weight
            sparseAdjacencyMatrix.insert(i,j) =  (*iter2)->first->weight;
        }
    }
    sparseAdjacencyMatrix.makeCompressed();
    return sparseAdjacencyMatrix;
}

/**
 * @ingroup GraphLayout
 * @brief Graph::isEdge
 *Check if an edge exists between two ndoes
 * @param n1
 * @param n2
 * @return True if edge exists, False otherwise
 */
bool Graph::isEdge(Node *n1, Node *n2)
{  Neighbors::iterator iter = n1->neighbors.find(n2->id);

    if (iter != n1->neighbors.end())
        return true;
    else
        return false;
}

/**
 * @ingroup GraphLayout
 * @brief Graph::getWeight
 * @param n1
 * @param n2
 * @return The edge weight between two selected nodes, if the edge doesn't exists, returns INFINITY
 */
double Graph::getWeight(Node *n1, Node *n2)
{  if (n1->id == n2->id) return 0;  //no self loops

    Neighbors::iterator iter = n1->neighbors.find(n2->id);

    if (iter != n1->neighbors.end())
        return iter->second.first->weight;
    else
        return numeric_limits<double>::max();
}

/**
 * @ingroup GraphLayout
 * @brief Graph::getWeightUndirected
 * @param n1
 * @param n2
 * @return The edge weight between two selected nodes, if the edge doesn't exists, returns INFINITY
 */
double Graph::getWeightUndirected(Node *n1, Node *n2)
{  if (n1->id == n2->id) return 0;  //no self loops

    Neighbors::iterator iter1 = n1->neighbors.find(n2->id);
    Neighbors::iterator iter2 = n2->neighbors.find(n1->id);

    if (iter1 != n1->neighbors.end() && iter2 != n2->neighbors.end())
        return iter1->second.first->weight;
    else
        return numeric_limits<double>::max();
}

/**
 * @brief Graph::computeAPSPFloydWarshall
 */
void Graph::computeAPSPFloydWarshall()
{
    int n = nodes.size();
    cerr << "Computing APSP Floyd..., resizing to " << n  ;
    SPmatrix.resize(n ,n );
    int i, j, k;
    Nodes::iterator iter1 = nodes.begin();
    Nodes::iterator iter2 = nodes.begin();
    // w is the edge weight: 0 if i==j, HUGENUMBER if i-j is not a edge, weight of edge i-j otherwise
    double w;

    for (i = 0; i < n; ++i)
    {  for (j = 0; j < n; ++j)
        {  w = getWeight(iter1->second, iter2->second);
            if (w == numeric_limits<double>::max())
                SPmatrix(i,j)= numeric_limits<double>::max();
            else
                SPmatrix(i,j)= w;

            ++iter2;
        }
        iter2 = nodes.begin();
        ++iter1;
    }
    // Now the dynamic programming procedure
    for (k = 0; k < n; ++k)
    {  for (i = 0; i < n; ++i)
        {  for (j = 0; j < n; ++j)
            {  if (SPmatrix(i,k) + SPmatrix(k,j)  < SPmatrix(i,j) )
                    SPmatrix(i, j) = SPmatrix(i, k)  + SPmatrix(k, j);
            }
        }
    }
    cerr << "Done" << endl;
    forceAPSP_LaplacianComputation=false;
}


/**
 * @brief Graph::computeAPSPJohnson
 */
void Graph::computeAPSPJohnson()
{
    int n = nodesRand.size();
    if (SPmatrix.cols()==0 || SPmatrix.cols()!=n)
        this->forceAPSP_LaplacianComputation=true;
    cerr << "Computing APSP matrix Johnson..." ;
    SPmatrix.setZero(n,n);
    insertNode(INT_MAX);  // here is a node very improbabile (impossible) ID
    for (Nodes::iterator u = nodes.begin(); u != nodes.end(); ++u)
    {  if (u->second->id != INT_MAX)
            insertEdge(INT_MAX, u->second->id, 0.0);
    }

    if ( bellmanFord(nodesRand.front()) == true )
    {
        map<Node*, double> h;    // here we use this map instead of using a double value for every node to spare memory
        for (NodesRand::const_iterator u = nodesRand.begin(); u != nodesRand.end(); ++u)
            h[(*u)] = (*u)->distance;

        removeNode(INT_MAX); // here is a node very improbabile (impossible) ID

        for (NodesRand::const_iterator u = nodesRand.begin(); u != nodesRand.end(); ++u)
        {
            dijkstra((*u));
            int i = (*u)->index-1;
            for (NodesRand::const_iterator v = nodesRand.begin(); v != nodesRand.end(); ++v)
            {
                int j = (*v)->index-1;
                SPmatrix(i , j) = (*v)->distance + h[(*v)] - h[(*u)];
            }
        }
    }
    else
    {
        this->hasNegativeWeightCycles=true;
        cerr << "has negative weight cycles, falling back to Floyd algo, deleting dummy node " << INT_MAX  << " before" << endl;
        removeNode(INT_MAX);
        this->computeAPSPFloydWarshall();
    }
    forceAPSP_LaplacianComputation=false;
    cerr << "Done" << endl;

}

/**
 * @ingroup GraphLayout
 * @brief Graph::unCoarsen Uncoarsen the graph, delete the previously allocated coarse graphs, freeing memory
 */
void Graph::unCoarsen()
{  if(coarseGraph)
    {  delete coarseGraph;
        coarseGraph = NULL;
    }
}

/**
 * @ingroup GraphLayout
 * @brief Graph::initializeSingleSource
 * Init the distance at 0 for the selected node, set the distance to INFINITY for the other nodes
 * @param source
 */
void Graph::initializeSingleSource(Node *source)
{  for (NodesRand::iterator iter1 = nodesRand.begin(); iter1 != nodesRand.end(); ++iter1)
    {  (*iter1)->distance = numeric_limits<double>::max();

    }
    source->distance = 0.0;
}

/**
 * @ingroup GraphLayout
 * @brief Graph::relax
 * Relax the edge, see CLRS for details
 * @param u
 * @param v
 */
void Graph::relax(Node *u, Node *v)
{

    if (v->distance > u->distance + getWeight(u, v))
    {  //cerr << "Relax " << u->id << " -- " << v->id << " w= " << getWeight(u,v) << " " << "\n\t" <<
        //  "because " << v->distance << " > " << u->distance << " + " << getWeight(u,v) << endl;
        v->distance = u->distance + getWeight(u, v);
        //cerr << "Now node " << v->id << ".distance = " << v->distance << endl;
    }
}

/**
 * @ingroup GraphLayout
 * @brief Graph::bellmanFord
 * Run the Bellman-Ford algorithm for the source node
 * @param source
 * @return True if the nodes has no negative-cycles
 */
bool Graph::bellmanFord(Node *source)
{
    initializeSingleSource(source);
    int n = nodes.size();
    for (int i = 0; i < n - 1; i++)
    {
        // Attraction between edges
        for (NodesRand::const_iterator iter1=nodesRand.begin(); iter1!=nodesRand.end(); ++iter1)
        {
            Node *u = (*iter1);
            for(NeighborsRand::const_iterator iter2 = u->neighborsRand.begin(); iter2 != u->neighborsRand.end(); ++iter2)
            {
                Node *v = ((*iter2)->second);
                if (v->distance > u->distance + (*iter2)->first->weight )
                    v->distance = u->distance + (*iter2)->first->weight;
            }
        }
    }

    unmarkAllEdges();
    // Check for negative weight cycles
    this->hasNegativeWeightCycles=false;
    // Run another iteration, at the next we can check if there is a negative cycle
    for (NodesRand::const_iterator iter1=nodesRand.begin(); iter1!=nodesRand.end(); ++iter1)
    {
        Node *u = (*iter1);
        for(NeighborsRand::const_iterator iter2 = u->neighborsRand.begin(); iter2 != u->neighborsRand.end(); ++iter2)
        {
            Node *v = ((*iter2)->second);
            if (v->distance > u->distance + getWeight(u, v) )
            {
                v->distance = u->distance + (*iter2)->first->weight;
                this->hasNegativeWeightCycles=true;
                return false;
            }
        }
    }

    /*
    for (NodesRand::iterator iter1 = nodesRand.begin(); iter1 != nodesRand.end(); ++iter1)
    {
        Node *u = (*iter1);
        for (NeighborsRand::iterator iter2 = u->neighborsRand.begin(); iter2 != u->neighborsRand.end(); ++iter2)
        {
            Node *v = ((*iter2)->second);
            if (v->distance > u->distance + getWeight(u, v))
            {
                this->hasNegativeWeightCycles=true;
                return false; // this means that the graph has negative weight cycles
            }
        }
    }
    */
    return true;
}

/**
 * @brief Graph::getShortestPathMatrix
 * @return
 */
const MatrixXd &Graph::getShortestPathMatrix(void)
{
    if (forceAPSP_LaplacianComputation || SPmatrix.cols()==0 || SPmatrix.cols()!=(nodesRand.size()) )
    {
        this->computeAPSPJohnson();
    }
    return SPmatrix;
}

/**
 * @ingroup GraphLayout
 * @brief Graph::getTotalEdgeWeight
 * Get the total edges weight of the graph.
 * @return Total sum of edges weight in the graph
 **/
double Graph::getTotalEdgeWeight()
{
    double totalWeight=0.0;
    unmarkAllEdges();
    for (NodesRand::const_iterator iter = nodesRand.begin(); iter!=nodesRand.end();++iter)
    {
        Node *u=(*iter);
        for (NeighborsRand::const_iterator iter = u->neighborsRand.begin(); iter != u->neighborsRand.end(); ++iter)
        {
            Edge*e = (*iter)->first;
            if (!e->mark)
            {
                totalWeight+=e->weight;
                e->mark=true;
            }
        }
    }
    return totalWeight;
}

/**
 * @ingroup GraphLayout
 * @brief Graph::getWeightedDegree
 * Get the weighted degree of a node. Weighted degree is the sum of weight of edges indicent to the node
 * @param n
 * @return The weighted degree
 **/
double Graph::getWeightedDegree(Node *n)
{
    double weightedDegree=0.0;
    for (NeighborsRand::iterator iter = n->neighborsRand.begin(); iter!=n->neighborsRand.end();++iter)
    {
        Edge *e = (*iter)->first;
        weightedDegree+=e->weight;
    }
    return weightedDegree;
}

/**
 * @ingroup GraphLayout
 * @brief Graph::getDiameter
 * Get the diameter of the graph without allocating the APSP matrix. Can be very slow for big graphs, but it's memory conservative
 * @return Graph diameter, i.e. distance between the two farthest nodes in the graph
 **/
double Graph::getDiameter()
{
    double diameter=0.0;
    for (NodesRand::const_iterator iter = nodesRand.begin(); iter!=nodesRand.end();++iter)
    {
        dijkstra(*iter);
        for (NodesRand::const_iterator iter2 = nodesRand.begin(); iter2!=nodesRand.end();++iter2)
        {
            diameter=std::max(diameter,(*iter2)->distance);
        }
    }
    return diameter;
}

/**
 * @ingroup GraphLayout
 * @brief Graph::dijkstra
 * Run the Dijkstra algorithm between two nodes source and target. It sets the distances from source node to target node
 * @param source
 * @param target
 **/
void Graph::dijkstra(Node *source,Node *target)
{
    initializeSingleSource(source);
    // Create the min priority queue of nodes keyed by ascending distance value
    //priority_queue<Node*, vector<Node*>, CompareDistance > Q;
    priority_queue<Node*, vector<Node*>, CompareDistance > Q;
    // fill the priority queue with the nodes, naturally the node with distance 0 will be
    // at the top of the priority_queue
    Q.push(source);
    Node *u;
    while ( !Q.empty() )
    {  u = Q.top();
        if (target!=NULL && target==u)
            break;
        Q.pop();
        for (NeighborsRand::const_iterator iter = u->neighborsRand.begin(); iter != u->neighborsRand.end(); ++iter)
        {
            Node *v = (*iter)->second;
            Edge *e = (*iter)->first;
            if (v->distance > u->distance + e->weight) // relax the edge
            {
                v->distance = u->distance + e->weight;
                Q.push(v);
            }
        }
    }
}

/**
 * @ingroup GraphLayout
* @brief Graph)sDistance
* Get nodes graph-theoretic distances using a modified version of Dijkstra algorithm.
* See Sedgewick and wikipedia page: http://en.wikipedia.org/wiki/Dijkstra%27s_algorithm#Pseudocode
* The returned value is a pair containing the distance of the two nodes and one of the possible shortest paths between them
 * @param source
 * @param target
 * @return The distance as first element of the pair, the list of visited nodes as second element of the pair
 **/
std::pair<double,vector<Node*> > Graph::getNodesDistance(Node *source, Node *target)
{
    initializeSingleSource(source);
    // Create the min priority queue of nodes keyed by ascending distance value
    //priority_queue<Node*, vector<Node*>, CompareDistance > Q;
    priority_queue<Node*, vector<Node*>, CompareDistance > Q;
    // fill the priority queue with the nodes, naturally the node with distance 0 will be
    // at the top of the priority_queue
    map<Node*,Node*> predecessors;
    for (NodesRand::const_iterator iter= nodesRand.begin(); iter!=nodesRand.end();++iter)
        predecessors[*iter]=NULL;

    Q.push(source);
    Node *u;
    while ( !Q.empty() )
    {  u = Q.top();
        if (target!=NULL && target==u)
            break;
        Q.pop();
        for (NeighborsRand::const_iterator iter = u->neighborsRand.begin(); iter != u->neighborsRand.end(); ++iter)
        {
            Node *v = (*iter)->second;
            Edge *e = (*iter)->first;
            if (v->distance > u->distance + e->weight) // relax the edge
            {
                v->distance = u->distance + e->weight;
                predecessors[v]=u;   // tracks the nodes closest predecessor in the path
                Q.push(v);
            }
        }
    }
    vector<Node*> path;
    u = target;
    while (predecessors[u]!=NULL)
    {
        path.push_back(predecessors[u]);
        u=predecessors[u];
    }
    std::reverse(path.begin(),path.end());
    path.push_back(target);

    return std::pair<double, vector<Node*> > ( target->distance, path );
}

/**
 * @ingroup GraphLayout
 * @brief Graph::bfs Run a breadth-first search on unweighted graph. If you want to keep edges weight in account to compute distances, use Dijkstra algo instead. This implementation also marks nodes connected component
 * @param source Source node where to start the visit
 * @param component Component to mark nodes of this breadth-first visit
 **/
void Graph::bfs(Node *source, int component)
{  if (source == NULL)
    {  DEBUG_PRINT( "BFS::NODE is null");
        return;
    }
    if (source->neighborsRand.empty())
    {  source->mark=true;
        source->color = BLACK;
        source->component=component;    // Added 5 november to correct a bug for singleton nodes
        source->distance = numeric_limits<double>::max();
        return;
    }
    // makes a breadth first search visit - see Cormen Chapter 22 to understand the implementation
    for (NodesRand::const_iterator iter1 = nodesRand.begin(); iter1 != nodesRand.end(); ++iter1)
    {  (*iter1)->color = WHITE;
        (*iter1)->distance = numeric_limits<double>::max();
    }
    source->color     = GRAY;
    source->distance = 0.0;

    queue <Node*> Q;
    Q.push(source);

    Node *u=NULL;

    while ( !Q.empty() )
    {  u = Q.front();
        Q.pop();

        for (NeighborsRand::const_iterator v = u->neighborsRand.begin(); v != u->neighborsRand.end(); ++v)
        {  Node *w = (*v)->second;
            if ( w->color == WHITE )
            {  w->color = GRAY;
                w->distance = u->distance + 1  ;
                if (component!=-1)
                    w->component=component; // this is to treat double use of bfs as simple bfs and as bfs+components checking when used with no arguments
                Q.push(w);
            }
        }
        u->color = BLACK;
        u->mark=true;
        if (component!=-1)  // this is to treat double use of bfs as simple bfs and as bfs+components checking when used with no arguments
            u->component=component;
    }
}

/**
 * @ingroup GraphLayout
 * @brief Graph::dfs Make a depth-first visit of the graph
 *
\code
color[u] <- GRAY  White vertex u has just been discovered.
time <- time+1
d[u] <- time
for each v ∈ Adj[u]  Explore edge (u, v).
do if color[v] = WHITE
then π[v] <- u
DFS-VISIT(v)
color[u] <- BLACK  Blacken u; it is finished.
f [u] <- time <- time+1
* \endcode
 **/
// For DFS algorithm
static int dfstime=0;
void Graph::dfs(void)
{
    /*
for each vertex u ∈ V[G]
    do color[u] <- WHITE
        π[u]<- NIL
time <- 0
for each vertex u ∈ V[G]
    do if color[u] = WHITE
        then DFS-VISIT(u)
*/
    for (NodesRand::const_iterator iter1 = nodesRand.begin(); iter1 != nodesRand.end(); ++iter1)
        (*iter1)->color = WHITE;

    dfstime=0;
    for (NodesRand::const_iterator iter1 = nodesRand.begin(); iter1 != nodesRand.end(); ++iter1)
    {
        Node *u = (*iter1);
        if ( u->color == WHITE )
        {  dfsVisit(u);
        }
    }
}

/**
 * @ingroup GraphLayout
 * @brief Graph::dfsVisit Make a depth-first visit of the graph from a given node
\code
color[u] <- GRAY  White vertex u has just been discovered.
time <- time+1
d[u] <- time
for each v ∈ Adj[u]  Explore edge (u, v).
do if color[v] = WHITE
then π[v] <- u
DFS-VISIT(v)
color[u] <- BLACK  Blacken u; it is finished.
f [u] <- time <- time+1
*\endcode
 * @param source Source node where to start the visit
 **/
void Graph::dfsVisit(Node *source)
{
    source->color = GRAY;
    dfstime++;
    source->distance=dfstime;
    for (NeighborsRand::const_iterator iter = source->neighborsRand.begin(); iter != source->neighborsRand.end(); ++iter)
    {
        Node *v = (*iter)->second;
        if ( v->color == WHITE )
            dfsVisit(v);
    }
    source->color = BLACK;
    source->mark = true;
}

/**
 * @ingroup GraphLayout
 * @brief Graph::removeNode Remove a node, slow method
 * @param id
 * @return True if the node has been removed, false if the node is not found or similar things...
 **/
bool Graph::removeNode(int id)
{
    Nodes::iterator iter;
    DEBUG_PRINT( "Removing node id=" << id );
    if((iter = nodes.find(id)) == nodes.end())
    {
        return false;
    }
    Node *n = iter->second;
    /*
    // Count the degree of incident edges
    double incidentDegree = 0.0;
    for (NeighborsRand::const_iterator iter = n->neighborsRand.begin();iter!=n->neighborsRand.end();++iter)
    {
        Edge *e = static_cast<Edge*>((*iter)->first);
        incidentDegree+=e->weight;
    }
    */
    for (Neighbors::const_iterator iterNeighMap = n->neighbors.begin(); iterNeighMap != n->neighbors.end(); ++iterNeighMap)
    {
        Edge *e = static_cast<Edge*>(iterNeighMap->second.first);
        statsEdgesCount--;
        iterNeighMap->second.second->degree-=e->weight;
        delete e; // delete edge (same on both sides!!!)
        for(NeighborsRand::iterator iter2 = iterNeighMap->second.second->neighborsRand.begin();  iter2 != iterNeighMap->second.second->neighborsRand.end(); ++iter2)  //non const because values are modified
        {
            if((*iter2)->second->id == id)
            {  iterNeighMap->second.second->neighborsRand.erase(iter2);
                break;
            }
        }
        iterNeighMap->second.second->neighbors.erase(id); // delete neighbor on the other side
        // is edge delete on the other side?
        // remove also from NeighborsRand.
        //cerr << "removing neighbor " << id << " from " << iter1->second.second->id << "\n";
    }
    n->neighbors.clear();
    n->neighborsRand.clear();

    // <- & -> neighbors + edge removed
    // remove from nodes (std::map) and nodesrand:
    nodes.erase(id);

    // Delete node from nodesRand (std::vector)
    for (NodesRand::iterator iter1 = nodesRand.begin(); iter1 != nodesRand.end(); ++iter1)
    {  if (n == *iter1)
        {  nodesRand.erase(iter1);
            break;
        }
    }

    // Renormalize indices and update statsMinNodeDegree, statsMaxNodeDegree
    int baseIndex=0;
    double tmpMaxNodeDegree=0,tmpMinNodeDegree=std::numeric_limits<double>::max();
    for (NodesRand::const_iterator iter1 = nodesRand.begin(); iter1 != nodesRand.end(); ++iter1)
    {
        Node *n = (*iter1);
        n->index = ++baseIndex;
        tmpMaxNodeDegree = std::max(tmpMaxNodeDegree,n->degree);
        tmpMinNodeDegree = std::min(tmpMinNodeDegree,n->degree);
    }
    this->statsMaxNodeDegree=tmpMaxNodeDegree;
    this->statsMinNodeDegree=tmpMinNodeDegree;

    delete n;
    statsNodesCount--;
    // Reset the stats components count so that it must be recomputed
    statsComponentsCount=0;
    return true;
}

/**
 * @ingroup GraphLayout
 * @brief Graph::removeEdge Remove the edge between two nodes
 * @param from Node 1 of the edge
 * @param to Node 2  of the edge
 * @return true if the node was removed, false otherwise (if edge has already been removed or extremum nodes don't exist)
 **/
bool Graph::removeEdge(int from, int to)
{
    if (from==to)
        return false;
    if (nodes.find(from)==nodes.end() )
        return false;
    if (nodes.find(to)==nodes.end() )
        return false;

    Node *fromNode = nodes[from];
    Node *toNode = nodes[to];

    // Remove the edge from neighborsrand on both sides
    double sumWeights=0.0;
    for(NeighborsRand::iterator iter2 = fromNode->neighborsRand.begin(); iter2 != fromNode->neighborsRand.end(); ++iter2)
    {
        if ((*iter2)->second->id == to)
        {
            Edge *e = (*iter2)->first;
            sumWeights+=e->weight;
            double w =1.0;// e->weight
            if (e)
            {
                w = e->weight;
                delete e;
                e=NULL;
            }
            fromNode->neighborsRand.erase(iter2);
            fromNode->degree-=w;
            statsEdgesCount--;
            break;
        }
    }

    // No need to delete the edge for the second time, otherwise a mem-leak appears, here just remove the node from the vector neighborsRand
    for(NeighborsRand::iterator iter2 = toNode->neighborsRand.begin(); iter2 != toNode->neighborsRand.end(); ++iter2)
    {
        Node *neighNode = (*iter2)->second;
        if(neighNode->id == from)
        {
            toNode->neighborsRand.erase(iter2);
            break;
        }
    }
    toNode->degree-=sumWeights;  // decrease the degree

    // We check if the neighbors exists before erasing them! No need to delete the Edge explicitly, is already deleted
    if (fromNode->neighbors.find(to)!=fromNode->neighbors.end())
    {
        fromNode->neighbors.erase(to);
    }
    if (toNode->neighbors.find(from)!=toNode->neighbors.end())
    {
        toNode->neighbors.erase(from);
    }

    // Reset the stats components count so that it must be recomputed
    statsComponentsCount=0;
    return true;
}

/**
  * @ingroup GraphLayout
  * @brief Get a const reference to the map<int,Node*>
  * @return Get a const reference to the map<int,Node*>
**/
const Nodes& Graph::getNodes() const
{
    return nodes;
}

/**
  * @ingroup GraphLayout
  * @brief Get the pointer to the specified node
  * @return Get the pointer to the specified node if it exists, otherwise return null
**/
Node* Graph::getNode(int nodeId)
{
    if (nodeExists(nodeId))
    {

#ifndef WIN32
        return this->nodes.at(nodeId);
#else
        return this->nodes[nodeId];
#endif
    }
    else
        return NULL;
}
/**
 * @brief Graph::nodeExists
 * @param nodeId
 * @return
 */
bool Graph::nodeExists(int nodeId) const
{
    return (this->nodes.find(nodeId)!=this->nodes.end());
}

double Graph::getWeight(int source, int target)
{
    if (nodes.find(source)!=nodes.end() && nodes.find(target)!=nodes.end())
    {
        return getWeight(nodes[source],nodes[target]);
    }
    else
        return 0.0;
}

/**
 * @ingroup GraphLayout
 * @brief Graph::countConnectedComponents
 * @return The number of weakly-connected components
 * This method is fast and additionally marks the component which every node belongs to
 **/
int Graph::countConnectedComponents(void)
{
    if (this==NULL)
        throw std::logic_error("Can't assign NULL");
    if (nodes.empty())
        return 0;
    if (this->statsComponentsCount!=0)
        return statsComponentsCount;

    int ncomponents=0;
    unmarkAllNodes();

    // Count connected components O(|V| + |E|) with no memory requirements
    for (NodesRand::const_iterator iter1 = nodesRand.begin(); iter1 != nodesRand.end(); ++iter1)
    {  Node *n = (*iter1);
        n->color = WHITE;
        n->component = 0;
        n->mark=false;
    }

    for (NodesRand::const_iterator iter1 = nodesRand.begin(); iter1 != nodesRand.end(); ++iter1)
    {  Node *n = (*iter1);
        if (!n->mark)
        {
            bfs(n,ncomponents++);
        }
        // This makes the algorithm faster when a singular node is encountered
    }
    statsComponentsCount=ncomponents;
    Timer timer;timer.start();
    // Normalize node components (XXX added 5 november 2012)
    int seq=0;
    map<int,int> comp2sequential;
    for (NodesRand::const_iterator iter1 = nodesRand.begin(); iter1 != nodesRand.end(); ++iter1)
    {
        Node *n = (*iter1);
        if (comp2sequential.find(n->component)==comp2sequential.end())
        {    comp2sequential[n->component]=seq;
            ++seq;
        }
    }

    for (NodesRand::const_iterator iter1 = nodesRand.begin(); iter1 != nodesRand.end(); ++iter1)
    {
        Node *n = (*iter1);
        n->component=comp2sequential[n->component];
    }
    DEBUG_PRINT( "Renormalization took " << timer.getElapsedTimeInMilliSec() << " [ms]" );

    return statsComponentsCount;
}

/**
 * @ingroup GraphLayout
 * @brief Graph::getDegreeCentrality
 * Get the degree centrality of a node http://en.wikipedia.org/wiki/Centrality#Degree_centrality
 * @param n node to evaluate degree centrality
 * @return the degree centrality of node
 **/
double Graph::getDegreeCentrality(Node *n)
{  return (n->degree)/(double (nodes.size() -1. ));
}

/**
 * @ingroup GraphLayout
 * @brief Graph::getClosenessCentrality
 * Get closeness centrality of a node, see http://toreopsahl.com/2010/03/20/closeness-centrality-in-networks-with-disconnected-components/
 * @param n node to evaluate closeness centrality
 * @return the closeness centrality
 **/
double Graph::getClosenessCentrality(Node *n)
{  double closenessCentrality=0;
    initializeSingleSource(n);
    for (NodesRand::const_iterator u = nodesRand.begin(); u != nodesRand.end(); ++u)
    {  if ((*u) == n)
            continue;
        else
        {   bfs((*u));
            closenessCentrality += n->distance;
        }
    }
    return closenessCentrality/(double (nodes.size() -1));
}

/**
 *@ingroup GraphLayout
 * @brief Graph::getRandomNode Get the pointer to a node chosen randomly
 * @return  The randomly selected node
 **/
Node *Graph::getRandomNode()
{
    try
    {
        return nodesRand.at(rand()%statsNodesCount);
    }
    catch (std::out_of_range &out)
    {
        throw std::out_of_range(out.what());
    }
}

/**
 *@ingroup GraphLayout
 * @brief Graph::getMaximalIndependentSet
 * A graph-destructive version of maximal indendent set algorithm
 * @return The indices of the maximal independent set
 **/
std::vector<int> Graph::getMaximalIndependentSet()
{
    std::vector<int> mis;
    while ( !nodes.empty() )
    {
        Node *n = getRandomNode();
        int id = n->id;

        Neighbors::const_iterator iter = n->neighbors.begin();

        while ( iter!=n->neighbors.end() )
        {  removeNode( (*(iter++)).second.second->id);
        }

        n->neighbors.clear();
        n->neighborsRand.clear();
        removeNode(id);
        mis.push_back(id);
    }
    return mis;
}

/**
 *@ingroup GraphLayout
 * @brief Graph::getMaximalIndependentSetSequential
 * In order to compute a maximal independent set S of a graph G = (V, E) in internal memory,
the following simple algorithm can be used: Process the vertices in an arbitrary order. When a
vertex \f$ v \in V\f$ is visited, add it to S if none of its neighbors is in S. Karp 1985
 * @return The indices of the maximal independent set
 **/
std::vector<int> Graph::getMaximalIndependentSetSequential()
{
    std::set<int> mis;
    for ( NodesRand::const_iterator iter = nodesRand.begin(); iter!=nodesRand.end(); ++iter)
    {
        Node *n = (*iter);
        bool ignoreNinsertion=false;
        for (NeighborsRand::const_iterator iter2 = n->neighborsRand.begin(); iter2 != n->neighborsRand.end(); ++iter2)
        {
            Node *v = (*iter2)->second;
            ignoreNinsertion = ignoreNinsertion || (mis.find(v->id) !=mis.end() );
        }
        if (!ignoreNinsertion)
            mis.insert(n->id);
    }

    std::vector<int> vmis;
    std::copy(mis.begin(),mis.end(), std::back_inserter(vmis));
    return vmis;
}

/**
 *@ingroup GraphLayout
 * @brief Graph::markMaximalIndependentSetSequential
 * Memory conservative version of getMaximalIndependentSetSequential
 * Mark the vertices in a maximal independent set
 */
void Graph::markMaximalIndependentSetSequential()
{
    std::set<int> mis;
    for ( NodesRand::const_iterator iter = nodesRand.begin(); iter!=nodesRand.end(); ++iter)
    {
        Node *n = (*iter);
        n->mark = false;
    }

    for ( NodesRand::const_iterator iter = nodesRand.begin(); iter!=nodesRand.end(); ++iter)
    {
        Node *n = (*iter);
        bool ignoreNinsertion=false;
        for (NeighborsRand::const_iterator iter2 = n->neighborsRand.begin(); iter2 != n->neighborsRand.end(); ++iter2)
        {
            Node *v = (*iter2)->second;
            ignoreNinsertion = ignoreNinsertion || (mis.find(v->id) !=mis.end() );
        }
        if (!ignoreNinsertion)
        {
            n->mark=true;
            mis.insert(n->id);
        }
    }
}

/**
 *@ingroup GraphLayout
 * @brief Graph::getMaximalIndependentSetVerticesLuby
 *A slower randomized version of maximal independent set of Luby
 * @return A vector of integers of nodes id of the maximal independent set
 */
std::vector<int> Graph::getMaximalIndependentSetVerticesLuby()
{
    std::vector<int> mis;
    while ( !nodes.empty() )
    {  set<Node*> randomSet;
        for ( NodesRand::const_iterator iter = nodesRand.begin(); iter!=nodesRand.end(); ++iter)
        {  double prob = 1.0/(2*(*iter)->degree);
            double unifrand = (double)rand()/(double)RAND_MAX;
            if ( prob > unifrand  )
                randomSet.insert((*iter));
        }
        for (NodesRand::const_iterator iter1 = nodesRand.begin(); iter1 != nodesRand.end(); ++iter1)
        {  Node *u = (*iter1);
            for (NeighborsRand::const_iterator iter2 = u->neighborsRand.begin(); iter2 != u->neighborsRand.end(); ++iter2)
            {  Node *v = (*iter2)->second;
                if (randomSet.find(u)!=randomSet.end() && randomSet.find(v)!=randomSet.end() )
                {  if ( u->degree > v->degree )
                        randomSet.erase(v);
                    else
                        randomSet.erase(u);
                }
            }
        }
        for (set<Node*>::const_iterator itermis = randomSet.begin(); itermis!=randomSet.end(); ++itermis )
        {  Node *n = (*itermis);
            mis.push_back(n->id);
            Neighbors::const_iterator iter2 = n->neighbors.begin();
            while ( iter2!=n->neighbors.end() )
            {  removeNode( (*(iter2++)).second.second->id);
            }
            removeNode(n->id);
        }
    }
    return mis;
}

#ifdef EXPERIMENTAL_FEATURES
/**
 *@ingroup GraphLayout
 * @brief Graph::bronKerboshMaximalClique
 * Enumerate maximal cliques in the graph using the Bron-Kerbosh maximal clique algorithm
 * This method is the internal method to be used, not to be call externally.
* http://en.wikipedia.org/wiki/Bron%E2%80%93Kerbosch_algorithm
 * @param Rcompsub
 * @param candidatesP
 * @param Xnot
 * @param cliques All the enumerated cliques
 * @param kLower a lower bound on maximal clique size (a filter on little cliques)
 */
void Graph::bronKerboshMaximalClique(set<int> &Rcompsub, set<int> &candidatesP, set<int> &Xnot, vector< set<int> > &cliques, unsigned int kLower )
{
    if ( candidatesP.empty() && Xnot.empty() )
    {
        if ( Rcompsub.size() >= kLower )
            cliques.push_back(Rcompsub);
        return;
    }

    set<int> PunionX;
    PunionX.insert(candidatesP.begin(),candidatesP.end());
    PunionX.insert(Xnot.begin(),Xnot.end());

    // here we select as pivot the vertex with highest degree in PunionX
    // this helps to reduce the number of recursive calls
    Node *u = NULL;

    double maxDeg=std::numeric_limits<double>::min();
    for (set<int>::const_iterator iter = PunionX.begin(); iter!=PunionX.end(); ++iter)
    {
        int id=*iter;
        Node *tmpNode =nodes[id];
        if ( tmpNode->degree >= maxDeg )
        {
            maxDeg=tmpNode->degree;
            u=tmpNode;
        }
    }

    // for each vertex v in P \ N(u):
    // Form the set P\ N(u) // XXX si può creare più velocemente questo set...
    set<int> PnotNeighborsOfU;
    for (set<int>::const_iterator iter = candidatesP.begin(); iter!=candidatesP.end(); ++iter)
    {
        int v = *iter;
        if ( u->neighbors.find( v ) == u->neighbors.end() )  // if v is not in the neighbors of u, insert it
            PnotNeighborsOfU.insert(v);
    }

    for (set<int>::const_iterator iter = PnotNeighborsOfU.begin(); iter!=PnotNeighborsOfU.end(); ++iter)
    {
        Node *v=nodes[*iter];
        set<int> Nv;
        for (NeighborsRand::const_iterator iterneigh = v->neighborsRand.begin(); iterneigh!=v->neighborsRand.end(); ++iterneigh)
        {
            Node *k = (*iterneigh)->second;
            Nv.insert( k->id);
        }

        // R U v
        set<int> RuV;
        RuV.insert(Rcompsub.begin(),Rcompsub.end());
        RuV.insert(v->id);

        // P intersect Neighbors(v)
        set<int> PintersectNeighV;

        // X intersect Neighbors(V)
        set<int> XintersecNeighV;

        std::set_intersection(candidatesP.begin(), candidatesP.end(), Nv.begin(), Nv.end(), std::inserter(PintersectNeighV, PintersectNeighV.end()));
        std::set_intersection(Xnot.begin(), Xnot.end(), Nv.begin(), Nv.end(), std::inserter(XintersecNeighV, XintersecNeighV.end()));

        bronKerboshMaximalClique(RuV,PintersectNeighV,XintersecNeighV,cliques,kLower);
        candidatesP.erase(v->id);
        Xnot.insert(v->id);
    }
}

/**
 * @ingroup GraphLayout
 * @brief Get the maximal cliques of size at least k of the Graph
 * The algorithmic cost is worst-case O(3^(n/3)) where n is the number of maximal cliques in the graph
 * but this implementation is quite efficient and gives results in reasonable time.
**/
vector< set<int> > Graph::getMaximalCliques(int k)
{
    vector< set<int> > cliques;
    set<int>  R,P,X;
    for (NodesRand::const_iterator iter = nodesRand.begin(); iter!=nodesRand.end();++iter)
        P.insert( (*iter)->id );
    bronKerboshMaximalClique(R,P,X,cliques,k);
    return cliques;
}

/**
 * @ingroup GraphLayout
 *@brief  Get a Kruskal MST as vector of Nodes pair.
  The edges in the MST are marked as true, the others are marked as false.
  This algorithms follows a faster, memory conservative approach.
  How to find the marked edges after a call to getKruskalMST():
\code
  for (Nodes::iterator iter = mstGraph->nodes.begin(); iter!=mstGraph->nodes.end();++iter)
  {
      Node* u = iter->second;
      for (Neighbors::iterator iter2 = u->neighbors.begin(); iter2 != u->neighbors.end(); ++iter2)
      {
          Edge *e = iter2->second.first;
          Node *v = iter2->second.second;
          if (e->mark && u>v)
              cout << u->id << " " << v->id << endl;
      }
  }
  \endcode
  @return a vector of pairs of maximal spanning tree nodes-pair
**/
vector<pair<Node *, Node *> > Graph::getKruskalMST()
{
    priority_queue< Edge*, vector<Edge*> > PQ;
    map<Edge*, pair<Node*,Node*> > edgeToTargetAndSource;
    Timer timer; timer.start();
    unmarkAllEdges();

    for (NodesRand::const_iterator iter1 = nodesRand.begin(); iter1 != nodesRand.end(); ++iter1)
    {  Node *u = (*iter1);
        for (NeighborsRand::const_iterator iter2 = u->neighborsRand.begin(); iter2 != u->neighborsRand.end(); ++iter2)
        {
            Edge *e = (*iter2)->first;
            Node *v = (*iter2)->second;
            if (e->mark)
                continue;
            else
            {
                PQ.push(e);
                edgeToTargetAndSource[e] = pair<Node*,Node*> (u,v);
                e->mark=true;
            }
        }
    }
    unmarkAllEdges();
    vector< pair<Node*,Node*> > MST;
    MST.reserve( nodesRand.size() ); //il minimum spanning tree avrà al più N-1 lati

    DisjointSet uf(this);
    while (!PQ.empty() )
    {
        Edge *e = PQ.top();
        PQ.pop();
        if (edgeToTargetAndSource.find(e)!=edgeToTargetAndSource.end() && e->mark==false)
        {
            int v = edgeToTargetAndSource[e].first->id;
            int w = edgeToTargetAndSource[e].second->id;

            if ( uf.connected(v,w) )
                continue;

            uf.merge(v,w);
            MST.push_back(std::pair<Node*,Node*>(nodes[v],nodes[w]));
            e->mark=true;
        }
    }

    return MST;
}


/**
 * @ingroup GraphLayout
  @brief Get a Kruskal MST as new Graph.
  The edges in the MST are marked as true in the new Graph, the others are marked as false.
  The nodes in the new Graph DON'T share the same memory of the nodes of the graph.
  This algorithms follows a slower but more clear approach.
  How to find the marked edges after a call to getKruskalMST():
\code
  Graph *mstGraph = g->getKruskalMSTasSubGraph();
  for (Nodes::iterator iter = mstGraph->nodes.begin(); iter!=mstGraph->nodes.end();++iter)
  {
      Node* u = iter->second;
      for (Neighbors::iterator iter2 = u->neighbors.begin(); iter2 != u->neighbors.end(); ++iter2)
      {
          Edge *e = iter2->second.first;
          Node *v = iter2->second.second;
          if (e->mark && u>v)
              cout << u->id << " " << v->id << endl;
      }
  }
  \endcode
**/
Graph* Graph::getKruskalMSTasSubGraph()
{
    if (mst==NULL)
        mst = new Graph();
    else
        return mst;
    unmarkAllEdges();

    priority_queue< Edge*, vector<Edge*> > PQ;
    map<Edge*, pair<Node*,Node*> > edgeToTargetAndSource;
    for (NodesRand::const_iterator iter1 = nodesRand.begin(); iter1 != nodesRand.end(); ++iter1)
    {  Node *u = (*iter1);
        for (NeighborsRand::const_iterator iter2 = u->neighborsRand.begin(); iter2 != u->neighborsRand.end(); ++iter2)
        {
            Edge *e = (*iter2)->first;
            Node *v = (*iter2)->second;
            if (e->mark)
                continue;
            else
            {
                PQ.push(e);
                edgeToTargetAndSource[e] = pair<Node*,Node*> (u,v);
                e->mark=true;
            }
        }
    }

    unmarkAllEdges();

    DisjointSet uf(this);
    while (!PQ.empty() )
    {
        Edge *e = PQ.top();
        PQ.pop();
        if (edgeToTargetAndSource.find(e)!=edgeToTargetAndSource.end() && e->mark==false )
        {
            int v = edgeToTargetAndSource[e].first->id;
            int w = edgeToTargetAndSource[e].second->id;

            if ( uf.connected(v,w) )
                continue;

            uf.merge(v,w);

            Node *nodeV = nodes[v];
            Node *nodeW = nodes[w];

            mst->insertNode(nodeV->id);
            mst->insertNode(nodeW->id);
            Edge *mstE = mst->insertEdge(nodeV->id,nodeW->id);
            mstE->mark=true;
            e->mark=true;
        }
    }

    return mst;
}
/**
 *@ingroup GraphLayout
 * @brief Graph::getHighestDegreeNeighbor Get the neighbor node to selected src node with the highest degree
 * @param src
 * @return highest degree neighbor as pointer
 */
Node * Graph::getHighestDegreeNeighbor(Node *src)
{
    if (src==NULL)
        throw std::runtime_error(std::string("Can't apply to NULL node"));

    if (src->neighborsRand.empty())
        return src;

    Node *highest = src->neighborsRand.front()->second;

    for (NeighborsRand::const_iterator iter2 = src->neighborsRand.begin(); iter2 != src->neighborsRand.end(); ++iter2)
    {  Node *v = (*iter2)->second;
        if ( v->degree > highest->degree )
            highest=v;
    }
    return highest;
}

/**
 *@ingroup GraphLayout
 * @brief Graph::getTreeCentersNodes If this graph is a forest, this algorithm gets the centers (or roots) of the tree, as a vector, one for every connected component.
 * @return The centers of every tree in the forest
 */
std::vector<Node *> Graph::getTreeCentersNodes()
{
    statsComponentsCount=countConnectedComponents();
    // A forest with k-edges has exactly |V|-k trees, because every tree (which is a connected component)
    // bring V-1 edges to the total edges sum.
    if ( statsComponentsCount!=statsNodesCount-statsEdgesCount )
    {
        throw std::runtime_error(  std::string("The graph is not a forest nor a simple tree") );
        return std::vector<Node*>();
    }

    normalizeIndex();

    std::vector< std::vector<unsigned int> > degrees(statsComponentsCount);
    for ( int comp=0; comp<statsComponentsCount; comp++)
        degrees.at(comp).resize(nodesRand.size()+1);

    std::vector< std::list<Node*> > leaves(statsComponentsCount);

    for (NodesRand::const_iterator iter = nodesRand.begin(); iter!=nodesRand.end();++iter)
    {

        unsigned int neighs = (*iter)->neighborsRand.size();
        degrees.at((*iter)->component).at((*iter)->index) = neighs;
        if ( neighs==1 )
        {
            leaves.at((*iter)->component).push_back((*iter));
        }
    }

    for ( int comp=0; comp<statsComponentsCount; comp++)
    {
        while ( leaves.at(comp).size()>1 )
        {
            Node* ni = leaves.at(comp).front();
            leaves.at(comp).pop_front();
            degrees.at(comp).at(ni->index)--;
            for (NeighborsRand::const_iterator iter = ni->neighborsRand.begin(); iter!=ni->neighborsRand.end(); ++iter)
            {
                Node *neigh = (*iter)->second;
                if (degrees.at(comp).at((neigh->index))>0)
                {
                    degrees.at(comp).at((neigh->index))--;
                    if (degrees.at(comp).at((neigh->index))==1)
                        leaves.at(comp).push_back(neigh);
                }
            }
        }
    }

    /* FOR DEBUG_PURPOSES ONLY
    for ( int comp=0; comp<statsComponentsCount; comp++)
    {
        for (std::list<Node*>::iterator iter = leaves.at(comp).begin(); iter!=leaves.at(comp).end();++iter)
        {
            cout << "root " << (*iter)->id << endl;
        }
    }
*/
    // Copy the remaining element from leaves list to a more useful data structure
    // which stores the centers of every weak connected component
    vector<Node*> centers;
    for ( int comp=0; comp<statsComponentsCount; comp++)
        centers.push_back(leaves.at(comp).front());
    return centers;
}

#endif

