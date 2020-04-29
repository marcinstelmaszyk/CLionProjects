#include <iostream>
#include <vector>
#include <initializer_list>

using namespace std;

class Test {
public:
    Test(initializer_list<string> texts) {
        for(auto& value: texts)
            cout << value << endl;
    }

    Test(const Test& other) = default;
    Test& operator=(const Test& other) = delete;
};


int main() {
    Test test{"apple", "orange", "banana"};
    Test test1{"pineapple"};

    Test test2 {test1};
    test2 = test;
    return 0;
}
