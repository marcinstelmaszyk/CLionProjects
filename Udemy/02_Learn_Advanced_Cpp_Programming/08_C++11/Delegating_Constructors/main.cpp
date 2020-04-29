#include <iostream>

class Parent {
public:
    Parent() {
        std::cout << "This is a default constructor\n";
    }

    Parent(std::string name) : Parent() {
        std::cout << "And this is " << name << std::endl;
    }

};


int main() {
    Parent("John");

    return 0;
}
