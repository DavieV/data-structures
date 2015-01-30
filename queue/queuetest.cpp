#include <iostream>
#include "Queue.hpp"

int main() {
    Queue<int> q;
    q.push(5);
    q.push(10);
    q.push(15);

    std::cout << q.front() << std::endl;
    std::cout << q.back() << std::endl;

    q.pop();

    std::cout << q.front() << std::endl;

    return 0;
}
