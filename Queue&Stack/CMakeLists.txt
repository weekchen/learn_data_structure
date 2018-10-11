cmake_minimum_required(VERSION 3.12)
SET(CMAKE_C_COMPILER g++)
add_compile_options(-std=c++11)

project(Queue&Stack)

add_executable(open_lock open_lock/open_lock.cpp)
add_executable(perfect_squares perfect_squares/perfect_squares.cpp)