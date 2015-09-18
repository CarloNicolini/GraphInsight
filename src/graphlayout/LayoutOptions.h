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

#ifndef LAYOUT_OPTIONS_H
#define LAYOUT_OPTIONS_H

/**
@ingroup GraphLayout
@struct Options
@brief A useful way to specify optimization options at compile time, it groups all modificable options of the layout mehods
**/
struct LayoutOptions
{
    /**
     * @ingroup GraphLayout
     *@brief Optionsfor recursive space decomposition algorithm (quadtree and octree)
     */
    static struct TreeOptions
    {
        static double theta;
        static double epsilon;
    } treeOptions;

    /**
     * @ingroup GraphLayout
     *@brief Optionsfor KamadaKawai layout algorithm
     */
    static struct KamadaKawaiOptions
    {
        static double gradientNorm;
    } kamadaKawaiOptions;

    /**
     * @ingroup GraphLayout
     *@struct Binary stress algorithm options
     */
    static struct BinaryStressOptions
    {
        static double gradientNorm;
    } binaryStressOptions;

    static struct BinaryStressMultilevelOptions
    {
        static int nodesThrehold;
    } binaryStressMultilevelOptions;

    /**
     * @ingroup GraphLayout
    * @brief Optionsfor Fruchterman Reingold algorithm
     */
    static struct FruchtermanReingoldOptions
    {
        static double speed;
        static double gradientNorm;
        static double deltaGradient;
        static double gravityStrength;
    } frOptions;

    /**
     * @ingroup GraphLayout
     *@brief Optionsfor Fruchterman Reingold Proportional algorithm
     */
    static struct FruchtermanReingoldProportionalOptions
    {
        static double speed;
        static double gradientNorm;
        static double deltaGradient;
        static double gravityStrength;
    } fruchtermanReingoldProportionalOptions;

    /**
     * @ingroup GraphLayout
     * @brief Optionsfor Lin Log algorithm
     */
    static struct LinLogOptions
    {
        static double speed;
        static double gradientNorm;
        static double deltaGradient;
        static double gravityStrength;
        static double attractiveStrength, repulsiveStrength;
    } linLogOptions;

    /**
     * @ingroup GraphLayout
     *@brief Optionsfor Fruchterman Reingold Multileve  algorithm
     */
   static struct FruchtermanReingoldMultilevelOptions
   {
       static double nodesNumberPercentDifference;
       static int minNumberOfNodesPerComponent;
       static int maxNumberOfLevels;
       static int minNumberOfEdges;

       static double gradientNorm;
       static int maxStepsPerLevel;
       static int matchingType;
   } fruchtermanReingoldMultilevelOptions;

   /**
    * @ingroup GraphLayout
    *@brief Optionsfor Fruchterman Reingold Proportional Multilevel algorithm
    */
   static struct FruchtermanReingoldProportionalMultilevelOptions
   {
       static double nodesNumberPercentDifference;
       static int minNumberOfNodesPerComponent;
       static int maxNumberOfLevels;
       static int minNumberOfEdges;

       static double gradientNorm;
       static int maxStepsPerLevel;
       static int matchingType;
   } fruchtermanReingoldPropMultilevelOptions;

   /**
    * @ingroup GraphLayout
    *@brief Optionsfor LinLog Multilevel algorithm
    */
   static struct LinLogMultilevelOptions
   {
       static double nodesNumberPercentDifference;
       static int minNumberOfNodesPerComponent;
       static int maxNumberOfLevels;
       static int minNumberOfEdges;

       static double gradientNorm;
       static int maxStepsPerLevel;
       static int matchingType;
   } linlogMultilevelOptions;

   /**
    * @ingroup GraphLayout
    *@brief Optionsfor high dimensional embedder algorithm
    */
   static struct HighDimensionalEmbedderOptions
   {
       static int embeddingDimension;
   } hdeOptions;

   static struct CircularMinCrossOptions
   {
       static int dispositionMethod;
   } circularMinCrossOptions;

   static struct StressMajorizationOptions
   {
       static double tolerance;
   } stressMajorizationOptions;

   static bool useMulticoreOpenMP;
};

#endif // LAYOUT_OPTIONS_H
