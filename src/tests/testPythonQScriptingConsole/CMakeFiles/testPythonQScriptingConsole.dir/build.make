# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list

# Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/cmake-gui

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/carlo/workspace/graphinsightdevel

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/carlo/workspace/graphinsightdevel

# Include any dependencies generated for this target.
include src/tests/testPythonQScriptingConsole/CMakeFiles/testPythonQScriptingConsole.dir/depend.make

# Include the progress variables for this target.
include src/tests/testPythonQScriptingConsole/CMakeFiles/testPythonQScriptingConsole.dir/progress.make

# Include the compile flags for this target's objects.
include src/tests/testPythonQScriptingConsole/CMakeFiles/testPythonQScriptingConsole.dir/flags.make

src/tests/testPythonQScriptingConsole/CMakeFiles/testPythonQScriptingConsole.dir/main.cpp.o: src/tests/testPythonQScriptingConsole/CMakeFiles/testPythonQScriptingConsole.dir/flags.make
src/tests/testPythonQScriptingConsole/CMakeFiles/testPythonQScriptingConsole.dir/main.cpp.o: src/tests/testPythonQScriptingConsole/main.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/carlo/workspace/graphinsightdevel/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/tests/testPythonQScriptingConsole/CMakeFiles/testPythonQScriptingConsole.dir/main.cpp.o"
	cd /home/carlo/workspace/graphinsightdevel/src/tests/testPythonQScriptingConsole && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/testPythonQScriptingConsole.dir/main.cpp.o -c /home/carlo/workspace/graphinsightdevel/src/tests/testPythonQScriptingConsole/main.cpp

src/tests/testPythonQScriptingConsole/CMakeFiles/testPythonQScriptingConsole.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/testPythonQScriptingConsole.dir/main.cpp.i"
	cd /home/carlo/workspace/graphinsightdevel/src/tests/testPythonQScriptingConsole && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/carlo/workspace/graphinsightdevel/src/tests/testPythonQScriptingConsole/main.cpp > CMakeFiles/testPythonQScriptingConsole.dir/main.cpp.i

src/tests/testPythonQScriptingConsole/CMakeFiles/testPythonQScriptingConsole.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/testPythonQScriptingConsole.dir/main.cpp.s"
	cd /home/carlo/workspace/graphinsightdevel/src/tests/testPythonQScriptingConsole && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/carlo/workspace/graphinsightdevel/src/tests/testPythonQScriptingConsole/main.cpp -o CMakeFiles/testPythonQScriptingConsole.dir/main.cpp.s

src/tests/testPythonQScriptingConsole/CMakeFiles/testPythonQScriptingConsole.dir/main.cpp.o.requires:
.PHONY : src/tests/testPythonQScriptingConsole/CMakeFiles/testPythonQScriptingConsole.dir/main.cpp.o.requires

src/tests/testPythonQScriptingConsole/CMakeFiles/testPythonQScriptingConsole.dir/main.cpp.o.provides: src/tests/testPythonQScriptingConsole/CMakeFiles/testPythonQScriptingConsole.dir/main.cpp.o.requires
	$(MAKE) -f src/tests/testPythonQScriptingConsole/CMakeFiles/testPythonQScriptingConsole.dir/build.make src/tests/testPythonQScriptingConsole/CMakeFiles/testPythonQScriptingConsole.dir/main.cpp.o.provides.build
.PHONY : src/tests/testPythonQScriptingConsole/CMakeFiles/testPythonQScriptingConsole.dir/main.cpp.o.provides

src/tests/testPythonQScriptingConsole/CMakeFiles/testPythonQScriptingConsole.dir/main.cpp.o.provides.build: src/tests/testPythonQScriptingConsole/CMakeFiles/testPythonQScriptingConsole.dir/main.cpp.o

src/tests/testPythonQScriptingConsole/CMakeFiles/testPythonQScriptingConsole.dir/PyExampleObject.cpp.o: src/tests/testPythonQScriptingConsole/CMakeFiles/testPythonQScriptingConsole.dir/flags.make
src/tests/testPythonQScriptingConsole/CMakeFiles/testPythonQScriptingConsole.dir/PyExampleObject.cpp.o: src/tests/testPythonQScriptingConsole/PyExampleObject.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/carlo/workspace/graphinsightdevel/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/tests/testPythonQScriptingConsole/CMakeFiles/testPythonQScriptingConsole.dir/PyExampleObject.cpp.o"
	cd /home/carlo/workspace/graphinsightdevel/src/tests/testPythonQScriptingConsole && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/testPythonQScriptingConsole.dir/PyExampleObject.cpp.o -c /home/carlo/workspace/graphinsightdevel/src/tests/testPythonQScriptingConsole/PyExampleObject.cpp

