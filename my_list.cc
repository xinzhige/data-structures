#include <iostream>
#include <stdexcept>
#include "my_list.h"
#include "list_node.h"

template<typename Object>
MyList<Object>::MyList() {
  init();
}

template<typename Object>
MyList<Object>::MyList(const MyList<Object> &rhs) {
  init();
  theSize = rhs.size();
  Node<Object> *curr = head;
  Node<Object> *curr_rhs = rhs; 
  for (int i = 0; i < theSize; ++i) {
    curr->next = new Node<Object>(curr_rhs->data, nullptr);
    curr = curr->next;
    curr_rhs = curr_rhs->next; 
  }   
}

template<typename Object>
MyList<Object> & MyList<Object>::operator= (const MyList<Object> &rhs) {
  MyList<Object> copy = rhs;
  std::swap(*this, copy);
  return *this;
}

template<typename Object>
MyList<Object>::~MyList() {
  Node<Object> *next; 
  while (!empty()) {
    next = head->next;
    delete head;
    head = next; 
  }  
}

template<typename Object>
void MyList<Object>::init() {
  theSize = 0;
  head = nullptr;
}

template<typename Object>
void MyList<Object>::output() {
  Node<Object> *curr;
  for (curr = head; curr; curr = curr->next) {
    std::cout<<curr->data<<" ";
  }
  std::cout<<std::endl;
}

template<typename Object>
MyList<Object> &  MyList<Object>::delete_elem(const int &k) {
  try { 
    if (k < 0 || !head) {
      throw std::out_of_range("No node to be deleted!"); 
    }
    Node<Object> *p = head;
    if (k == 0) {
      head = head->next;
    } else {
      Node<Object> *q = head;
      for (int i = 0; (i < k - 1) && q; ++i) {
	q = q->next;
      }
      if (!q || !q->next) {
	throw std::out_of_range("No node to be deleted!");
      }
      p = q->next;
      q->next = p->next;
    }
    delete p;
  }
  catch (const std::out_of_range& oor) {
    std::cerr<<"Out of Range error: "<<oor.what()<<'\n';
  }
  return *this;
}

template<typename Object>
MyList<Object> & MyList<Object>::insert_node(const int &k, const Object &x) {
  try {  
    if (k < 0) {
      throw std::out_of_range("No position to be inserted!");
    }
    Node<Object> *p = head;
    for (int i = 1; (i < k) && p; ++i) {
      p = p->next;
    }
    if (k > 0 && !p) {
      throw std::out_of_range("No position to be inserted!");
    }
    Node<Object> *y = new Node<Object>(0, nullptr);
    y->data = x;
    if (k) {
      y->next = p->next;
      p->next = y;
    } else {
      y->next = head;
      head = y;
    }
  }
  catch (const std::out_of_range& oor) {
    std::cerr<<"Out of Range error: "<<oor.what()<<'\n';
  }
  return *this; 
}

template<typename Object>
MyList<Object> & MyList<Object>::delete_nodes(const Object &x) {
  Node<Object> *curr = head; 
  while (curr && curr->data == x) {
    Node<Object> *tmp = curr;
    curr = curr->next;
    delete tmp;
  }
  head = curr;
  if (!curr) {
    return *this;
  }
  while (curr->next) {
    if (curr->next->data == x) {
      Node<Object> *tmp = curr->next; 
      curr->next = tmp->next; 
      delete tmp;
    } else {
      curr = curr->next;
    }  
  }
  return *this;
}
