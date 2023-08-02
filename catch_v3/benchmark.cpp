#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/catch_test_macros.hpp>
#include <catch2/generators/catch_generators.hpp>
std::uint64_t Fibonacci_(std::uint64_t number) {
    return number < 2 ? 1 : Fibonacci_(number - 1) + Fibonacci_(number - 2);
}
TEST_CASE("Fibonacci") {
    CHECK(Fibonacci_(0) == 1);
    // some more asserts..
    CHECK(Fibonacci_(5) == 8);
    // some more asserts..

    // now let's benchmark:
    BENCHMARK("Fibonacci 20") {
        return Fibonacci_(20);
    };

    BENCHMARK("Fibonacci 25") {
        return Fibonacci_(25);
    };
}