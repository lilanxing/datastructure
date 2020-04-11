#include "chain.h"

template <class T>
Chain<T>::Chain() {
    first = 0;
}

template <class T>
Chain<T>::~Chain() {
    ChainNode<T>* next;
    while (first) {
	next = first->link;
	delete first;
	first = next;
    }
}

template <class T>
int Chain<T>::Length() const {
    ChainNode<T>* current = first;
    int len = 0;
    while (current) {
	++len;
	current == current->link;
    }
    return len;
}

template <class T>
bool Chain<T>::Find(const int k, T& x) const {
    if (k < 1) return false;
    ChainNode<T>* current = first;
    int index = 1;
    while (index < k && current) {
	current = current->link;
	++index;
    }
    if (current) {
	x = current->data;
	return true;
    }
    return false;
}

template <class T>
int Chain<T>::Search(const T& x) const {
    ChainNode<T>* current = first;
    int index = 1;
    while (current && current->data != x) {
	current = current->link;
	++index;
    }
    if (current) return index;
    return 0;
}

template <class T>
Chain<T>& Chain<T>::Delete(const int k, T& x) {
    if (k < 1 || !first) throw "out of bounds";

    ChainNode<T>* p = first;
    if (k == 1) first = first->link;
    else {
	ChainNode<T>* q = first;
	for (int i = 1; i < k - 1 && q; ++i) q = q->link;
	if (!q || !q->link) throw "out of bounds";
	p = q->link;
	q->link = p->link;
    }

    x = p->data;
    delete p;
    
    return *this;
}

template <class T>
Chain<T>& Chain<T>::Insert(const int k, const T& x) {
    if (k < 0) throw "out of bounds";

    ChainNode<T>* p = first;
    for (int i = 1; i < k && p; ++i) p = p->link;
    if (k > 0 && !p) throw "out of bounds";

    ChainNode<T>* y = new ChainNode<T>;
    y->data = x;
    if (k) {
	y->link = p->link;
	p->link = y;
    } else {
	y->link = first;
	first = y;
    }
    
    return *this;
}

template <class T>
void Chain<T>::Output(std::ostream& out) const {
    ChainNode<T>* current;
    for (current = first; current; current = current->link) {
	out << current->data << " ";
    }
}
