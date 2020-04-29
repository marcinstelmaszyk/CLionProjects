#ifndef INC_10_DECORATOR_LOGGER_H
#define INC_10_DECORATOR_LOGGER_H

#include <functional>
#include <iostream>

struct Logger {
    std::function<void()> func;
    std::string name;

    Logger(const std::function<void()> &func, const std::string &name)
            : func(func), name(name) {}

    void operator()() const {
        std::cout << "Entering " << name << std::endl;
        func();
        std::cout << "Exiting " << name << std::endl;
    }
};

#endif //INC_10_DECORATOR_LOGGER_H
