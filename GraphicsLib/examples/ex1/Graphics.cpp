#include "Graphics.h"


void keyboard(unsigned char key, int x, int y) {
    switch (key ) {
        case '\x1B':
            exit(EXIT_SUCCESS);
            break;
    }
}

void animate(void) {
    glutPostRedisplay();
}

void setColor(ColorName name) {
    switch ( name ) {
        case RED: glColor3d(1.0, 0.0, 0.0);
    }
}

void graphicsSetup(int argc, char **argv, void (*display)(void)) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(WINDOW_X, WINDOW_Y);
    glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    glutCreateWindow("COSC1337 Graphics Lab");
    glClearColor(1.0,1.0,1.0,0.0);
    glutKeyboardFunc(&keyboard);
    glutDisplayFunc(display);
    glutIdleFunc(animate);
    glutMainLoop();
}


void drawFilledBox(int x1, int y1, int x2, int y2) {
    glBegin(GL_POLYGON);
    glVertex2i(x1, y1);
    glVertex2i(x2, y1);
    glVertex2i(x2, y2);
    glVertex2i(x1, y2);
    glVertex2i(x1, y1);
    glEnd();
}


