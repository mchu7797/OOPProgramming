#include <iostream>

int sum(int a, int b) {
    int result = 0;

    for (int i = a; i <= b; ++i) {
        result += i;
    }

    return result;
}

int sum(int a) {
    int result = 0;

    for (int i = 0; i <= a; ++i) {
        result += i;
    }

    return result;
}

int main() {
    std::cout << sum(3, 5) << std::endl;
    std::cout << sum(3) << std::endl;
    std::cout << sum(100) << std::endl;
}