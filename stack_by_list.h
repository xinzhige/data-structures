#include <iostream>
#include <stdexcept>
#include "list_node.h"

template<typename Object>
class MyStack {
public:
  MyStack();
  MyStack(const MyStack &rhs);
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

template<typename Object>
MyStack<Object>::MyStack() {
  init();
}

template<typename Object>
MyStack<Object>::MyStack(const MyStack<Object> &rhs) {
  init();
  theSize = rhs.size();
  Node<Object> *curr = head;
  Node<Object> *curr_rhs = rhs.head; 
  for (int i = 0; i < theSize; ++i) {
    curr->next = new Node<Object>(curr_rhs->data, nullptr);
    curr = curr->next;
    curr_rhs = curr_rhs->next; 
  }   
}

template<typename Object>
MyStack<Object> & MyStack<Object>::operator= (const MyStack<Object> &rhs) {
  MyStack<Object> copy = rhs;
  std::swap(*this, copy);
  return *this;
}

template<typename Object>
MyStack<Object>::~MyStack() {
  Node<Object> *next; 
  while (head) {
    next = head->next;
    delete head;
    head = next; 
  }  
}

template<typename Object>
void MyStack<Object>::init() {
  theSize = 0;
  head = nullptr;
}

template<typename Object>
void MyStack<Object>::pop_out() {
  try { 
    if (!head) {
      throw std::out_of_range("No node to be deleted!"); 
    }
    Node<Object> *p = head;
    head = head->next;
    delete p;
    --theSize;
  }
  catch (const std::out_of_range& oor) {
    std::cerr<<"Out of Range error: "<<oor.what()<<'\n';
  }
}

template<typename Object>
void MyStack<Object>::push_in(const Object &x) {
  try {  
    Node<Object> *y = new Node<Object>(x, head); 
    if (!y) {  
      throw std::out_of_range("No position to be inserted!");
    } 
    head = y;
    ++theSize;
  }
  catch (const std::out_of_range& oor) {
    std::cerr<<"Out of Range error: "<<oor.what()<<'\n';
  }
}

template<typename Object>
Object & MyStack<Object>::peek() {
  try {
    if (!head) {   
      throw std::out_of_range("No node to be deleted!");
    }
    return head->data;
  }
  catch (const std::out_of_range& oor) {
    std::cerr<<"Out of Range error: "<<oor.what()<<'\n';
  }
  exit(1);
}
