#define XPOS 0
#define YPOS 1
#ifndef POINT2D_H
  #define POINT2D_H
  #include "Point2D.h"
#endif

Point2D::Point2D()
{
	this->point[XPOS] = 0.0;
   this->point[YPOS] = 0.0;
}

Point2D::Point2D(GLdouble x, GLdouble y)
{
  this->point[XPOS] = x;
  this->point[YPOS] = y;
};

void Point2D::setPx(int px){this->px = px;};
void Point2D::setValue(int i,GLdouble value){this->point[i] = value;};
void Point2D::setPoint2D(GLdouble x, GLdouble y)
{
	this->point[XPOS] = x;
   this->point[YPOS] = y;
};

int Point2D::getPx(){return px;};
GLdouble* Point2D::getPoint2D(){ return this->point;};
GLdouble Point2D::getValue(int i){return this->point[i];};


void Point2D::drawPoint2D(int px)
{
  glPointSize(px);
  glBegin(GL_POINTS);
  	glVertex2d( getValue(XPOS) , getValue(YPOS) );
  glEnd();
};

void Point2D::drawPoint2D()
{
    glColor3f(0.5, 0.5, 0.5);
  glPointSize(2);
  glBegin(GL_POINTS);
    glVertex2d( getValue(XPOS) , getValue(YPOS) );
  glEnd();
};
