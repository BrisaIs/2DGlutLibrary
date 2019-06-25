#ifndef UTILITIES_H
  #define UTILITIES_H
  #include "Utilities.h"
#endif

#ifndef GLUT
  #define GLUT
  #include <GL/glut.h>
#endif

class Point2D
{

  private:
    int px;
    GLdouble point[2];

  public:

    Point2D();
    Point2D(GLdouble, GLdouble);

	 void setPx(int);
	 void setValue(int,GLdouble);
    void setPoint2D(GLdouble, GLdouble);

	  int getPx();
    GLdouble* getPoint2D();
    GLdouble getValue(int);

   void drawPoint2D(int);
	void drawPoint2D();

};
