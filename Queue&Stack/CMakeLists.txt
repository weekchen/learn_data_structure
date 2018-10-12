cmake_minimum_required(VERSION 3.12)
SET(CMAKE_C_COMPILER g++)
add_compile_options(-std=c++11)

project(Queue&Stack)

add_executable(circular_queue circular_queue.cpp)
add_executable(count_islands count_islands.cpp)
add_executable(open_lock open_lock.cpp)
add_executable(perfect_squares perfect_squares.cpp)
add_executable(min_stack min_stack.cpp)
add_executable(valid_parentheses valid_parentheses.cpp)
add_executable(daily_temperatures daily_temperatures.cpp)