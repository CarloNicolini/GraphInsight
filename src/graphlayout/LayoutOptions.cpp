/****************************************************************************
**
** Copyright (C) 2012 Carlo Nicolini (nicolini.carlo@gmail.com)
** All rights reserved.
**
** Warning: This program is protected by copyright law and international
** treaties. Unauthorized reproduction and distribution of this program,
** or any portion of it, may result in severe civil and criminal penalties,
** and will be persecuted to the maximum extent possible under the law.
**
****************************************************************************/

#include "LayoutOptions.h"
#include "Matcher.h"

// Tree options
double LayoutOptions::TreeOptions::epsilon=1E-6;
double LayoutOptions::TreeOptions::theta=0.99;

// Kamada Kawai options
double LayoutOptions::KamadaKawaiOptions::gradientNorm=5E-4;

// Binary Stress options
double LayoutOptions::BinaryStressOptions::gradientNorm=1E-2;

// Binary Stress multilevel options
int LayoutOptions::BinaryStressMultilevelOptions::nodesThrehold=10;// xxx da controllare

// Fruchterman Reingold options
double LayoutOptions::FruchtermanReingoldOptions::speed=1.0;
double LayoutOptions::FruchtermanReingoldOptions::gradientNorm=1E-6;
double LayoutOptions::FruchtermanReingoldOptions::deltaGradient=1E-9;
double LayoutOptions::FruchtermanReingoldOptions::gravityStrength=1.0;

// Fruchterman Reingold proportional options
double LayoutOptions::FruchtermanReingoldProportionalOptions::speed=1.0;
double LayoutOptions::FruchtermanReingoldProportionalOptions::gradientNorm=1E-6;
double LayoutOptions::FruchtermanReingoldProportionalOptions::deltaGradient=1E-9;
double LayoutOptions::FruchtermanReingoldProportionalOptions::gravityStrength=1.0;

// Lin-Log options
double LayoutOptions::LinLogOptions::speed=1.0;
double LayoutOptions::LinLogOptions::gradientNorm=1E-6;
double LayoutOptions::LinLogOptions::deltaGradient=1E-9;
double LayoutOptions::LinLogOptions::gravityStrength=1.0;
double LayoutOptions::LinLogOptions::attractiveStrength=20;
double LayoutOptions::LinLogOptions::repulsiveStrength=50;

// Fruchterman-Reingold Multilevel options
double LayoutOptions::FruchtermanReingoldMultilevelOptions::gradientNorm=1E-6;
int LayoutOptions::FruchtermanReingoldMultilevelOptions::maxNumberOfLevels=100;
int LayoutOptions::FruchtermanReingoldMultilevelOptions::maxStepsPerLevel=1E4;
int LayoutOptions::FruchtermanReingoldMultilevelOptions::minNumberOfEdges=1;
int LayoutOptions::FruchtermanReingoldMultilevelOptions::minNumberOfNodesPerComponent=2;
double LayoutOptions::FruchtermanReingoldMultilevelOptions::nodesNumberPercentDifference=0.9;
int LayoutOptions::FruchtermanReingoldMultilevelOptions::matchingType=MATCHING_LIGHT_NODE;

// Fruchterman-Reingold Proportional Multilevel options
double LayoutOptions::FruchtermanReingoldProportionalMultilevelOptions::gradientNorm=1E-6;
int LayoutOptions::FruchtermanReingoldProportionalMultilevelOptions::maxNumberOfLevels=100;
int LayoutOptions::FruchtermanReingoldProportionalMultilevelOptions::maxStepsPerLevel=1E4;
int LayoutOptions::FruchtermanReingoldProportionalMultilevelOptions::minNumberOfEdges=1;
int LayoutOptions::FruchtermanReingoldProportionalMultilevelOptions::minNumberOfNodesPerComponent=2;
double LayoutOptions::FruchtermanReingoldProportionalMultilevelOptions::nodesNumberPercentDifference=0.9;
int LayoutOptions::FruchtermanReingoldProportionalMultilevelOptions::matchingType=MATCHING_LIGHT_NODE;

// Fruchterman-Reingold Proportional Multilevel options
double LayoutOptions::LinLogMultilevelOptions::gradientNorm=1E-6;
int LayoutOptions::LinLogMultilevelOptions::maxNumberOfLevels=100;
int LayoutOptions::LinLogMultilevelOptions::maxStepsPerLevel=1E4;
int LayoutOptions::LinLogMultilevelOptions::minNumberOfEdges=1;
int LayoutOptions::LinLogMultilevelOptions::minNumberOfNodesPerComponent=2;
double LayoutOptions::LinLogMultilevelOptions::nodesNumberPercentDifference=0.9;
int LayoutOptions::LinLogMultilevelOptions::matchingType=MATCHING_LIGHT_NODE;

int LayoutOptions::HighDimensionalEmbedderOptions::embeddingDimension=50;

// Circular Min-Cross
int LayoutOptions::CircularMinCrossOptions::dispositionMethod=0;

// Stress majorization
double LayoutOptions::StressMajorizationOptions::tolerance=1E-4;

bool LayoutOptions::useMulticoreOpenMP=false;
