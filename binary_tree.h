#ifndef BINARY_TREE_H_
#define BINARY_TREE_H_

#endif

#include "binary_tree_node.h"
#include <stack>

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

template <typename Object>
void BinaryTree<Object>::make_tree(const Object &elem, BinaryTree<Object> &l, BinaryTree<Object> &r) {
  root = new BinaryTreeNode<Object> (elem, l.root, r.root);
  l.root = nullptr;
  r.root = nullptr;
}

template <typename Object>
void BinaryTree<Object>::pre_order(void(*visit) (BinaryTreeNode<Object> *r), BinaryTreeNode<Object> *t) {
  if (t) {
    visit(t);
    pre_order(visit, t->left);
    pre_order(visit, t->right);  
  }
}

template <typename Object>
void BinaryTree<Object>::pre_order_iter(void(*visit) (BinaryTreeNode<Object> *r), BinaryTreeNode<Object> *t) {
  std::stack<BinaryTreeNode<Object> *> my_stack;
  if (t) {
    my_stack.push(t);
  }  
  while (!my_stack.empty()) {
    BinaryTreeNode<Object> *curr = my_stack.top();
    visit(curr);
    my_stack.pop();
    if (curr->right) {   
      my_stack.push(curr->right);
    }
    if (curr->left) {
      my_stack.push(curr->left);
    } 
  } 
}

template <typename Object>
void BinaryTree<Object>::in_order(void(*visit) (BinaryTreeNode<Object> *r), BinaryTreeNode<Object> *t) {
  if (t) {
    in_order(visit, t->left);
    visit(t);
    in_order(visit, t->right);
  }
}

template <typename Object>
void BinaryTree<Object>::in_order_iter(void(*visit) (BinaryTreeNode<Object> *r), BinaryTreeNode<Object> *t) {
  std::stack<BinaryTreeNode<Object> *> my_stack;
  BinaryTreeNode<Object> *curr = t; 
  while (!my_stack.empty() || curr) { 
    if (curr) {
      my_stack.push(curr);
      curr = curr->left;
    } else {
      curr = my_stack.top();
      my_stack.pop();
      visit(curr);
      curr = curr->right;
    }
  } 
}

template <typename Object>
void BinaryTree<Object>::post_order(void(*visit) (BinaryTreeNode<Object> *r), BinaryTreeNode<Object> *t) {
  if (t) {
    post_order(visit, t->left);
    post_order(visit, t->right);
    visit(t);
  }
}

template <typename Object>
void BinaryTree<Object>::post_order_iter(void(*visit) (BinaryTreeNode<Object> *r), BinaryTreeNode<Object> *t) {
  std::stack<BinaryTreeNode<Object> *> my_stack;
  BinaryTreeNode<Object> *curr = t;
  BinaryTreeNode<Object> *last_visited = nullptr;
  while (!my_stack.empty() || curr) {
    if (curr) {
      my_stack.push(curr);
      curr = curr->left;
    } else {
      BinaryTreeNode<Object> *peek = my_stack.top();
      if (peek->right && last_visited != peek->right) {
        // if right child exists and traversing node from left child, move right 
        curr = peek->right; 
      } else {
        visit(peek);
        last_visited = my_stack.top();
        my_stack.pop(); 
      }
    }
  } 
}

template <typename Object>
int BinaryTree<Object>::height(BinaryTreeNode<Object> *r) const {
  if (!r) { return 0; }
  int left_height =  height(r->left);
  int right_height = height(r->right);
  if (left_height > right_height) {
    return left_height + 1;
  } else {
    return right_height + 1;
  }
}
