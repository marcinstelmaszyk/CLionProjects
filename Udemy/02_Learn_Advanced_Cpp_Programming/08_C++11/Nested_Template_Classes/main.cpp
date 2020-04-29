#include <iostream>
#include <vector>
#include "ring.h"

using namespace std;

int main() {
    //ring<string> textring(3);

    //textring.add("one");
    //textring.add("two");
    //textring.add("three");
    //textring.add("four");

    //for (int i = 0; i < textring.size(); ++i)
    //    cout << textring.get(i) << endl;

    ring<std::string>::iterator it;
    it.print();

    int* pointer{};
    cout << pointer << endl;

    int numbers[]{1, 2, 3};

    std::vector<int> nums {1,2,3};

    return 0;
}
