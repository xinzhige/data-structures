#include <iostream>
#include <stdexcept>
#include "stack_by_list.h"
#include "list_node.h"

template<typename Object>
MyStack<Object>::MyStack() {
  init();
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
    Node<Object> *p = new Node<Object>(x, head); 
    if (!p) {  
      throw std::out_of_range("No position to be inserted!");
    } 
    head = p;
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
