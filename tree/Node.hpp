template <class T>
class Node {
    private:
        T datum_;
        Node<T>* left_;
        Node<T>* right_;
        Node<T>* parent_;
    public:
        Node(T datum_);

        // ========== Get Functions ==========
        T datum() { return datum_; }
        Node<T>* left() { return left_; }
        Node<T>* right() { return right_; }
        Node<T>* parent() { return parent_; }

        // ========== Set Functions ==========
        void set_datum(T datum_) { this.datum_ = datum_; }
        void set_left(Node<T>* node) { left_ = node; }
        void set_right(Node<T>* node) { right_ = node; }
        void set_parent(Node<T>* node) { parent_ = node; }

        T operator *() const;
};

template <class T>
Node<T>::Node(T datum_) {
    this->datum_ = datum_;
    left_ = nullptr;
    right_ = nullptr;
}

template <class T>
T Node<T>::operator *() const {
    return datum_;
}
