 cmake_minimum_required(VERSION 3.16)
 project( protobuf_test)
 set(CMAKE_CXX_STANDARD 17)
 set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -O2")
 set(CMAKE_BUILD_TYPE "Release")
 find_package(Protobuf REQUIRED)
 add_executable(protobuf_test yaojun_person.cpp person.pb.cc person.pb.h)
 target_link_libraries(protobuf_test ${PROTOBUF_LIBRARIES})

 

