#if defined (__APPLE__)
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

// set the pre-defined colors
enum ColorName {
    WHITE, 
    GREY, 
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

void clearWindow();
void setColor(ColorName name);
void graphicsSetup(int argc, char *argv[], void (*display)());

// graphic object primatives
void drawTriangle(int x1, int y1,int x2,int y2,int x3,int y3);
void drawLine(int x1, int y1, int x2, int y2);
void drawBox(int x1, int y1, int x2, int y2); // x-y coords of upper-right and lower-left corners
void drawCircle(int x, int y, int radius);

// filled graphics primatives
void drawFilledTriangle(int x1, int y1,int x2,int y2,int x3,int y3);
void drawFilledBox(int x1, int y1, int x2, int y2);
void drawFilledCircle(int x, int y, int radius);
