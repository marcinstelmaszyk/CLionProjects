#include <iostream>

template<typename T>
auto test(T value) -> decltype(value) {
    return value;
}

int main() {
    std::cout << test(7) << std::endl;
    return 0;
}
