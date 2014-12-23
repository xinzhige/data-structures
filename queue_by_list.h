#include <iostream>
#include <stdexcept>
#include "list_node.h"

template<typename Object>
class MyQueue {
public:
  MyQueue();
  //MyQueue(const MyQueue &rhs);
  ~MyQueue();
  MyQueue<Object> & operator= (const MyQueue<Object> &rhs);
  int size() const { return theSize; }
  bool empty() const { return size() == 0; }
  Object & front_data();
  Object & back_data(); 
  void pop_out();
  void push_in(const Object &x);
  void init();
  void output(); 
private: 
  int theSize;
  Node<Object> *head;   
  Node<Object> *tail; 
};

template<typename Object>
MyQueue<Object>::MyQueue() {
  init();
}

template<typename Object>
MyQueue<Object> & MyQueue<Object>::operator= (const MyQueue<Object> &rhs) {
  MyQueue<Object> copy = rhs;
  std::swap(*this, copy);
  return *this;
}

template<typename Object>
MyQueue<Object>::~MyQueue() {
  Node<Object> *next; 
  while (head) {
    next = head->next;
    delete head;
    head = next; 
  }  
}

template<typename Object>
void MyQueue<Object>::init() {
  theSize = 0;
  head = nullptr;
  tail = nullptr;
}

template<typename Object>
void MyQueue<Object>::output() {
  Node<Object> *curr;
  for (curr = head; curr; curr = curr->next) {
    std::cout<<curr->data<<" ";
  }
  std::cout<<std::endl;
}

template<typename Object>
void MyQueue<Object>::pop_out() {
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
void MyQueue<Object>::push_in(const Object &x) {
  Node<Object> *p = new Node<Object>(x, nullptr);
  if (!empty()) {
    tail->next = p;
  } else {
    head = p;
  }
  tail = p;
  ++theSize;
}

template<typename Object>
Object & MyQueue<Object>::front_data() {
  try {
    if (empty()) {
      throw std::out_of_range("No data to return!");
    }
    return head->data;
  }
  catch (const std::out_of_range& oor) {
    std::cerr<<"Out of Range error: "<<oor.what()<<'\n';
  }  
  exit(1); 
}

template<typename Object>
Object & MyQueue<Object>::back_data() {
  try {        
    if (empty()) {
      throw std::out_of_range("No data to return!");
    }
    return tail->data;
  }
  catch (const std::out_of_range& oor) {
    std::cerr<<"Out of Range error: "<<oor.what()<<'\n';
  }
  exit(1);
}
