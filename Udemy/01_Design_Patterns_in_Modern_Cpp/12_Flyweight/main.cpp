#include <iostream>
#include <string>
#include <vector>
#include "assignment.h"

using namespace std;

class FormattedText {
    string plain_text;
    bool *caps;
public:
    explicit FormattedText(const string &plain_text) : plain_text(plain_text) {
        caps = new bool[plain_text.length()];
    }

    ~FormattedText() {
        delete [] caps;
    }

    void capitalize(int start, int end) {
        for (int i = start; i <= end; i++)
            caps[i] = true;
    }

    friend ostream &operator<<(ostream &os, const FormattedText &obj) {
        string s;
        for (int i = 0; i < obj.plain_text.length(); ++i) {
            char c = obj.plain_text[i];
            s += obj.caps[i] ? toupper(c) : c;
        }
        return os << s;
    }
};

class BetterFormattedText {
public:
    struct TextRange {
        int start, end;
        bool capitalize;

        bool covers(int position) const {
            return position >= start && position <= end;
        }
    };
    TextRange& get_range(int start, int end) {
        formatting.emplace_back(TextRange{start, end});
        return *formatting.rbegin();
    }

    explicit BetterFormattedText(const string &plainText) : plain_text(plainText) {}

    friend ostream &operator<<(ostream &os, const BetterFormattedText &obj) {
        string s;
        for (int i = 0; i < obj.plain_text.length(); ++i) {
            char c = obj.plain_text[i];
            for (const auto& rng : obj.formatting) {
                if (rng.covers(i) && rng.capitalize)
                    c = toupper(c);
                s += c;
            }
        }
        return os << s;
    }

private:
    string plain_text;
    vector<TextRange> formatting;
};



int main() {
    //FormattedText ft {"This is the last word."};
    //ft.capitalize(10, 15);
    //std::cout << ft << std::endl;
    //
    //BetterFormattedText bft{"This is the last word."};
    //bft.get_range(10, 15).capitalize = true;
    //std::cout << bft << std::endl;

    // Assignment
    Sentence s{"This is the last word."};
    s[0].capitalize = true;
    cout << s.str();

    return 0;
}
