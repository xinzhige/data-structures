#ifndef LIST_NODE_H_
#define LIST_NODE_H_

template<typename Object>
class Node {
public:
  Node(const Object &d, Node<Object> *n = nullptr) : data(d), next(n) {}
  Object data;
  Node<Object> *next;
};

#endif
