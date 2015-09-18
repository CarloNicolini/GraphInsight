# IMPORTANTE SE SI VUOLE CAMBIARE COMPILATORE BISOGNA SCRIVERLO PRIMA DI project(xprojects)
# Una guida per scrivere con cmake+QT 
# http://www.qtcentre.org/wiki/index.php?title=Compiling_Qt4_apps_with_CMake

#if(APPLE)# usa il compilatore clang-mp-3.3 installato con macport
#set(CMAKE_C_COMPILER "/opt/local/bin/clang-mp-3.3")
#set(CMAKE_CXX_COMPILER "/opt/local/bin/clang++-mp-3.3")
#endif(APPLE)
# http://www.cmake.org/Wiki/CMakeMacroListOperations


PROJECT(GraphInsight)
CMAKE_MINIMUM_REQUIRED(VERSION 2.8 FATAL_ERROR)
# Set GraphInsight version
FILE(STRINGS "${CMAKE_CURRENT_SOURCE_DIR}/cmake/BUILD_VERSION.txt" GRAPHINSIGHT_VERSION)
string(REPLACE "." ";" GRAPHINSIGHT_VERSION_LIST ${GRAPHINSIGHT_VERSION} )
LIST(GET GRAPHINSIGHT_VERSION_LIST 0 GRAPHINSIGHT_MAJOR)
LIST(GET GRAPHINSIGHT_VERSION_LIST 1 GRAPHINSIGHT_MINOR)
LIST(GET GRAPHINSIGHT_VERSION_LIST 2 GRAPHINSIGHT_PATCH)

#LICENSE_TYPE can be one of these 3 Trial/Academic/Professional
IF(LICENSE_TYPE MATCHES "Trial" OR LICENSE_TYPE MATCHES "Academic" OR LICENSE_TYPE MATCHES "Pro" )
	message("==== Building GraphInsight ${GRAPHINSIGHT_VERSION} ${LICENSE_TYPE}====" )
ELSE(LICENSE_TYPE MATCHES "Trial" OR LICENSE_TYPE MATCHES "Academic" OR LICENSE_TYPE MATCHES "Pro")
	message(STATUS "Select a license by specifying variable LICENSE_TYPE" )
	message(STATUS " Options are\n\t1) cmake -D LICENSE_TYPE=Professional\n\t2) cmake -D LICENSE_TYPE=Trial\n\t3) cmake -D LICENSE_TYPE=Academic" )
	message(FATAL_ERROR "\nNow exiting...")
ENDIF(LICENSE_TYPE MATCHES "Trial" OR LICENSE_TYPE MATCHES "Academic" OR LICENSE_TYPE MATCHES "Pro")


# Set the correct license, only Trial version doesn't have python shell
IF( LICENSE_TYPE MATCHES "Academic" OR LICENSE_TYPE MATCHES "Pro")
	SET(PYTHON_QT_SUPPORT On)
    ADD_DEFINITIONS(-DUSE_PYTHONQT=True)
ENDIF( LICENSE_TYPE MATCHES "Academic" OR LICENSE_TYPE MATCHES "Pro")

IF( NOT WIN32)
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC")
ENDIF(NOT WIN32)

# HERE WE CREATE THE GRAPHINSIGHT PACKAGE NAME WHICH CONTAINS THE LICENSE TYPE, VERSION AND ARCHITECTURE OF THE BUILD 
# QT LIBRARIES
SET(QT_MIN_VERSION "4.6.0")
SET(QT_USE_QTMAIN TRUE)
SET(QT_USE_OPENGL TRUE)
if (APPLE)
find_package(Qt4 4.6.0 COMPONENTS QtGui QtCore QtOpenGL QtSvg REQUIRED )
else(APPLE)
find_package(Qt4 4.6.0 COMPONENTS QtGui QtCore QtOpenGL QtSvg REQUIRED )
endif(APPLE)
INCLUDE(${QT_USE_FILE})

