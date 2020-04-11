#include "btree.h"

int main() {
    NODE* root = new NODE(0);

    NODE* node1 = new NODE(1);
    root->lchild = node1;
    NODE* node2 = new NODE(2);
    root->rchild = node2;

    NODE* node3 = new NODE(3);
    node1->lchild = node3;
    NODE* node4 = new NODE(4);
    node1->rchild = node4;

    BTree tree(root);

    std::cout << "------ pre order ------" << std::endl;
    tree.PreOrder();
    std::cout << std::endl;

    std::cout << "------ in order  ------" << std::endl;
    tree.InOrder();
    std::cout << std::endl;

    std::cout << "------ post order -----" << std::endl;
    tree.PostOrder();
    std::cout << std::endl;

    std::cout << "------ in order no recursion -----" << std::endl;
    tree.InOrderNoRecursion();
    std::cout << std::endl;

    std::cout << "------ post order no recursion -----" << std::endl;
    tree.PostOrderNoRecursion();
    std::cout << std::endl;

    std::cout << "------ level order -----" << std::endl;
    tree.LevelOrder();
    std::cout << std::endl;
    
    return 0;
}
