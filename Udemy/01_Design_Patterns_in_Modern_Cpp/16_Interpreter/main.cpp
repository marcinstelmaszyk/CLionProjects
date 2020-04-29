#include <iostream>
#include "Interpreter.h"

int main() {
    std::string input{"(13-4)-(12+1)"};

    auto tokens = Interpreter::lex(input);

    for (auto& t : tokens) {
        cout << t << " ";
    }

    return 0;
}
