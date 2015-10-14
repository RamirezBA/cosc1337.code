#include <iostream>
using namespace std;

#include "Graphics.h"
#include <cmath>
const double PI = acos(-1.0);
const double ANGLE_STEP      = PI/180.0;
void keyboard(unsigned char key, int x, int y)
{
	if (key == 27)
		exit(1);
}

void clearWindow() {
    glClear( GL_COLOR_BUFFER_BIT );
}

void setColor(ColorName name) {
    switch(name) {
        case WHITE: glColor3d(1.0, 1.0, 1.0); break;
        case GREY: glColor3d(0.4, 0.4, 0.4); break;
        case BLACK: glColor3d(0.0, 0.0, 0.0); break;
        case RED: glColor3d(1.0, 0.0, 0.0); break;
        case ORANGE: glColor3d(1.0, 0.5, 0.0); break;
        case YELLOW: glColor3d(1.0, 1.0, 0.0); break;
        case GREEN: glColor3d(0.0, 1.0, 0.0); break;
        case FOREST_GREEN: glColor3d(0.0, 0.25, 0.0); break;
        case BLUE: glColor3d(0.0, 0.0, 1.0); break;
        case CYAN: glColor3d(0.0, 1.0, 1.0); break;
        case MIDNIGHT_BLUE: glColor3d(0.0, 0.0, 0.25); break;
        case PURPLE: glColor3d(0.5, 0.25, 0.0); break;
        case MAGENTA: glColor3d(1.0, 0.0, 1.0); break;
        case BROWN: glColor3d(0.36, 0.16, 0.1); break;
        default: cerr << "Trying to set invalid color. Color unchanged" << endl;
    }
}
void graphicsSetup(int argc, char *argv[], void (*display)()) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGB);
  if (! glutGet(GLUT_DISPLAY_MODE_POSSIBLE))
     glutInitDisplayMode(GLUT_INDEX);
  glutInitWindowPosition(50,50);
  glutInitWindowSize(640, 480);
  glutCreateWindow("single triangle");
  glClearColor(1.0,1.0,1.0,0.0);
  glutDisplayFunc(display);

  // set "esc" key to end program
  glutKeyboardFunc(keyboard);

  // set coordinates to "normal"
  glLoadIdentity();
  glOrtho(0,640,0,480, 1, -1);
}

void drawTriangle(int x1, int y1, int x2, int y2, int x3, int y3) {
     glBegin(GL_LINE_STRIP);
     glVertex2i(x1,y1);
     glVertex2i(x2,y2);
     glVertex2i(x3,y3);
     glVertex2i(x1,y1);
     glEnd();
}

void drawFilledTriangle(int x1, int y1, int x2, int y2, int x3, int y3) {
     glBegin(GL_POLYGON);
     glVertex2i(x1,y1);
     glVertex2i(x2,y2);
     glVertex2i(x3,y3);
     glVertex2i(x1,y1);
     glEnd();
}

void drawLine(int x1, int y1, int x2, int y2) {
     glBegin(GL_LINE_STRIP);
     glVertex2i(x1,y1);
     glVertex2i(x2,y2);
     glEnd();
}

void drawBox(int x1, int y1, int x2, int y2) {
     glBegin(GL_LINE_STRIP);
     glVertex2i(x1,y1);
     glVertex2i(x2,y1);
     glVertex2i(x2,y2);
     glVertex2i(x1,y2);
     glVertex2i(x1,y1);
     glEnd();
}

void drawFilledBox(int x1, int y1, int x2, int y2) {
     glBegin(GL_POLYGON);
     glVertex2i(x1,y1);
     glVertex2i(x2,y1);
     glVertex2i(x2,y2);
     glVertex2i(x1,y2);
     glVertex2i(x1,y1);
     glEnd();
}

void drawCircle(int x, int y, int radius) {
     double angle;
     int X, Y;
     glBegin(GL_LINE_STRIP);
     for (angle=0;angle< 2.0*PI + ANGLE_STEP; angle += ANGLE_STEP) {
         X = x + int(double(radius) * cos(angle));
         Y = y + int(double(radius) * sin(angle));
         glVertex2i(X,Y);
     }
     glEnd();
}         

void drawFilledCircle(int x, int y, int radius) {
     double angle;
     int X0, Y0, X1, Y1;
     glBegin(GL_TRIANGLES);
     X1 = x + radius;
     Y1 = y;
     for (angle=0;angle< 2.0*PI + ANGLE_STEP; angle += ANGLE_STEP) {
         X0 = X1;
         Y0 = Y1;
         X1 = x + int(double(radius) * cos(angle));
         Y1 = y + int(double(radius) * sin(angle));
         glVertex2i(x,y);
         glVertex2i(X0,Y0);
         glVertex2i(X1,Y1);
     }
     glEnd();
}         
