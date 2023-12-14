#include <iostream>

class Point {
    int x, y;
public:
    Point(int x=0, int y=0) { this->x = x; this-> y = y; }
    friend std::ostream& operator<<(std::ostream& stream, Point p);
};

std::ostream& operator<<(std::ostream& stream, Point p) {
    stream << "(" << p.x << ", " << p.y << ")";
    return stream;
}

int main() {
    Point p(3, 4);
    
    std::cout << p << std::endl;

    Point q(1, 100), r(2, 200);

    std::cout << q << r << std::endl;
}