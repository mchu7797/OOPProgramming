//
// Created by Minseok Chu on 10/31/23.
//

#include <iostream>

using namespace std;

class Circle {
private:
    int radius;
public:
    Circle();

    Circle(int r);

    ~Circle();

    double getArea() { return 3.14 * radius * radius; }

    int getRadius() { return radius; }

    void setRadius(int radius) { this->radius = radius; }
};

Circle::Circle() {
    radius = 1;
    cout << "생성자 실행 -> Radius = " << radius << endl;
}

Circle::Circle(int radius) {
    this->radius = radius;
    cout << "생성자 실행 -> Radius = " << radius << endl;
}

Circle::~Circle() {
    cout << "소멸자 실행 -> Radius = " << radius << endl;
}

void increase(Circle c) {
    cout << "Memory Addr : " << &c << endl;
    int r = c.getRadius();
    c.setRadius(r + 1);
}

void increaseRef(Circle *c) {
    cout << "Memory Addr : " << c << endl;
    int r = c->getRadius();
    c->setRadius(r + 1);
}

int main() {
    Circle waffle(30);
    cout << "Memory Addr : " << &waffle << endl;
    increase(waffle);
    cout << waffle.getRadius() << endl;
    increaseRef(&waffle);
    cout << waffle.getRadius() << endl;

    return EXIT_SUCCESS;
}