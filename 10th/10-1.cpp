#include <iostream>

class Circle {
    int radius;
public:
    Circle(int radius=1) { this->radius = radius; }
    int getRadius() { return radius; }
};

template <class T>
void myswap(T &a, T& b) {
    T tmp;
    tmp = a;
    a = b;
    b = tmp;
}

int main() {
    int a = 4, b = 5;
    myswap(a, b);
    std::cout << "a=" << a << ", " << "b=" << b << std::endl;

    double c = 0.3, d = 12.5;
    myswap(c, d);
    std::cout << "c=" << c << ", " << "d=" << d << std::endl;

    Circle donut(5), pizza(20);
    myswap(donut, pizza);
    std::cout << "Donut Radius : " << donut.getRadius() << std::endl;
    std::cout << "Pizza Radius : " << pizza.getRadius() << std::endl;
}