template <class T>
class Node {
    public:
        Node() : datum_() {};
        Node(T datum);
        T datum_;
        Node<T> *next_;
};

template <class T>
Node<T>::Node(T datum) {
    datum_ = datum;
    next_ = nullptr;
}
