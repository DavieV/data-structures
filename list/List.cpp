#include <iostream>

template <class T>
class List {
    public:
        List(T data);
        void add_node(T data);
        void display_list();
    private:
        Node<T> *head_;
};

template <class T>
List<T>::List(T data) {
    head_ = new Node<T>(data);
}

template <class T>
void List<T>::add_node(T data) {
    Node<T> *new_node = new Node<T>(data);
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
