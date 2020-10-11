cmake_minimum_required(VERSION 3.15)
project(c__20)

set(CMAKE_CXX_STANDARD 20)
set(libpq_DIR /usr/local/pqsql/lib)

add_executable(c__20 Shared_library/shared_library.cpp Shared_library/shared_library.h)

# linking
target_link_libraries(c__20 pq pthread)