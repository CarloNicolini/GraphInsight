This folder contains two set of dynamic libraries needed to run GraphInsight.

*	glut32.dll
	Is the old-styled OpenGL based library, must be in the same folder of the executable, see src/graphinsight/CMakeLists.txt in order for it to be run
*	QtCore4.dll, QtGui4.dll, QtOpenGL4.dll are the 4.7.3 version of Qt libraries, compiled for MSVC2008. They must be in the same of the executable.