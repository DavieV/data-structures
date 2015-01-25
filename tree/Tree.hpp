#include "Node.hpp"
#include <iostream>

template <class T>
class Tree {
    private:
        Node<T>* root_;
    public:
        Tree() { root_ = nullptr; }
        Tree(T datum);
        ~Tree();

        //  ========== Search Functions ==========
        void insert(const T datum);
        Node<T>* search(T datum);
        Node<T>* search(Node<T>* root, T datum);
        Node<T>* successor(T datum);
        Node<T>* predecessor(T datum);

        Node<T>* min() { return min(root_); }
        Node<T>* max() { return max(root_); }
        Node<T>* min(Node<T>* root);
        Node<T>* max(Node<T>* root);

        // ========== Utility Funtions ==========
        void print() const;
        void print_inorder(Node<T>* node) const;
        void kill_tree(Node<T>* node);
};

template <class T>
Tree<T>::Tree(T datum) {
    root_ = new Node<T>(datum);
}

template <class T>
Tree<T>::~Tree() {
    if (root_ == nullptr) {
        delete root_;
    } else {
        kill_tree(root_);
    }
}

template <class T>
void Tree<T>::insert(T datum) {
    Node<T>* new_node = new Node<T>(datum);
    if (root_ == nullptr) {
        root_ = new_node;
    } else {
        Node<T>* tmp = root_;
        while (new_node->parent() == nullptr) {
            if (*(*new_node) > *(*tmp)) {
                if (tmp->right() == nullptr) {
                    tmp->set_right(new_node);
                    new_node->set_parent(tmp);
                } else {
                    tmp = tmp->right();
                }
            } else {
                if (tmp->left() == nullptr) {
                    tmp->set_left(new_node);
                    new_node->set_parent(tmp);
                } else {
                    tmp = tmp->left();
                }
            }
        }
    }
}

template <class T>
Node<T>* Tree<T>::search(T datum) {
    if (root_ == nullptr)
        return nullptr;
    else
        return search(root_, datum);
}

template <class T>
Node<T>* Tree<T>::search(Node<T>* root, T datum) {
    if (root == nullptr) {
        return nullptr;
    } else {
        if (datum == *(*root))
            return root;
        else if (datum > *(*root))
            return search(root->right(), datum);
        else
            return search(root->left(), datum);
    }
}

/*
    Returns a pointer to the node with the next highest datum value in the tree
*/
template <class T>
Node<T>* Tree<T>::successor(T datum) {
    if (root_ == nullptr) {
        return nullptr;
    } else {
        Node<T>* tmp = root_;
        Node<T>* pot_succ;
        while (*(*tmp) != datum) {
            if (tmp == nullptr)
                return nullptr;
            if (datum > *(*tmp)) {
                tmp = tmp->right();
            } else {
                pot_succ = tmp;
                tmp = tmp->left();
            }
        }
        if (tmp->right() != nullptr)
            return min(tmp->right());
        else
            return pot_succ;
    }
}

/*
    Returns a pointer to the node with the next lowest datum value in the tree
*/
template <class T>
Node<T>* Tree<T>::predecessor(T datum) {
    if (root_ == nullptr) {
        return nullptr;
    } else {
        Node<T>* tmp = root_;
        Node<T>* pot_succ;
        while (*(*tmp) != datum) {
            if (tmp == nullptr)
                return nullptr;
            if (datum < *(*tmp)) {
                tmp = tmp->left();
            } else {
                pot_succ = tmp;
                tmp = tmp->right();
            }
        }
        if (tmp->left() != nullptr)
            return max(tmp->left());
        else
            return pot_succ;
    }
}

/*
    Find the node with the lowest datum value, rooted at a specific subtree
*/
template <class T>
Node<T>* Tree<T>::min(Node<T>* root) {
    if (root == nullptr)
        return nullptr;
    while (root->left() != nullptr)
        root = root->left();
    return root;
}

/*
    Find the node with the highst datum value, rooted at a specific subtree
*/
template <class T>
Node<T>* Tree<T>::max(Node<T>* root) {
    if (root == nullptr)
        return nullptr;
    while (root->right() != nullptr)
        root = root->right();
    return root;
}

template <class T>
void Tree<T>::print() const {
    print_inorder(root_);
}

template <class T>
void Tree<T>::print_inorder(Node<T>* node) const {
    if (node == nullptr) return;  // Base case
    print_inorder(node->left());
    std::cout << *(*node) << std::endl;
    print_inorder(node->right());
}

template<class T>
void Tree<T>::kill_tree(Node<T>* node) {
    if (node == nullptr) { // Base case
        delete node;
    } else {
        kill_tree(node->left());
        kill_tree(node->right());
        delete node;
    }
}
