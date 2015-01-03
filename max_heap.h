#ifndef _MAX_HEAP_H_
#define _MAX_HEAP_H_

#include <assert.h>

template <typename Object>
class MaxHeap {
public:
  MaxHeap(int MaxHeapSize = 10);
  ~MaxHeap() { delete [] heap; }
  int size() const { return CurrentSize; }
  Object max();
  void insert_node(const Object & x);
  void delete_max();
  void initialize(Object a[], int size, int ArraySize);
private:
  int CurrentSize, MaxSize;
  Object *heap; 
};

template <typename Object>
MaxHeap<Object>::MaxHeap(int MaxHeapSize) {
  MaxSize = MaxHeapSize;
  heap = new Object[MaxSize + 1];
  CurrentSize = 0;
}

template <typename Object>
Object MaxHeap<Object>::max() {
  assert(CurrentSize != 0);
  return heap[1];  
}

template <typename Object>
void MaxHeap<Object>::insert_node(const Object &x) {
  assert(CurrentSize != MaxSize);
  CurrentSize += 1; 
  int i = CurrentSize;
  while (i != 1 && x > heap[i/2]) {
    heap[i] = heap[i/2];
    i /= 2;
  }
  heap[i] = x;
}

template <typename Object>
void MaxHeap<Object>::delete_max() {
  assert(CurrentSize != 0);
  Object x = heap[CurrentSize];
  CurrentSize -= 1;
  int i = 1;  // current node of the heap
  int child_i = 2;  // i's child
  while (child_i <= CurrentSize) {
    // heap[child_i] should be the child with larger value
    if (child_i < CurrentSize && heap[child_i] < heap[child_i+1]) {
      heap[child_i] += 1;
    }
    if (x >= heap[child_i]) {
      break;
    }
    heap[i] = heap[child_i];
    i = child_i;
    child_i *= 2;
  }
  heap[i] = x; 
}

template <typename Object>
void MaxHeap<Object>::initialize(Object a[], int size, int ArraySize) {
  delete [] heap;
  heap = a; 
  CurrentSize = size;
  for (int i = CurrentSize/2; i >= 1; --i) {
    Object x = heap[i];
    int child_i = 2*i;
    while (child_i <= CurrentSize) {
      if (child_i < CurrentSize && heap[child_i] < heap[child_i+1]) {
        child_i += 1;
      }
      if (x >= heap[child_i]) {
        break;
      }
      heap[child_i/2] = heap[child_i];
      child_i *= 2;
    }
    heap[i] = x;
  }
}

#endif 
