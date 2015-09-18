/****************************************************************************
**
** Copyright (C) 2010 Michele Dallachiesa (michele.dallachiesa@gmail.com)
** All rights reserved.
**
** Warning: This program is protected by copyright law and international
** treaties. Unauthorized reproduction and distribution of this program,
** or any portion of it, may result in severe civil and criminal penalties,
** and will be persecuted to the maximum extent possible under the law.
**
****************************************************************************/


#ifndef _GLUTILS_H
#define  _GLUTILS_H

#ifdef __APPLE__
#include <OpenGL/OpenGL.h>
#include <OpenGL/glu.h>
#endif
#ifdef __linux__
#include <GL/gl.h>
#include <GL/glu.h>
#endif

#ifdef _WIN32
#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#endif

#define AMBIENT_COLOR_WHITE 1.0,1.0,1.0
#define AMBIENT_COLOR_BLACK 0.0,0.0,0.0
#define AMBIENT_COLOR_RED 1.0,0.0,0.0
#define AMBIENT_COLOR_GREEN 0.0,1.0,0.0
#define AMBIENT_COLOR_BLUE 0.0,0.0,1.0
#define AMBIENT_COLOR_ORANGE 1.0,0.5,0.0
#include <vector>

#include <stdlib.h>
#include <math.h>
#ifndef M_PI_2
#define M_PI_2 1.570796327
#endif
#include <sstream>

#define getGLerrors() (GLUtils::glError(__FILE__,__LINE__))

using namespace std;

class GLUtils
{
public:
   GLUtils();
   GLUtils(const GLUtils& orig);
   virtual ~GLUtils();
   static void drawSphereAt(float x, float y, float z, float radius, int quality);
   static void drawArrow(float baseRadius, float topRadius, float height, float x, float y, float z, float a, float ax, float ay, float az);
   static void drawGrid(float x, float y, float z, float height, int n, float a, float ax, float ay, float az);
   static void drawPlane(float x, float y, float z, float width, float a, float ax, float ay, float az);
   static void setAmbientColor(float r, float g, float b, float a);
   static void beginOrtho();
   static void endOrtho();
   static void unProject(int x, int y, double *cx, double *cy, double *cz);
   static void hsv2rgb(double S, double H,double V, double *r, double *g, double *b );
   static void RGBtoHSV( double r, double g, double b, double *h, double *s, double *v );
   static void HSVtoRGB( double *r, double *g, double *b, double h, double s, double v );
   static void drawCylinder(double radius, double x0, double y0, double z0, double x1, double y1, double z1, int quality, int type);
   static void project(double x0, double y0, double z0, double *x1, double *y1, double *z1);
   static void projectWithMVP(double x0, double y0, double z0, GLdouble* modelviewMatrix, GLdouble *projMatrix, GLint* viewport, double *x1, double *y1, double *z1);
   static void glError(const char *file, int line);
private:

};

#endif   /* _GLUTILS_H */

