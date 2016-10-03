#ifndef DV_STACK_NODE
#define DV_STACK_NODE

#include <memory>

template <typename T>
class Stack;

template <class T>
class Node {
 public:
  friend class Stack<T>;
  Node(const T& datum) : datum_(datum){};

 private:
  T datum_;
  std::unique_ptr<Node<T>> next_;
};

#endif /* ifndef DV_STACK_NODE */
