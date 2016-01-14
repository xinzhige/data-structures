#ifndef MY_LIST_H_
#define MY_LIST_H_

#include "list_node.h"

template<typename Object>
class MyList {
public:
  MyList();
  MyList(const MyList &rhs);
  ~MyList();
  MyList<Object> & operator= (const MyList<Object> &rhs);
  int size() const { return theSize; }
  bool empty() const { return size() == 0; }
  MyList<Object> & delete_elem(const int &k); // Can't be named to the same name, delete, in the library
  MyList<Object> &delete_nodes(const Object &x);
  MyList<Object> &insert_node(const int &k, const Object &x);
  void output();
  void init(); 
private: 
  int theSize;
  Node<Object> *head;    
};

#endif 
