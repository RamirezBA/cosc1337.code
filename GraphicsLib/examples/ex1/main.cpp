#include "Graphics.h"

void drawScene(void) {
    clearWindow();          // clear the last scene
    setColor(RED);
    drawFilledCircle(100, 100, 50);
    glutSwapBuffers();      // double buffering control
}

void animate() {
    // move your objects here
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

