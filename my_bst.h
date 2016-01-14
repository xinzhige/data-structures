#ifndef MY_BST_H_
#define MY_BST_H_

#include "binary_tree.h"

template <typename Object, typename Obj>
class BSTree : public BinaryTree<Object> {
public:
  bool search(const Obj &x) const;
  void insert_node(const Object &x);
  void delete_node(const Obj &x);
};

#endif
