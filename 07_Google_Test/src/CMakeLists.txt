cmake_minimum_required(VERSION 3.8)

set(This OrbitalMath)

project(${This} CXX)
set(CMAKE_CXX_STANDARD 11)

set(Headers OrbitalMath.h)
set(Sources OrbitalMath.cpp)

add_library(${This} STATIC ${Sources} ${Headers})