template<typename Object>
class Node {
public:
  Node(const Object &d, Node<Object> *n = nullptr) : data(d), next(n) {}
  Object data;
  Node<Object> *next;
};
