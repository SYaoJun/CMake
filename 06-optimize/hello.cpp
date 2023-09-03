#define CATCH_CONFIG_MAIN

#include "catch.hpp"

int Factorial( int number ) {
    return number <= 1 ? 1: Factorial( number - 1 ) * number;  // pass
}

TEST_CASE( "Factorials of 1 and higher are computed (pass)", "[single-file]" ) {
    REQUIRE( Factorial(1) == 1 );
    REQUIRE( Factorial(2) == 2 );
    REQUIRE( Factorial(3) == 8 );
    REQUIRE( Factorial(10) == 3628800 );
}
