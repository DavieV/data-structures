#include <iostream>
#include <string>
#include "Tree.hpp"

int main() {
    Tree<int> t;

    t.insert(10);
    t.insert(5);
    t.insert(20);
    t.insert(15);
    t.insert(11);
    t.insert(12);

    std::cout << t.size() << std::endl;

    return 0;
}
