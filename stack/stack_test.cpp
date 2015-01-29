#include "Stack.hpp"
#include <iostream>
#include <stack>

int main() {
    Stack<int> s;

    s.push(5);
    std::cout << s.top() << std::endl;
    s.push(10);
    std::cout << s.top() << std::endl;

    s.pop();
    s.pop();

    if (!s.empty()) {
        std::cout << s.top() << std::endl;
    } else {
        std::cout << "Stack is empty" << std::endl;
    }

    return 0;
}
