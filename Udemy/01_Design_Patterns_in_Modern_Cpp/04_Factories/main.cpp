#include <iostream>

#include "DrinkFactory.h"

int main() {
    DrinkFactory df;
    auto t = df.make_drink("coffee");

    return 0;
}
