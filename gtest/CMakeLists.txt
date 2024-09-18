cmake_minimum_required(VERSION 3.16)
project(gtest_test)
set(CMAKE_CXX_STANDARD 17)
add_subdirectory(googletest)
#add_executable(inner_test inner_test.cpp)
#target_link_libraries(inner_test GTest::gtest_main GTest::gtest GTest::gmock)

# add_executable(client_server_test cs/client_server_test.cpp)
# target_link_libraries(client_server_test GTest::gtest_main GTest::gtest GTest::gmock)

 add_executable(a_contain_b_test a_contain_b_test.cpp)
 target_link_libraries(a_contain_b_test GTest::gtest_main GTest::gtest GTest::gmock)