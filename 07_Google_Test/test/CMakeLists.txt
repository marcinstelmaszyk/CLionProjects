cmake_minimum_required(VERSION 3.8)

set(Sources ExampleTests.cpp)

add_executable(Tests ${Sources})
target_link_libraries(Tests PUBLIC
    gtest_main
    OrbitalMath
    gtest
    pthread
)