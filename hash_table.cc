#include "hash_table.h"
#include "hash_func.h"
#include <vector>
#include <list>

using namespace std;

template<typename Object>
void HashTable<Object>::makeEmpty() {
  for (auto & thisList : theLists) {
    thisList.clear();
  } 
}

template<typename Object>
bool HashTable<Object>::contains(const Object & x) const {
  auto & whichList = theLists[myhash(x)];
  return find(begin(whichList), end(whichList), x) != end(whichList); 
}

template<typename Object>
bool HashTable<Object>::remove(const Object & x) {
  auto & whichList = theLists[myhash(x)];
  auto iter = find(begin(whichList), end(whichList), x);
  if (iter == end(whichList)) {
    return false;
  }
  whichList.erase(iter);
  currentSize -= 1;
  return true; 
}

template<typename Object>
bool HashTable<Object>::insert(const Object & x) {
  auto & whichList = theLists[myhash(x)];
  if (find(begin(whichList), end(whichList), x) != end(whichList)) {
    return false;
  }
  whichList.push_back(x);
  currentSize += 1;
  if (currentSize > theLists.size()) {
    rehash();
  }
  return true;
}

template<typename Object>
size_t HashTable<Object>::myhash(const Object & x) const {
  static hashFunc hf;
  return hf(x) % theLists.size();
}

template<typename Object>
void HashTable<Object>::rehash() {
  vector<list<Object> > oldLists = theLists;
  // create new doubled-sized, empty table
  // TODO: to create a prime number that is first after 2 * theLists.size()
  theLists.resize(2 * theLists.size());
  for (auto & thisList : theLists) {
    thisList.clear();
  }
  currentSize = 0;
  for (auto & thisList : oldLists) {
    for (auto & x : thisList) {
      insert(x);
    }
  }
}
