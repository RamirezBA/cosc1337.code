#include<stdlib.h>
#include "Graphics.h"


void display(void)
{
  glClear(GL_COLOR_BUFFER_BIT);

  setColor(RED);
  drawFilledBox(100,100, 300, 300);

  glFlush();
}

int main(int argc, char** argv) {
  graphicsSetup(argc, argv, display);
  return EXIT_SUCCESS;
}
