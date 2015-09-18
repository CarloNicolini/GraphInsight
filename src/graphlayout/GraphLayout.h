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

#ifndef _GRAPHLAYOUT_H
#define _GRAPHLAYOUT_H


class LayoutMethod;
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include "Graph.h"
#include "LNode.h"
#include "CostFunction.h"

#include "FKamadaKawai2D.h"
#include "FKamadaKawai3D.h"
#include "FBinaryStress2D.h"
#include "FBinaryStress3D.h"

#include "Solver.h"
#include "CGSolver.h"
#include "Statistic.h"
#include "Matcher.h"

#include "LayoutMethod.h"
#include "Common.h"

/**
* \defgroup GraphLayout GraphLayout is the part of the code devoted to layout a graph, so graph algorithms and layout algorithms are contained here.
* @brief GraphLayout groups all the files and classes needed to lay out a graph
* @class GraphLayout
**/
class GraphLayout : public Graph
{

public:

    GraphLayout();

    void  _init();

    GraphLayout(const GraphLayout& orig);

    ~GraphLayout() ;

    int methodType;

    virtual GraphLayout* clone() const
    {  return new GraphLayout( *this );
    }

    Node *nodeProvider(int id)
    {  return new LNode(id, 1);
    }

    // Init methods and other necessary methods

    int init(int methodType, int nDimensions, bool randomize, bool shake);
    int steps(int n);

    // Save solution to node position
    void setNodesPosition(const vector <double> &);
    void setDimensions(int d);
    void initRandomCoordinates();
    void reloadNodeCoordinates(int nodeId);
    void reloadNodeCoordinates(bool randomize);
    void reloadNodeCoordinates2D(int nodeId);
    void reloadNodeCoordinates2D(bool randomize);
    void reloadNodeCoordinates3D(int nodeId);
    void reloadNodeCoordinates3D(bool randomize);
    void shakeZ();
    void updateLogDegree();

    // i/o
    void writeGnuplot(string graphname, bool withColors);
    void writeGnuplot(ofstream &edges_file, bool withColors);
    void writeDimacs(ofstream &os);
    void loadDimacs(ifstream &is);
    void loadDimacs( const std::string &filename);
    void loadTrueDimacs(ifstream &is);
    void normalizeCoordinates();

    // Quality measures
    double getAverageLength();
    void updateStaticStats();
    void updateDynamicStats();

    double minEdgeLength;
    double maxEdgeLength;

    double maxEdgeDegreeSum;
    double minEdgeDegreeSum;
    double logDegreeMax;

    void print();
    void printSolution();
    bool lmOk(int lmIndex);
    void checkNans();

    int nDimensions;
    LayoutMethod *lm;

public:
    GraphLayout *g;
    vector<double> solution;
    unsigned int getMemoryFootprintInBytes();

    static const char * const layoutMethods[];
    // NON MULTILEVEL
    static const int MethodNothing = 0;
    static const int MethodKamadaKawai = 1;
    static const int MethodFruchtermanReingold = 2;
    static const int MethodFruchtermanReingoldProportional = 3;
    static const int MethodLinLogModel = 4;
    static const int MethodBinaryStress = 5;
    // MULTILEVEL
    static const int MethodFruchtermanReingoldMultilevel = 6;
    static const int MethodFruchtermanReingoldProportionalMultilevel = 7;
    static const int MethodLinLogModelMultilevel = 8;
    static const int MethodBinaryStressMultilevel = 9;
    // ALGEBRAIC AND OTHERS
    static const int MethodHighDimensionalEmbedder = 10;
    static const int MethodCircularLayout = 11;
    static const int MethodRandom = 12;
    static const int MethodACE = 13;
    static const int MethodStressMajorization = 14;
    static const int MethodCircularLayoutMinCross = 15;

};
#endif

