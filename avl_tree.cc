#include "avl_tree.h"

template <typename Object>
AVLTree<Object>::AVLTree(): root(nullptr) { }

template <typename Object> 
AVLTree<Object>::~AVLTree() {
  destroy();
}
// define the height of empty tree to be 0 
template <typename Object>
int AVLTree<Object>::height(AVLTreeNode<Object>* r) {
  if (r) {
    return r->height;
  }
  return 0;
}

template <typename Object>
int AVLTree<Object>::height() {
  return height(root);
}

template <typename Object>
int AVLTree<Object>::max(int a, int b) {
  return a > b ? a : b;
}

template <typename Object>
AVLTreeNode<Object>* AVLTree<Object>::search(AVLTreeNode<Object>* r, Object x) const {
  while ((!r) || (r->data != x)) {
    if ( x < r->data) {
      r = r->left;
    } else {
      r = r->right;
    }
  }
  return r;
}

template <typename Object>
AVLTreeNode<Object>* AVLTree<Object>::ll_rotate(AVLTreeNode<Object>* k2) {
  AVLTreeNode<Object>* k1;
  k1 = k2->left;
  k2->left = k1->right;
  k1->right = k2;
  k2->height = max(height(k2->left), height(k2->right)) + 1;
  k1->height = max(height(k1->left), k2->height) + 1;
  return k1;
}

template <typename Object>
AVLTreeNode<Object>* AVLTree<Object>::rr_rotate(AVLTreeNode<Object>* k1) {
  AVLTreeNode<Object>* k2;
  k2 = k1->right;
  k1->right = k2->left;
  k2->left = k1;
  k1->height = max(height(k1->left), height(k1->right)) + 1;
  k2->height = max(height(k2->right), k1->height) + 1;
  return k2;
}

template <typename Object>
AVLTreeNode<Object>* AVLTree<Object>::lr_rotate(AVLTreeNode<Object>* k3) {
  k3->left = rr_rotate(k3->left);
  return ll_rotate(k3);
}

template <typename Object>
AVLTreeNode<Object>* AVLTree<Object>::rl_rotate(AVLTreeNode<Object>* k1) {
  k1->right = ll_rotate(k1->right);
  return rr_rotate(k1);
}

template <typename Object>
AVLTreeNode<Object>* AVLTree<Object>::insert_node(AVLTreeNode<Object>* &r, Object x) {
  if (!r) {
    r = new AVLTreeNode<Object>(x, nullptr, nullptr);
    if (!r) {
      std::cout<<"ERROR: create avltree node failed!"<<std::endl;
      return nullptr; 
    }
  } else if (x < r->data) {
    r->left = insert_node(r->left, x);
    if (height(r->left) - height(r->right) == 2) {
      if (x < r->left->data) {
        r = ll_rotate(r);
      } else {
        r = lr_rotate(r);
      }
    }
  } else if (x > r->data) {
    r->right = insert_node(r->right, x);
    if (height(r->right) - height(r->left) == 2) {
      if (x > r->right->data) {
        r = rr_rotate(r);
      } else {
        r = rl_rotate(r);
      }
    }
  } else {
    std::cout<<"Failed to add the same node!"<<std::endl;
  }
  r->height = max(height(r->left), height(r->right)) + 1;
  return r;
}

template <typename Object>
AVLTreeNode<Object>* AVLTree<Object>::delete_node(AVLTreeNode<Object>* &r, Object x) {
  if ((!r) || (!search(r, x))) {
    return nullptr;
  }
  if (x < r->data) {
    r->left = delete_node(r->left, x);
    if (height(r->right) - height(r->left) == 2) {
      AVLTreeNode<Object> *tr = r->right;
      if (height(tr->left) > height(tr->right)) {
        r = rl_rotate(r);
      } else {
        r = rr_rotate(r);
      }
    }
  } else if (x > r->data) {
    r->right = delete_node(r->right, x);
    if (height(r->left) - height(r->right) == 2) {
      AVLTreeNode<Object> *tl = r->left;
      if (height(tl->right) > height(tl->left)) {
        r = lr_rotate(r);
      } else {
        r = ll_rotate(r);
      }
    }
  } else {
    if ((r->left) && (r->right)) {
      if (height(r->left) > height(r->right)) {
        AVLTreeNode<Object> *max_node = maximum(r->left);
        r->data = max_node->data;
        r->left = delete_node(r->left, max_node);
      } else {
        AVLTreeNode<Object> *min_node = maximum(r->right);
        r->data = min_node->data;
        r->right = delete_node(r->right, min_node);
      }
    } else {
      AVLTreeNode<Object> *tmp = r;
      r = r->left ? r->left : r->right;
      delete tmp; 
    }
  }
  return r;
}

template <typename Object>
AVLTreeNode<Object>* AVLTree<Object>::minimum(AVLTreeNode<Object>* r) {
  if (!r) {
    return nullptr;
  }
  while (r->left) {
    r = r->left;
  }
  return r;
}

template <typename Object>
AVLTreeNode<Object>* AVLTree<Object>::maximum(AVLTreeNode<Object>* r) {
  if (!r) {
    return nullptr;
  }
  while (r->right) {
    r = r->right;
  }
  return r;
}

template <typename Object>
void AVLTree<Object>::destroy(AVLTreeNode<Object>* &r) {
  if (!r) {
    return;
  }
  if (r->left) {
    destroy(r->left);
  }
  if (r->right) {
    destroy(r->right);
  }
  delete r;
}
