cmake_minimum_required(VERSION 3.16)
project(folly_test)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BUILD_TYPE RELESE)

cmake_minimum_required(VERSION 3.10)
project(test)
# folly
include_directories(/opt/homebrew/Cellar/folly/2023.08.14.00/include)
find_library(FOLLY_LIBS folly /opt/homebrew/Cellar/folly/2023.08.14.00/lib)
# fmt
include_directories(/opt/homebrew/Cellar/fmt/10.1.0/include)
find_library(FMT_LIBS fmt /opt/homebrew/Cellar/fmt/10.1.0/lib)
# boost
include_directories(/opt/homebrew/Cellar/boost/1.82.0_1/include)
find_library(BOOST_LIBS boost_chrono /opt/homebrew/Cellar/boost/1.82.0_1/lib)

# glog
include_directories(/opt/homebrew/Cellar/glog/0.6.0/include)
find_library(GLOG_LIBS glog /opt/homebrew/Cellar/glog/0.6.0/lib)

# gflags
include_directories(/opt/homebrew/Cellar/gflags/2.2.2/include)
find_library(GFLAGS_LIBS gflags /opt/homebrew/Cellar/gflags/2.2.2/lib)
# double-conversion
include_directories(/opt/homebrew/Cellar/double-conversion/3.3.0/include)
find_library(DD_LIBS double-conversion /opt/homebrew/Cellar/double-conversion/3.3.0/lib)
#libevent
include_directories(/opt/homebrew/Cellar/libevent/2.1.12_1/include)
find_library(LB_LIBS event_core /opt/homebrew/Cellar/libevent/2.1.12_1/lib)


add_executable(folly_test folly_test.cpp)
target_link_libraries(folly_test ${LIBS} ${FMT_LIBS} ${BOOST_LIBS} ${GLOG_LIBS} ${GFLAGS_LIBS}
${DD_LIBS} ${LB_LIBS})

