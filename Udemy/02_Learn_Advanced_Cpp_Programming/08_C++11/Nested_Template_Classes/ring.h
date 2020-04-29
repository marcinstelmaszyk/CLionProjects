#pragma once

#include <string>
#include <iostream>

template<typename T>
class ring {
public:
    class iterator;

    void add(std::string name);
};

template<typename T>
class ring<T>::iterator {
public:
    void print() { std::cout << "HEllo\n"; }
};
