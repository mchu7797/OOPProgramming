//
// Created by Minseok Chu on 12/5/23.
//

#include <iostream>


class Test1 {
public:
    void Hello() { std::cout << "Test1" << std::endl; }

    virtual void World() { std::cout << "Test1 W" << std::endl; }
};

class Test2 : public Test1 {
public:
    void Hello() { std::cout << "Test2" << std::endl; }

    void World() { std::cout << "Test2 W" << std::endl; }
};

int main(void) {
    Test1 t1;
    Test2 t2;
    Test1 *t3;

    t1.Hello();
    t1.World();

    t2.Hello();
    t2.World();

    t3 = &t1;
    t3->Hello();
    t3->World();

    t3 = &t2;
    t3->Hello();
    t3->World();
}