#ifndef TRIE_H_
#define TRIE_H_

#include "trie_node.h"

template <int Size>
class Index {
public: 
  int operator[] (char vchar) {
    return vchar % Size;
  }
};

template <int Size, typename Object>
class trie {
public:
  // define the type alias
  typedef trieNode<Size> Node;
  typedef trieNode<Size>* pNode;
  trie() : root(new Node) {}
  ~trie() { clear(); }
  void clear() {
    clear_node(root);
    for (int i = 0; i < Size; ++i) {
      root->children[i] = nullptr;
    }
  }
  template<typename Iterator>
  void insert(Iterator begin, Iterator end);
  void insert(const char *str);
 
  template<typename Iterator>
  bool find(Iterator begin, Iterator end);
  bool find(const char *str);
  
  template<typename Iterator>
  bool downNodeAlone(Iterator begin);
  
  template<typename Iterator>
  bool erase(Iterator begin, Iterator end);
  bool erase(const char *str);
  
  int sizeAll(pNode);
  int sizeNoneRedundant(pNode);  
public:
  pNode root;
private:
  void clear_node(pNode curr);
  Object index; 
};

#endif
