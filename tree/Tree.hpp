#include <iostream>
#include <queue>
#include "Node.hpp"

template <class T>
class Tree {
    private:
        Node<T>* root_;
    public:
        Tree() : root_(nullptr) {};
        Tree(T datum);
        ~Tree();

        //  ========== Search Functions ==========
        void insert(const T datum);
        Node<T>* search(T datum);
        Node<T>* search(Node<T>* root, T datum);
        Node<T>* successor(T datum);
        Node<T>* predecessor(T datum);

        void breadth_first();

        Node<T>* min() { return min(root_); }
        Node<T>* max() { return max(root_); }
        Node<T>* min(Node<T>* root);
        Node<T>* max(Node<T>* root);

        // ========== Utility Funtions ==========
        void print_inorder() const;
        void print_inorder(Node<T>* root) const;
        void print_preorder() const;
        void print_preorder(Node<T>* ) const;
        void print_postorder() const;
        void print_postorder(Node<T>* root) const;
        void kill_tree(Node<T>* root);
        size_t size() const;
        size_t size(Node<T>* root) const;
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
        Node<T>* pot_pred;
        while (*(*tmp) != datum) {
            if (tmp == nullptr)
                return nullptr;
            if (datum < *(*tmp)) {
                tmp = tmp->left();
            } else {
                pot_pred = tmp;
                tmp = tmp->right();
            }
        }
        if (tmp->left() != nullptr)
            return max(tmp->left());
        else
            return pot_pred;
    }
}

template <class T>
void Tree<T>::breadth_first() {
    std::queue<Node<T>*> q;
    q.push(root_);
    int next_row = 0;
    int current_row = 1;
    while (!q.empty()) {
        auto top = q.front();
        q.pop();
        if (top->left() != nullptr) {
            ++next_row;
            q.push(top->left());
        }
        if (top->right() != nullptr) {
            ++next_row;
            q.push(top->right());
        }
        --current_row;
        std::cout << top->datum() << " ";
        if (current_row == 0) {  // Row has been completed
            std::cout << std::endl;
            current_row = next_row;
            next_row = 0;
        }
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

// ==================== Print Functions ====================
template <class T>
void Tree<T>::print_inorder() const {
    print_inorder(root_);
    std::cout << "\n\n";
}

template <class T>
void Tree<T>::print_inorder(Node<T>* root) const {
    if (root == nullptr) return;  // Base case
    print_inorder(root->left());
    std::cout << *(*root) << " ";
    print_inorder(root->right());
}

template <class T>
void Tree<T>::print_preorder() const {
    print_preorder(root_);
    std::cout << "\n\n";
}

template <class T>
void Tree<T>::print_preorder(Node<T>* root) const {
    if (root == nullptr) return;
    std::cout << root->datum() << " ";
    print_preorder(root->left());
    print_preorder(root->right());
}

template <class T>
void Tree<T>::print_postorder() const {
    print_postorder(root_);
    std::cout << "\n\n";
}

template <class T>
void Tree<T>::print_postorder(Node<T>* root) const {
    if (root == nullptr) return;
    print_postorder(root->left());
    print_postorder(root->right());
    std::cout << root->datum() << " ";
}

template <class T>
void Tree<T>::kill_tree(Node<T>* root) {
    if (root == nullptr) { // Base case
        return;
    } else {
        kill_tree(root->left());
        kill_tree(root->right());
        delete root;
    }
}

template <class T>
size_t Tree<T>::size() const {
    return size(root_);
}

template <class T>
size_t Tree<T>::size(Node<T>* root) const {
    if (root == nullptr)
        return 0;
    else
        return 1 + size(root->left()) + size(root->right());
}
