#include <iostream>
#include "llist.h"

template <class T>
LinearList<T>::LinearList(const int max_size) {
    this->max_size = max_size;
    length = 0;
    element = new T(max_size);
}

template <class T>
LinearList<T>::~LinearList() {
    delete [] element;
}

template <class T>
bool LinearList<T>::IsEmpty() const {
    return length == 0;
}

template <class T>
int LinearList<T>::Length() const {
    return length;
}

template <class T>
bool LinearList<T>::Find(const int k, T& x) const {
    if (k < 1 || k > length) return false;
    x = element[k - 1];
    return true;
}

template <class T>
int LinearList<T>::Search(const T& x) const {
    for (int i = 0; i < length; ++i) {
	if (element[i] == x) return i + 1;
    }
    return 0;
}

template <class T>
LinearList<T>& LinearList<T>::Delete(const int k, T& x) {
    if (!Find(k, x)) throw "out of bounds";
    for (int i = k; i < length; ++i) element[i - 1] = element[i];
    --length;
    return *this;
}

template <class T>
LinearList<T>& LinearList<T>::Insert(const int k, const T& x) {
    if (k < 0 || k > length) throw "out of bounds";
    if (length == max_size) throw "no mem";
    for (int i = length - 1; i >= k; --i) element[i + 1] = element[i];
    element[k] = x;
    ++length;
    return *this;
}

template <class T>
void LinearList<T>::Output(std::ostream& out) const {
    for (int i = 0; i < length; ++i) out << element[i] << "";
}
