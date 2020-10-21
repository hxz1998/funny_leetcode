cmake_minimum_required(VERSION 3.16)

aux_source_directory(. DIR_SRCS)
set(CMAKE_CXX_STANDARD 20)

add_executable(priority-queue-test priority-queue-test.cc)
add_executable(UVa136 UVa136.cc)