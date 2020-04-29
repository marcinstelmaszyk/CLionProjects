cmake_minimum_required(VERSION 3.15)
project(04_STL)
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-std=c++11 -pthread")

set(CMAKE_CXX_STANDARD 14)

add_executable(04_STL main.cpp)

target_link_libraries(${PROJECT_NAME} libgtest.a libgtest_main.a)