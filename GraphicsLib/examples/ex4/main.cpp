/* Copyright (c) Mark J. Kilgard, 1996. */

/* This program is freely distributable without licensing fees 
   and is provided without guarantee or warrantee expressed or 
   implied. This program is -not- in the public domain. */

#include "Graphics.h"



void display(void)
{
  glClear(GL_COLOR_BUFFER_BIT);
  setColor(RED);
  drawFilledTriangle(0,0,100,100,200,0);
  setColor(BLUE);
  drawFilledCircle(200,200,50);
  glFlush();  /* Single buffered, so needs a flush. */
}

int main(int argc, char **argv)
{
  graphicsSetup( argc, argv, &display);
  glutMainLoop();
  return 0;           
}
