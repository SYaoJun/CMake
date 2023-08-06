#include "crc32c/crc32c.h"
#include <iostream>

int main() {
  const std::uint8_t buffer[] = {0, 0, 0, 0};
  std::uint32_t result;

  // Process a raw buffer.
  result = crc32c::Crc32c(buffer, 4);

  // Process a std::string.
  std::string string;
  string.resize(4);
  result = crc32c::Crc32c(string);

  // If you have C++17 support, process a std::string_view.
  std::string_view string_view(string);
  result = crc32c::Crc32c(string_view);

  std::cout<<result<<std::endl;
  return 0;
}