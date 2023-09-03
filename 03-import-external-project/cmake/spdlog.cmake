include(ExternalProject)
set(SPDLOG_ROOT ${CMAKE_BINARY_DIR}/third_party/extern_spdlog)
ExternalProject_Add(
  extern_spdlog
  PREFIX ${CMAKE_BINARY_DIR}/third_party/extern_spdlog
  GIT_REPOSITORY https://gitee.com/roberchen/spdlog.git
  GIT_TAG v1.6.0
  CONFIGURE_COMMAND cd ${SPDLOG_ROOT}/src/extern_spdlog && cmake -B build
                    -DCMAKE_INSTALL_PREFIX=${SPDLOG_ROOT}
  BUILD_COMMAND cd ${SPDLOG_ROOT}/src/extern_spdlog && cmake --build build -j 8
  INSTALL_COMMAND cd ${SPDLOG_ROOT}/src/extern_spdlog && cmake --install build
  BUILD_BYPRODUCTS ${SPDLOG_ROOT}/lib/libspdlog.a
  )
# 指定编译好的静态库文件的路径 find_library(SPDLOG_LIBRARIES spdlog ${SPDLOG_ROOT}/lib/) #
# 指定头文件所在的目录
set(SPDLOG_INCLUDE_DIR ${SPDLOG_ROOT}/include)
set(SPDLOG_LIBRARIES ${SPDLOG_ROOT}/lib/libspdlog.a)
add_library(spdlog STATIC IMPORTED GLOBAL)
add_dependencies(spdlog extern_spdlog)
set_target_properties(
  spdlog PROPERTIES IMPORTED_LOCATION ${SPDLOG_LIBRARIES}
                    INTERFACE_INCLUDE_DIRECTORIES ${SPDLOG_INCLUDE_DIR})
