#include <iostream>
#include "chain.cpp"

int main() {
    Chain<int> L;
    L.Insert(0, 1);
    std::cout << L << std::endl;
    return 0;
}
