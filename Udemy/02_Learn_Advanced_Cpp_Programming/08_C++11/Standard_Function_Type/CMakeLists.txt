cmake_minimum_required(VERSION 3.16)
project(Standard_Function_Type)

set(CMAKE_CXX_STANDARD 14)

message("Using CMAKE_BUILD_TYPE = ${CMAKE_BUILD_TYPE}")

if (CMAKE_BUILD_TYPE MATCHES Debug)
    add_definitions(-DDEBUG=1)
endif()

add_executable(Standard_Function_Type main.cpp)