#include <iostream>
#include <string>
#include "List.hpp"

int main() {
    List<std::string> *mylist = new List<std::string>();
    std::string tmp;
    for (int i = 0; i < 5; ++i) {
        std::cin >> tmp;
        mylist->add(tmp);
    }
    mylist->print_list();
    return 0;
}
