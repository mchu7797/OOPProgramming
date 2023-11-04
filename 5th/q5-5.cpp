//
// Created by Minseok Chu on 2023-11-04.
//

#include <iostream>

class Circle {
    int radius;
public:
    Circle(int r) { radius = r; }
    int getRadius() { return radius; }
    void setRadius(int r) { radius = r; }
    void show() { std::cout << "반지름이 " << radius << "인 원" << std::endl; }
};

void increaseBy(Circle &a, Circle &b) {
    int r = a.getRadius() + b.getRadius();
    a.setRadius(r);
}

int main(void) {
    Circle x(10), y(5);
    increaseBy(x, y);
    x.show();

    return EXIT_SUCCESS;
}