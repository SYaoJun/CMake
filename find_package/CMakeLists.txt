cmake_minimum_required(VERSION 3.0)
project(gtest_test)
enable_testing()
find_package(GTest REQUIRED)
if(GTest_FOUND)
  add_executable(gtest_test main.cpp)
  # GTest::gtest The Google Test gtest library, if found; adds Thread::Thread
  # automatically
  target_link_libraries(gtest_test GTest::gtest GTest::gtest_main)
  add_test(AllTestsInFoo gtest_test)
else(GTest_FOUND)
  message(FATAL_ERROR "gtest library not found")
endif(GTest_FOUND)