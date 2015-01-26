#include <iostream>
#include "Node.hpp"

template <class T>
class List {
    private:
        Node<T>* head_;
    public:
        List() { head_ = nullptr; }
        List(T data);
        void add(T data);
        void print_list();
};

template <class T>
List<T>::List(T data) {
    head_ = new Node<T>(data);
}

template <class T>
void List<T>::add(T data) {
    Node<T>* new_node = new Node<T>(data);
    if (head_ == nullptr) {
        head_ = new_node;
    } else {
        Node<T> *tmp = head_;
        while (tmp->next_ != nullptr) {
            tmp = tmp->next_;
        }
        tmp->next_ = new_node;
    }
}

template <class T>
void List<T>::print_list() {
    Node<T> *tmp = head_;
    while (tmp != nullptr) {
        std::cout << tmp->data_ << std::endl;
        tmp = tmp->next_;
    }
}
