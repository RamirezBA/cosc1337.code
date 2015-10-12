#include "Graphics.h"

void Graphics::init(int argc, char *argv[]) {
    glutInit(&argc, argv);
    glutCreateWindow("COSC1337 Graphics Lab");
    glutKeyboardFunc(&keyboard);
}

void Graphics::setSize(int width, int height){
}

void Graphics::setPosition(int x, int y) {
}

void Graphics::clear(void) {
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case '\x1B':
            exit(EXIT_SUCCESS);
            break;
    }
}


