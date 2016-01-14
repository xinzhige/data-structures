#ifndef HASH_FUNC_H_
#define HASH_FUNC_H_

// keys are strings
#include <string>

using namespace std;

class hashFunc {
public:
  size_t operator() (const string & key) {
    size_t hashVal = 0;
    for (char ch : key) {
      hashVal = 37 * hashVal + ch;
    }
    return hashVal;
  }
};

#endif
