#include "my_vector.h"

template <typename Object>
explicit MyVector<Object>::MyVector(int initSize = 0) : theSize(initSize),
  theCapacity(initSize + SPARE_CAPACITY) { 
  objects = new Object[theCapacity]; 
}

template <typename Object>
MyVector<Object>::MyVector(const MyVector &rhs) : theSize(rhs.theSize),
  theCapacity(rhs.theCapacity), objects(nullptr) {
  objects = new Object[theCapacity];
  for (int k = 0; k < theSize; ++k) {
    objects[k] = rhs.objects[k]; 
  } 
}

template <typename Object>
MyVector<Object>::MyVector & operator= (const MyVector &rhs) {
  MyVector copy = rhs;
  std::swap(*this, copy);
  return *this;
}

template <typename Object>
MyVector<Object>::~MyVector() {
    delete []objects;
  }

template <typename Object>
void MyVector<Object>::reserve(int newCapacity) {
  if (newCapacity < theSize) {
    return;
  }
  Object *newArray = new Object[newCapacity];
  for (int k = 0; k < theSize; ++k) {
    newArray[k] = std::move(objects[k]);
  }
  theCapacity = newCapacity;
  std::swap(objects, newArray);
  delete []newArray;
}

template <typename Object>
void MyVector<Object>::push_back(const Object &x) {
  if (theSize == theCapacity) {
    reserve(2 * theCapacity + 1);    
  }
  objects[theSize++] = x;
}

template <typename Object>
void MyVector<Object>::pop_back() {
  --theSize;
}

template <typename Object>
Object & MyVector<Object>::operator[](int index) { 
  return objects[index]; 
}
