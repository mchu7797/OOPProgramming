#include <iostream>

class Rect {
  int a, b;
public:
    Rect(int a, int b) { this->a = a; this->b = b; }
    void Print();
    bool operator==(Rect other) { return this->a == other.a && this->b == other.b ? true : false; }
    Rect& operator++();
};

void Rect::Print() {
    std::cout << a << " " << b << std::endl;
}

Rect& Rect::operator++() {
    ++this->a;
    ++this->b;

    return *this;
}

int main() {
    Rect r(1, 0), s(1, 1), t(1, 0), u(1, 1);

    if (r == t) {
        std::cout << "Same r t" << std::endl;
    }

    if (s == u) {
        std::cout << "Same s u" << std::endl;
    }

    if (r == u) {
        std::cout << "Same r u" << std::endl;
    }

    r.Print();
    ++r;
    r.Print();
}