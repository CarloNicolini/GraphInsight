#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>

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
#include "Arcball.h"

using namespace std; 
using namespace Eigen;

/**
@ingroup GraphLayout
Arcball constructor,set ball radius to a typical value of 600
**/
Arcball::Arcball() : ballRadius(600), isRotating(false),width(0),height(0)
{
        reset();
}

/**
@ingroup GraphLayout
  Costructor, set the ball radius
**/
Arcball::Arcball(float _ballRadius) : ballRadius(_ballRadius), isRotating(false), width(0),height(0)
{
	reset();
}

/**
@ingroup GraphLayout
Set width and height of the screen in pixels
**/
void Arcball::setWidthHeight(int w, int h)
{
    width=w;
    height=h;
    ballRadius = std::min((w)/2, (h)/2);
}

/**
@ingroup GraphLayout
Set the radius of the arcball
**/
void Arcball::setRadius(float newRadius) {
	ballRadius = newRadius;
}


/**
@ingroup GraphLayout
Start the arcball rotation, save the current opengl matrix and starting points
@param _x the mouse x coordinate
@param _y the mouse y coordinate
**/
void Arcball::startRotation(int _x, int _y)
{
    int x = ( (_x)-(width/2) );
    int y = ((height/2)-_y);
    
	startRotationVector = convertXY(x,y);
	startRotationVector.normalize();

	currentRotationVector=  startRotationVector;
	isRotating = true;

}

/**
@ingroup GraphLayout
Update the rotation matrix to the current mouse coordinates
@param _x the mouse x coordinate
@param _y the mouse y coordinate
**/
void Arcball::updateRotation(int _x, int _y){
    int x = ( (_x)-(width/2) );
    int y = ((height/2)-_y);
    
	currentRotationVector = convertXY(x,y);
		
	currentRotationVector.normalize();
}

/**
@ingroup GraphLayout
Apply the rotation matrix to the scene
**/
void Arcball::applyRotationMatrix() {
	if (isRotating) {
		// Do some rotation according to start and current rotation vectors
		// Avoid too little rotations
        if ( ( currentRotationVector - startRotationVector).norm() > 1E-6 )
        {   
		Vector3d rotationAxis = currentRotationVector.cross(startRotationVector);
		rotationAxis.normalize();

		double val = currentRotationVector.dot(startRotationVector);
        if (val > 1-1E-6)
            val=1.0;

        double rotationAngle = acos(val) * 180.0f/(float)M_PI;
               
	    // rotate around the current position
		applyTranslationMatrix(true);
		glRotatef(rotationAngle * 2, -rotationAxis.x(),  -rotationAxis.y(),-rotationAxis.z());
		applyTranslationMatrix(false);
	    }
	}
	glMultMatrixf(startMatrix);	
}

/**
@ingroup GraphLayout
Stop the current rotation and reset the transform matrix
**/
void Arcball::stopRotation(){

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	applyRotationMatrix();
	// set the current matrix as the permanent one
	glGetFloatv(GL_MODELVIEW_MATRIX, startMatrix);
	isRotating = false;
}

/**
@ingroup GraphLayout
Apply the precomputed translation+rotation matrix to the current view
**/
void Arcball::applyTranslationMatrix(bool reverse) {
	float factor = (reverse?-1.0f:1.0f);		
	float tx = transX + (currentTransX - startTransX)*TRANSLATION_FACTOR;
	float ty = transY + (currentTransY - startTransY)*TRANSLATION_FACTOR;
	glTranslatef(factor*tx,  factor*(-ty), 0);
}

 
/**
@ingroup GraphLayout
Convert X and Y mouse coordinates to a 3D vector from the projection of the 2d coordinates on a sphere to the origin
@param x mouse x coordinate
@param y mouse y coordinate
**/
Vector3d Arcball::convertXY(int x, int y) {
    
	int d = x*x+y*y;
	float radiusSquared = ballRadius*ballRadius;
	if (d > radiusSquared) { 
		return Vector3d((float)x,(float)y, 0 );
	} else {
		return Vector3d((float)x,(float)y, sqrt(radiusSquared - d));
	}
}

/**
@ingroup GraphLayout
Reset the arcball rotation, set translation matrix to zero and rotation matrix to identity
**/
void Arcball::reset() {
    // reset matrix
	memset(startMatrix, 0, sizeof(startMatrix));
	startMatrix[0] = 1; startMatrix[1] =0; startMatrix[2] = 0; startMatrix[3] = 0;
	startMatrix[4] = 0; startMatrix[5] =1; startMatrix[6] = 0; startMatrix[7] = 0;
	startMatrix[8] = 0; startMatrix[9] =0; startMatrix[10] = 1; startMatrix[11] = 0;
	startMatrix[12] = 0; startMatrix[13] =0; startMatrix[14] = 0; startMatrix[15] = 1;

	transX = transY = 0;
	startTransX = startTransY = currentTransX = currentTransY = 0;
}

const float Arcball::TRANSLATION_FACTOR = 0.01f;

