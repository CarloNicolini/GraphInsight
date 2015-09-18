# GRAPHINSIGHT header files
SET(GI_HDRS
DataSet.h GLUtils.h GLWidget.h GraphLayoutGL.h GraphLayoutGLOptions.h
LayoutThread.h Licensing.h MainWindow.h QUtils.h SplashDialog.h BackgroundLayoutThread.h OptionsDialog.h DocumentationText.h
)
# GRAPHINSIGHT source files
SET(GI_SRCS main.cpp MainWindow.cpp DataSet.cpp GLUtils.cpp GLWidget.cpp GraphLayoutGL.cpp GraphLayoutGLOptions.cpp
LayoutThread.cpp Licensing.cpp QUtils.cpp SplashDialog.cpp BackgroundLayoutThread.cpp OptionsDialog.cpp DocumentationText.cpp
)

if (PYTHON_QT_SUPPORT)  # if we use pythonqt, add the necessary classes
SET(GI_HDRS "${GI_HDRS};LNodeWrapper.h;MainWindowDecorator.h;LNodeFactory.h")
SET(GI_SRCS "${GI_SRCS};LNodeWrapper.cpp;MainWindowDecorator.cpp;LNodeFactory.cpp")
ENDIF(PYTHON_QT_SUPPORT)

# GRAPHINSIGHT user interface files
SET(GI_FORMS About.ui  Activate.ui  HelpDialog.ui  Licensing.ui  MainWindow.ui SplashDialog.ui OptionsDialog.ui)
SET(GI_RSCS "${CMAKE_SOURCE_DIR}/resources/images.qrc" "${CMAKE_SOURCE_DIR}/resources/demos.qrc" "${CMAKE_SOURCE_DIR}/resources/documents.qrc")
#link_libraries ( ${QT_QTCORE_LIBRARY} ${QT_QTGUI_LIBRARY} )
include_directories( ${QT_INCLUDE_PATH} ${QT_QTGUI_INCLUDE_DIR} ${QT_QTCORE_INCLUDE_DIR}  ../common/ ../graphlayout/ ../eigen/ ${CMAKE_CURRENT_BINARY_DIR})

QT4_ADD_RESOURCES( GI_RSCS_SOURCES ${GI_RSCS} )
QT4_WRAP_UI( GI_FORMS_HDRS ${GI_FORMS} )
QT4_WRAP_CPP( GI_HDRS_MOC ${GI_HDRS} )

SET(GI_PROGNAME "GraphInsight")

# Inizia la parte dipendente dal sistema operativo.
#### WINDOWS 32 ####
IF(WIN32)
        ADD_EXECUTABLE(${GI_PROGNAME} WIN32 ${GI_SRCS} ${GI_HDRS} ${GI_HDRS_MOC} ${GI_RSCS_SOURCES} ${GI_FORMS_HDRS} ${GraphInsight_RCS} ${CMAKE_SOURCE_DIR}/resources/icons/iconwin32.rc LicenseType.h)
        SET_TARGET_PROPERTIES(${GI_PROGNAME} PROPERTIES COMPILE_DEFINITIONS "${LICENSE_TYPE}")
	if ( PYTHON_QT_SUPPORT )
        TARGET_LINK_LIBRARIES(${GI_PROGNAME} ${QT_LIBRARIES} Common GraphLayout PythonQt ${PYTHON_LIBRARY} ${OPENGL_LIBRARIES} )
	else (PYTHON_QT_SUPPORT)
        TARGET_LINK_LIBRARIES(${GI_PROGNAME} ${QT_LIBRARIES} Common GraphLayout ${OPENGL_LIBRARIES})
	endif (PYTHON_QT_SUPPORT)
	# We also install the msvcrt library which is really necessary!
	INCLUDE(InstallRequiredSystemLibraries)
        INSTALL(TARGETS ${GI_PROGNAME} DESTINATION bin COMPONENT Application)
        INSTALL(TARGETS ${GI_PROGNAME} RUNTIME DESTINATION bin)
	# Aggiunge che in fase di installazione copia le librerie Qt 4.7.3 nella stessa cartella del binario
	INSTALL(FILES
		"${QT_LIBRARY_DIR}/QtCore${QT_VERSION_MAJOR}.dll"
		"${QT_LIBRARY_DIR}/QtOpenGL${QT_VERSION_MAJOR}.dll"
		"${QT_LIBRARY_DIR}/QtGui${QT_VERSION_MAJOR}.dll"
		DESTINATION bin  COMPONENT Libraries)
	INSTALL(FILES ${CMAKE_install_SYSTEM_RUNTIME_LIBS} DESTINATION bin COMPONENT Libraries)
        IF( PYTHON_QT_SUPPORT )
		    INSTALL(FILES "${CMAKE_SOURCE_DIR}/deps/Python/python27.dll" DESTINATION bin  COMPONENT Libraries)
		    MESSAGE(STATUS "Copying PythonQt.DLL from ${EXECUTABLE_OUTPUT_PATH}/Release/ to installation bin")
		    INSTALL(FILES "${EXECUTABLE_OUTPUT_PATH}/Release/PythonQt.dll" DESTINATION bin  COMPONENT Libraries)
        ENDIF(PYTHON_QT_SUPPORT)
	MESSAGE(STATUS "Copying Microsoft Runtime libraries ${CMAKE_install_SYSTEM_RUNTIME_LIBS}")
	# Because of a BUG in CMake 2.8.7 http://public.kitware.com/Bug/view.php?id=12964
	# if OpenMP is activated, the necessary vcomp90.dll library is not added to the CMAKE_install_SYSTEM_RUNTIME_LIBS,
	# so we add BRUTE FORCE the DLL and the Manifest file
    IF(OPENMP_FOUND)
		INSTALL(FILES "C:/Program Files (x86)/Microsoft Visual Studio 9.0/VC/redist/x86/Microsoft.VC90.OPENMP/vcomp90.dll" DESTINATION bin COMPONENT Libraries)
		INSTALL(FILES "C:/Program Files (x86)/Microsoft Visual Studio 9.0/VC/redist/x86/Microsoft.VC90.OPENMP/Microsoft.VC90.OpenMP.manifest" DESTINATION bin COMPONENT Libraries)
	ENDIF(OPENMP_FOUND)
