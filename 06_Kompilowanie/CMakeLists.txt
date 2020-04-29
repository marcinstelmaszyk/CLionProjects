cmake_minimum_required(VERSION 3.10)
project(ProjectName)

set(SOURCES src/main.cpp)

link_directories(/home/mast/CLionProjects/lib)

add_executable(program ${SOURCES})
target_link_libraries(program LINK_PUBLIC Math)
