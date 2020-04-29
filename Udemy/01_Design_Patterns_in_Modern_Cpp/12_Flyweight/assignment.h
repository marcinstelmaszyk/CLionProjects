#pragma once

#include <vector>
#include <iostream>

using namespace std;

struct Sentence {
    struct WordToken {
        size_t start, end;
        bool capitalize {false};
        WordToken(size_t start, size_t end) :
                start{start}, end{end} {}
        bool contains(size_t i) const {
            return (i >= start && i < end);
        }
    };

    vector<WordToken> words;
    string sentence_text;
    string delimiter = " ";

    explicit Sentence(const string& text) {
        sentence_text = text;
        split_into_word_tokens(text);
    }

    void split_into_word_tokens(const string &text) {
        size_t pos = 0, last=0;
        while ((pos = text.find(delimiter, last)) != string::npos) {
            words.emplace_back(WordToken{last, pos});
            last = pos + delimiter.length();
        }
        // Append the last word in the sentence
        words.emplace_back(WordToken{last, text.length()});
    }

    WordToken& operator[](size_t index) {
        return words[index];
    }

    string str() const {
        string s;
        for (int i = 0; i < sentence_text.length(); ++i) {
            char c = sentence_text[i];
            for (const auto &token : words) {
                if (token.contains(i) && token.capitalize)
                    c = toupper(c);
            }
            s += c;
        }
        return s;
    }
};