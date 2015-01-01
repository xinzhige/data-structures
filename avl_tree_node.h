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
