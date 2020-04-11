#include <iostream>
#include "b_tree.h"

int main() {
    BTree tree(3);
    tree.insert(10);
    tree.insert(20);
    tree.insert(5);
    tree.insert(6);
    tree.insert(12);
    tree.insert(30);
    tree.insert(7);
    tree.insert(17);

    tree.traverse();

    tree.search(6) != NULL ? std::cout << "\n6 present\n" : std::cout << "\n6 not present\n";
    tree.search(15) != NULL ? std::cout << "\n15 present\n" : std::cout << "\n15 not present\n";
}
