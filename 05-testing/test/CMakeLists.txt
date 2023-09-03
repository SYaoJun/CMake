 # google test
 include(FetchContent)
 FetchContent_Declare(
         googletest
         GIT_REPOSITORY https://github.com/google/googletest.git
         GIT_TAG v1.14.0
 )
 FetchContent_MakeAvailable(googletest)

macro(my_add_test TEST_NAME)
    add_executable(${TEST_NAME} ${ARGN}) 
    add_test(NAME cs.${TEST_NAME} COMMAND ${TEST_NAME})
    target_link_libraries(${TEST_NAME} PRIVATE gtest gtest_main)
endmacro()

my_add_test(test01 gtest_test.cpp)
add_executable(test02 gtest_test2.cpp)
target_link_libraries(test02 PRIVATE gtest gtest_main)
add_test(NAME ee.test02 COMMAND test02)