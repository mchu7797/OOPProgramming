#include <iostream>

using namespace std;

int getExp(int base, int exp) {
    if (base <= 0 || exp <= 0) {
        return -1;
    }

    int value = 1;

    for (int n = 0; n < exp; ++n) {
        value = value * base;
    }

    return value;
}

int main() {
    int v = getExp(2, 3);
    
    if (v >= 0) {
        cout << "2^3 = " << v << endl;
    } else {
        cout << "Cannot calculate 2^3" << endl;
    }

    int e = getExp(2, -3);
    
    if (e >= 0) {
        cout << "2^-3 = " << e << endl;
    } else {
        cout << "Cannot calculate 2^-3" << endl;
    }
}