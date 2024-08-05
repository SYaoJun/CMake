cmake_minimum_required(VERSION 3.5)
project(gtest_test)

enable_testing() 
find_package(GTest REQUIRED)
if(GTest_FOUND)
  add_executable(main1 main.cpp)
  add_executable(main2 main2.cpp)

  target_link_libraries(main1 GTest::gtest GTest::gtest_main)
  target_link_libraries(main2 GTest::gtest GTest::gtest_main)

  gtest_discover_tests(main1)
  gtest_discover_tests(main2)
else(GTest_FOUND)
  message(FATAL_ERROR "gtest library not found")
endif(GTest_FOUND)