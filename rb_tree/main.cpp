#include "rb_tree.h"

int main() {
    RBTree tree;

    tree.insert(7);
    tree.insert(6);
    tree.insert(5);
    tree.insert(4);
    tree.insert(3);
    tree.insert(2);
    tree.insert(1);

    tree.inOrder();
    std::cout << std::endl;
    tree.levelOrder();
    std::cout << std::endl;

    std::cout << "==================" << std::endl;
    std::cout << tree.root->left->data << std::endl;
    
    return 0;
}
