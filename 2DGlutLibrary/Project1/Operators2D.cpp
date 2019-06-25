#ifndef OPERATORS2D_H
  #define OPERATORS2D_H
  #include "Operators2D.h"
#endif

Operators2D::Operators2D(){}

Operators2D::~Operators2D(){}

void Operators2D::translation2D(Polygon2D &poli, Point2D pT)
{
    Point2D aux;
   Matrix matrixT, matrixP, matrixC;

   matrixT.loadTranslation2D(pT);

   for(int i = 0; i < poli.getSides(); i++)
   {
     matrixP.loadPoint2D(poli.getVertex(i));
     matrixC.zeroVector2D();
     matrixT.multiplyVector(matrixP,matrixC);
     aux.setPoint2D(matrixC.getPosition(0,0,1), matrixC.getPosition(1,0,1));
     poli.setVertex(i,aux);
   }

   poli.generateLines2D();
}

void Operators2D::scale2D(Polygon2D &poli, Point2D scalar)
{
    Point2D aux;
   Matrix matrixO, matrixI, matrixE,matrixM, matrixR,matrixP, matrixC;

   matrixE.loadScale2D(scalar);
   matrixE.printMatrix();
   for(int i = 0; i < poli.getSides(); i++)
   {
       matrixO.loadOrigin2D(poli.getVertex(i));
       //printf("Origen %d\n",i );
       //matrixO.printMatrix();

       matrixI.loadVertex(poli.getVertex(i));
       //printf("Original %d\n",i );
       //matrixI.printMatrix();

       matrixR.zeroMatrix2D();
       matrixO.multiply(matrixE, matrixR);
       //printf("Origen x Escalar %d\n",i );
       //matrixR.printMatrix();

       matrixM.zeroMatrix2D();
       matrixR.multiply(matrixI, matrixM);
       //printf("Resultado x original %d\n",i );
       //matrixM.printMatrix();

       matrixP.loadPoint2D(poli.getVertex(i));
       //printf("Vertice %d\n",i );
       //matrixP.printVector();

       matrixC.zeroVector2D();
       matrixM.multiplyVector(matrixP, matrixC);
       //printf("Escalado %d\n",i );
      // matrixC.printVector();
       aux.setPoint2D(matrixC.getPosition(0,0,1), matrixC.getPosition(1,0,1));
       poli.setVertex(i,aux);

   }
   poli.generateLines2D();
}

void Operators2D::rotation2D(Polygon2D &poli, GLdouble angle)
{
    Point2D aux;
   Matrix matrixO, matrixI, matrixRotation, matrixM, matrixR, matrixP, matrixC;

   matrixRotation.loadRotation2D(angle);

   for(int i = 0; i < poli.getSides(); i++)
   {
     matrixO.loadOrigin2D(poli.getVertex(i));
     matrixI.loadVertex( poli.getVertex(i));

     matrixR.zeroMatrix2D();
     matrixRotation.multiply(matrixO, matrixR);

     matrixM.zeroMatrix2D();
     matrixR.multiply(matrixI, matrixM);

     matrixP.loadPoint2D(poli.getVertex(i));
     matrixC.zeroVector2D();
     matrixM.multiplyVector(matrixP, matrixC);

     aux.setPoint2D(matrixC.getPosition(0,0,1), matrixC.getPosition(1,0,1));
     poli.setVertex(i,aux);
   }
   poli.generateLines2D();
}

void Operators2D::reflexX2D(Polygon2D &poli)
{
    Point2D aux;

   for(int i = 0; i < poli.getSides(); i++)
   {
     aux.setPoint2D(poli.getVertex(i).getValue(0), -1*poli.getVertex(i).getValue(1));
     poli.setVertex(i,aux);
   }
   poli.generateLines2D();
}

void Operators2D::reflexY2D(Polygon2D &poli)
{
  Point2D aux;

 for(int i = 0; i < poli.getSides(); i++)
 {
   aux.setPoint2D(-1*poli.getVertex(i).getValue(0), poli.getVertex(i).getValue(1));
   poli.setVertex(i,aux);
 }
 poli.generateLines2D();
}

void Operators2D::reflexXY2D(Polygon2D &poli)
{
  Point2D aux;

 for(int i = 0; i < poli.getSides(); i++)
 {
   aux.setPoint2D(-1*poli.getVertex(i).getValue(0), -1*poli.getVertex(i).getValue(1));
   poli.setVertex(i,aux);
 }
 poli.generateLines2D();
}
