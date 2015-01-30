#include "Node.hpp"

template <class T>
class Queue {
    private:
        Node<T>* front_;
        Node<T>* back_;
    public:
        Queue() : front_(), back_() {};
        Queue(T datum);
        ~Queue();
        void push(T datum);
        void push(Node<T>* node);
        void pop();
        T front();
        T back();
        bool empty() { return front_ == nullptr; }
};

template <class T>
Queue<T>::Queue(T datum) {
    front_ = new Node<T>(datum);
    back_ = front_;
}

template <class T>
Queue<T>::~Queue() {
    while (front_ != nullptr)
        pop();
}

template <class T>
void Queue<T>::push(T datum) {
    if (front_ == nullptr) {
        front_ = new Node<T>(datum);
        back_ = front_;
    } else {
        back_->next_ = new Node<T>(datum);
        back_ = back_->next_;
    }
}

template <class T>
void Queue<T>::push(Node<T>* node) {
    if (front_ == nullptr) {
        front_ = node;
        back_ = node;
    } else {
        back_->next = node;
        back_ = node;
    }
}

template <class T>
void Queue<T>::pop() {
    if (front_ == nullptr) {
        return;
    } else {
        Node<T>* tmp = front_;
        front_ = front_->next_;
        delete tmp;
        if (front_ == nullptr)
            back_ = nullptr;
    }
}

template <class T>
T Queue<T>::front() {
    return front_->datum_;
}

template <class T>
T Queue<T>::back() {
    return back_->datum_;
}
