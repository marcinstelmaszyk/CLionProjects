cmake_minimum_required(VERSION 3.8)

set(PROJECT_NAME ExampleProject)

project(${PROJECT_NAME} CXX)
set(CMAKE_CXX_STANDARD 11)

set(Sources main.cpp)
add_subdirectory(src)
add_subdirectory(test)

add_executable(Main ${Sources})
target_link_libraries(Main PUBLIC OrbitalMath)