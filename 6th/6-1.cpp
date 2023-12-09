/*
 * Created by Minseok Chu on 2023-12-09.
 */

#include <iostream>

int big(int a, int b) {
    return a > b ? a : b;
}

int big(int a[], int size) {
    int result = a[0];

    for (int i = 0; i < size; ++i) {
        result = result < a[i] ? a[i] : result;
    }

    return result;
}

int main() {
    int array[5] = {1, 9, -2, 8, 6};

    std::cout << big(2, 3) << std::endl;
    std::cout << big(array, 5) << std::endl;
}