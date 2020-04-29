#include <iostream>

using namespace std;

int main() {
    auto texts = {"one", "two", "three"};

    for (auto text: texts)
        std::cout << text << std::endl;

    return 0;
}
