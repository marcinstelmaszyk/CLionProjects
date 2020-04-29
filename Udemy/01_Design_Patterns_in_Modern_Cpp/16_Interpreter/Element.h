#pragma once

#include <memory>

using namespace std;

struct Element {
    virtual int eval() const = 0;
};

struct Integer : Element {
    int value;

    Integer(int value) : value(value) {}

    int eval() const override {
        return value;
    }
};

struct BinaryOperation : Element {
    enum Type { addition, subtraction } type;
    shared_ptr<Element> lhs, rhs;

    int eval() const override {
        auto left = lhs->eval();
        auto right = rhs->eval();
        if (type == addition)
            return left + right;
        else
            return left - right;
    }
};