src/tests/testPythonQScriptingConsole/CMakeFiles/testPythonQScriptingConsole.dir/PyExampleObject.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/testPythonQScriptingConsole.dir/PyExampleObject.cpp.i"
	cd /home/carlo/workspace/graphinsightdevel/src/tests/testPythonQScriptingConsole && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/carlo/workspace/graphinsightdevel/src/tests/testPythonQScriptingConsole/PyExampleObject.cpp > CMakeFiles/testPythonQScriptingConsole.dir/PyExampleObject.cpp.i

src/tests/testPythonQScriptingConsole/CMakeFiles/testPythonQScriptingConsole.dir/PyExampleObject.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/testPythonQScriptingConsole.dir/PyExampleObject.cpp.s"
	cd /home/carlo/workspace/graphinsightdevel/src/tests/testPythonQScriptingConsole && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/carlo/workspace/graphinsightdevel/src/tests/testPythonQScriptingConsole/PyExampleObject.cpp -o CMakeFiles/testPythonQScriptingConsole.dir/PyExampleObject.cpp.s

src/tests/testPythonQScriptingConsole/CMakeFiles/testPythonQScriptingConsole.dir/PyExampleObject.cpp.o.requires:
.PHONY : src/tests/testPythonQScriptingConsole/CMakeFiles/testPythonQScriptingConsole.dir/PyExampleObject.cpp.o.requires

src/tests/testPythonQScriptingConsole/CMakeFiles/testPythonQScriptingConsole.dir/PyExampleObject.cpp.o.provides: src/tests/testPythonQScriptingConsole/CMakeFiles/testPythonQScriptingConsole.dir/PyExampleObject.cpp.o.requires
	$(MAKE) -f src/tests/testPythonQScriptingConsole/CMakeFiles/testPythonQScriptingConsole.dir/build.make src/tests/testPythonQScriptingConsole/CMakeFiles/testPythonQScriptingConsole.dir/PyExampleObject.cpp.o.provides.build
.PHONY : src/tests/testPythonQScriptingConsole/CMakeFiles/testPythonQScriptingConsole.dir/PyExampleObject.cpp.o.provides

src/tests/testPythonQScriptingConsole/CMakeFiles/testPythonQScriptingConsole.dir/PyExampleObject.cpp.o.provides.build: src/tests/testPythonQScriptingConsole/CMakeFiles/testPythonQScriptingConsole.dir/PyExampleObject.cpp.o

src/tests/testPythonQScriptingConsole/CMakeFiles/testPythonQScriptingConsole.dir/moc_PyExampleObject.cxx.o: src/tests/testPythonQScriptingConsole/CMakeFiles/testPythonQScriptingConsole.dir/flags.make
src/tests/testPythonQScriptingConsole/CMakeFiles/testPythonQScriptingConsole.dir/moc_PyExampleObject.cxx.o: src/tests/testPythonQScriptingConsole/moc_PyExampleObject.cxx
	$(CMAKE_COMMAND) -E cmake_progress_report /home/carlo/workspace/graphinsightdevel/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/tests/testPythonQScriptingConsole/CMakeFiles/testPythonQScriptingConsole.dir/moc_PyExampleObject.cxx.o"
	cd /home/carlo/workspace/graphinsightdevel/src/tests/testPythonQScriptingConsole && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/testPythonQScriptingConsole.dir/moc_PyExampleObject.cxx.o -c /home/carlo/workspace/graphinsightdevel/src/tests/testPythonQScriptingConsole/moc_PyExampleObject.cxx

src/tests/testPythonQScriptingConsole/CMakeFiles/testPythonQScriptingConsole.dir/moc_PyExampleObject.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/testPythonQScriptingConsole.dir/moc_PyExampleObject.cxx.i"
	cd /home/carlo/workspace/graphinsightdevel/src/tests/testPythonQScriptingConsole && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/carlo/workspace/graphinsightdevel/src/tests/testPythonQScriptingConsole/moc_PyExampleObject.cxx > CMakeFiles/testPythonQScriptingConsole.dir/moc_PyExampleObject.cxx.i

