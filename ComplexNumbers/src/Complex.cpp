#include <iostream>
#include <sstream>
using namespace std;
#include "Complex.h"

// constructors -------------------------------------------
Complex::Complex() {
    r = 0;
    i = 0;
}

Complex::Complex( double r, double i ) {
    this->r = r;
    this->i = i;
}

Complex::Complex( double r ) {
    this->r = r;
    i = 0;
}

// accessors ----------------------------------------------

string Complex::toString( void ) {
    ostringstream  tmp;
    tmp << r <<  "+" << i << "i";
    return tmp.str();
}

// operators ----------------------------------------------
Complex Complex::operator + ( const Complex & rhs ) {
    Complex temp;
    temp.r = r + rhs.r;
    temp.i = i + rhs.i;
    return temp;
}

Complex Complex::operator - ( const Complex & rhs ) {
    Complex temp;
    return temp;
}

Complex Complex::operator * ( const Complex & rhs ) {
    Complex temp;
    return temp;
}

Complex Complex::operator / ( const Complex & rhs ) {
    Complex temp;
    return temp;
}

ostream & operator << ( ostream & lhs, const Complex & rhs ) {
    lhs << rhs.r << '+' << rhs.i << 'i';
    return lhs;
}

Complex operator + ( double lhs, const Complex & rhs ){
    return rhs;
}

Complex operator + ( Complex & lhs, const double rhs ) {
    Complex temp;
    return temp;
}

