#include <iostream>
#include <string>
#include <memory>

using namespace std;

struct Address {
    string street, city;
    int suite;

    Address(const string &street, const string &city, int suite)
    : street(street), city(city), suite(suite) {}

    Address(const Address &other) = default;

    friend ostream &operator<<(ostream &os, const Address &address) {
        os << "street: " << address.street << " city: " << address.city << " suite: " << address.suite;
        return os;
    }
};

struct Contact {
    string name;
    Address* address;

    Contact(const string &name, Address *address) : name(name), address(address) {}

    Contact(const Contact &other)
    : name {other.name}
    , address { new Address { *other.address } }
    {}

    friend ostream &operator<<(ostream &os, const Contact &contact) {
        os << "name: " << contact.name << " address: " << *contact.address;
        return os;
    }

    ~Contact() { delete address;  }

};

struct EmployeeFactory {
    static unique_ptr<Contact> new_main_office_employee(const string& name, const int suite) {
        static Contact p{"", new Address{"123 East Dr", "London", 0}};
        return new_employee(name, suite, p);
    }
private:
    static unique_ptr<Contact> new_employee(const string &name, const int suite, const Contact& prototype) {
        auto result = make_unique<Contact>(prototype);
        result->name = name;
        result->address->suite = suite;
        return result;
    }
};

struct Point {
    int x{0}, y{0};
    Point(){}
    Point(const int x, const int y) : x{x}, y{y} {}
    Point(Point& p) : x{p.x}, y{p.y} {}
};

struct Line {
    Point *start, *end;

    Line(Point* const start, Point* const end) : start(start), end(end) {}
    Line(const Line& l) {
        start = new Point(*l.start);
        end = new Point(*l.end);
    }
    ~Line() { delete start; delete end; }
    Line deep_copy() const {
        return Line(*this);
    }
};

int main() {
    Point s {1,2};
    Point e {4,4};
    Line l1 {&s, &e};
    Line l2 = l1.deep_copy();
    l1.start->x = 9;

    return 0;
}
