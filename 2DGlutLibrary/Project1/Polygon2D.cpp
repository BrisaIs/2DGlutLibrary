#ifndef POLYGON2D_H
	#define POLYGON2D_H
	#include "Polygon2D.h"
#endif

#ifndef UTILITIES_H
	#define UTILITIES_H
	#include "Utilities.h"
#endif

Polygon2D::Polygon2D(int sides, Point2D mainPoints2D[])
{
	int i;
	this->sides = sides;

	/*Se crea la memoria para los puntos base del polígono y se copian
	los valores del arreglo dado*/
	this->mainPoints2D = new Point2D[this->sides];
	for( i = 0; i < this->sides; i++)
		this->mainPoints2D[i] = mainPoints2D[i];

	generateLines2D();
}

/*void Polygon3D::createMemory()
{
	int i;

	this->mainPoints3D = new GLint*[this->sides];

	for( i = 0; i < this->sides; i++)
	{
	  this->mainPoints3D[i] = new GLint[DIMENSION];
  }
}*/

void Polygon2D::setVertex(int i,Point2D vertex){this->mainPoints2D[i] = vertex;}

void Polygon2D::setCentroid()
{
/*
	GLdouble x = (getVertex(0).getValue(X)+ getVertex(1).getValue(X)+getVertex(2).getValue(X))/3;
	GLdouble y = (getVertex(0).getValue(Y)+ getVertex(1).getValue(Y)+getVertex(2).getValue(Y))/3;
	GLdouble z = (getVertex(0).getValue(Z)+ getVertex(1).getValue(Z)+getVertex(2).getValue(Z))/3;

	this->centroid.setPoint3D(x,y,z);
*/
/*
	 double signedArea = 0.0;
    double x0 = 0.0; // Current vertex X
    double y0 = 0.0; // Current vertex Y
    double x1 = 0.0; // Next vertex X
    double y1 = 0.0; // Next vertex Y
    double a = 0.0;  // Partial signed area

    // For all vertices except last
    int i=0;
    for (i=0; i< sides-1; ++i)
    {
        x0 = mainPoints3D[i].getX();
        y0 = mainPoints3D[i].getY();
        x1 = mainPoints3D[i+1].getX();
        y1 = mainPoints3D[i+1].getY();

				a = x0*y1 - x1*y0;
        signedArea += a;

        this->centroid.setX((double)this->centroid.getX() + (x0 + x1)*a);
        this->centroid.setY((double)this->centroid.getY()+ (y0 + y1)*a);
    }

    // Do last vertex separately to avoid performing an expensive
    // modulus operation in each iteration.
    x0 = mainPoints3D[i].getX();
    y0 = mainPoints3D[i].getY();
    x1 = mainPoints3D[0].getX();
    y1 = mainPoints3D[0].getY();

    a = x0*y1 - x1*y0;
    signedArea += a;

		this->centroid.setX((double)this->centroid.getX() + (x0 + x1)*a);
		this->centroid.setY((double)this->centroid.getY()+ (y0 + y1)*a);

    signedArea *= 0.5;
    centroid.setX((double)this->centroid.getX() / (6.0*signedArea));
    centroid.setY((double)this->centroid.getY()/ (6.0*signedArea));
*/
}

Point2D Polygon2D::getCentroid(){return this->centroid;}
Point2D Polygon2D::getVertex(int i){return this->mainPoints2D[i];}
int Polygon2D::getSides(){return this->sides;}

void Polygon2D::printMainPoints()
{
	int i;
	for(i = 0; i < this->sides; i++)
        printf("[%f, %f]\n ",mainPoints2D[i].getValue(0), mainPoints2D[i].getValue(1));
		/*printf("x[%f] y[%f] z[%f]\n", this->getVertex(i).getValue(X),
		this->getVertex(i).getValue(Y),this->getVertex(i).getValue(Z) );*/
}

void Polygon2D::generateLines2D()
{
	this->awns = new Line[sides];

	int i;
	for(i = 0; i < sides-1; i++)
	{
		awns[i].setOrigin(mainPoints2D[i]);
		awns[i].setEnd(mainPoints2D[i+1]);
	}

	awns[sides-1].setOrigin(mainPoints2D[sides-1]);
	awns[sides-1].setEnd(mainPoints2D[0]);

/*
	glColor3f(0.5, 0.5, 0.5);
	glClear(GL_COLOR_BUFFER_BIT);

	glEnableClientState(GL_VERTEX_ARRAY);
		glVertexPointer(3, GL_DOUBLE, 0, mainPoints3D);
	   glDrawArrays(GL_LINE_LOOP, 0, this->sides);
	glDisableClientState(GL_VERTEX_ARRAY);
	*/
}

//Line* getLines(){return this->awns;}
void Polygon2D::drawPolygon2D()
{
/*
	glColor3f(1.0, 0.0, 1.0);

	glEnableClientState(GL_VERTEX_ARRAY);
		glVertexPointer(3, GL_INT, 0, mainPoints3D);
	   glDrawArrays(GL_LINE_LOOP, 0, 3);
	glDisableClientState(GL_VERTEX_ARRAY);
	*/
	int i;
	for( i = 0; i < this->sides; i++)
		awns[i].drawLine();
		glFlush();
		glutSwapBuffers();
}

Polygon2D::~Polygon2D()
{
	delete[] mainPoints2D;
	delete[] awns;
}
