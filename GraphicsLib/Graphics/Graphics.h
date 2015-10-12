#ifndef GRAPHICS_H
#define GRAPHICS_h

#include <GL/glut.h>

class Graphics {
    public:
        void init(int argc, char *argv[]);
        void setSize(int width, int height);
        void setPosition(int x, int y);
        void clear(void);
};

#endif

