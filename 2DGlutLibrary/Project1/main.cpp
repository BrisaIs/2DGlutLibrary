#ifndef UTILITIES_H
  #define UTILITIES_H
  #include "Utilities.h"
#endif

#ifndef POINT2D_H
  #define POINT2D_H
  #include "Point2D.h"
#endif

#ifndef POLYGON2D_H
	#define POLYGON2D_H
	#include "Polygon2D.h"
#endif

#ifndef GLUT
 #define GLUT
 #include <GL/glut.h>
#endif

#ifndef OPERATORS2D_H
  #define OPERATORS2D_H
  #include "Operators2D.h"
#endif

#include <unistd.h>

int width = 500;
int heigth = 500;

 void init();
 void drawAxis();
 void draw();

int main(int argc, char** argv)
{

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);

    glutInitWindowPosition(100, 100);
    glutInitWindowSize(400, 400);
    glutCreateWindow("Proyecto 1");

    init();
    glutDisplayFunc(draw);
    glutMainLoop();

    return 0;
}

void init()
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-450, 450, -450, 450);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void drawAxis()
{
  glLineWidth(2);
  glColor3f(0.0, 0.5, 1.0);
  glBegin(GL_LINES);
    glVertex2d(-1000.0, 0.0);
    glVertex2d(1000.0, 0.0);
  glEnd();

  glColor3f(1.0, 0.0, 1.0);
  glBegin(GL_LINES);
    glVertex2d(0.0,-1000.0);
    glVertex2d(0.0, 1000.0);
  glEnd();

}

void draw()
{
  Point2D mainPoints2D[3], pT,pS;
  Operators2D op;
  mainPoints2D[0].setPoint2D((GLdouble) 0, (GLdouble) 10);
  mainPoints2D[1].setPoint2D((GLdouble) 50, (GLdouble) 10);
  mainPoints2D[2].setPoint2D((GLdouble) 25, (GLdouble) 50);

  Polygon2D p1(3, mainPoints2D);
  pT.setPoint2D(-10.0,-10.0);
  pS.setPoint2D(2.0,2.0);

  drawAxis();

  p1.drawPolygon2D();

  /*Sleep(300);
  glutPostRedisplay();
  glClearColor(0.0, 0.0, 0.0, 0.0);
  glClear(GL_COLOR_BUFFER_BIT);
  drawAxis();
*/

    //op.translation2D(p1,pT);
    //op.scale2D(p1,pS);
    //op.rotation2D(p1,90.0);
    //op.reflexX2D(p1);
    //op.reflexY2D(p1);
    op.reflexXY2D(p1);        
    p1.drawPolygon2D();
//  p1.printMainPoints();

  //printf("Translate OK C: !\n");
}
