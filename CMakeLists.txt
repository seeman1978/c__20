cmake_minimum_required(VERSION 3.15)
project(c__20)

set(CMAKE_CXX_STANDARD 20)
set(libpq_DIR /usr/local/pqsql/lib)

add_executable(c__20 "atomic/memory_order2.cpp")
