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


#include "GLUtils.h"
#include "Statistic.h"

using namespace std;


GLUtils::GLUtils()
{
}

GLUtils::GLUtils(const GLUtils& orig)
{
}

GLUtils::~GLUtils()
{
}

/**
 * @brief GLUtils::drawSphereAt
 * @param x
 * @param y
 * @param z
 * @param radius
 * @param quality
 * @param wired
 */
void GLUtils::drawSphereAt(float x, float y, float z, float radius, int quality)
{  if(quality == 0)
   {  glPointSize(radius * 400);
      glBegin(GL_POINTS);
      glVertex3f(x,y,z);
      glEnd();
   }
   else
   {
      GLUquadricObj *quadricSphere=gluNewQuadric();
      gluQuadricNormals(quadricSphere, GLU_SMOOTH);
      glPushMatrix();
      glTranslatef(x, y, z);
      gluSphere(quadricSphere,radius,quality,quality);
      glPopMatrix();
      gluDeleteQuadric(quadricSphere);
   }
}

/**
 * @brief GLUtils::drawArrow
 * @param baseRadius
 * @param topRadius
 * @param height
 * @param x
 * @param y
 * @param z
 * @param a
 * @param ax
 * @param ay
 * @param az
 */
void GLUtils::drawArrow(float baseRadius, float topRadius, float height, float x, float y, float z, float a, float ax, float ay, float az)
{
   GLUquadricObj* cyl = NULL;
   cyl = gluNewQuadric();
   gluQuadricDrawStyle(cyl, GLU_FILL);

   glPushMatrix();
   glTranslated(x, y, z);
   glRotatef(a, ax, ay, az);
   gluCylinder(cyl, baseRadius, topRadius, height, 6, 4);
   gluDeleteQuadric(cyl);

   glTranslated(0.0, 0.0, height);
   GLUquadric *coneQuadric = gluNewQuadric();
   gluCylinder(coneQuadric,0.05,0.0,0.2,10,10); //should be the same as glutSolidCone
   //glutSolidCone(0.05, 0.2, 20, 20);
    gluDeleteQuadric(coneQuadric);
   glPopMatrix();
}

/**
 * @brief GLUtils::drawCylinder
 * @param radius
 * @param x0
 * @param y0
 * @param z0
 * @param x1
 * @param y1
 * @param z1
 * @param quality
 * @param type
 */
void GLUtils::drawCylinder(double radius, double x0, double y0, double z0, double x1, double y1, double z1, int quality, int type)
{  if(quality == 0)
   {  glLineWidth(radius * 400);
      glBegin(GL_LINES);
      glVertex3f(x0,y0,z0);
      glVertex3f(x1,y1,z1);
      glEnd();
   }
   else
   {  glPushMatrix();
      GLUquadricObj* quad = gluNewQuadric();
      glTranslatef(x0, y0, z0);
      double d[3];
      d[0] = x1 - x0;
      d[1] = y1 - y0;
      d[2] = z1 - z0;
      double d_norm = sqrt(d[0]*d[0]+d[1]*d[1]+d[2]*d[2]);
      double angle = 180.0 / 3.141592654 * acosf(d[2]/d_norm);
      double r[3];
      r[0] = -d[1];
      r[1] = d[0];
      r[2] = 0;
      double r_norm = sqrt(r[0]*r[0]+r[1]*r[1]+r[2]*r[2]);
      r[0] /= r_norm;
      r[1] /= r_norm;
      r[2] /= r_norm;

      if(fabs(angle) < 0.001)
      {  //      cout << "parallel" << endl;
      }
      else if(fabs(angle-180.0) < 0.001)
      {  //    cout << "anti-parallel" << endl;
      }
      else
         glRotatef(angle, r[0], r[1], r[2]);
      // parameters for gluCylinder: (quad, baseRadius, topRadius, height, slices, stacks);
      gluCylinder(quad, radius, type == 1 ? 0 : radius, d_norm, quality*4, 4);

      if(type == 2)
      {  glTranslated(0.0, 0.0, d_norm/2);
         //glutSolidCone(radius*2,radius*4, 20, 20);
      }
      gluDeleteQuadric(quad);
      glPopMatrix();
   }
}

/**
 * @brief GLUtils::drawGrid
 * @param x
 * @param y
 * @param z
 * @param width
 * @param n
 * @param a
 * @param ax
 * @param ay
 * @param az
 */
