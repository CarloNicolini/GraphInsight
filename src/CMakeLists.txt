include_directories(common)
include_directories(graphlayout)
include_directories(eigen)
include_directories(graphinsight)

add_subdirectory(common)
add_subdirectory(graphlayout)

if( PYTHON_QT_SUPPORT )
    #-----------------------------------------------------------------------------
    # Python libraries
    if (APPLE)
        # Use the system python (python 2.5 built in universal flavour)
        set(PYTHON_LIBRARY "/System/Library/Frameworks/Python.framework/Versions/2.5/Python")
        set(PYTHON_INCLUDE_DIR "/System/Library/Frameworks/Python.framework/Versions/Current/Headers")
        # Use the MacPort library, install all the python in +universal flavour
        # sudo port install python25 python26 python27 +universal
        #set(PYTHON_LIBRARY "/opt/local/Library/Frameworks/Python.framework/Versions/2.7/Python")
        #set(PYTHON_INCLUDE_DIR "/opt/local/Library/Frameworks/Python.framework/Versions/2.7/Headers")
    endif(APPLE)
    find_package(PythonLibs REQUIRED )
    #----- Print some informations on python libraries linked and included
    message(STATUS "Python libraries are ${PYTHON_LIBRARIES}")
    message(STATUS "Python libraries are included in ${PYTHON_INCLUDE_DIRS}")
    message(STATUS "Python versions found is ${PYTHONLIBS_VERSION_STRING}")
    include_directories("${PYTHON_INCLUDE_DIR}")
    add_definitions(-DPYTHONQT_USE_RELEASE_PYTHON_FALLBACK)
    # Include PythonQt directory BISOGNA INCLUDERLE SEMPRE
    include_directories(${CMAKE_SOURCE_DIR}/src/pythonqt/src)
    #----- Finally add the subdirectory to build and link the PythonQt library
    add_subdirectory(pythonqt)
endif(PYTHON_QT_SUPPORT)

# Add the tests directory
add_subdirectory(tests)
# Add main graphinsight directory
add_subdirectory(graphinsight)

if(USE_CYTHON)
add_subdirectory(pywrapper)
endif(USE_CYTHON)

if( DIMENSION_REDUCTION )
add_subdirectory( dimreduction )
endif( DIMENSION_REDUCTION )

