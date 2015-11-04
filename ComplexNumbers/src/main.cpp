#include <iostream>
#include "Complex.h"
using namespace std;

int main( int argc, char * argv[] ) {
    Complex a;
    Complex b(2.0);
    Complex c(3,5);

    cout << a << ' ' << b << ' ' << b + c << ' ' << c << endl;
    cout << a + 1.5  << ' ' << 2.5 + b << ' ' << b - c << ' ' << c << endl;
}

