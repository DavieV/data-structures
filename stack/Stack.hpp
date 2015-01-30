#include "Node.hpp"

template <class T>
class Stack {
    private:
        Node<T>* top_;
    public:
        Stack() : top_(nullptr) {};
        Stack(T datum);
        ~Stack();
        void push(T datum);
        void push(Node<T>* node);
        void pop();
        T top();
        bool empty() { return top_ == nullptr; }
};

template <class T>
Stack<T>::Stack(T datum) {
    top_ = new Node<T>(datum);
}

template <class T>
Stack<T>::~Stack() {
    while (top_ != nullptr)
        pop();
}

template <class T>
void Stack<T>::push(T datum) {
    Node<T>* node = new Node<T>(datum);
    node->next_ = top_;
    top_ = node;
}

template <class T>
void Stack<T>::push(Node<T>* node) {
    node->next_ = top_;
    top_ = node;
}

template <class T>
void Stack<T>::pop() {
    if (top_ == nullptr) {
        return;
    } else {
        Node<T>* tmp = top_;
        delete top_;
        top_ = tmp->next_;
    }
}

template <class T>
T Stack<T>::top() {
    return top_->datum_;
}
