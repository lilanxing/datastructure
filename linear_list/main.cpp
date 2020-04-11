#include <iostream>
#include "llist.h"

int main() {
    try {
	LinearList<int> L(5);
	std::cout << "Length = " << L.Length() << std::endl;
	std::cout << "IsEmpty = " << L.IsEmpty() << std::endl;
	L.Insert(0, 2).Insert(1, 6);
	std::cout << "List is " << L << std::endl;
	std::cout << "IsEmpty = " << L.IsEmpty() << std::endl;
    } catch (...) {
	std::cout << "catch err" << std::endl;
    }
    
    return 0;
}
