#include <GL/glut.h>

#define WINDOW_HEIGHT   500
#define WINDOW_WIDTH    1000
#define WINDOW_X        100
#define WINDOW_Y        100

enum ColorName { 
    WHITE, 
    GRAY, 
    BLACK, 
    RED, 
    ORANGE, 
    YELLOW, 
    GREEN, 
    FOREST_GREEN, 
    BLUE, 
    MIDNIGHT_BLUE, 
    CYAN, 
    PURPLE, 
    MAGENTA, 
    BROWN, 
    NUM_COLORS
};

void keyboard(unsigned char key, int x, int y);
void graphicsSetup(int argc, char **argv, void (*display)(void));

void setColor(ColorName name);
void drawFilledBox(int x1, int y1, int x2, int y2);

