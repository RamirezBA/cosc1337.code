#include "Graphics.h"

int main( int argc, char *argv[] ) {
    Graphics win;
    win.init(argc, argv);
    win.setSize(640, 480);
    win.setPosition(50,50);
    win.clear();
}

