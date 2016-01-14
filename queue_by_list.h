#ifndef QUEUE_BY_LIST_H_
#define QUEUE_BY_LIST_H_

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

#endif
