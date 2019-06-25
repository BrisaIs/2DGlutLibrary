#define XPOS 0
#define YPOS 1

#ifndef POINT2D_H
  #define POINT2D_H
  #include "Point2D.h"
#endif

#ifndef MATRIX_H
    #define MATRIX_H
    #include "Matrix.h"
#endif // MATRIX_H

#ifndef POLYGON2D_H
	#define POLYGON2D_H
	#include "Polygon2D.h"
#endif
class Operators2D
{
	public:
		Operators2D();
		~Operators2D();

		void translation2D(Polygon2D&, Point2D);
		void scale2D(Polygon2D&, Point2D);
		void rotation2D(Polygon2D&, GLdouble);
		void reflexX2D(Polygon2D&);
		void reflexY2D(Polygon2D&);
		void reflexXY2D(Polygon2D&);
};
