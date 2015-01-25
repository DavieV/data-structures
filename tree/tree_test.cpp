#include <iostream>
#include <string>
#include "Tree.hpp"

int main()
{
    Tree<int> t;

    t.insert(10);
    t.insert(5);
    t.insert(20);
    t.insert(15);
    t.insert(11);
    t.insert(12);

    // t.print();

    Node<int>* succ = t.successor(12);
    Node<int>* pred = t.predecessor(15);

    std::cout << succ->datum() << std::endl;
    std::cout << pred->datum() << std::endl;

    return 0;
}
