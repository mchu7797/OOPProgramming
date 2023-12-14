#include <iostream>
#include <string>

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

int main() {
    MyStack<int> stack_one;
    stack_one.push(3);
    std::cout << stack_one.pop() << std::endl;

    MyStack<double> stack_two;
    stack_two.push(3.5);
    std::cout << stack_two.pop() << std::endl;

    MyStack<char> *stack_three;
    stack_three->push('A');
    std::cout << stack_three->pop() << std::endl;

    delete stack_three;
}