cmake_minimum_required(VERSION 3.16)
project(advanced)
set(CMAKE_CXX_STANDARD 14)

set(SRC_FILES 
    main.cpp
    hello.cpp
    )
# 去掉cpp后缀
string(REPLACE ".cpp" "" SRC_FILE_NAME "${SRC_FILES}" )

add_custom_target(submit
        zip my-submission.zip
        ${SRC_FILES}
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
        )

foreach(name ${SRC_FILE_NAME} )
    add_executable( ${name}
      ${name}.cpp )
endforeach()