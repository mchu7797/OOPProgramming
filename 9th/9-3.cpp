#include <iostream>

class Base {
public:
    virtual ~Base() { std::cout << "~Base()" << std::endl; }
};

class Derived: public Base {
public:
    virtual ~Derived() { std::cout << "~Derived()" << std::endl; }
};

int main() {
    Derived *dp = new Derived();
    Base *bp = new Derived();

    delete dp;
    delete bp;
}