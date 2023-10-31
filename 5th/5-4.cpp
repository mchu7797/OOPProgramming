//
// Created by Minseok Chu on 10/31/23.
//
#include <iostream>

using namespace std;

class Circle {
    int radius;
public:
    Circle() { radius = 1; }

    Circle(int radius) { this->radius = radius; }

    void setRadius(int radius) { this->radius = radius; }

    double getArea() { return 3.14 * radius * radius; }
};

int main() {
    Circle circle;
    Circle &refCircle = circle;
    refCircle.setRadius(10);
    cout << refCircle.getArea() << " " << circle.getArea();
}
