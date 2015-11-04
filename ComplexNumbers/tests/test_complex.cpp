#include "catch.hpp"
#include "Complex.h"

TEST_CASE( "Complext numbers are created" ) {
    REQUIRE( Complex( ).toString()  == "0+0i" );
    REQUIRE( Complex( 5 ).toString()  == "5+0i" );
    REQUIRE( Complex( 3,5.5 ).toString()  == "3+5.5i" );
}

TEST_CASE( "complex addition tests" ) {
    Complex a(3,5);
    Complex b(2,4);
    REQUIRE( (a + b).toString() == "5+9i" );
}

