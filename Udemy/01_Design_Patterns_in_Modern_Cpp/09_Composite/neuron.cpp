#include <vector>
#include <iostream>

using namespace std;

struct Neuron {
    vector<Neuron*> in, out;
    unsigned int id;

    Neuron() {
        static int id{1};
        this->id = id++;
    }

    void connect_to(Neuron& other) {
        out.push_back(&other);
        other.in.push_back(this);
    }

    friend std::ostream &operator<<(std::ostream &os, const Neuron &obj) {
        for (Neuron* n : obj.in)
            os << n->id << "\t-->\t[" << obj.id << "]\n";

        for (Neuron* n : obj.out)
            os << "[" << obj.id << "]\t-->\t" << n->id << endl;
        return os;
    }
};

int main() {
    Neuron n1, n2;
    n1.connect_to(n2);
    cout << n1 << n2;
}
