#include <queue>
#include "rb_tree.h"

void inOrderCore(NODE* node) {
    if (node == NULL) return;
    inOrderCore(node->left);
    std::cout << node->data << " ";
    inOrderCore(node->right);
}

void levelOrderCore(NODE* node) {
    if (node == NULL) return;

    std::queue<NODE*> Q;
    Q.push(node);

    while (!Q.empty()) {
	NODE* tmp = Q.front();
	std::cout << tmp->data << " ";
	Q.pop();

	if (tmp->left != NULL) Q.push(tmp->left);
	if (tmp->right != NULL) Q.push(tmp->right);
    }
}

NODE* BSTInsert(NODE* root, NODE* node) {
    if (root == NULL) return node;

    if (node->data < root->data) {
	root->left = BSTInsert(root->left, node);
	root->left->parent = root;
    } else if (node->data > root->data) {
	root->right = BSTInsert(root->right, node);
	root->right->parent = root;
    }
    std::cout << ">>>" << root->data << "; left: ";
    if (root->left != NULL) std::cout << root->left->data << std::endl;
    return root;
}

RBTree::RBTree() {root = NULL;}
RBTree::~RBTree() {}

void RBTree::leftRotate(NODE* root, NODE* pt) {
    NODE* pt_right = pt->right;
    pt->right = pt_right->left;

    if (pt->right != NULL) pt->right->parent = pt;
    pt_right->parent = pt->parent;

    if (pt->parent == NULL) root = pt_right;
    else if (pt == pt->parent->left) pt->parent->left = pt_right;
    else pt->parent->right = pt_right;

    pt_right->left = pt;
    pt->parent = pt->right;
}

void RBTree::rightRotate(NODE* root, NODE* pt) {
    NODE* pt_left = pt->left;
    pt->left = pt_left->right;

    if (pt->left != NULL) pt->left->parent = pt;
    pt_left->parent = pt->parent;

    if (pt->parent == NULL) root = pt_left;
    else if (pt == pt->parent->left) pt->parent->left = pt_left;
    else pt->parent->right = pt_left;

    pt_left->right = pt;
    pt->parent = pt_left;
}

void RBTree::fixViolation(NODE* root, NODE* pt) {
    NODE* parent_pt = NULL;
    NODE* grand_parent_pt = NULL;

    while (pt != root && pt->color != BLACK && pt->parent->color == RED) {
	parent_pt = pt->parent;
	grand_parent_pt = pt->parent->parent;

	if (parent_pt == grand_parent_pt->left) {
	    NODE* uncle_pt = grand_parent_pt->right;

	    if (uncle_pt != NULL && uncle_pt->color == RED) {
		grand_parent_pt->color = RED;
		parent_pt->color = BLACK;
		uncle_pt->color = BLACK;
		pt = grand_parent_pt;
	    } else {
		if (pt == parent_pt->right) {
		    leftRotate(root, parent_pt);
		    pt = parent_pt;
		    parent_pt = pt->parent;
		}
		rightRotate(root, grand_parent_pt);
		std::swap(parent_pt->color, grand_parent_pt->color);
		pt = parent_pt;
	    }
	} else {
	    NODE* uncle_pt = grand_parent_pt->left;

	    if (uncle_pt != NULL && uncle_pt->color == RED) {
		grand_parent_pt->color = RED;
		parent_pt->color = BLACK;
		uncle_pt->color = BLACK;
		pt = grand_parent_pt;
	    } else {
		if (pt == parent_pt->left) {
		    rightRotate(root, parent_pt);
		    pt = parent_pt;
		    parent_pt = pt->parent;
		}
		leftRotate(root, grand_parent_pt);
		std::swap(parent_pt->color, grand_parent_pt->color);
		pt = parent_pt;
	    }
	}
    }
    root->color = BLACK;
}

void RBTree::insert(const int data) {
    NODE* pt = new NODE(data);
    root = BSTInsert(root, pt);
    fixViolation(root, pt);
}

void RBTree::inOrder() const {
    inOrderCore(root);
}

void RBTree::levelOrder() const {
    levelOrderCore(root);
}
