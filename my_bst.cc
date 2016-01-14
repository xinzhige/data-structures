#include "my_bst.h"
#include "binary_tree.h"

template <typename Object, typename Obj>
bool BSTree<Object, Obj>::search(const Obj &x) const {
  BinaryTreeNode<Object> *p = this->root;
  while (p) {
    if (x < p->data) {
      p = p->left;
    } else if (x > p->data) {
      p = p->right;
    } else {
      return true;
    }
  }
  return false;
}

template <typename Object, typename Obj>
void BSTree<Object, Obj>::insert_node(const Object &x) {
  BinaryTreeNode<Object> *p = this->root;
  BinaryTreeNode<Object> *pp = nullptr;
  while (p) {
    pp = p;
    if (x < p->data) {
      p = p->left;
    } else if (x > p->data) {
      p = p->right;
    } else {
      return;
    }
  }
  BinaryTreeNode<Object> *r = new BinaryTreeNode<Object>(x); 
  if (this->root) {
    if (x < pp->data) {
      pp->left = r;
    } else {
      pp->right = r; 
    }
  } else {
    this->root = r;
  }
}

template <typename Object, typename Obj>
void BSTree<Object, Obj>::delete_node(const Obj &x){
  BinaryTreeNode<Object> *p = this->root; // node that needs to be deleted
  BinaryTreeNode<Object> *pp = nullptr;
  while (p && p->data != x) {
    pp = p;
    if (x < p->data) {
      p = p->left; 
    } else if (x > p->data) {
      p = p->right;
    }
  } 
  if (!p) {
    return;
  }
  // p has both left and right child and here we pick the maximum on the left subtree to replace p
  if (p->left && p->right) {
    BinaryTreeNode<Object> *s = p->left;
    BinaryTreeNode<Object> *ps = p;
    while (s->right) {
      ps = s;
      s = s->right;
    }   
    p->data = s->data;
    p = s;
    pp = ps; 
  } 
  BinaryTreeNode<Object> *c;
  if (p->left) {
    c = p->left;
  } else {
    c = p->right;
  }
  if (p == this->root) {
    this->root = c;
  } else {
    if (p == pp->left) {
      pp->left = c;
    } else {
      pp->right = c;
    }
  }
  delete p; 
}
