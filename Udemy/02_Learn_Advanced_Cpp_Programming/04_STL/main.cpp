#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <stack>
#include <memory>

#include "gtest/gtest.h"

using namespace std;

void increaseCapacity() {
    vector<string> strings;
    int capacity = strings.capacity();

    for (int i=0; i < 10000; ++i){
        strings.push_back("1");
        if (strings.capacity() != capacity) {
            capacity = strings.capacity();
            cout << i << " " << capacity << endl;
        }
    }
}

void twoDimensionalVector() {
    vector<vector<int>> grid(3, vector<int>(4,7));
    for (auto& row : grid) {
        for (auto &col : row) {
            cout << col << " ";
        }
        std::cout << endl;
    }
}

void lists() {
    list<int> numbers;

    numbers.push_back(1);
    numbers.push_back(3);
    numbers.push_front(0);
    auto it = begin(numbers);
    numbers.insert(++it, 10);

    for (auto& elem : numbers)
        cout << elem << " ";
    cout << endl;
    cout << *it << endl;

    it = numbers.erase(it);
    cout << *it << endl;


    for (auto& elem : numbers)
        cout << elem << " ";
}

typedef map<const string, int> mapping;
pair<bool, mapping::const_iterator>
        isInMap(mapping& aMap, const std::string& key) {
    auto elementFound = aMap.find(key);
    return {(aMap.find(key) != end(aMap)), elementFound};
}

void map_lesson() {
    map<const string, int> ages {
            {"John", 20}
    };

    ages["Mike"] = 40;
    ages["Tom"] = 23;

    // Adding an element to map with std::make_pair
    ages.insert(make_pair("Marcin", 32));

    for (auto& person : ages)
        cout << person.first << " is "
             << person.second << " years old." << endl;

    auto person = isInMap(ages, "Vicky");
    if (person.first) {
        cout << (person.second)->second;
    }
}

void multimap_lesson() {
    multimap<int, string> lookup;

    lookup.insert(make_pair(30, "Mike"));
    lookup.insert(make_pair(10, "Vicky"));
    lookup.insert(make_pair(30, "Raj"));
    lookup.insert(make_pair(20, "Bob"));
    lookup.insert(make_pair(50, "John"));

    for (const auto& person : lookup)
        cout << person.first << ": " << person.second << endl;
    cout << endl;

    auto person30YearsOld = lookup.equal_range(30);
    for (auto it = person30YearsOld.first; it != person30YearsOld.second; ++it)
        cout << it->first << ": " << it->second << endl;
}

class Test {
    int id;
public:
    string name;

    Test(int id, const string &name) : id(id), name(name) {}

    friend ostream &operator<<(ostream &os, const Test &test) {
        os << "id: " << test.id << " name: " << test.name;
        return os;
    }

    virtual ~Test() {
        cout << std::setw(6) << name << " at " << this << " has been destroyed" << endl;
    }

    Test(const Test& other) {
        name = other.name;
        id = other.id;
        cout << "Created a new instance of " << name << " " << &other
             << " at " << this << endl;
    }

    bool operator<(const Test &rhs) const {
        return name < rhs.name;
    }
};

void set_lesson() {
    set<int> numbers;
    numbers.insert(10);
    numbers.insert(20);
    numbers.insert(30);
    numbers.insert(30);

    for (set<int>::iterator it = begin(numbers); it != numbers.end(); ++it) {
        cout << *it << endl;
    }

    auto itFound = numbers.find(30);
    if (itFound != end(numbers))
        cout << "Found: " << *itFound << endl;

    if (numbers.count(30))
        cout << "Found: " << *numbers.find(30) << endl;

    set<Test> tests;
    tests.insert(Test{1, "Tom"});
    tests.insert(Test{3, "Hanna"});
    tests.insert(Test{0, "Hanna"});

    for (const auto& t : tests)
        cout << t << endl;

}

void set_stack() {
    stack<Test> tests;
    tests.emplace(0, "Tom");
    //tests.push(Test{1, "Tom"});
    //tests.push(Test{1, "Sue"});
    cout << "After push operation\n";
    //cout << tests.top() << endl;
    //cout << tests.top() << endl;
}

int main(int argc, char** argv) {
    // Stack
    set_stack();

    // Set
    //set_lesson();

    // Multimap
    //multimap_lesson();

    // Map
    //map_lesson();

    // List
    //lists();

    // Two-dimensional vector
    //twoDimensionalVector();

    // Increasing capacity
    //increaseCapacity();

    return 0;
}
