#include <iostream>

using namespace std;

void test(void (*func)(const string&)) {
    func("Mike");
}

class Test {
private:
    int one{1};
    int two{2};
public:
    void run() {
        int three{3};
        int four{4};

        auto pLambda = [this, three, four]() {
            cout << one << endl;
            cout << three << endl;
            cout << four << endl;
        };
        pLambda();
    }
};

int main() {
    Test test;
    test.run();

    return 0;
}
