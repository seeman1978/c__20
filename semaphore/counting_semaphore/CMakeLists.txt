cmake_minimum_required(VERSION 3.20)
project(counting_semaphore)

set(CMAKE_CXX_STANDARD 20)

add_executable(counting_semaphore main.cpp)

target_link_libraries(counting_semaphore pthread)
