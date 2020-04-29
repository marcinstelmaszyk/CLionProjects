#include <iostream>
#include <sstream>
#include "Logger.h"

struct Shape {
    virtual std::string str() const = 0;
};

struct Circle : Shape {
    float radius;
    Circle() {}
    Circle(float radius) : radius(radius) {}
    void resize(float factor) {
        radius *= factor;
    }
    std::string str() const override {
        std::ostringstream oss;
        oss << "A circle of radius " << radius;
        return oss.str();
    }
};

struct Square : Shape {
    float side;

    Square() {}

    Square(float side) : side(side) {}
    std::string str() const override {
        std::ostringstream oss;
        oss << "A square with side " << side;
        return oss.str();
    }
};

struct ColoredShape : Shape {
    Shape& shape;
    std::string color;

    ColoredShape(Shape &shape, const std::string &color) : shape(shape), color(color) {}
    std::string str() const override {
        std::ostringstream oss;
        oss << shape.str() << " has the color " << color;
        return oss.str();
    }
};

struct TransparentShape : Shape {
    Shape& shape;
    uint8_t transparency;

    TransparentShape(Shape &shape, uint8_t transparency) : shape(shape), transparency(transparency) {}
    std::string str() const override {
        std::ostringstream oss;
        oss << shape.str() << " has "
            << static_cast<float>(transparency) / 255.f * 100.f
            << "% transparency";
        return oss.str();
    }
};

struct AStruct {};

template <typename T>
struct ColoredShape2 : T {
    static_assert(std::is_base_of<Shape, T>::value,
            "Template argument must be a Shape");
    std::string color;

    ColoredShape2() {}

    template<typename...Args>
    ColoredShape2(const std::string& color, Args ...args)
        : T(std::forward<Args>(args)...), color {color} {}

    std::string str() const override {
        std::ostringstream oss;
        oss << T::str() << " has the color " << color;
        return oss.str();
    }
};

int main() {
    //Circle c{1};
    //Square s{2};
    //ColoredShape cs{s, "red"};
    //TransparentShape t{cs, 51};
    //ColoredShape2<Circle> cs2 {"yellow", 2};
    //cs2.resize(3);
    //std::cout << cs2.str();
    //std::string answer {"42"};
    //Logger logger{[&](){ std::cout << answer << std::endl; answer = "0"; }, "Ultimate answer"};
    //logger();
    //std::cout << answer;

    //std::string a{"red"};
    //std::cout << a.find("reda");



    return 0;
}
