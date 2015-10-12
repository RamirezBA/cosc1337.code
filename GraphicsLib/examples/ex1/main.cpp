#include "Graphics.h"

void drawScene(void) {
    clearWindow();          // clear the last scene
    setColor(RED);
    drawFilledCircle(100, 100, 50);
    //glutSwapBuffers();      // double buffering control
}

int main(int argc, char **argv) {
    graphicsSetup(argc, argv, display);      // initialize the graphics system

}

