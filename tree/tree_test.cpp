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

    t.print_inorder();
    t.print_preorder();
    t.print_postorder();
    return 0;
}
