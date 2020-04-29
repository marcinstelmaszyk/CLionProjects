#include <iostream>
#include <algorithm>
#include "OutputFileHandler.h"
#include <vector>

class ToSquare {
public:
    constexpr int operator()(const int value) const noexcept { return value * value; }
};

class IncreasingNumbers {
    unsigned int number{0};
public:
    int operator()() { return number++; }
};

using Numbers = std::vector<int>;

int main() {
    OutputFileHandler output{"data"};
    std::cout << output.is_open();
    output << "Next line\n";
    std::cout << output.is_open();

    const std::size_t AMOUNT_OF_NUMBERS = 100;
    Numbers numbers(AMOUNT_OF_NUMBERS);

    std::generate(std::begin(numbers), std::end(numbers),
            IncreasingNumbers());

    std::transform(std::begin(numbers) + 10, std::end(numbers), std::begin(numbers) + 10,
            [](auto x) { return x * x; });

    return 0;
}
