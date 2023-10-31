//
// Created by Minseok Chu on 10/31/23.
//

#include <iostream>

using namespace std;

int swap(int *a, int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;

}

int main() {
    int a, b;
    a = 9;
    b = 4;
    cout << a << " " << b << endl;
    swap(&a, &b);
    cout << a << " " << b << endl;
}