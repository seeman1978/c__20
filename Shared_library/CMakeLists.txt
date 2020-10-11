cmake_minimum_required(VERSION 3.15)
project(c__20)

set(CMAKE_CXX_STANDARD 20)

SET (LIBRARY_OUTPUT_PATH lib)

add_library(shared_library SHARED shared_library.cpp)   #STATIC  or SHARED

SET_TARGET_PROPERTIES (shared_library PROPERTIES VERSION 1.2 SOVERSION 1.2)