# GraphInsight
GraphInsight is a visualization software that lets you explore graph data through high quality interactive representations.

## How to build
### WINDOWS
Building GraphInsight for Windows is rather cumbersome and you need to pay some attention to details. In particular you must be sure that the Qt libraries are the ones built for your same compiler and, in order to package all the project and generate the setup.exe you need other external programs, such as 7-zip and NSIS.

* For code checkout
1) Install GIT for Windows. We suggest to use Tortoise GIT as git user-interface: 
	http://code.google.com/p/tortoisegit/
Follow the installation instructions on TortoiseGIT website for further information on how make git available on 
your Windows computer.

### For building:
Install as follows in this order:

1) Install Microsoft Visual Studio 2008 or Microsoft Visual Studio 2010. You can build GraphInsight also with free version of 
the Microsoft Visual Studio, namely "Visual Studio Express 2008" or "Visual Studio Express 2010". Build process is not tested with Visual Studio 2012 or newer. 

2) Install CMake for Windows, the latest version tested is the 2.8.11
	http://www.cmake.org/

3) Install Qt 4.8.4 SDK. It is very important that the binaries of Qt 4.8.4 SDK **MATCH** your current version 
of Visual Studio.
	http://download.qt-project.org/official_releases/qt/4.8/4.8.4/qt-win-opensource-4.8.4-vs2008.exe

4) Install the latest Python 2.7.x for Windows. We currently don't support Python 3.x
	http://python.org/ftp/python/2.7.5/python-2.7.5.msi
When installing it, don't change the default settings for the installation, so Python will be under "C:/Python27"

* For packaging
5) Install NSIS (a sfor package creation)
	http://nsis.sourceforge.net/Main_Page

6) Install 7zip for Windows (for package creation)
	http://www.7-zip.org/

Be sure that you have the following directories in your system Path:

<code>
	C:\Program Files (x86)\CMake 2.8\bin;

	C:\QtSDK\Desktop\Qt\4.8.4\msvc2008\bin;

	C:\QtSDK\Desktop\Qt\4.8.4\msvc2008\lib;

	C:\QtSDK\Desktop\Qt\4.8.4\msvc2008\include;

	C:\Program Files (x86)\Microsoft Visual Studio 9.0\Common7\IDE\;

	C:\Program Files (x86)\7-Zip\;

</code>

Open a command prompt and try to isse the following commands:

<code>
"devenv" #This should open Visual Studio

"cmake" # This should run cmake

"7z" # this should run 7zip
</code>

### AUTOMATIC BUILD INSTRUCTIONS
We provide a simple "deployWin32.bat" script that allows you to deploy all the GraphInsight versions in one step. If you are lucky enough and all
the things already mentioned were installed correctly, a double click on it would suffice:


### MANUAL BUILD INSTRUCTIONS

If the deployWin32 script didn't work you have to set up things manually. 
Once you have installed everything, you must run CMake for the first time in order to generate the Visual Studio solution.
Open the CMake GUI interface. Select the base folder where you've checked out the GraphInsight repository.
The content of "Where is the source code" and "Where to build the binaries" must be the SAME.

You can do the same in order to set the Debug/Release version.

If you prefer to use cmake from command line, then you just have to change to the base directory of GraphInsight (for example, suppose 
you've downloaded GraphInsight source code in 

<code>
	C:\Users\username\Desktop\graphinsight_base_directory)
</code>

and then:
<code>
	cd C:\Users\username\Desktop\graphinsight_base_directory\build

	cmake -D CMAKE_BUILD_TYPE=Release ..
</code>

If CMake process went fine, then you have to open the solution file <b>GraphInsight.sln</b> in the same folder of GraphInsight and try to build the 
sub-project GraphInsight.

### WINDOWS BUILD FAQ
If you get side-by-side configuration is incorrect it's because in the installer no runtime libraries are included.
So you have to manually check that the following files are redistributed with the pack:

<code>
	msvcm90.dll
	msvcr90.dll
	msvcp90.dll
	vcomp90.dll
</code>

