#ifndef STACK_BY_LIST_H_
#define STACK_BY_LIST_H_

#include "list_node.h"

template<typename Object>
class MyStack {
public:
  MyStack();
  //MyStack(const MyStack &rhs);
  ~MyStack();
  MyStack<Object> & operator= (const MyStack<Object> &rhs);
  int size() const { return theSize; }
  bool empty() const { return size() == 0; }
  void pop_out(); // Can't be named to the same name, delete, in the library
  void push_in(const Object& x);
  Object& peek(); 
  void init(); 
private: 
  int theSize;
  Node<Object> *head;    
};

#endif
