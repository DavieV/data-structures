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
