#ifndef BINARY_TREE_NODE_H_
#define BINARY_TREE_NODE_H_

template <typename Object>
class BinaryTreeNode {
public:
  BinaryTreeNode() {
    left = nullptr;
    right = nullptr;
  }
  BinaryTreeNode(const Object &e, 
                 BinaryTreeNode *l= nullptr, 
                 BinaryTreeNode *r = nullptr) { 
    data = e;
    left = l;
    right = r; 
  }
  Object data;
  BinaryTreeNode<Object> *left;
  BinaryTreeNode<Object> *right; 
};

#endif