# COMANDI PER SPOSTARE I FILE DI BUILD (eseguibili di test e librerie ) DENTRO LA CARTELLA ./build
SET(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
SET(PROJECT_BINARY_DIR "${CMAKE_CURRENT_SOURCE_DIR}/build/")
SET(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR} CACHE PATH "Single directory for all libraries")
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR} CACHE PATH "Single directory for all executables")
# http://stackoverflow.com/questions/7747857/in-cmake-how-do-i-work-around-the-debug-and-release-directories-visual-studio-2
#SET( CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/build/${CMAKE_BUILD_TYPE}" )
#SET( CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/build/${CMAKE_BUILD_TYPE}" )
#SET( CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/build/${CMAKE_BUILD_TYPE}" )

# Cython needs Python>2.7 to compile, so you have to be sure that the current version of python > 2.7
if (USE_CYTHON)
include( UseCython )
add_custom_target( ReplicatePythonSourceTree ALL ${CMAKE_COMMAND} -P
  ${CMAKE_CURRENT_SOURCE_DIR}/cmake/ReplicatePythonSourceTree.cmake
  ${CMAKE_CURRENT_BINARY_DIR}
  WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} )
endif (USE_CYTHON)

# For Subversion repository (DEPRECATED)
#find_package(Subversion)
#IF(SUBVERSION_FOUND)
	#Subversion_WC_INFO(${PROJECT_SOURCE_DIR} Project)
	#MESSAGE("Current revision is ${Project_WC_REVISION}")
	#ADD_DEFINITIONS(-DREVISION_NUMBER="${Project_WC_REVISION}")
#else (SUBVERSION_FOUND)
#   ADD_DEFINITIONS(-DREVISION_NUMBER="0")
#ENDIF(SUBVERSION_FOUND)

INCLUDE(GetGitRevisionDescription)
GET_GIT_HEAD_REVISION(GIT_REFSPEC GIT_SHA1)
ADD_DEFINITIONS("-DGIT_SHA1=${GIT_SHA1}")
MESSAGE(STATUS "GIT SHA1 ${GIT_SHA1}")

