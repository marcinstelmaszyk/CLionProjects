#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool match(const string& test) {
    return test.size() == 3;
}

int countStrings(vector<string>& texts, bool (*match)(const string&)) {
    int count {0};    
    for (const auto& t : texts) {
        if (match(t))
            count++;
    }
    return count;
}

int main() {
    vector<string> text;
    text.emplace_back("one");
    text.emplace_back("two");
    text.emplace_back("three");


    cout << count_if(begin(text), end(text), match) << endl;
    cout << countStrings(text, match) << endl;


    return 0;
}
