#ifndef AVL_TREE_NODE_H_
#define AVL_TREE_NODE_H_

template <typename Object>
class AVLTreeNode {
public:
  Object data; 
  int height;
  AVLTreeNode *left;
  AVLTreeNode *right;
  AVLTreeNode(Object &d, AVLTreeNode *l, AVLTreeNode *r) : 
    data(d), height(0), left(l), right(r) {} 
};

#endif
