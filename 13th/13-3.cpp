#include <iostream>

using namespace std;

int getExp(int base, int exp) {
    if (base <= 0 || exp <= 0) {
        throw "Cannot calculate exponential";
    }

    int value = 1;

    for (int n = 0; n < exp; ++n) {
        value = value * base;
    }

    return value;
}

int main() {
    try
    {
        int v = getExp(2, 3);
        cout << "2^3 = " << v << endl;

        int e = getExp(2, -3);
        cout << "2^-3 = " << e << endl;
    }
    catch(const char* error)
    {
        cout << error << endl;
    }
}