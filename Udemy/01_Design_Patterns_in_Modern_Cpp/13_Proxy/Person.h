#pragma once

#include <string>
#include <iostream>

using namespace std;

namespace assignment {

    class Person {
        friend class ResponsiblePerson;

        int age;
    public:
        Person(int age) : age(age) {}

        int get_age() const { return age; }

        void set_age(int age) { this->age = age; }

        string drink() const { return "drinking"; }

        string drive() const { return "driving"; }

        string drink_and_drive() const { return "driving while drunk"; }
    };

    class ResponsiblePerson {
    public:
        ResponsiblePerson(const Person &person) : person(person) {}

        void set_age(int age) { person.set_age(age); }

        string drink() const {
            if (person.get_age() < 18)
                return "too young";
            return person.drink();
        }

        string drive() const {
            if (person.get_age() < 16)
                return "too young";
            return person.drive();
        }

        string drink_and_drive() const {
            return "dead";
        }

    private:
        Person person;
    };
}