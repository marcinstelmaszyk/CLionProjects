cmake_minimum_required(VERSION 3.15)
project(08_Bridge)

set(CMAKE_CXX_STANDARD 14)

add_executable(08_Bridge main.cpp Person.h Person.cpp pimpl.h pimpl.cpp)