#include "linear_stack.cpp"

int main() {
    LinearStack<int> s(5);

    try {
	for (int i = 0; i < 6; ++i) s.Push(i);
    } catch (char const* str) {
	std::cout << str << std::endl;
    }
    
    s.Output();
    std::cout << s.Length() << std::endl;

    int x;
    for (int i = 0; i < 5; ++i) {
	s.Pop(x);
	std::cout << x << " poped" << std::endl;
    } 
    s.Output();
    std::cout << s.Length() << std::endl;
    
    return 0;
}
