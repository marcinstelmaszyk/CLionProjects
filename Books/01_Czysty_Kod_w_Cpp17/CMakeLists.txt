cmake_minimum_required(VERSION 3.16)
project(01_Czysty_Kod_w_Cpp17)

set(CMAKE_CXX_STANDARD 14)

add_executable(01_Czysty_Kod_w_Cpp17 main.cpp)
target_link_libraries(01_Czysty_Kod_w_Cpp17 gtest_main gtest pthread)