If you have problem when compiling with OpenMP active, you have to be sure that the correct path of the OPENMP msvc library is correct, because I've included it brute-force
because of a bug in CMake (currently still a bug in version 2.8, this is discussed in src/graphinsight/CMakeLists.txt)
If you are using Visual Studio 2010 the files are instead:

<code>
	msvcm100.dll
	msvcr100.dll
	msvcp100.dll
	vcomp100.dll
</code>

If you still experience problems of this kind, try to disable the OpenMP support from the main CMakeLists.txt, by commenting the following lines:

<code>
	IF(NOT APPLE)
	    include(FindOpenMP)
	    IF(OPENMP_FOUND)
		SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
		SET(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${OpenMP_EXE_LINKER_FLAGS}")
	    ENDIF(OPENMP_FOUND)
	ENDIF(NOT APPLE)
</code>

We didn't enable OpenMP on Apple explicitly because of a bug of Qt when is spawning a layout thread.
The QThread and OpenMP seem to interfere in a bad way, causing a segfault crash. 

---
## LINUX
In order to correctly build the packages for 64 bit linux, please download the latest "cmake".

Here we provide instructions to build on debian-based distributions (I'm using Ubuntu 14.04 x86_64)

<code>
	sudo apt-get update
	sudo apt-get upgrade

	sudo apt-get install libglew1.9 libglew1.9-dev libglu1-mesa libglu1-mesa-dev libgl1-mesa-glx libgl1-mesa-dev mesa-common-dev libxi-dev libxmu-dev libxmuu-dev qt4-dev-tools build-essential rpm
</code>

---
### MAC OSX
GraphInsight build is tested and it works on OSX-10.5.8 system. No newer OSX system has already been tested for the build process.

In order to build GraphInsight for OSX you need the following programs:
	* XCode 4
	* git (should be included in the XCode installation)
	* Qt 4.8 (you can download Qt for Mac-OSX at the following website: http://qt-project.org/downloads )
	We suggest to first install Qt libraries 4.8.4 for Mac (185 MB) and then install the latest Qt Creator tool (Qt Creator 2.7.1 for Mac (Intel 32/64bit)) as preferred tool for GraphInsight code editing.

	* http://download.qt-project.org/official_releases/qt/4.8/4.8.4/qt-mac-opensource-4.8.4.dmg
	* http://download.qt-project.org/official_releases/qtcreator/2.7/2.7.1/qt-creator-mac-opensource-2.7.1.dmg

* Check your current version of Python
	$> python --version 

First of all set the environment variable:

<code>
	$> export MAC_OSX_DEPLOYMENT_TARGET=10.5

	$> git pull
	
	$> cmake -DCMAKE_BUILD_TYPE=Release -DLICENSE_TYPE=Pro .
	
	$> make GraphInsight
	
	$> sudo macdeployqt build/GraphInsight.app
</code>

Ensure that the following folder is inserted into the Bundle:
GraphInsight.app/Contents/Frameworks/Python.framework

Only if you have dependencies problems, you can run the following commands:

	install_name_tool -change /opt/local/Library/Frameworks/Python.framework/Versions/2.7/Python /Library/Frameworks/Python.framework/Versions/2.5/Python GraphInsight.app/Contents/MacOS/GraphInsight

You should also indicate which Python library it must be added in the bundle. Avoid the MacPort library, because is not build for multiarchitecture (both i386 and x86_64)

<code>
	$> export DYLD_LIBRARY_PATH e cercare di evitare /opt/local/lib/libpython2.7.dylib
</code>
For Python dependencies, install the universal binaries from macport

<code>
	$> sudo port install python25 +universal python26 +universal python27 +universal
</code>

Specify the folder where is searching for python, directly in the CMakeLists.txt, find the rows:

<code>
	# Use the MacPort library
	set(PYTHON_LIBRARY "/opt/local/lib/")
	set(PYTHON_INCLUDE_DIR "/opt/local/include/python2.5/")
</code>

In order for everything to run smoothly, everything must match (headers and binaries of python must be the very same version).
