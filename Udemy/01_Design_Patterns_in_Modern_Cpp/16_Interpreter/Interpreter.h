#pragma once

#include <vector>
#include "Token.h"
#include "Element.h"

namespace Interpreter {

    vector <Token> lex(const string &input) {
        vector <Token> result;

        for (int i = 0; i < input.size(); ++i) {
            switch (input[i]) {
                case '+':
                    result.push_back(Token{Token::plus, "+"});
                    break;
                case '-':
                    result.push_back(Token{Token::minus, "-"});
                    break;
                case '(':
                    result.push_back(Token{Token::lparen, "("});
                    break;
                case ')':
                    result.push_back(Token{Token::rparen, ")"});
                    break;
                default:
                    ostringstream buffer;
                    buffer << input[i];
                    for (int j = i + 1; j < input.size(); ++j) {
                        if (isdigit(input[j])) {
                            buffer << input[j];
                            ++i;
                        } else {
                            result.push_back(
                                    Token{Token::integer, buffer.str()});
                            break;
                        }
                    }
            }
        }
        return result;
    }

    shared_ptr<Element> parse(const vector<Token>& tokens) {

    }

}