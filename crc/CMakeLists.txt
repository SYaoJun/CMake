cmake_minimum_required(VERSION 3.16)
project(crc_test)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BUILD_TYPE RELESE)
find_package(CRC REQUIRED)

add_executable(crc_test crc_test.cpp)

if(CRC_FOUND)
    message(STATUS "found")
    target_link_libraries(crc_test ${CRC_LIBRARY})
elseif(CRC_FOUND)
    message(STATUS "not found")
endif(CRC_FOUND)

