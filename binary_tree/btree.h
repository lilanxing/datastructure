#ifndef BTREE_H
#define BTREE_H

#include <iostream>

typedef struct Node {
    int data;
    struct Node* lchild;
    struct Node* rchild;

    Node(const int x) {
	data = x;
	lchild = rchild = NULL;
    };
} NODE;

class BTree {
public:
    BTree(NODE* p) { root = p; }
    void PreOrder() const;
    void InOrder() const;
    void PostOrder() const;

    void InOrderNoRecursion() const;
    void PostOrderNoRecursion() const;
    void LevelOrder() const;

private:
    inline void __Visit(const NODE* const p) const { std::cout << p->data << std::endl; };
    void __PreOrderCore(const NODE* const p) const;
    void __InOrderCore(const NODE* const p) const;
    void __PostOrderCore(const NODE* const p) const;

private:
    NODE* root;
};

#endif
