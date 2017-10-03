#include <memory>

template <class T>
class List;

template <class T>
class Node {
 public:
  Node(const T& data) : data_(data) {}

 private:
  T data_;
  std::unique_ptr<Node<T>> next_;

  friend class List<T>;
};
