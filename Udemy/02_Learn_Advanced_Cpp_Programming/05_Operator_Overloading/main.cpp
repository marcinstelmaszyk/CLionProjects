#include <iostream>

class Test {
    int id;
    std::string name;
public:
    Test(int id, const std::string& name) : id(id), name(name) {
        std::cout << &name << std::endl;
    }
    void print() {
        std::cout << id << ": " << name << std::endl;
    }
    Test& operator=(const Test& other) {
        id = other.id;
        name = other.name;
        return *this;
    }
};

int main() {
    std::string name{"John"};
    std::cout << &name << std::endl;
    Test test1{10, name};
    test1.print();

    Test test2{20, "Bob"};

    test2 = test1;
    test2.print();

    return 0;
}
