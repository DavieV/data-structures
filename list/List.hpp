#include <iostream>
#include <memory>

#include "Node.hpp"

template <class T>
class List {
 public:
  List(const T& data) : head_(std::make_unique<Node<T>>(data)) {}
  List() = default;

  void add(const T& data);
  void print_list();

 private:
  std::unique_ptr<Node<T>> head_;
};

template <class T>
void List<T>::add(const T& data) {
  auto new_node = std::make_unique<Node<T>>(data);
  if (!head_) {
    head_ = std::move(new_node);
  } else {
    Node<T>* tmp = head_.get();
    while (tmp->next_) {
      tmp = tmp->next_.get();
    }
    tmp->next_ = std::move(new_node);
  }
}

template <class T>
void List<T>::print_list() {
  Node<T>* tmp = head_.get();
  while (tmp) {
    std::cout << tmp->data_ << std::endl;
    tmp = tmp->next_.get();
  }
}
