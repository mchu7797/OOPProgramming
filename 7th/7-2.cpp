#include <iostream>

class equal_test {
    int a;
public:
    equal_test(int a) { this->a = a; }
    bool equals(equal_test b);
};

bool equal_test::equals(equal_test b) {
    if (this->a == b.a) {
        return true;
    }

    return false;
}

int main() {
    equal_test a(1), b(1), c(2);

    std::cout << a.equals(b) << std::endl;
    std::cout << b.equals(c) << std::endl;
}