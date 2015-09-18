project(xprojects)
CMAKE_MINIMUM_REQUIRED(VERSION 2.6.0 FATAL_ERROR)

include_directories( ${QT_INCLUDE_PATH} ${QT_QTGUI_INCLUDE_DIR} ${QT_QTCORE_INCLUDE_DIR}  ../common/ ../graphlayout/ ../eigen/ ../graphinsight/ ${CMAKE_CURRENT_BINARY_DIR})

add_executable(testGraph1 testGraph1.cpp )
add_executable(testGraph2 testGraph2.cpp )
add_executable(testGraph3 testGraph3.cpp )
add_executable(testGraphLayout1 testGraphLayout1.cpp )
add_executable(testGraphLayout2 testGraphLayout2.cpp )
add_executable(testGraphMemory testGraphMemory.cpp)
add_executable(testBarnesHutTree testBarnesHutTree.cpp)
add_executable(testCGSolver testCGSolver.cpp)
add_executable(testCNF testCNF.cpp)

# Add a test to check dataset and entity possible memory leaks
target_link_libraries(testCGSolver GraphLayout Common)
target_link_libraries(testGraphLayout1  GraphLayout Common)
target_link_libraries(testGraphLayout2  GraphLayout Common)

target_link_libraries(testGraph1 Common GraphLayout)
target_link_libraries(testGraph2 Common GraphLayout)
target_link_libraries(testGraph3 Common GraphLayout)

target_link_libraries(testGraphMemory Common GraphLayout)
target_link_libraries(testBarnesHutTree Common GraphLayout)

target_link_libraries(testCNF Common GraphLayout)

if(PYTHON_QT_SUPPORT)
add_executable(testPythonDict testPythonDict.cpp)
target_link_libraries(testPythonDict Common PythonQt ${PYTHON_LIBRARY})
add_subdirectory(testPythonQScriptingConsole)
endif(PYTHON_QT_SUPPORT)
