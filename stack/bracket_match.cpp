#include <iostream>
#include <map>
#include <stack>

std::map<char, char> bracket_left_map = {
    {'(', ')'},
    {'[', ']'}
};

std::map<char, char> bracket_right_map = {
    {')', '('},
    {']', '['}
};

bool Match(const std::string& brackets) {
    std::stack<int> s;

    for (int i = 0; i < brackets.size(); ++i) {
	if (bracket_left_map[brackets[i]] != '\0') s.push(brackets[i]);
	if (bracket_right_map[brackets[i]] != '\0') {
	    if (s.top() != bracket_right_map[brackets[i]]) return false;
	    s.pop();
	}
    }
    
    return s.empty();
}

int main() {
    std::string s = "([()])";
    std::cout << Match(s) << std::endl;

    s = "([][])";
    std::cout << Match(s) << std::endl;

    s = "[))]";
    std::cout << Match(s) << std::endl;
    
    return 0;
}
