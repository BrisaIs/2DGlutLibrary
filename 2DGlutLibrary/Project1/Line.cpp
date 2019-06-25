#ifndef LINE_H
  #define LINE_H
  #include "Line.h"
#endif

   #ifndef MATH_H
    #define MATH_H
    #include <math.h>
  #endif
Line::Line()
{
    this->startL = Point2D(0.0, 0.0);
    this->endL = Point2D(0.0, 0.0);
}

Line::Line(Point2D p1, Point2D p2)
{
    this->startL = p1;
    this->endL = p2;
}

Line::Line(GLdouble x1, GLdouble y1, GLdouble x2, GLdouble y2)
{
    this->startL.setValue(XPOS,x1);
    this->startL.setValue(YPOS,y1);

    this->endL.setValue(XPOS,x2);
    this->endL.setValue(YPOS,y2);
}

Line::~Line(){}

void Line::setOrigin(Point2D a){this->startL = a;}
void Line::setEnd(Point2D b){this->endL = b;}

Point2D Line::getOrigin(){return this->startL;}
Point2D Line::getEnd(){return this->endL;}

void Line::drawLine()
{

    GLdouble dx=0, dy=0, xInc=0, yInc=0, steps=0, x=0, y=0;

    dy = (GLdouble)(this->endL.getValue(YPOS)) - (this->startL.getValue(YPOS));
    dx = (GLdouble)(this->endL.getValue(XPOS)) - (this->startL.getValue(XPOS));

    if( abs(dx) > abs(dy) )
        steps = abs(dx);
    else
        steps = abs(dy);

    xInc = dx / steps;
    yInc = dy / steps;

    x = (GLdouble)this->startL.getValue(XPOS);
    y = (GLdouble)this->startL.getValue(YPOS);

    //drawPoint2D(0.0, 0.0);
    Point2D aux;

    for(int i=1; i<=steps; i++)
    {
        x += xInc;
        y += yInc;

        aux.setPoint2D(floor(x),floor(y));


        aux.drawPoint2D();
    }

};
