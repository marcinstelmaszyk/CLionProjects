cmake_minimum_required(VERSION 3.15)
project(03_CMake_Tutorial)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_executable(03_CMake_Tutorial main.cpp src/calc.cpp include/calc.h)

find_library(LIBRARY library lib)

target_link_libraries(03_CMake_Tutorial LINK_PUBLIC ${LIBRARY})