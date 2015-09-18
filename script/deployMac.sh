### SCRIPT FOR DEPLOYMENT ON OSX ###
# Support for older OSX Versions
export MACOSX_DEPLOYMENT_TARGET=10.5

while true; do
    read -p "Do you wish to deploy GraphInsight? I have to DELETE ALL UNVERSIONED FILES here, continue [y/n]?" yn
    case $yn in
        [Yy]* ) git clean -df .; break;;
        [Nn]* ) exit;;
        * ) echo "Please answer Y or N (yes or no).";;
    esac
done

GRAPHINSIGHT_VERSION=$(<cmake/BUILD_VERSION.txt)
echo "The GraphInsight version to build is GRAPHINSIGHT_VERSION"

while true; do
    read -p "You are going to create GraphInsight ${GRAPHINSIGHT_VERSION} OSX deploy, are you sure to continue? [yY/nN]" yn
    case $yn in
        [Yy]* ) break;;
        [Nn]* ) exit;;
        * ) echo "Please answer Y or N (yes or no).";;
    esac
done

ARCHITECTURE_TYPE=`uname -p`;

for license in `echo "Trial Academic Pro"`
do
    export DMG_NAME="GraphInsight-${license}-${GRAPHINSIGHT_VERSION}-MacOSX-`uname -p`.dmg";
    # Creates the makefile for the build, Release version
    cmake -DCMAKE_BUILD_TYPE=RelWithDebInfo -DGRAPHINSIGHT_RELEASE=Alpha -D LICENSE_TYPE=${license} .
    # Make the GraphInsight subproject (exclude all the tests)
    make -j2 GraphInsight
    # macdeployqt inserts all the dependencies in the .app folder (for portability issues)
    macdeployqt build/GraphInsight.app
    cp resources/macx_bundle/Info.plist build/GraphInsight.app/Contents/
    mkdir -p deploymentosx/GraphInsight.app
    cp -r build/GraphInsight.app/ deploymentosx/GraphInsight.app
    # Copy sample graph in the deploymentosx directory
    cp -r data/Samples deploymentosx/
    # Remove .svn directory from Samples
    rm -rf deploymentosx/Samples/.svn/
    # Create a symbolic link  to Applications in the same directory (installation by Drag&Drop)
    ln -s /Applications deploymentosx/
    # Creates the .dmg disk image, includings all examples, licenses and link to Applications
    hdiutil create -volname "GraphInsight-${license}-${GRAPHINSIGHT_VERSION}" -ov -format UDZO -imagekey zlib-level=9 -srcfolder "deploymentosx" "${DMG_NAME}"
    cp ${DMG_NAME} $HOME/Dropbox/Builds/GraphInsight_1.3/OSX/
done
