#ifndef AVL_TREE_H
#define AVL_TREE_H

#include <iostream>

typedef struct Node {
    int data;
    int height;
    struct Node* left;
    struct Node* right;

    Node(const int _data) {
	data = _data;
	height = 1;
	left = right = NULL;
    }
} NODE;

int max(const int a, const int b) {
    return a > b ? a : b;
}

int height(const NODE* const N) {
    if (N == NULL) return 0;
    return N->height;
}

int getBalance(const NODE* const N) {
    if (N == NULL) return 0;
    return height(N->left) - height(N->right);
}

NODE* rightRotate(NODE* y) {
    NODE* x = y->left;
    NODE* x_right = x->right;

    x->right = y;
    y->left = x_right;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

NODE* leftRotate(NODE* x) {
    NODE* y = x->right;
    NODE* y_left = y->left;

    y->left = x;
    x->right = y_left;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

NODE* insert(NODE* node, const int key) {
    if (node == NULL) return new NODE(key);

    if (key < node->data) {
	node->left = insert(node->left, key);
    } else if (key > node->data) {
	node->right = insert(node->right, key);
    } else {
	return node;
    }
    node->height = max(height(node->left), height(node->right)) + 1;

    int balance = getBalance(node);
    if (balance > 1 && key < node->left->data) {
	return rightRotate(node);
    }
    if (balance < -1 && key > node->right->data) {
	return leftRotate(node);
    }
    if (balance > 1 && key > node->left->data) {
	node->left = leftRotate(node->left);
	return rightRotate(node);
    }
    if (balance < -1 && key < node->right->data) {
	node->right = rightRotate(node->right);
	return leftRotate(node);
    }

    return node;
}

NODE* minNode(NODE* node) {
    NODE* cur = node;
    while (cur->left != NULL) cur = cur->left;
    return cur;
}

NODE* deleteNode(NODE* node, const int key) {
    if (node == NULL) return node;

    if (key < node->data) node->left = deleteNode(node->left, key);
    else if (key > node->data) node->right = deleteNode(node->right, key);
    else {
	if (node->left || node->right == NULL) {
	    NODE* tmp = node->left != NULL ? node->left : node->right;
	    if (tmp == NULL) {
		tmp = node;
		node = NULL;
	    } else {
		*node = *tmp;
	    }
	    delete tmp;
	} else {
	    NODE* tmp = minNode(node->right);
	    node->data = tmp->data;
	    node->right = deleteNode(node->right, tmp->data);
	}
    }

    if (node == NULL) return node;

    node->height = max(height(node->left), height(node->right)) + 1;
    int balance = getBalance(node);
    if (balance > 1 && getBalance(node->left) >= 0) {
	return rightRotate(node);
    }
    if (balance > 1 && getBalance(node->left) < 0) {
	node->left = leftRotate(node->left);
	return rightRotate(node);
    }
    if (balance < -1 && getBalance(node->right) <= 0) {
	return leftRotate(node);
    }
    if (balance < -1 && getBalance(node->right) > 0) {
	node->right = rightRotate(node->right);
	return leftRotate(node);
    }
    return node;
}

void preOrder(const NODE* const N) {
    if (N != NULL) {
	std::cout << N->data << " ";
	preOrder(N->left);
	preOrder(N->right);
    }
}

#endif
