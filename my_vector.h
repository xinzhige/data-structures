#ifndef MY_VECTOR_H_
#define MY_VECTOR_H_

template <typename Object>

class MyVector {
public:
  explicit MyVector(int initSize = 0) : theSize(initSize),
      theCapacity(initSize + SPARE_CAPACITY) { 
    objects = new Object[theCapacity]; 
  }

  MyVector(const MyVector &rhs) : theSize(rhs.theSize),
      theCapacity(rhs.theCapacity), objects(nullptr) {
    objects = new Object[theCapacity];
    for (int k = 0; k < theSize; ++k) {
      objects[k] = rhs.objects[k]; 
    } 
  }
  
  MyVector & operator= (const MyVector &rhs) {
    MyVector copy = rhs;
    std::swap(*this, copy);
    return *this;
  }

  ~MyVector() {
    delete []objects;
  }
  
  void reserve(int newCapacity) {
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

  void push_back(const Object &x) {
    if (theSize == theCapacity) {
      reserve(2 * theCapacity + 1);    
    }
    objects[theSize++] = x;
  }
  
  void pop_back() {
    --theSize;
  }
  
  Object & operator[](int index) { return objects[index]; }
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
