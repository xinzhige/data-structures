#ifndef BINARY_TREE_H_
#define BINARY_TREE_H_

#include "binary_tree_node.h"

template <typename Object>
class BinaryTree {
public:
  BinaryTree() { root = nullptr; }
  ~BinaryTree() {};
  bool empty() const { return (root) ? false : true; }
  void make_tree(const Object &elem, BinaryTree<Object> &l, BinaryTree<Object> &r);
  void pre_order(void(*visit) (BinaryTreeNode<Object> *r)) {
    pre_order(visit, root); 
  }
  void pre_order_iter(void(*visit) (BinaryTreeNode<Object> *r)) {
    pre_order_iter(visit, root);
  }
  void in_order(void(*visit) (BinaryTreeNode<Object> *r)) {
    in_order(visit, root);
  }
  void in_order_iter(void(*visit) (BinaryTreeNode<Object> *r)) {
    in_order_iter(visit, root);
  }
  void post_order(void(*visit) (BinaryTreeNode<Object> *r)) {
    post_order_iter(visit, root); 
  }
  void post_order_iter(void(*visit) (BinaryTreeNode<Object> *r)) {
    post_order_iter(visit, root);
  }
  int height() const { return height(root); }
protected:
  BinaryTreeNode<Object> *root;
  void pre_order(void (*visit) (BinaryTreeNode<Object> *r), BinaryTreeNode<Object> *t);
  void pre_order_iter(void (*visit) (BinaryTreeNode<Object> *r), BinaryTreeNode<Object> *t);
  void in_order(void (*visit) (BinaryTreeNode<Object> *r), BinaryTreeNode<Object> *t);
  void in_order_iter(void (*visit) (BinaryTreeNode<Object> *r), BinaryTreeNode<Object> *t);
  void post_order(void (*visit) (BinaryTreeNode<Object> *r), BinaryTreeNode<Object> *t);
  void post_order_iter(void (*visit) (BinaryTreeNode<Object> *r), BinaryTreeNode<Object> *t);
  int height(BinaryTreeNode<Object> *r) const;
};

#endif
