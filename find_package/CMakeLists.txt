cmake_minimum_required(VERSION 3.5)
project(gtest_test)

enable_testing() 

if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
  message(STATUS "enter this")
  add_compile_options(-fsanitize=address -fno-omit-frame-pointer -g)
  add_link_options(-fsanitize=address)

    add_compile_options(--coverage)
    add_link_options(--coverage)
endif()

find_package(GTest REQUIRED)
if(GTest_FOUND)
  add_executable(main1 main.cpp)
  add_executable(main2 main2.cpp)
  add_executable(main3 main3.cpp)
  target_link_libraries(main1 GTest::gtest GTest::gtest_main)
  target_link_libraries(main2 GTest::gtest GTest::gtest_main)

  gtest_discover_tests(main1)
  gtest_discover_tests(main2)
else(GTest_FOUND)
  message(FATAL_ERROR "gtest library not found")
endif(GTest_FOUND)

add_custom_target(coverage
    COMMAND ${CMAKE_COMMAND} -E echo "Running tests and generating coverage report..."
    COMMAND ${CMAKE_CTEST_COMMAND} --output-on-failure
    COMMAND  mkdir coverage
    COMMAND gcovr --root ${CMAKE_SOURCE_DIR} --html --html-details -o ./coverage/coverage.html --exclude-directories '(/usr/.*|.*CMakeFiles.*)' --exclude-unreachable-branches --exclude-throw-branches
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMENT "Generating HTML coverage report with gcovr"
)


add_dependencies(coverage main1)
add_dependencies(coverage main2)