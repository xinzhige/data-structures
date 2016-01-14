#ifndef MAX_HEAP_H_
#define MAX_HEAP_H_

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

#endif 
