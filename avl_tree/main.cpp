#include "avl_tree.h"

int main() {
    NODE* root = NULL;

    root = insert(root, 9);
    root = insert(root, 5);
    root = insert(root, 10);
    root = insert(root, 0);
    root = insert(root, 6);
    root = insert(root, 11);
    root = insert(root, -1);
    root = insert(root, 1);
    root = insert(root, 2);

    preOrder(root);
    std::cout << std::endl;

    root = deleteNode(root, 10);
    preOrder(root);
    std::cout << std::endl;

    return 0;
}
