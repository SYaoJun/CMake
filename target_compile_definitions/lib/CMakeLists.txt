
add_library(mylib SHARED mylib.cpp)

target_compile_definitions(mylib PRIVATE USE_A)
# make sure that the header file can be found by the other targets
target_include_directories(mylib INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
