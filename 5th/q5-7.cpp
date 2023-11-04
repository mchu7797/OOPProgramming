//
// Created by Minseok Chu on 2023-11-04.
//

#include <iostream>

class MyIntStack {
    int p[10];
    int tos;
public:
    MyIntStack() { tos = 0; };

    bool push(int n);

    bool pop(int &n);
};

bool MyIntStack::push(int n) {
    if(tos == 10) {
        return false;
    }

    p[tos++] = n;

    return true;
}

bool MyIntStack::pop(int &n) {
    if (tos == 0) {
        return false;
    }

    n = p[--tos];

    return true;
}

int main() {
    MyIntStack a;

    for (int i = 0; i < 11; i++) {
        if (a.push(i)) {
            std::cout << i << ' ';
        } else {
            std::cout << std::endl << i + 1 << "번째 stack full" << std::endl;
        }
    }

    int n;

    for (int i = 0; i < 11; i++) {
        if (a.pop(n)) {
            std::cout << n << ' ';
        } else {
            std::cout << std::endl << i + 1 << "번째 stack empty";
        }
    }
}