#include <stack>
#include <queue>
#include "btree.h"

void BTree::PreOrder() const {
    __PreOrderCore(root);
}

void BTree::__PreOrderCore(const NODE* const p) const {
    if (!p) return;
    __Visit(p);
    __PreOrderCore(p->lchild);
    __PreOrderCore(p->rchild);
}

void BTree::InOrder() const {
    __InOrderCore(root);
}

void BTree::__InOrderCore(const NODE* const p) const {
    if (!p) return;
    __InOrderCore(p->lchild);
    __Visit(p);
    __InOrderCore(p->rchild);
}

void BTree::PostOrder() const {
    __PostOrderCore(root);
}

void BTree::__PostOrderCore(const NODE* const p) const {
    if (!p) return;
    __PostOrderCore(p->lchild);
    __PostOrderCore(p->rchild);
    __Visit(p);
}

void BTree::InOrderNoRecursion() const {
    std::stack<NODE*> s;
    NODE* p = root;

    while (p || !s.empty()) {
	if (p) {
	    s.push(p);
	    p = p->lchild;
	} else {
	    p = s.top();
	    __Visit(p);
	    s.pop();
	    p = p->rchild;
	}
    }
}

void BTree::PostOrderNoRecursion() const {
    std::stack<NODE*> s;
    NODE* p = root;
    NODE* r = NULL;

    while (p || !s.empty()) {
	if (p) {
	    s.push(p);
	    p = p->lchild;
	} else {
	    p = s.top();
	    if (p->rchild && p->rchild != r) {
		p = p->rchild;
		s.push(p);
		p = p->lchild;
	    } else {
		__Visit(p);
		s.pop();
		r = p;
		p = NULL;
	    }
	}
    }
}

void BTree::LevelOrder() const {
    std::queue<NODE*> Q;
    NODE* p = NULL;
    Q.push(root);

    while (!Q.empty()) {
	p = Q.front();
	Q.pop();
	__Visit(p);
	if (p->lchild) Q.push(p->lchild);
	if (p->rchild) Q.push(p->rchild);
    }
}
