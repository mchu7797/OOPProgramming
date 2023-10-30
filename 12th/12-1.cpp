//
// Created by Minseok Chu on 2023-10-29.
//

#include <iostream>
#include <fstream>

using namespace std;

int main() {
    char name[10], major[20];
    int sid;

    cout << "NAME :";
    cin >> name;
    cout << "STUDENT_NUMBER :";
    cin >> sid;
    cout << "MAJOR :";
    cin >> major;

    ofstream student_file("student-info.txt");
    if (!student_file) {
        cout << "student-info.txt 파일을 열 수 없습니다!";
        return EXIT_FAILURE;
    }

    student_file << name << " ";
    student_file << sid << " ";
    student_file << major << endl;

    student_file.close();

    return EXIT_SUCCESS;
}