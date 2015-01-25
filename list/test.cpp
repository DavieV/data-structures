#include <iostream>
#include <string>
// #include "Node.cpp"
// #include "List.cpp"

template <class T>
class Node {
    public:
        Node(T data);
        T data_;
        Node<T> *next_;
};

template <class T>
Node<T>::Node(T data) {
    data_ = data;
    next_ = nullptr;
}

template <class T>
class List {
    public:
        List();
        List(T data);
        void add_node(T data);
        void display_list();
    private:
        Node<T> *head_;
};

template <class T>
List<T>::List() {
    head_ = nullptr;
}

template <class T>
List<T>::List(T data) {
    head_ = new Node<T>(data);
}

template <class T>
void List<T>::add_node(T data) {
    Node<T> *new_node = new Node<T>(data);
    if (head_ == nullptr) {
        head_ = new_node;
        return;
    }
    Node<T> *tmp = head_;
    while (tmp->next_ != nullptr) {
        tmp = tmp->next_;
    }
    tmp->next_ = new_node;
}

template <class T>
void List<T>::display_list() {
    Node<T> *tmp = head_;
    while (tmp != nullptr) {
        std::cout << tmp->data_ << std::endl;
        tmp = tmp->next_;
    }
}


int main() {
    List<std::string> *mylist = new List<std::string>();
    std::string tmp;
    for (int i = 0; i < 5; ++i) {
        std::cin >> tmp;
        mylist->add_node(tmp);
    }
    mylist->display_list();
    return 0;
}
