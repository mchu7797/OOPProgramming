//
// Created by Minseok Chu on 2023-11-04.
//

#include <iostream>

bool bigger(int a, int b, int& big) {
    if (a == b) {
        big = a;
        return true;
    }

    if (a > b) {
        big = a;
    } else {
        big = b;
    }

    return false;
}

int main() {
    int a, b, big;
    std::cout << "숫자 입력 :";
    std::cin >> a >> b;

    if (bigger(a, b, big)) {
        std::cout << "숫자가 같습니다!" << std::endl;
    } else {
        std::cout << big << std::endl;
    }

    return EXIT_SUCCESS;
}