#include <iostream>
#include "linear_stack.h"

// cap: how many elements the stack will be hold.
template <class T>
LinearStack<T>::LinearStack(const int cap) {
    top = -1;
    this->cap = cap;
    data = new T(cap);
}

template <class T>
LinearStack<T>::~LinearStack() {
    if (data) {
	std::cout << "~ begin" << std::endl;
	delete [] data;
    }
}

template <class T>
bool LinearStack<T>::IsEmpty() const {
    return top == -1;
}

template <class T>
LinearStack<T>& LinearStack<T>::Push(const T& x) {
    if (this->Length() >= cap) throw "stack is full";
    data[++top] = x;
    return *this;
}

template <class T>
LinearStack<T>& LinearStack<T>::Pop(T& x) {
    if (this->IsEmpty()) throw "stack is empty";
    x = data[top--];
    return *this;
}

template <class T>
LinearStack<T>& LinearStack<T>::Clear() {
    top = -1;
    return *this;
}

template <class T>
const T& LinearStack<T>::Top() const {
    if (this->IsEmpty()) throw "stack is empty";
    return data[top];
}

template <class T>
void LinearStack<T>::Output() const {
    for (int i = top; i >= 0; --i) std::cout << data[i] << " ";
    std::cout << std::endl;
}

template <class T>
int LinearStack<T>::Length() const {
    return top + 1;
}
