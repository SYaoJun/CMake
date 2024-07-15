#include <iostream>
#include <zlib.h>
#include <fmt/core.h>

int main() {
    std::cout << "ZLIB version: " << zlibVersion() << std::endl;
    fmt::print("Hello, {}!\n", "world");
    return 0;
}
