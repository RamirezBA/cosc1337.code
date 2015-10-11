#include "Graphics.h"

// set up global variables for animation
int xPos = 100;
int yPos = 100;
int radius = 50;

void drawScene(void) {
    clearWindow();          // clear the last scene
    setColor(RED);
    drawFilledCircle(xPos, yPos, radius);
    glutSwapBuffers();      // double buffering control
}

void animate() {
    // move your objects here
    xPos += 2;              // slide to the left 2 pixels per loop
    yPos += 2;              // slide upward 2 pixels per loop
    glutPostRedisplay();
}

// keyboard handler to terminate the program when "q" key is pressed
void handleKey(unsigned char key, int x, int y) {
    switch(key) {
        case 'q':
            exit(0);
            break;
    }
}


int main(int argc, char **argv) {
    graphicsSetup(argc, argv);      // initialize the graphics system
    glutDisplayFunc(drawScene);     // tell GLUT what function draws the scene
    glutIdleFunc(animate);          // Move objects when animating
    glutKeyboardFunc(handleKey);    // set up the "q" key to quit
    glutMainLoop();                 // GLUT will control the action
}

