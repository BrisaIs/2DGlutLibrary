#define XPOS 0
#define YPOS 1

#ifndef UTILITIES_H
  #define UTILITIES_H
  #include "Utilities.h"
#endif

#ifndef MATH_H
    #define MATH_H
    #include <math.h>
  #endif

#ifndef POINT2D_H
  #define POINT2D_H
  #include "Point2D.h"
#endif

#ifndef GLUT
  #define GLUT
  #include <GL/glut.h>
#endif
#ifndef ESSE
    #define ESSE
    #include <stdio.h>
    #include <stdlib.h>
#endif

class Matrix
{
    private:
      GLdouble matrix[3][3];
      GLdouble vector [3];
    public:
    	Matrix();
    	~Matrix();

      void setPosition(int,int,int,GLdouble);
      GLdouble getPosition(int,int,int);

      void sumPosition(int,int,int,GLdouble);

      void zeroVector2D();
      void zeroMatrix2D();

      void loadVertex(Point2D);
      void loadOrigin2D(Point2D);
      void loadIdentity2D();
      void loadPoint2D(Point2D);

      void loadTranslation2D(Point2D);
      void loadScale2D(Point2D);
      void loadRotation2D(GLdouble);

      void loadReflexX2D();
      void loadReflexY2D();
      void loadReflexXY2D();

      void multiplyVector(Matrix,Matrix&);
      void multiply(Matrix,Matrix&);

      void printVector();
      void printMatrix();

};
