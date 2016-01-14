#ifndef HASH_TABLE_H_
#define HASH_TABLE_H_

template <typename Object>
class HashTable {
 public:
  explicit HashTable(int size = 101);
  bool contains(const Object & x) const;
  void makeEmpty();
  bool insert(const Object & x);
  bool remove(const Object & x);
 private:
  vector<list<Object> > theLists;
  int currentSize;
  void rehash();
  size_t myhash(const Object & x) const;
};

#endif
