#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <boost/lexical_cast.hpp>
using namespace std;


class SingletonDatabase {
public:
    SingletonDatabase() {
        std::cout << "Initializing database\n";
        ifstream ifs("capitals.txt");

        string s, s2;

        while(getline(ifs, s)) {
            getline(ifs, s2);
            int pop = lexical_cast<int>(s2);
            capitals[s] = pop;
        }
    }
    std::map<string, int> capitals;
};

int main() {
    SingletonDatabase a {};
    return 0;
}

