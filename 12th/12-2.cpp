//
// Created by Minseok Chu on 2023-10-29.
//

#include <iostream>
#include <fstream>

using namespace std;

int main(void) {
    ifstream student_file;
    student_file.open("student-info.txt");

    if (!student_file) {
        cout << "파일을 열 수 없습니다!";
        return EXIT_FAILURE;
    }

    char name[10];
    char major[20];
    int student_id;

    student_file >> name;
    student_file >> student_id;
    student_file >> major;

    cout << name << endl;
    cout << student_id << endl;
    cout << major << endl;

    return EXIT_SUCCESS;
}