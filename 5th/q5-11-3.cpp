//
// Created by Minseok Chu on 11/10/23.
//

#include <iostream>
#include <string>

class Book {
    std::string title;
    int price;
public:
    Book(std::string title, int price);

    void set(std::string title, int price);

    void show() { std::cout << title << ' ' << price << "원" << std::endl; }
};

Book::Book(std::string title, int price) {
    this->title = title;
    this->price = price;
}

void Book::set(std::string title, int price) {
    this->title = title;
    this->price = price;
}

int main() {
    Book cpp("명품C++", 10000);
    Book java = cpp;
    java.set("명품자바", 12000);
    cpp.show();
    java.show();

    return 0;
}