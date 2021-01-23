cmake_minimum_required(VERSION 3.15)
project(c__20)

set(CMAKE_CXX_STANDARD 20)
set(libpq_DIR /usr/local/pqsql/lib)

add_executable(c__20 Parallel/unique_lock.cpp Singleton/Singleton1.cpp)
# linking
target_link_libraries(c__20 pthread)