void GLUtils::drawGrid(float x, float y, float z, float width, int n, float a, float ax, float ay, float az)
{

   float step = width / (float) n;
   glPushMatrix();
   glTranslated(x, y, z);
   glRotatef(a, ax, ay, az);
   /* Render grid over 0..rows, 0..columns. */
   glBegin(GL_LINES);
   /* Horizontal lines. */
   for (float yoff = 0.0; yoff <= width; yoff += step)
   {  glVertex3f(0, yoff, 0);
      glVertex3f(0 + width, yoff, 0);
   }
   for (float xoff = 0.0; xoff <= width; xoff += step)
   {  glVertex3f(xoff, 0, 0);
      glVertex3f(xoff, width, 0);
   }
   glEnd();
   glPopMatrix();
}

/**
 * @brief GLUtils::setAmbientColor
 * @param r
 * @param g
 * @param b
 * @param a
 */
void GLUtils::setAmbientColor(float r, float g, float b, float a)
{  static float rgba[5];
   rgba[0] = r;
   rgba[1] = g;
   rgba[2] = b;
   rgba[3] = a;

   glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, rgba);
}

/**
 * @brief GLUtils::drawPlane
 * @param x
 * @param y
 * @param z
 * @param width
 * @param a
 * @param ax
 * @param ay
 * @param az
 */
void GLUtils::drawPlane(float x, float y, float z, float width, float a, float ax, float ay, float az)
{

   glPushMatrix();
   glTranslated(x, y, z);
   glRotatef(a, ax, ay, az);
   /* Render grid over 0..rows, 0..columns. */
   glBegin(GL_POLYGON);
   glVertex3f(0, 0, 0);
   glVertex3f(0, width, 0);
   glVertex3f(width, width, 0);
   glVertex3f(width, 0, 0);
   glEnd();
   glPopMatrix();
}

/**
 * @brief GLUtils::beginOrtho
 */
void GLUtils::beginOrtho()
{  glMatrixMode(GL_PROJECTION);
   glPushMatrix();
   glLoadIdentity();
   GLint viewport [4];
   glGetIntegerv(GL_VIEWPORT, viewport);
   gluOrtho2D(0, viewport[2], viewport[3], 0);
   glMatrixMode(GL_MODELVIEW);
   glPushMatrix();
   glLoadIdentity();
}

/**
 * @brief GLUtils::endOrtho
 */
void GLUtils::endOrtho()
{  glMatrixMode(GL_PROJECTION);
   glPopMatrix();
   glMatrixMode(GL_MODELVIEW);
   glPopMatrix();
}

/**
 * @brief GLUtils::unProject
 * @param x
 * @param y
 * @param cx
 * @param cy
 * @param cz
 */
void GLUtils::unProject(int x, int y, double *cx, double *cy, double *cz)
{  GLint viewport[4];
   GLdouble modelview[16];
   GLdouble projection[16];
   GLfloat winX, winY, winZ;

   glMatrixMode(GL_PROJECTION);
   glPushMatrix();
   glLoadIdentity();
   glGetDoublev(GL_MODELVIEW_MATRIX, modelview);
   glGetDoublev(GL_PROJECTION_MATRIX, projection);
   glGetIntegerv(GL_VIEWPORT, viewport);
   winX = (float) x;
   winY = (float) viewport[3] - (float) y;
   //    glReadPixels(x, int(winY), 1, 1, GL_DEPTH_COMPONENT, GL_FLOAT, &winZ);
   winZ = 0;
   gluUnProject(winX, winY, winZ, modelview, projection, viewport, cx, cy, cz);
   glPopMatrix();
   glMatrixMode(GL_MODELVIEW);
}

/**
 * @brief GLUtils::hsv2rgb
 * @param S
 * @param H
 * @param V
 * @param r
 * @param g
 * @param b
 */
