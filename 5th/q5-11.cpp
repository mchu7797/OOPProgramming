//
// Created by minse on 2023-11-09.
//

#include <iostream>
#include <cstring>

class Book {
    char *title;
    int price;
public:
    Book(const char *title, int price);

    Book(Book& book);

    ~Book();

    void set(char *title, int price);

    void show() { std::cout << title << ' ' << price << "원" << std::endl; }
};

// 11-1번 문제 해답 (생성자, 소멸자, set() 구현)
Book::Book(const char *title, int price) {
    this->title = new char[strlen(title)];
    strcpy(this->title, title);

    this->price = price;
}

Book::~Book() {
    delete[] this->title;
}

void Book::set(char *title, int price) {
    if (this->title != NULL) {
        delete[] this->title;
    }

    this->title = new char[strlen(title)];
    strcpy(this->title, title);

    this->price = price;
}

// 11-2번 문제 해답 (디폴트 복사 생성자의 코드)
Book::Book(Book& book) {
    this->title = book.title;
    this->price = book.price;
}


int main() {
    Book cpp("명품C++", 10000);
    Book java = cpp;
    java.set("명품자바", 12000);
    cpp.show();
    java.show();
    return 0;
}