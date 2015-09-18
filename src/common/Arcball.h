/****************************************************************************
**
** Copyright (C) 2010 Carlo Nicolini (nicolini.carlo@gmail.com)
** All rights reserved.
**
** Warning: This program is protected by copyright law and international
** treaties. Unauthorized reproduction and distribution of this program,
** or any portion of it, may result in severe civil and criminal penalties,
** and will be persecuted to the maximum extent possible under the law.
**
****************************************************************************/

#ifndef ARCBALL_H
#define ARCBALL_H

#ifdef __APPLE__
#include <OpenGL/OpenGL.h>
#endif
#ifdef __linux__
#include <GL/gl.h>
#include <GL/glu.h>
#endif

#ifdef _WIN32
#include <windows.h>
#include <gl\gl.h>            // Header File For The OpenGL32 Library
#include <gl\glu.h>            // Header File For The GLu32 Library
#endif

#include <Eigen/Core>
#include <Eigen/Geometry>

using namespace Eigen;

/**
* \ingroup Common
* \class Arcball
* \brief Arcball is a method to manipulate and rotate objects in 3D intuitively.
*
* The motivation behind the trackball (aka arcball) is to provide an intuitive user interface for complex 3D
* object rotation via a simple, virtual sphere - the screen space analogy to the familiar input device bearing
* the same name.
*
* The sphere is a good choice for a virtual trackball because it makes a good enclosure for most any object;
* and its surface is smooth and continuous, which is important in the generation of smooth rotations in response
* to smooth mouse movements.
* Any smooth, continuous shape, however, could be used, so long as points on its surface can be generated
*  in a consistent way.
* The algorithm for accomplishing this, needs to perform the following steps (not neseccarily in order).
*
*
*
*
* \b ArcBall Algorithm made easy
*  - Detect the left-button of the mouse being depressed.
*  - Keep track of the last known mouse position.
*  - Treat the mouse position as the projection of a point on the hemi-sphere down to the image plane (along the z-axis), and determine that point on the hemi-sphere.
*  - Detect the mouse movement
*  - Determine the great circle connecting the old mouse-hemi-sphere point to the current mouse-hemi-sphere point.
*  - Calculate the normal to this plane. This will be the axis about which to rotate.
*  - Set the OpenGL state to modify the MODELVIEW matrix.
*  - Read off the current matrix, since we want this operation to be the last transformation, not the first, and OpenGL does things LIFO.
*  - Reset the model-view matrix to the identity
*  - Rotate about the axis
*  - Multiply the resulting matrix by the saved matrix.
*  - Force a redraw of the scene.
*
* An example of the code for using successfully this class is the following:
* First set the radius of the arcball by using the appropriate method when you call the handle to the GLUT resize method (this is usually accomplished with a
* \code
* void handleResize(int w, int h)
* \endcode
* function in GLUT (if you are using Qt or other, please refer to the relative API ).
* An example of a \code handleResize(int w, int h) \endcode function is the following:
* \code
* void handleResize(int w, int h)
* {
*   arcball.setWidthHeight(w, h);
*   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
*   glViewport(0, 0, w, h);
*
*   glMatrixMode(GL_PROJECTION);
*   glLoadIdentity();
*   gluPerspective(viewAngle, (float)w / (float)w, zNear, zFar );
*
*   glMatrixMode(GL_MODELVIEW);
* }
* \endcode
*
*
These are the two functions (GLUT) that control the mouse events:
* \code
* void mouseFunc(int state, int button, int _x , int _y)
* {
*   if ( button == GLUT_LEFT_BUTTON )
*       arcball.startRotation(_x,_y);
*   else
*       arcball.stopRotation();
*
*
*   glutPostRedisplay();
* }
*
* void mouseDrag(int _x, int _y)
* {
*
*   arcball.updateRotation(_x,_y);
*   glutPostRedisplay();
* }
*
* \endcode
*
**/
typedef float GLMatrix[16];

class Arcball {
private:

	float transX, transY;
	float currentTransX, currentTransY;
	float startTransX, startTransY;

	GLMatrix startMatrix;
	GLMatrix currentMatrix;
	Vector3d startRotationVector;
	Vector3d currentRotationVector;
	bool isRotating;
	float ballRadius;
	static const float INITIAL_FOV;
	static const float MINIMAL_FOV;
	static const float TRANSLATION_FACTOR;

	Vector3d convertXY(int x, int y);
    int width, height;
public:
    Arcball();
	Arcball(float ballRadius);
	
    void setWidthHeight(int w, int h);
	void startRotation(int x, int y);
	void updateRotation(int x, int y);
	void stopRotation();
	
	
	void applyTranslationMatrix(bool reverse = false);
	void applyRotationMatrix();

	void setRadius(float newRadius);
	void reset();
};


#endif

