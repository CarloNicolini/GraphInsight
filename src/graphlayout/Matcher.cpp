/****************************************************************************
**
** Copyright (C) 2010 Michele Dallachiesa (michele.dallachiesa@gmail.com)
** All rights reserved.
**
** Warning: This program is protected by copyright law and international
** treaties. Unauthorized reproduction and distribution of this program,
** or any portion of it, may result in severe civil and criminal penalties,
** and will be persecuted to the maximum extent possible under the law.
**
****************************************************************************/


#include <vector>
#include "Matcher.h"

/**
 * @ingroup GraphLayout
 * @brief Matcher::Matcher Standard constructor
 */
Matcher::Matcher() : graph(NULL), matchingType(MATCHING_RANDOM)
{

}

/**
 * @brief Matcher::Matcher Setup a Matcher object with a given matching type
 * @param graph The graph from which create matching
 * @param matchingType One of the already discussed matching method (0-6)
 */
Matcher::Matcher(Graph *_graph, int _matchingType) : graph(_graph), matchingType(_matchingType)
{
}

/**
 * @ingroup GraphLayout
 * @brief Matcher::Matcher
 * @param orig
 */
Matcher::Matcher(const Matcher& orig) : graph(orig.graph), matchingType(orig.matchingType)
{
}

/**
 * @ingroup GraphLayout
 * @brief Matcher::~Matcher Destructor, does nothing
 */
Matcher::~Matcher()
{

}

/**
 * @ingroup GraphLayout
 * @brief Matcher::find Find a node corresponding to the matching type
 * @param node The node to start from
 * @return  The node with the selected match type w.r.t the input node
 */
Node *Matcher::find(Node *node)
{

   switch (matchingType)
   {  case MATCHING_LIGHT_NODE:
         return findLightNode(node);
         break;

      case MATCHING_RANDOM:
         return findRandom(node);
         break;

      case MATCHING_HEAVY_EDGE:
         return findHeavyEdge(node);
         break;

      case MATCHING_LIGHT_EDGE:
         return findLightEdge(node);
         break;

      case MATCHING_HEAVY_CONNECTED:
         return findHeavyConnected(node);
         break;

      case MATCHING_LIGHT_CONNECTED:
         return findLightConnected(node);
         break;

      default:
         return NULL; // matcher unknown.
   }
}

/**
 * @brief Matcher::findLightNode Find the lightest node in the neighbors of input node
 * @param node The input node
 * @return  The lightest node in the neighbors of input node
 */
Node *Matcher::findLightNode(Node *node)
{  Node *best = NULL;

   if (node->neighborsRand.empty())
      return node;
   for (NeighborsRand::iterator iter = node->neighborsRand.begin(); iter != node->neighborsRand.end(); ++iter)
   {  if ((*iter)->second->mark == true || (*iter)->second->id == node->id)
         continue;

      if (best == NULL || (*iter)->second->weight < best->weight)
      {  best = (*iter)->second;
      }

   }

   return best;
}

/**
 * @brief Matcher::findRandom Get a random node in the neighbors of input node
 * @param node Input node
 * @return A random node in the neighbors of input node
 */
Node *Matcher::findRandom(Node *node)
{  if (node->neighborsRand.empty())
      return node;
   for (NeighborsRand::iterator iter = node->neighborsRand.begin(); iter != node->neighborsRand.end(); ++iter)
   {

      if ((*iter)->second->mark == false)
         return (*iter)->second;
   }

   return NULL;
}

/**
 * @brief Matcher::findHeavyEdge Find the node corresponding to the heaviest edge from input node to its neighbors
 * @param node The input node
 * @return  the node corresponding to the heaviest edge from input node to its neighbors
 */
Node *Matcher::findHeavyEdge(Node *node)
{  Node *bestNode = NULL;
   Edge *bestEdge = NULL;
   if (node->neighborsRand.empty())
      return node;

   for (NeighborsRand::iterator iter = node->neighborsRand.begin(); iter != node->neighborsRand.end(); ++iter)
   {  if ((*iter)->second->mark == true || (*iter)->second->id == node->id)
         continue;

      if (bestEdge == NULL || (*iter)->first->weight > bestEdge->weight)
      {  bestEdge = (*iter)->first;
         bestNode = (*iter)->second;
      }
   }
   return bestNode;
}

/**
 * @brief Matcher::findLightEdge Find the node corresponding to the lightest edge from input node to its neighbors
 * @param node The input node
 * @return  the node corresponding to the lightest edge from input node to its neighbors
 */
Node *Matcher::findLightEdge(Node *node)
{  Node *bestNode = NULL;
   Edge *bestEdge = NULL;
   if (node->neighborsRand.empty())
      return node;

   for (NeighborsRand::iterator iter = node->neighborsRand.begin(); iter != node->neighborsRand.end(); ++iter)
   {  if ((*iter)->second->mark == true || (*iter)->second->id == node->id)
         continue;

      if (bestEdge == NULL || (*iter)->first->weight < bestEdge->weight)
      {  bestEdge = (*iter)->first;
         bestNode = (*iter)->second;
      }
   }
   return bestNode;
}

/**
 * @brief Matcher::findHeavyConnected Find the node with higher degree from input node to its neighbors
 * @param node Input node
 * @return Higher degree node
 */
Node *Matcher::findHeavyConnected(Node *node)
{  Node *bestNode = NULL;
   if (node->neighborsRand.empty())
      return node;

   for (NeighborsRand::iterator iter = node->neighborsRand.begin(); iter != node->neighborsRand.end(); ++iter)
   {  if ((*iter)->second->mark == true || (*iter)->second->id == node->id)
         continue;

      if (bestNode == NULL || (*iter)->second->neighbors.size() > bestNode->neighbors.size())
      {  bestNode = (*iter)->second;
      }
   }
   return bestNode;
}

/**
 * @brief Matcher::findLightConnected Find the node with lower degree from input node to its neighbors
 * @param node Input node
 * @return Lower degree node
 */
Node *Matcher::findLightConnected(Node *node)
{  Node *bestNode = NULL;
   if (node->neighborsRand.empty())
      return node;

   for (NeighborsRand::iterator iter = node->neighborsRand.begin(); iter != node->neighborsRand.end(); ++iter)
   {  if ((*iter)->second->mark == true || (*iter)->second->id == node->id)
         continue;

      if (bestNode == NULL || (*iter)->second->neighbors.size() < bestNode->neighbors.size())
      {  bestNode = (*iter)->second;
      }
   }
   return bestNode;
}