void GLUtils::hsv2rgb( double S, double H, double V, double *r, double *g, double *b )
{  /*
    * Purpose:
    * Convert a double 0<x<1 values to RGB values
    */
   double F, M, N, K;
   int   I;
   //   S = 1;  /* Saturation */
   //   H = X;  /* Hue */
   //   V = 1;  /* value or brightness */
   if ( S == 0.0 )
   {  /*
      * Achromatic case, set level of grey
      */
      *r = V;
      *g = V;
      *b = V;
      //   printf("=> Red %g Green %g Blue %g\n", *r,*g,*b);
   }
   else
   {  /*
      * Determine levels of primary colours.
      */
      if (H >= 1.0)
      {  H = 0.0;
      }
      else
      {  H = H * 6;
      } /* end if */
      I = (int) H;   /* should be in the range 0..5 */
      F = H - I;     /* fractional part */
      M = V * (1 - S);
      N = V * (1 - S * F);
      K = V * (1 - S * (1 - F));
      if (I == 0)
      {  *r = V;
         *g = K;
         *b = M;
      }
      if (I == 1)
      {  *r = N;
         *g = V;
         *b = M;
      }
      if (I == 2)
      {  *r = M;
         *g = V;
         *b = K;
      }
      if (I == 3)
      {  *r = M;
         *g = N;
         *b = V;
      }
      if (I == 4)
      {  *r = K;
         *g = M;
         *b = V;
      }
      if (I == 5)
      {  *r = V;
         *g = M;
         *b = N;
      }
   }
} /* end function hsv2rgb */

//http://en.wikipedia.org/wiki/HSL_and_HSV
// http://www.cs.rit.edu/~ncs/color/t_convert.html
// r,g,b values are from 0 to 1
// h = [0,360], s = [0,1], v = [0,1]
//    if s == 0, then h = -1 (undefined)
void GLUtils::RGBtoHSV( double r, double g, double b, double *h, double *s, double *v )
{  double min = std::min( r, std::min(g, b ));
   double max = std::max( r, std::max(g, b ));
   *v = max;// v

   double delta = max - min;

   if( max != 0 )
      *s = delta / max;     // s
   else
   {  // r = g = b = 0      // s = 0, v is undefined
      *s = 0;
      *h = -1;
      return;
   }
   if( r == max )
      *h = ( g - b ) / delta;     // between yellow & magenta
   else if( g == max )
      *h = 2 + ( b - r ) / delta; // between cyan & yellow
   else
      *h = 4 + ( r - g ) / delta; // between magenta & cyan
   *h *= 60;           // degrees
   if( *h < 0 )
      *h += 360;
}

void GLUtils::HSVtoRGB( double *r, double *g, double *b, double h, double s, double v )
{  int i=0;
   double f=0.0, p=0.0, q=0.0, t=0.0;
   if( s == 0 )
   {  // achromatic (grey)
      *r = *g = *b = v;
      return;
   }

   h /= 60;         // sector 0 to 5
   i = floor( h );
   f = h - i;       // factorial part of h
   p = v * ( 1 - s );
   q = v * ( 1 - s * f );
   t = v * ( 1 - s * ( 1 - f ) );

   switch( i )
   {  case 0:
         *r = v;
         *g = t;
         *b = p;
         break;
      case 1:
         *r = q;
         *g = v;
         *b = p;
         break;
      case 2:
         *r = p;
         *g = v;
         *b = t;
         break;
      case 3:
         *r = p;
         *g = q;
         *b = v;
         break;
      case 4:
         *r = t;
         *g = p;
         *b = v;
         break;
      default:      // case 5:
         *r = v;
         *g = p;
         *b = q;
         break;
   }
}

/**
*
**/
void GLUtils::project(double x0, double y0, double z0, double *x1, double *y1, double *z1)
{  
   GLint viewport[4];
   GLdouble modelview[16];
   GLdouble projection[16];

   glGetDoublev(GL_MODELVIEW_MATRIX, modelview);
   glGetDoublev(GL_PROJECTION_MATRIX, projection);
   glGetIntegerv(GL_VIEWPORT, viewport);
   // we dont' need to push-pop matrix here!
   glMatrixMode(GL_PROJECTION);
   glPushMatrix();
   glLoadIdentity();
   gluProject(x0,y0,z0,modelview,projection,viewport,x1,y1,z1);
   glPopMatrix();
   glMatrixMode(GL_MODELVIEW);

   *y1 = viewport[3] - *y1;
}

/**
*
**/
void GLUtils::projectWithMVP(double x0, double y0, double z0, GLdouble* modelviewMatrix, GLdouble *projMatrix, GLint* viewport, double *x1, double *y1, double *z1)
{
	gluProject(x0,y0,z0,modelviewMatrix,projMatrix,viewport,x1,y1,z1);
	*y1 = viewport[3] - *y1;
}
