//
// Created by Minseok Chu on 10/31/23.
//

#include <iostream>

using namespace std;

int main() {
    cout << "i" << '\t' << "n" << '\t' << "ref_n" << endl;
    int i = 1;
    int n = 2;
    int &ref_n = n;
    n = 4;
    ref_n++;
    cout << i << '\t' << n << '\t' << ref_n << endl;

    ref_n = i;
    ref_n++;
    cout << i << '\t' << n << '\t' << ref_n << endl;

    int *p = &ref_n;
    *p = 20;
    cout << i << '\t' << n << '\t' << ref_n << endl;
}