ENDIF(WIN32)

#### APPLE ####
IF(APPLE)
        SET( GI_OSX_RSC_DIR ${CMAKE_SOURCE_DIR}/build/${GI_PROGNAME}.app/Contents/Resources )
        # Set the icon of the bundle correctly
        #set( MACOSX_BUNDLE_INFO_PLIST ${CMAKE_CURRENT_SOURCE_DIR}/resources/macx_bundle/Info.plist )
        SET( MACOSX_BUNDLE_ICON_FILE logo2.icns)
        SET_SOURCE_FILES_PROPERTIES(${MACOSX_BUNDLE_ICON_FILE} PROPERTIES MACOSX_PACKAGE_LOCATION Resources)
        SET( CPACK_BUNDLE_NAME "GraphInsight")
        SET( MACOSX_BUNDLE_NAME "GraphInsight")
        SET( MACOSX_BUNDLE_INFO_STRING "GraphInsight v${GRAPHINSIGHT_VERSION}" )
        SET( MACOSX_BUNDLE_VERSION "Bundle " )
        SET( MACOSX_BUNDLE_SHORT_VERSION_STRING "${GRAPHINSIGHT_VERSION}" )
        SET( MACOSX_BUNDLE_LONG_VERSION_STRING "Version ${GRAPHINSIGHTVERSION}" )

        ADD_EXECUTABLE(${GI_PROGNAME} MACOSX_BUNDLE ${GI_SRCS} ${GI_HDRS} ${GI_HDRS_MOC} ${GI_RSCS_SOURCES} ${GI_FORMS_HDRS} ${GraphInsight_RCS} LicenseType.h)
        # Copy the custom icon inside bundle Contents/Resources folder
        ADD_CUSTOM_COMMAND( TARGET ${GI_PROGNAME} POST_BUILD
              COMMAND mkdir ARGS -p ${GI_OSX_RSC_DIR}
              COMMAND cp ARGS ${CMAKE_SOURCE_DIR}/resources/icons/${MACOSX_BUNDLE_ICON_FILE} ${GI_OSX_RSC_DIR} )
                 
        SET_TARGET_PROPERTIES(${GI_PROGNAME} PROPERTIES COMPILE_DEFINITIONS "${LICENSE_TYPE}")
        TARGET_LINK_LIBRARIES(${GI_PROGNAME} ${QT_LIBRARIES} ${OPENGL_LIBRARIES} Common GraphLayout)
	    IF(PYTHON_QT_SUPPORT)
	        MESSAGE(STATUS "Linking GraphInsight Python ${PYTHON_LIBRARY}")
            TARGET_LINK_LIBRARIES(${GI_PROGNAME} PythonQt ${PYTHON_LIBRARY})
        ENDIF(PYTHON_QT_SUPPORT)
        INCLUDE(InstallRequiredSystemLibraries)
        INSTALL(TARGETS ${GI_PROGNAME} DESTINATION bin COMPONENT Application)
ENDIF(APPLE)

#### LINUX ####
if (UNIX AND NOT APPLE)
	# Generate the PROFESSIONAL version
        ADD_EXECUTABLE(${GI_PROGNAME} ${GI_SRCS} ${GI_HDRS} ${GI_HDRS_MOC} ${GI_RSCS_SOURCES} ${GI_FORMS_HDRS} ${GraphInsight_RCS} LicenseType.h)
        SET_TARGET_PROPERTIES(${GI_PROGNAME} PROPERTIES COMPILE_DEFINITIONS "${LICENSE_TYPE}")
        TARGET_LINK_LIBRARIES(${GI_PROGNAME} ${QT_LIBRARIES} Common GraphLayout GL GLU )
	if (PYTHON_QT_SUPPORT )
                TARGET_LINK_LIBRARIES(${GI_PROGNAME} PythonQt)
	endif (PYTHON_QT_SUPPORT)
	# Parte relativa a CPACK per generazione del pacchetto (debian o rpm, facendo così installa anche le dipendenze da Qt
        INSTALL(TARGETS ${GI_PROGNAME} DESTINATION bin COMPONENT "${QT_LIBRARIES};${GL_LIBS}")
        INSTALL(FILES "${CMAKE_SOURCE_DIR}/resources/icons/logo2.png" DESTINATION share/graphinsight/icons/)
endif (UNIX AND NOT APPLE)

