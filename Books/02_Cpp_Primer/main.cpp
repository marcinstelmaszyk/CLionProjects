#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <memory>

using namespace std;

template <typename T>
void show_vector(const T& vec, bool showHalf = false) {
    // Set the iterator pointing to the last element to be shown.
    auto end = showHalf ? vec.begin() + vec.size() / 2 : vec.end();

    for (auto it = vec.begin(); it < end; ++it){
        cout << *it << endl;
    }
}

template <typename T>
vector<T> sum_of_adjacent(const vector<T> &vec) {
    vector<T> sums;
    sums.reserve(vec.size()/2);
    for (auto it = vec.begin(); it + 1 < vec.end(); ++it) {
        sums.push_back(accumulate(it, it + 2, 0));
    }
    return sums;
}

void vector_exercise() {
    vector<int> vec(20, 0);
    // Fill the vector with sequentially increasing values
    iota(vec.begin(), vec.end(), 1);

    auto result = sum_of_adjacent<int>(vec);

    // Show vector
    show_vector(result);
}

struct entity {
        int value;
    entity(int val) : value(val){ cout << "Created " << val << endl; }
    ~entity() { cout << "Deleted\n"; }
};


int main() {
    {
        shared_ptr<entity> e = make_shared<entity>(1);
        {
            shared_ptr<entity> shared = make_shared<entity>(2);
            e = shared;
            cout << endl;
        }
        cout << endl;
        cout << endl;
    }




    return 0;
}
