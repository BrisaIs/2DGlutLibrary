#ifndef UTILITIES_H
  #define UTILITIES_H
  #include "Utilities.h"
#endif

#ifndef ESSE
    #define ESSE
    #include <stdio.h>
    #include <stdlib.h>
#endif


#ifndef LINE_H
  #define LINE_H
  #include "Line.h"
#endif

#ifndef POINT2D_H
  #include "Point2D.h"
  #define POINT2D_H
#endif

class Polygon2D
{
	private:
		int sides;
		//double distance; //Se asume que se trabaja con poligonos regulares
		Point2D centroid;
		//int distances[sides];
		Point2D *mainPoints2D;
		Line *awns;

	public:
  //  Polygon2D();
		Polygon2D(int,Point2D[]);
		~Polygon2D();

   void createMemory();

    void setVertex(int,Point2D);
    void setCentroid();

    Point2D getVertex(int);
    Point2D getCentroid();
    int getSides();

	 void printMainPoints();
   ///Line* getLines();
	 void generateLines2D();
	 void drawPolygon2D();
};
