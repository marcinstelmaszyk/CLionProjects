#include <iostream>
#include <string>
using namespace std;

template <typename T>
void print(T n) {
    cout << n << endl;

}

int main() {
    print<std::string>("5");
    return 0;
}
