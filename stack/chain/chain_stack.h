#ifndef CHAIN_STACK_H
#define CHAIN_STACK_H

#include <iostream>

typedef struct Node {
    int data;
    struct Node* prior;
    struct Node* next;

    Node(const int x) {data = x; next = NULL; prior = NULL;}
} NODE;

class ChainStackInt {
public:
    ChainStackInt() {
	top = NULL;
	length = 0;
    }
    ~ChainStackInt() {
	Clear();
    }

    inline bool IsEmpty() const {
	return top == NULL;
    }
    inline int Length() const { return length; }
    inline int Top() const { return top->data; }

    ChainStackInt& Push(const int x) {
	NODE* node = new NODE(x);
	if (IsEmpty()) top = node;
	else {
	    node->prior = top;
	    top->next = node;
	    top = node;
	}
	++length;
	return *this;
    }

    ChainStackInt& Pop(int& x) {
	if (!IsEmpty()) {
	    x = top->data;
	    top = top->prior;
	    if (top) delete top->next;
	    --length;
	}
	return *this;
    }

    void Clear() {
	while (top) {
	    NODE* p = top;
	    top = p->prior;
	    delete p;
	}
    }
    
private:
    NODE* top;
    int   length;
};

#endif
