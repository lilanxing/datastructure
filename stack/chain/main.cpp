#include <iostream>
#include "chain_stack.h"

int main() {
    ChainStackInt s;
    for (int i = 0; i < 5; ++i) s.Push(i);

    int x;
    while (!s.IsEmpty()) {
	s.Pop(x);
	std::cout << x << std::endl;
    }
    
    return 0;
}
