#include <iostream>
#include <typeinfo>

using namespace std;

int main() {
    int value;

    cout << typeid(value).name() << endl;

    decltype(value) newInt {10};
    cout << newInt;
    return 0;
}
