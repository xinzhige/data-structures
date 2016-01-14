#include <cstring>
#include "trie.h"
#include "trie_node.h"
 
template <int Size, typename Object>
void trie<Size, Object>::clear_node(pNode curr) {
  for (int i = 0; i < Size; ++i) {
    if (curr->children[i]) {
      clear_node(curr->children[i]);
      delete curr->children[i];
      curr->children[i] = nullptr;
      curr->nodeSize -= 1;
      if (curr->nodeSize == 0) {
        break;
      }
    }
  }
}

template <int Size, typename Object>
template <typename Iterator>
void trie<Size, Object>::insert(Iterator begin, Iterator end) {
  pNode curr = root;
  pNode prev;
  for (; begin != end; ++begin) {
    if (!curr->children[index[*begin]]) {
      curr->children[index[*begin]] = new(Node);
      curr->nodeSize += 1;
    }
    prev = curr;
    curr = curr->children[index[*begin]];
  } 
  prev->terminableSize += 1; 
}

template <int Size, typename Object>
void trie<Size, Object>::insert(const char *str) {
  return insert(str, str + strlen(str));
}

template <int Size, typename Object>
template <typename Iterator>
bool trie<Size, Object>::find(Iterator begin, Iterator end) {
  pNode curr = root;
  pNode prev;
  for (; begin != end; ++begin) {
    if (!curr->children[index[*begin]]) {
      return false; 
    }
    prev = curr;
    curr = curr->children[index[*begin]]; 
  } 
  if (prev->terminableSize > 0) {
    return true;
  } 
  return false; 
}

template <int Size, typename Object>
bool trie<Size, Object>::find(const char *str) {
  return find(str, str + strlen(str));
}

template <int Size, typename Object>
template <typename Iterator>
bool trie<Size, Object>::downNodeAlone(Iterator begin) {
  pNode curr = root;
  int terminableSum = 0;
  while (curr->nodeSize != 0) {
    terminableSum += curr->terminableSize;
    if ( curr->nodeSize > 1) {
      return false;
    } else {
      for (int i = 0; i < Size; ++i) {
        if (curr->children[i]) {
          curr = curr->children[i];
        }
      }
    }
  }
  if (terminableSum == 1) {
    return true;
  }
  return false;
}

template <int Size, typename Object>
template <typename Iterator>
bool trie<Size, Object>::erase(Iterator begin, Iterator end) {
  if (find(begin, end)) {
    pNode curr = root;
    pNode prev;
    for (; begin != end; ++begin) {
      if (downNodeAlone(curr)) {
        delete curr;
        return true;
      }
      prev = curr;
      curr = curr->children[index[*begin]];
    }
    if (prev->terminableSize > 0) {
      prev->terminableSize -= 1;
    }
    return true;
  }
  return false; 
}

template <int Size, typename Object>
bool trie<Size, Object>::erase(const char *str) {
  if (find(str)) {
    erase(str, str + strlen(str));
    return true;
  }
  return false;
}

template <int Size, typename Object>
int trie<Size, Object>::sizeAll(pNode ptr) {
  if (ptr == nullptr) {
    return 0;
  }
  int result = ptr->terminableSize;
  for (int i = 0; i < Size; ++i) {
    result += sizeAll(ptr->children[i]);
  }
  return result;
}

template <int Size, typename Object>
int trie<Size, Object>::sizeNoneRedundant(pNode ptr) {
  if (ptr == nullptr) {
    return 0; 
  }
  int result = 0;
  if (ptr->terminableSize > 0) {
    result = 1;
  }
  if (ptr->nodeSize != 0) {
    for (int i = 0; i < Size; ++i) {
      result += sizeNoneRedundant(ptr->children[i]);
    }
  }
  return result;
}
