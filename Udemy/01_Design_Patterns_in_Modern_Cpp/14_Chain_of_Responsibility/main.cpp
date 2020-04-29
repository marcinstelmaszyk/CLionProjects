#include <iostream>
#include <string>

using namespace std;

struct Creature {
    string name;
    int attack, defence;

    Creature(const string &name, int attack, int defence)
        : name(name), attack(attack), defence(defence) {}

    friend ostream &operator<<(ostream &os, const Creature &creature) {
        os << "name: " << creature.name << " attack: " << creature.attack << " defence: " << creature.defence;
        return os;
    }
};

class CreatureModifier {
    CreatureModifier* next{nullptr};
protected:
    Creature& creature;
public:
    CreatureModifier(Creature &creature) : creature(creature) {}

    void add(CreatureModifier *cm) {
        if (next) next->add(cm);
        else next = cm;
    }

    virtual void handle() {
        if (next) next->handle();
    }
};

class DoubleAttackModifier : public CreatureModifier {
public:
    DoubleAttackModifier(Creature &creature) : CreatureModifier(creature) {}

    void handle() override {
        creature.attack *= 2;
        CreatureModifier::handle();
    }
};

class IncreaseDefenceModifier : public CreatureModifier {
public:
    explicit IncreaseDefenceModifier(Creature &creature) : CreatureModifier(creature) {}

    void handle() override {
        if (creature.attack <= 2)
            creature.defence++;
        CreatureModifier::handle();
    }
};

int main() {
    Creature goblin{"Goblin", 1, 1};
    CreatureModifier root{goblin};
    DoubleAttackModifier r1{goblin};
    DoubleAttackModifier r1_2{goblin};
    IncreaseDefenceModifier r2{goblin};

    root.add(&r1);
    root.add(&r1_2);
    root.add(&r2);

    root.handle();
    cout << goblin;

    return 0;
}
