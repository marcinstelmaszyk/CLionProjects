#include <iostream>
#include <string>
#include <memory>
#include <thread>
#include <chrono>

#include "Person.h"

using namespace std;

struct Image {
    virtual void draw() = 0;
    virtual ~Image() {};
};

struct Bitmap : Image {
    explicit Bitmap(const string& filename) {
        cout << "Loading bitmap from " << filename << endl;
        this_thread::sleep_for(chrono::milliseconds(2000));
    }

    void draw() override {
        cout << "Drawing bitmap" << endl;
    }

    ~Bitmap() override = default;
};

struct LazyBitmap : Image {
    explicit LazyBitmap(const string &filename) : filename(filename) {}

    void draw() override {
        if (!bmp)
            bmp = new Bitmap(filename);
        bmp->draw();
    }

    ~LazyBitmap() override {
        cout << "About to free memory at address: " << bmp << endl;
        delete bmp;
    }

private:
    string filename;
    Bitmap *bmp{nullptr};
};



int main() {
    // Proxy example
    {
        cout << "==== Proxy example =====\n";
        unique_ptr<Image> bitmap = make_unique<LazyBitmap>("pokemon.png");
        bitmap->draw();
    }

    // Assignment
    cout << "\n==== Assignment ====\n";
    unique_ptr<assignment::Person> person = make_unique<assignment::Person>(15);
    cout << person->drink_and_drive() << endl;
    auto responsible = make_unique<assignment::ResponsiblePerson>(20);
    cout << responsible->drink_and_drive() << endl;

    return 0;
}
