#ifndef DV_STACK
#define DV_STACK

#include <memory>
#include "Node.hpp"

template <class T>
class Stack {
 public:
  void push(const T& datum);
  void pop() { top_ = std::move(top_->next_); }
  const T& top() const { return top_->datum_; }
  bool empty() const { return top_ == nullptr; }

 private:
  std::unique_ptr<Node<T>> top_;
};

template <class T>
void Stack<T>::push(const T& datum) {
  if (!top_) {
    top_ = std::make_unique<Node<T>>(datum);
  } else {
    auto new_top = std::make_unique<Node<T>>(datum);
    new_top->next_ = std::move(top_);
    top_ = std::move(new_top);
  }
}

#endif /* ifndef DV_STACK */
