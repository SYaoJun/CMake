#include "spdlog/spdlog.h"

// Use the default logger (stdout, multi-threaded, colored)
int main() {
    spdlog::info("Hello, {}!", "World");
}