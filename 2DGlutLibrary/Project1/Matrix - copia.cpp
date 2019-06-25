#ifndef MATRIX
  #include "Matrix.h"
  #define MATRIX
#endif

Matrix::Matrix()
{
  this->rows = 4;
  this->columns = 4;
  createMemory();
}

Matrix::Matrix(int rows, int columns)
{
  this->rows = rows;
  this->columns = columns;
  createMemory();
}

Matrix::Matrix(double x, double y, double z)
{
  this->rows = rows;
  this->columns = columns;
  createMemory();

  matrix[0][0] = x;
  matrix[1][0] = y;
  matrix[2][0] = z;
}

void Matrix::createMemory()
{
	int i,j;

  this->matrix = new double*[this->rows];

  for( i = 0; i < rows; i++)
  {
    this->matrix[i] = new double[this->columns];

    if(this->columns > 1)
      for( j = 0; j < this->columns; j++)
      {
        if( j == i )
          this->matrix[i][j] = 1.0;
        else
          this->matrix[i][j] = 0.0;
      }
    else
        this->matrix[i][0] = 1.0;
  }
}

void Matrix::setPositionValue(int r,int c, double value){this->matrix[r][c] = value;}

int Matrix::getRows(){return this->rows;}
int Matrix::getColumns(){return this->columns;}
double Matrix::getPositionValue(int r,int c){return this->matrix[r][c];}

Matrix Matrix::multiply(Matrix factor)
{
 	int i,j,k;
	Matrix aux = Matrix(this->rows,this->columns);
	aux.fullOfCeros();

	for(i = 0; i < this->rows; i++)
		for(j = 0; j < this->rows; j++)
			for(k = 0; k < this->rows; k++)
				aux.setPositionValue( i,j,aux.getPositionValue(i,j) + this->matrix[i][k] * factor.getPositionValue(k,j) );
  return aux;
}

Matrix Matrix::multiplyVector(Matrix factor)
{
	//NotSure
	int i,j;
	 Matrix aux = Matrix(this->rows,1);
	 aux.fullOfCeros();

	for(i = 0; i < 3; i++)
     for(j = 0; j < 3; j++)
			result.setPositionValue(j,0, result.getPositionValue(j,0 )+ this->matrix[i][j] * factor.getPositionValue(j, 0));
}

void Matrix::fullOfCeros()
{
	int i,j;
	for(i = 0; i < this->rows; i++)
		for(j = 0; j < this->columns; j++)
			this->matrix[i][j] = 0.0;
}

void Matrix::toIdentity()
{
	for(int i = 0; i < rows; i++)
   {
     if(this->columns > 1)
       for(int j = 0; j < this->columns; j++)
       {
         if( j == i )
           this->matrix[i][j] = 1.0;
         else
           this->matrix[i][j] = 0.0;
       }
     else
         this->matrix[i][0] = 1.0;
   }
}

void Matrix::chargeTranslation(double x, double y, double z)
{
  matrix[0][3] = x;
  matrix[1][3] = y;
  matrix[2][3] = z;
}

void Matrix::chargeRotation(int flag, double delta, double x, double y,double z)
{
	switch (axis)
	{
		case X:
			//x
			matrix[1][1] = cos((delta*PI)/180);
			matrix[1][2] = -1*sin((delta*PI)/180);

			//y
			matrix[2][1] = sin((delta*PI)/180);
			matrix[2][2] = cos((delta*PI)/180);
		break;

		case Y:
			//x
			matrix[0][0] = cos((delta*PI)/180);
			matrix[0][2] = -1*sin((delta*PI)/180);

			//y
			matrix[2][0] = sin((delta*PI)/180);
			matrix[2][2] = cos((delta*PI)/180);
		break;

		case Z:
			//x
			matrix[0][0] = cos((delta*PI)/180);
			matrix[0][1] = -1*sin((delta*PI)/180);

			//y
			matrix[1][0] = sin((delta*PI)/180);
			matrix[1][1] = cos((delta*PI)/180);
		break;

		case OX:
			//x
			matrix[1][1] = z
			matrix[1][2] = -1*y;

			//y
			matrix[2][1] = y;
			matrix[2][2] = z;
		break;

		case OY:
			//x
			matrix[0][0] = y;
			matrix[0][2] = -1*x;

			//y
			matrix[2][0] = x;
			matrix[2][2] = y;
		break;
	}
}

void Matrix::chargeScaling(double x, double y, double z)
{
  matrix[0][0] = x;
  matrix[1][1] = y;
  matrix[2][2] = z;
}

void Matrix::chargeReflection(int axis)
{
	switch (axis)
	{
		case XY:
			matrix[2][2] = -1;
		break;

		case ZX:
			matrix[1][1] = -1;
		break;

		case YZ:
			matrix[0][0] = -1;
		break;

	}
}


Matrix::~Matrix()
{
  for(int i = 0; i < rows; i++)
    delete[] matrix[i];
  delete[] matrix;
}
