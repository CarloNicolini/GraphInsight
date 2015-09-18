QT4_WRAP_CPP( PyExampleObject_MOC PyExampleObject.h )
add_executable(testPythonQScriptingConsole main.cpp PyExampleObject.cpp ${PyExampleObject_MOC} )
target_link_libraries(testPythonQScriptingConsole  PythonQt ${PYTHON_LIBRARY})

add_executable(testGetSaveFileName testGetSaveFileName.cpp)
target_link_libraries(testGetSaveFileName ${QT_LIBRARIES})
