/*
 * Created by Minseok Chu on 11/28/23.
 */

#include <iostream>

class Point {
protected:
    int x, y;
public:
    void Set(int x, int y);

    void ShowPoint();
};

void Point::Set(int x, int y) {
    this->x = x;
    this->y = y;
}

void Point::ShowPoint() {
    std::cout << "X : " << x << ", Y : " << y << std::endl;
}

class ColorPoint : public Point {
    std::string color;
public:
    void SetColor(std::string color);

    void ShowColorPoint();

    bool Equals(ColorPoint other);
};

void ColorPoint::SetColor(std::string color) {
    this->color = color;
}

void ColorPoint::ShowColorPoint() {
    std::cout << "COLOR : " << color << std::endl;
    ShowPoint();
}

bool ColorPoint::Equals(ColorPoint other) {
    if (x == other.x && y == other.y && color == other.color) {
        return true;
    }

    return false;
}

int main() {
    Point p;
    ColorPoint cp1, cp2;

    p.Set(1, 3);
    p.ShowPoint();

    cp1.Set(5, 6);
    cp1.SetColor("RED");
    cp1.ShowColorPoint();

    cp2.Set(5, 6);
    cp2.SetColor("RED");
    cp2.ShowColorPoint();

    std::cout << (cp1.Equals(cp2) ? "True" : "False") << std::endl;

    return 0;
}