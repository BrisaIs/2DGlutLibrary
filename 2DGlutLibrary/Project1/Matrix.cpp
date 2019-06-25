#ifndef MATRIX_H
    #define MATRIX_H
    #include "Matrix.h"
#endif // MATRIX_H
#ifndef MATH_H
 #define MATH_H
 #include <math.h>
#endif

Matrix::Matrix()
{
    zeroVector2D();
    zeroMatrix2D();
}
Matrix::~Matrix(){}

void Matrix::setPosition(int i, int j,int f, GLdouble value)
{
  if(f == 0)//matriz
    this->matrix[i][j] = value;
  else
    this->vector[i] = value;
}
GLdouble Matrix::getPosition(int i,int j,int f)
{
  GLdouble aux;
  if(f == 0)
    aux = this->matrix[i][j];
  else
    aux = this->vector[i];

  return aux;
}

void Matrix::sumPosition(int i, int j,int f, GLdouble value)
{
  if(f == 0)
    this->matrix[i][j] += value;
  else
    this->vector[i] += value;
}

void Matrix::zeroVector2D()
{
	for(int i=0; i<3; i++)
		this->vector[i] = 0;
}

void Matrix::zeroMatrix2D()
{
	for(int i=0; i<3; i++)
	{
		for(int j=0; j<3; j++)
			this->matrix[i][j] = 0;
	}
}

void Matrix::loadVertex(Point2D vertex)
{
  this->matrix[0][0] = 1;
  this->matrix[0][1] = 0;
  this->matrix[0][2] = vertex.getValue(XPOS);

  this->matrix[1][0] = 0;
  this->matrix[1][1] = 1;
  this->matrix[1][2] = vertex.getValue(YPOS);

  this->matrix[2][0] = 0;
  this->matrix[2][1] = 0;
  this->matrix[2][2] = 1;
}
void Matrix::loadOrigin2D(Point2D tras)
{
    this->matrix[0][0] = 1;
    this->matrix[0][1] = 0;
    this->matrix[0][2] = -1*tras.getValue(XPOS);

    this->matrix[1][0] = 0;
    this->matrix[1][1] = 1;
    this->matrix[1][2] = -1*tras.getValue(YPOS);

    this->matrix[2][0] = 0;
    this->matrix[2][1] = 0;
    this->matrix[2][2] = 1;
}

void Matrix::loadIdentity2D()
{
  for(int i=0; i<3; i ++)
  {
      for(int j=0; j<3; j++)
      {
          if(i == j)
              this->matrix[i][j] = 1;
          else
              this->matrix[i][j] = 0;
      }
  }
}

void Matrix::loadPoint2D(Point2D origin)
{
    this->vector[0] = origin.getValue(XPOS);
    this->vector[1] = origin.getValue(YPOS);
    this->vector[2] = 1;//BIEN
}

void Matrix::loadTranslation2D( Point2D destiny)
{
    loadIdentity2D();
    matrix[0][2] = destiny.getValue(XPOS);
    matrix[1][2] = destiny.getValue(YPOS);
}

void Matrix::loadScale2D(Point2D scalar)
{
  loadIdentity2D();
    this->matrix[0][0] = scalar.getValue(XPOS);
    //this->matrix[0][1] = 0;
    //this->matrix[0][2] = 0;

    //this->matrix[1][0] = 0;
    this->matrix[1][1] = scalar.getValue(YPOS);
    //this->matrix[1][2] = 0;

    //this->matrix[2][0] = 0;
    //this->matrix[2][1] = 0;
    //this->matrix[2][2] = 1;
}

void Matrix::loadRotation2D(GLdouble angle)
{
  loadIdentity2D();
	this->matrix[0][0] = cos((angle * 3.1416)/180);
	this->matrix[0][1] = -sin((angle * 3.1416)/180);

	this->matrix[1][0] = sin((angle * 3.1416)/180);
	this->matrix[1][1] = cos((angle * 3.1416)/180);

}

void Matrix::loadReflexX2D()
{
  loadIdentity2D();
	this->matrix[1][1] = -1;
}

void Matrix::loadReflexY2D()
{
  loadIdentity2D();
	this->matrix[0][0] = -1;
}

void Matrix::loadReflexXY2D()
{
	this->matrix[0][0] = -1;
	this->matrix[0][0] = 0;
	this->matrix[0][0] = 0;

	this->matrix[0][0] = 0;
	this->matrix[0][0] = -1;
	this->matrix[0][0] = 0;

	this->matrix[0][0] = 0;
	this->matrix[0][0] = 0;
	this->matrix[0][0] = 1;
}

void Matrix::multiplyVector( Matrix matrixP, Matrix &matrixC)
{//matrixP[3][1], double matrixC[3][1]
    for(int i = 0; i < 3; i++)
		{
    	for(int j = 0; j < 3; j++)
      		matrixC.sumPosition(i,0,1, this->matrix[i][j] * matrixP.getPosition(j,0,1));
    }
}

void Matrix::multiply(Matrix matrixI, Matrix &matrizM)
{
	for(int i=0; i<3; i++)
	{
    	for(int j=0; j<3; j++)
			{
      		for(int k=0; k<3; k++)
       			matrizM.sumPosition(i,j,0,this->matrix[i][k] * matrixI.getPosition(k,j,0));
    	}
  	}
}

void Matrix::printVector()
{
  for(int i = 0; i < 3; i++)
  printf("[%i] = %f\n", i,vector[i]);
//printf("\n");
}
void Matrix::printMatrix()
{
  for(int i = 0; i < 3; i++)
  {
    for(int j= 0; j <3; j++)
      { printf("[%d][%d] = %f\t", i,j,matrix[i][j]);}
    printf("\n");
  }
}
