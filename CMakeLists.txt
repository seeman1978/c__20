cmake_minimum_required(VERSION 3.15)
project(c__20)

set(CMAKE_CXX_STANDARD 20)
set(libpq_DIR /usr/local/pqsql/lib)

#include_directories(./Shared_library)

#LINK_DIRECTORIES(/home/qiangwang/CLionProjects/c__20/Shared_library/cmake-build-debug/lib)

add_executable(c__20 class/StudentT.cpp)
target_link_libraries(c__20 pthread)
#TARGET_LINK_LIBRARIES(c__20 libshared_library.so)