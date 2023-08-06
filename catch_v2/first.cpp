#define CATCH_CONFIG_MAIN
#include "catch.hpp"
int add_(int a, int b) {
    return a+b;
}
TEST_CASE("add 3 and 4 is 7(success)", "anything"){
    REQUIRE(add_(3, 4)==7);
}