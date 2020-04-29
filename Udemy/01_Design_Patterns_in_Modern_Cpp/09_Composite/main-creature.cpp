#include <array>
#include <iostream>
#include <numeric>

using namespace std;

class Creature {
    enum Abilities { str, agl, intl, count };
    array<int, count> abilities {0};
public:
    int get_strength() const { return abilities[str]; }
    void set_strength(int value) { abilities[str] = value; }

    int get_aglility() const { return abilities[agl]; }

    void set_agility(int value) { abilities[agl] = value; }

    int sum() const {
        return accumulate(abilities.begin(), abilities.end(), 0);
    }

    double average() const {
        return sum() / (double)count;
    }
};


int main() {
    Creature c;
    c.set_strength(10);
    c.set_agility(20);
    cout << c.sum() << " " << c.average();

    return 0;
}