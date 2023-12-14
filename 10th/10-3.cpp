#include <iostream>

template <class T>
class MyStack {
    int topOfStack;
    T data[100];
public:
    MyStack();
    void push(T element);
    T pop();
};

template <class T>
MyStack<T>::MyStack() {
    topOfStack = -1;
}

template <class T>
void MyStack<T>::push(T element) {
    if (this->topOfStack == 99) {
        std::cout << "Stack Full!" << std::endl;
        return;
    }

    ++this->topOfStack;
    data[this->topOfStack] = element;
}

template <class T>
T MyStack<T>::pop() {
    T result;

    if (this->topOfStack == -1) {
        std::cout << "Stack Empty!" << std::endl;
        return 0;
    }

    result = data[this->topOfStack--];

    return result;
}

class Point {
    int x, y;
public:
    Point(int x=0, int y=0) { this->x = x; this->y = y; }
    void Show() { std::cout << x << ", " << y << std::endl; }
};

int main() {
    MyStack<int*> intPointerStack;
    int* p = new int[3];

    for (int i = 0; i < 3; ++i) {
        *(p + i) = i * 10;
    }

    intPointerStack.push(p);
    int* q = intPointerStack.pop();

    for (int i = 0; i < 3; ++i) {
        std::cout << *(q + i) << ' ';
    }

    std::cout << std::endl;

    delete []p;

    MyStack<Point> pointStack;
    Point a(2, 3), b;

    pointStack.push(a);
    b = pointStack.pop();
    b.Show();

    MyStack<std::string> stringStack;
    std::string s = "C++";

    stringStack.push(s);
    stringStack.push("Java");

    std::cout << stringStack.pop() << ' ';
    std::cout << stringStack.pop() << std::endl;
}