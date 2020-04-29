#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>

using namespace std;

void run(vector<string>& vec, function<bool(string&)> check) {
    int count = count_if(begin(vec), end(vec),
            [](string test){ return test.size() == 3;});
    std::cout << count << std::endl;
}

int main() {
    vector<string> vec{"one", "two", "three"};

    

    #if DEBUG
        run(vec, [](string test){ return test.size() == 3;});
    #endif

    return 0;
}
