#ifndef RB_TREE_H
#define RB_TREE_H

#include <iostream>

enum COLOR {RED, BLACK};

typedef struct Node {
    int data;
    int color;
    struct Node* left;
    struct Node* right;
    struct Node* parent;

    Node(const int _data) {
	data = _data;
	left = right = parent = NULL;
	color = RED;
    }
} NODE;

class RBTree {
public:
    RBTree();
    ~RBTree();

    void insert(const int data);
    void inOrder() const;
    void levelOrder() const;

protected:
    void leftRotate(NODE* root, NODE* node);
    void rightRotate(NODE* root, NODE* node);
    void fixViolation(NODE* root, Node* node);
    
public:
    NODE* root;
};

#endif
