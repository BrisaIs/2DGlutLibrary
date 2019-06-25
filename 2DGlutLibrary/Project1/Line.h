#define XPOS 0
#define YPOS 1
#ifndef POINT2D_H
  #define POINT2D_H
  #include "Point2D.h"
#endif

class Line
{
	private:
		Point2D startL;
		Point2D endL;

	public:
		Line();
		Line(Point2D,Point2D);
		Line(double, double, double, double);

		~Line();

		void setOrigin(Point2D);
    void setEnd(Point2D);

		Point2D getOrigin();
    Point2D getEnd();

		void drawLine();
};
