#ifndef AVL_TREE_H_
#define AVL_TREE_H_

#include "avl_tree_node.h"

template <typename Object>
class AVLTree {
public:
  AVLTree();
  ~AVLTree();
  int height();
  int max(int a, int b);
  AVLTreeNode<Object> *search(Object x) { return search(root, x); }
  void insert_node(Object x) { insert_node(root, x); }
  void delete_node(Object x) { delete_node(root, x); }
  void destroy() { destroy(root); }
private:
  AVLTreeNode<Object> *root;
  int height(AVLTreeNode<Object> *r);
  AVLTreeNode<Object>* search(AVLTreeNode<Object> *r, Object x) const;
  AVLTreeNode<Object>* ll_rotate(AVLTreeNode<Object>* k2);
  AVLTreeNode<Object>* rr_rotate(AVLTreeNode<Object>* k1);
  AVLTreeNode<Object>* lr_rotate(AVLTreeNode<Object>* k3);
  AVLTreeNode<Object>* rl_rotate(AVLTreeNode<Object>* k1);
  AVLTreeNode<Object>* insert_node(AVLTreeNode<Object>* &r, Object x);
  AVLTreeNode<Object>* delete_node(AVLTreeNode<Object>* &r, Object x);
  AVLTreeNode<Object>* minimum(AVLTreeNode<Object>* r);
  AVLTreeNode<Object>* maximum(AVLTreeNode<Object>* r);
  void destroy(AVLTreeNode<Object>* &r);
};

#endif
