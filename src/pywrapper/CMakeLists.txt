project(xprojects)
CMAKE_MINIMUM_REQUIRED(VERSION 2.6.0 FATAL_ERROR)

if(USE_CYTHON)
# here you must put the .pyx wrappers and set the property CYTHON_IS_CXX
set( PYTHON_GRAPHLAYOUT_WRAPPERS_SRC
pyNode.pyx
pyEdge.pyx
pyGraphLayout.pyx
pyGraphLayout2.pyx
pyGraphLayout2.pyx
)

set(GraphLayout_SRC
#Community.cpp
../graphlayout/LayoutOptions.cpp
../graphlayout/CGSolver.cpp
../graphlayout/DaisyFilter.cpp
../graphlayout/DisjointSet.cpp
../graphlayout/Edge.cpp
../graphlayout/FBinaryStress2D.cpp
../graphlayout/FBinaryStress3D.cpp
../graphlayout/FKamadaKawai2D.cpp
../graphlayout/FKamadaKawai3D.cpp
../graphlayout/Graph.cpp
../graphlayout/GraphLayout.cpp
../graphlayout/LabelVisualizer.cpp
../graphlayout/LEdge.cpp
../graphlayout/LMACE.cpp
../graphlayout/LMBinaryStress.cpp
../graphlayout/LMBinaryStressMultilevel.cpp
../graphlayout/LMCircular.cpp
../graphlayout/LMCircularMinCross.cpp
../graphlayout/LMFruchtermanReingold.cpp
../graphlayout/LMFruchtermanReingoldProportional.cpp
../graphlayout/LMFruchtermanReingoldMultilevel.cpp
../graphlayout/LMFruchtermanReingoldProportionalMultilevel.cpp
../graphlayout/LMHighDimensionalEmbedder.cpp
../graphlayout/LMKamadaKawai.cpp
../graphlayout/LMLabelAdjust.cpp
../graphlayout/LMLinLogModel.cpp
../graphlayout/LMLinLogModelMultilevel.cpp
../graphlayout/LMNothing.cpp
../graphlayout/LMRandom.cpp
../graphlayout/LMStressMajorization.cpp
../graphlayout/LNode.cpp
../graphlayout/Matcher.cpp
../graphlayout/Node.cpp
../graphlayout/BarnesHutQuadtree.cpp
../graphlayout/BarnesHutOctree.cpp
../graphlayout/ForceDirectedMethod.cpp
)


set_source_files_properties( ${PYTHON_GRAPHLAYOUT_WRAPPERS_SRC} PROPERTIES CYTHON_IS_CXX 1 )
# In this following command you must put the cython wrapper and then the implementation of the classes used (NOT THE CXX!)
cython_add_module( "pyGraphLayout_${CMAKE_BUILD_TYPE}_${CMAKE_SYSTEM_NAME}" pyGraphLayout.pyx ${GraphLayout_SRC} ../common/Timer.cpp ../common/Common.cpp )
cython_add_module(  "pyGraphLayout2_${CMAKE_BUILD_TYPE}_${CMAKE_SYSTEM_NAME}" pyGraphLayout2.pyx ${GraphLayout_SRC} ../common/Timer.cpp ../common/Common.cpp )
#cython_add_module( pyGraphLayout3 pyGraphLayout3.pyx ${GraphLayout_SRC} ../common/Timer.cpp ../common/Common.cpp )
endif(USE_CYTHON)
