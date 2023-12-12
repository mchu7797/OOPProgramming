//
// Created by Minseok Chu on 12/5/23.
//

#include <iostream>

class Abstract {
public:
    virtual void Hello() = 0;
};

class Test1 : public Abstract {
public:
    void Hello() { std::cout << "Test1" << std::endl; }
};

class Test2 : public Abstract {
    void Hello() { std::cout << "Test2" << std::endl; }
};

int main() {
    Test1 t1;
    Test2 t2;
    Abstract* ab;

    ab = &t1;
    ab->Hello();

    ab = &t2;
    ab->Hello();
}