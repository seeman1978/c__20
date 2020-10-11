cmake_minimum_required(VERSION 3.15)
project(c__20)

set(CMAKE_CXX_STANDARD 20)
set(libpq_DIR /usr/local/pqsql/lib)

INCLUDE_DIRECTORIES(Shared_library)
LINK_DIRECTORIES(Shared_library/cmake-build-debug/lib)

add_executable(c__20 InvokeSharedLibrary.cpp)

# linking
target_link_libraries(c__20 pq pthread shared_library)