ADD_DEFINITIONS(-DGRAPHINSIGHT_VERSION="${GRAPHINSIGHT_VERSION}")
###### ADD SOME OPTIMIZATION FLAGS FOR G++ COMPILER (which is found on Unix )
if ( UNIX )
SET(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3 -pipe -msse3 -fomit-frame-pointer -funroll-loops ")
SET(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELWITHDEBINFO} -O3 -pipe -msse3 -fomit-frame-pointer -funroll-loops ")
SET(CMAKE_CXX_FLAGS_DEBUG   "${CMAKE_CXX_FLAGS_DEBUG} -O0 -g2 -ggdb -Wall -Wextra -ansi -Wuninitialized -DDEBUG")
endif ( UNIX )

####### Push more optimization options with MSVC compiler
# Push more optimization options with Microsoft Compiler
IF(MSVC)
# _WIN32, _NOMINMAX, disable some stupid warnings and enable multiprocessor compilation (/MP)
ADD_DEFINITIONS(-D_WIN32 -D_CRT_SECURE_NO_DEPRECATE -D_SCL_SECURE_NO_DEPRECATE -DNOMINMAX)
ADD_DEFINITIONS("/EHsc /wd4127 /wd4505 /wd4714 /wd4800 /wd4181 /wd4244 /wd4996 /MP")
# This push some other optimizations in order: Full optimization (Ox), omit frame pointer (Oy), Enable FiberSafe optimizations(GT),
# Whole Program Optimization (/GL), OpenMP support (/openmp), NONdynamic runtime libraries (MT)
SET(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} ${CMAKE_CXX_FLAGS} /arch:SSE2 /Ox /Oy /GT /GL")
# Specify to use multithreaded debug (non dynamic)
SET(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} ${CMAKE_CXX_FLAGS}")
ENDIF(MSVC)

####### Activates OpenMP on architectures which support it, exclude Apple because of a bug when Qt tries 
# to load OpenMP from a spawned thread
IF(NOT APPLE)
    include(FindOpenMP)
    IF(OPENMP_FOUND)
        SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
        SET(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${OpenMP_EXE_LINKER_FLAGS}")
    ENDIF(OPENMP_FOUND)
ENDIF(NOT APPLE)

####### SEARCH FOR OPENGL ########################
####### Both OpenGL are set as REQUIRED
find_package(OpenGL REQUIRED)
IF(APPLE)
	# PARAMETRO IMPORTANTE PER FARE LA BUILD SU OSX CON LIBRERIE 64 bit, potrebbe non essere necessario su altri mac!!!
    SET(CMAKE_OSX_ARCHITECTURES "i386;x86_64")
	# To fix http://asqueella.blogspot.it/2010/12/dyld-unknown-required-load-command.html
	# you also have to export MACOSX_DEPLOYMENT_TARGET=10.5 environment variable before building!
	SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -mmacosx-version-min=10.5")
	include_directories ( /System/Library/Frameworks )
	include_directories(${OPENGL_INCLUDE_DIR})
	find_library(OpenGL_LIBRARY OpenGL )
	# Linkare le librerie opengl
    SET(GL_LIBS "-framework OpenGL" )
ENDIF (APPLE)

IF ( UNIX AND NOT APPLE)
    include_directories(${OPENGL_INCLUDE_DIR})
    SET(GL_LIBS ${OPENGL_LIBRARIES})
ENDIF ( UNIX AND NOT APPLE)
##################### END SEARCH FOR OPENGL ###########################

#############################  SEARCH FOR X11  #################################
find_package(X11)
IF( X11_XTest_FOUND )
		include_directories( ${X11_X11_INCLUDE_PATH} ${X11_XTest_INCLUDE_PATH} )
ENDIF( X11_XTest_FOUND )

############################# END CMAKE SCRIPT #################################
# Add the subdirectory with all the needed sources
add_subdirectory(src)

################################################################################
############## CREAZIONE PACCHI OSX, WINDOWS E LINUX ###########################
################################################################################
SET(CPACK_PACKAGE_VERSION "${GRAPHINSIGHT_MAJOR}.${GRAPHINSIGHT_MINOR}.${GRAPHINSIGHT_PATCH}")
SET(CPACK_PACKAGE_DESCRIPTION "GraphInsight: networks and graphs layout, fast, intuitive, reactive.")
SET(CPACK_PACKAGE_DESCRIPTION_SUMMARY "GraphInsight is a visualization software that lets you explore graph data through high quality interactive representations. www.graphinsight.com")
#SET(CPACK_PACKAGE_DESCRIPTION_FILE "${CMAKE_SOURCE_DIR}/README.txt")
SET(CPACK_PACKAGE_CONTACT "Carlo Nicolini info@graphinsight.com")
SET(CPACK_PACKAGE_AUTHOR "Carlo Nicolini")
SET(CPACK_PACKAGE_VENDOR "The GraphInsight Team")
SET(CPACK_PACKAGE_VERSION_MAJOR ${GRAPHINSIGHT_MAJOR})
SET(CPACK_PACKAGE_VERSION_MINOR ${GRAPHINSIGHT_MINOR})
SET(CPACK_PACKAGE_VERSION_PATCH ${GRAPHINSIGHT_PATCH})
SET(CPACK_PACKAGE_NAME "GraphInsight-${LICENSE_TYPE}-${GRAPHINSIGHT_MAJOR}.${GRAPHINSIGHT_MINOR}.${GRAPHINSIGHT_PATCH}")
# This variable will set a univoque name per build, for example GraphInsight-Pro-1.2.0-Linux-x86_64
SET(CPACK_PACKAGE_FILE_NAME  "${CPACK_PACKAGE_NAME}-${CMAKE_SYSTEM_NAME}-${CMAKE_SYSTEM_PROCESSOR}")
SET(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/LICENSE.txt")
#SET(CPACK_SET_DESTDIR ON) # http://cmake.3232098.n2.nabble.com/CPack-RPM-and-install-td5213420.html

##################### SEZIONE CREAZIONE PACCO LINUX  #############################
if (UNIX AND NOT APPLE)
	INCLUDE (InstallRequiredSystemLibraries)
        #If a sysconfdir is specified, use it instead
        #of the default configuration dir.
        IF(DEFINED SYSCONFDIR)
                SET(SYSCONFDIR ${SYSCONFDIR} CACHE PATH "config directory")
        else(DEFINED SYSCONFDIR)
                SET(SYSCONFDIR ${PREFIX}/etc CACHE PATH "config directory")
        ENDIF(DEFINED SYSCONFDIR)
        #If an XDG Config Dir is specificed, use it instead
        #of the default XDG configuration dir.
        IF(DEFINED XDG_CONFIG_DIR)
        SET(XDG_CONFIG_DIR ${XDG_CONFIG_DIR} CACHE PATH "xdg config directory")
        else(DEFINED XDG_CONFIG_DIR)
                SET(XDG_CONFIG_DIR ${SYSCONFDIR}/xdg CACHE PATH "xdg config directory")
        ENDIF(DEFINED XDG_CONFIG_DIR)
        
        SET(CPACK_GENERATOR "DEB;RPM;TGZ;STGZ")
	SET(CPACK_DEBIAN_ARCHITECTURE ${CMAKE_SYSTEM_PROCESSOR})
	#SET(CPACK_DEBIAN_PACKAGE_SHLIBDEPS TRUE)
        # LE DIPENDENZE PER IL PACCO RPM VENGONO RISOLTE AUTOMATICAMENTE DA CMAKE VERSIONE >= 2.8.1
        IF( NOT DESKTOP_ENTRY )
        SET( DESKTOP_ENTRY graphinsight.desktop )
        ENDIF( NOT DESKTOP_ENTRY )
        # Crea il file graphinsight.desktop
        add_custom_command( OUTPUT ${DESKTOP_ENTRY} COMMAND touch ${DESKTOP_ENTRY} COMMAND sh ${CMAKE_MODULE_PATH}/generateLinuxDesktopEntry.sh ${CMAKE_INSTALL_PREFIX} >${DESKTOP_ENTRY} 
                DEPENDS ${CMAKE_MODULE_PATH}/generateLinuxDesktopEntry.sh COMMENT "Generating desktop entry file")
        add_custom_target( DESKTOP_ENTRY_FILE ALL DEPENDS ${DESKTOP_ENTRY} )
        # crea il file graphinsight.menu XML contenente le informazioni per aggiungere al menu
        IF( NOT MENU_ENTRY )
                SET( MENU_ENTRY graphinsight.menu )
        ENDIF( NOT MENU_ENTRY )
        add_custom_command( OUTPUT ${MENU_ENTRY} COMMAND touch ${MENU_ENTRY} COMMAND sh ${CMAKE_MODULE_PATH}/generateLinuxMenuEntry.sh ${CMAKE_INSTALL_PREFIX} >${MENU_ENTRY} DEPENDS ${CMAKE_MODULE_PATH}/generateLinuxMenuEntry.sh COMMENT "Generating menu XML entry file")
        add_custom_target( MENU_ENTRY_FILE ALL DEPENDS ${MENU_ENTRY} )

        IF( NOT DIRECTORY_ENTRY )
                SET( DIRECTORY_ENTRY graphinsight.directory )
        ENDIF( NOT DIRECTORY_ENTRY )
        add_custom_command( OUTPUT ${DIRECTORY_ENTRY} COMMAND touch ${DIRECTORY_ENTRY} COMMAND sh ${CMAKE_MODULE_PATH}/generateLinuxDirectory.sh ${CMAKE_INSTALL_PREFIX} >${DIRECTORY_ENTRY} DEPENDS ${CMAKE_MODULE_PATH}/generateLinuxDirectory.sh COMMENT "Generating linux directory entry file")
        add_custom_target( DIRECTORY_ENTRY_FILE ALL DEPENDS ${DIRECTORY_ENTRY} )

        # Imposta l'icona
        SET(APP_ICON ${CMAKE_SOURCE_DIRECTORY}/resources/icons/logo2.png)
        # freedesktop file, lo copia in /usr/share/applications dove stanno tutti gli altri file delle applicazioni da mostrare nella lista principale
        install(FILES graphinsight.desktop DESTINATION "share/applications/")
        #install(FILES graphinsight.menu DESTINATION "${XDG_CONFIG_DIR}/menus/")
        install(FILES graphinsight.directory DESTINATION "share/desktop-directories/")
ENDIF(UNIX AND NOT APPLE)

############################ CREAZIONE PACCO WIN32 #############################

if (WIN32)
	# Come preparare pacchi per win32
	# http://www.cmake.org/Wiki/CMake:CPackWin32NewbiesChecklist
	INCLUDE (InstallRequiredSystemLibraries)
	SET(CPACK_GENERATOR "NSIS;ZIP")
	
	SET(CPACK_PACKAGE_INSTALL_DIRECTORY "GraphInsight")
	# "Benvenuti nell'installazione di GraphInsight e mette l'eseguibile in ProgramFiles\GraphInsight e nome della versione
	SET(CPACK_PACKAGE_INSTALL_DIRECTORY "GraphInsight ${GRAPHINSIGHT_MAJOR}.${GRAPHINSIGHT_MINOR}.${GRAPHINSIGHT_PATCH}")
	#SET(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/LICENSE.txt")	# stringa contenente la lettura della licenza da parte dell'utente
	# Set the components to be installed
	SET(CPACK_COMPONENTS_ALL Application Libraries) #Importante, per capire come funziona vedere l'occorrenza delle stringhe "Application" e "Libraries" in src/graphinsight/CMakeLists.txt
	# Set components display name which is visualized in the installer
	# i nomi utilizzati in queste variabili _APPLICATION_ e _LIBRARIES_ corrispondono ai nomi delle componenti messi sopra. Lasciamo cosi va...
	# sembra strano ma in qualche modo scemo lui sostituisce la stringa e si cambia il nome della variabile via preprocessore...
	SET(CPACK_COMPONENT_APPLICATION_DISPLAY_NAME "GraphInsight ${LICENSE_TYPE} ${GRAPHINSIGHT_MAJOR}.${GRAPHINSIGHT_MINOR}.${GRAPHINSIGHT_PATCH}")
	SET(CPACK_COMPONENT_LIBRARIES_DISPLAY_NAME "Qt4, MSVC")
	
        IF( PYTHON_QT_SUPPORT )
            SET(CPACK_COMPONENT_LIBRARIES_DISPLAY_NAME "${CPACK_COMPONENT_LIBRARIES_DISPLAY_NAME} and Python2.7 runtime libraries")
        else(PYTHON_QT_SUPPORT )
            SET(CPACK_COMPONENT_LIBRARIES_DISPLAY_NAME " ${CPACK_COMPONENT_LIBRARIES_DISPLAY_NAME} runtime libraries")
        ENDIF(PYTHON_QT_SUPPORT )
	SET(CPACK_COMPONENT_APPLICATION_DESCRIPTION "GraphInsight main executable")
	SET(CPACK_COMPONENT_LIBRARIES_DESCRIPTION "Qt and runtime libraries")
	# ----> installER OK ---< #
	
	# Set the icons for the installer
	SET(CPACK_NSIS_INSTALLED_ICON_NAME "GraphInsight-${LICENSE_TYPE}-${GRAPHINSIGHT_MAJOR}.${GRAPHINSIGHT_MINOR}.${GRAPHINSIGHT_PATCH}.exe")
	#SET(CPACK_NSIS_MUI_ICON "${CMAKE_SOURCE_DIR}/resources/icons/logowin32.ico")
	SET(CPACK_PACKAGE_DESCRIPTION "GraphInsight ${GRAPHINSIGHT_MAJOR}.${GRAPHINSIGHT_MINOR}.${GRAPHINSIGHT_PATCH} Windows Installer")
	# Qui si imposta il nome dell'eseguibile che apparirà nel menu start (primo argomento deve restare GraphInsight, secondo argomento nome invece può contenere la versione)
	SET(CPACK_PACKAGE_EXECUTABLES "GraphInsight" "GraphInsight (v${GRAPHINSIGHT_MAJOR}.${GRAPHINSIGHT_MINOR}.${GRAPHINSIGHT_PATCH})")
	# --> FINE --<  #
	
ENDIF(WIN32)

INCLUDE(CPack)