src/tests/testPythonQScriptingConsole/CMakeFiles/testPythonQScriptingConsole.dir/moc_PyExampleObject.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/testPythonQScriptingConsole.dir/moc_PyExampleObject.cxx.s"
	cd /home/carlo/workspace/graphinsightdevel/src/tests/testPythonQScriptingConsole && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/carlo/workspace/graphinsightdevel/src/tests/testPythonQScriptingConsole/moc_PyExampleObject.cxx -o CMakeFiles/testPythonQScriptingConsole.dir/moc_PyExampleObject.cxx.s

src/tests/testPythonQScriptingConsole/CMakeFiles/testPythonQScriptingConsole.dir/moc_PyExampleObject.cxx.o.requires:
.PHONY : src/tests/testPythonQScriptingConsole/CMakeFiles/testPythonQScriptingConsole.dir/moc_PyExampleObject.cxx.o.requires

src/tests/testPythonQScriptingConsole/CMakeFiles/testPythonQScriptingConsole.dir/moc_PyExampleObject.cxx.o.provides: src/tests/testPythonQScriptingConsole/CMakeFiles/testPythonQScriptingConsole.dir/moc_PyExampleObject.cxx.o.requires
	$(MAKE) -f src/tests/testPythonQScriptingConsole/CMakeFiles/testPythonQScriptingConsole.dir/build.make src/tests/testPythonQScriptingConsole/CMakeFiles/testPythonQScriptingConsole.dir/moc_PyExampleObject.cxx.o.provides.build
.PHONY : src/tests/testPythonQScriptingConsole/CMakeFiles/testPythonQScriptingConsole.dir/moc_PyExampleObject.cxx.o.provides

src/tests/testPythonQScriptingConsole/CMakeFiles/testPythonQScriptingConsole.dir/moc_PyExampleObject.cxx.o.provides.build: src/tests/testPythonQScriptingConsole/CMakeFiles/testPythonQScriptingConsole.dir/moc_PyExampleObject.cxx.o

src/tests/testPythonQScriptingConsole/moc_PyExampleObject.cxx: src/tests/testPythonQScriptingConsole/PyExampleObject.h
	$(CMAKE_COMMAND) -E cmake_progress_report /home/carlo/workspace/graphinsightdevel/CMakeFiles $(CMAKE_PROGRESS_4)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Generating moc_PyExampleObject.cxx"
	cd /home/carlo/workspace/graphinsightdevel/src/tests/testPythonQScriptingConsole && /usr/bin/moc-qt4 -I/usr/include/qt4 -I/usr/include/qt4/QtOpenGL -I/usr/include/qt4/QtSvg -I/usr/include/qt4/QtGui -I/usr/include/qt4/QtCore -I/usr/include -I/home/carlo/workspace/graphinsightdevel/src/common -I/home/carlo/workspace/graphinsightdevel/src/graphlayout -I/home/carlo/workspace/graphinsightdevel/src/eigen -I/home/carlo/workspace/graphinsightdevel/src/graphinsight -I/usr/include/python2.7 -I/home/carlo/workspace/graphinsightdevel/src/pythonqt/src -I/home/carlo/workspace/graphinsightdevel/src/tests/../common -I/home/carlo/workspace/graphinsightdevel/src/tests/../graphlayout -I/home/carlo/workspace/graphinsightdevel/src/tests/../eigen -I/home/carlo/workspace/graphinsightdevel/src/tests/../graphinsight -I/home/carlo/workspace/graphinsightdevel/src/tests -DUSE_PYTHONQT=True -DQT_OPENGL_LIB -DQT_SVG_LIB -DQT_GUI_LIB -DQT_CORE_LIB -DGIT_SHA1=4ea64b395f569159a44e6b736ee7d235cf4281da -DGRAPHINSIGHT_VERSION=\"1.3.3\" -DPYTHONQT_USE_RELEASE_PYTHON_FALLBACK -o /home/carlo/workspace/graphinsightdevel/src/tests/testPythonQScriptingConsole/moc_PyExampleObject.cxx /home/carlo/workspace/graphinsightdevel/src/tests/testPythonQScriptingConsole/PyExampleObject.h

