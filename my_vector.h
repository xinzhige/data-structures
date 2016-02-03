#ifndef MY_VECTOR_H_
#define MY_VECTOR_H_

template <typename Object>

class MyVector {
public:
  explicit MyVector(int initSize = 0);
  MyVector(const MyVector &rhs);
  MyVector & operator= (const MyVector &rhs);
  ~MyVector();
  void reserve(int newCapacity);
  void push_back(const Object &x);
  void pop_back();
  Object & operator[](int index); 
  const Object & operator[](int index) const { return objects[index]; }
  bool empty() const { return size() == 0; }
  int size() const { return theSize; }
  int capacity() const { return theCapacity; } 
  static const int SPARE_CAPACITY = 16;
 
private: 
  int theSize;
  int theCapacity;
  Object *objects; 
};

#endif
