#pragma once

#include <sstream>

using namespace std;

struct Token {
    enum Type { integer, plus, minus, lparen, rparen } type;
    std::string text;

    Token(Type type, const std::string &text) : type(type), text(text) {}

    friend std::ostream &operator<<(std::ostream &os, const Token &token) {
        os << "`" << token.text << "`";
        return os;
    }
};