# Object files for target testPythonQScriptingConsole
testPythonQScriptingConsole_OBJECTS = \
"CMakeFiles/testPythonQScriptingConsole.dir/main.cpp.o" \
"CMakeFiles/testPythonQScriptingConsole.dir/PyExampleObject.cpp.o" \
"CMakeFiles/testPythonQScriptingConsole.dir/moc_PyExampleObject.cxx.o"

# External object files for target testPythonQScriptingConsole
testPythonQScriptingConsole_EXTERNAL_OBJECTS =

build/testPythonQScriptingConsole: src/tests/testPythonQScriptingConsole/CMakeFiles/testPythonQScriptingConsole.dir/main.cpp.o
build/testPythonQScriptingConsole: src/tests/testPythonQScriptingConsole/CMakeFiles/testPythonQScriptingConsole.dir/PyExampleObject.cpp.o
build/testPythonQScriptingConsole: src/tests/testPythonQScriptingConsole/CMakeFiles/testPythonQScriptingConsole.dir/moc_PyExampleObject.cxx.o
build/testPythonQScriptingConsole: build/libPythonQt.a
build/testPythonQScriptingConsole: /usr/lib/libpython2.7.so
build/testPythonQScriptingConsole: /usr/lib/x86_64-linux-gnu/libQtGui.so
build/testPythonQScriptingConsole: /usr/lib/x86_64-linux-gnu/libQtXml.so
build/testPythonQScriptingConsole: /usr/lib/x86_64-linux-gnu/libQtCore.so
build/testPythonQScriptingConsole: src/tests/testPythonQScriptingConsole/CMakeFiles/testPythonQScriptingConsole.dir/build.make
build/testPythonQScriptingConsole: src/tests/testPythonQScriptingConsole/CMakeFiles/testPythonQScriptingConsole.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable ../../../build/testPythonQScriptingConsole"
	cd /home/carlo/workspace/graphinsightdevel/src/tests/testPythonQScriptingConsole && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/testPythonQScriptingConsole.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/tests/testPythonQScriptingConsole/CMakeFiles/testPythonQScriptingConsole.dir/build: build/testPythonQScriptingConsole
.PHONY : src/tests/testPythonQScriptingConsole/CMakeFiles/testPythonQScriptingConsole.dir/build

src/tests/testPythonQScriptingConsole/CMakeFiles/testPythonQScriptingConsole.dir/requires: src/tests/testPythonQScriptingConsole/CMakeFiles/testPythonQScriptingConsole.dir/main.cpp.o.requires
src/tests/testPythonQScriptingConsole/CMakeFiles/testPythonQScriptingConsole.dir/requires: src/tests/testPythonQScriptingConsole/CMakeFiles/testPythonQScriptingConsole.dir/PyExampleObject.cpp.o.requires
src/tests/testPythonQScriptingConsole/CMakeFiles/testPythonQScriptingConsole.dir/requires: src/tests/testPythonQScriptingConsole/CMakeFiles/testPythonQScriptingConsole.dir/moc_PyExampleObject.cxx.o.requires
.PHONY : src/tests/testPythonQScriptingConsole/CMakeFiles/testPythonQScriptingConsole.dir/requires

src/tests/testPythonQScriptingConsole/CMakeFiles/testPythonQScriptingConsole.dir/clean:
	cd /home/carlo/workspace/graphinsightdevel/src/tests/testPythonQScriptingConsole && $(CMAKE_COMMAND) -P CMakeFiles/testPythonQScriptingConsole.dir/cmake_clean.cmake
.PHONY : src/tests/testPythonQScriptingConsole/CMakeFiles/testPythonQScriptingConsole.dir/clean

src/tests/testPythonQScriptingConsole/CMakeFiles/testPythonQScriptingConsole.dir/depend: src/tests/testPythonQScriptingConsole/moc_PyExampleObject.cxx
	cd /home/carlo/workspace/graphinsightdevel && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/carlo/workspace/graphinsightdevel /home/carlo/workspace/graphinsightdevel/src/tests/testPythonQScriptingConsole /home/carlo/workspace/graphinsightdevel /home/carlo/workspace/graphinsightdevel/src/tests/testPythonQScriptingConsole /home/carlo/workspace/graphinsightdevel/src/tests/testPythonQScriptingConsole/CMakeFiles/testPythonQScriptingConsole.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/tests/testPythonQScriptingConsole/CMakeFiles/testPythonQScriptingConsole.dir/depend

