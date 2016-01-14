#include "disj_sets.h"
#include <vector>

int DisjSets::find(int x) {
  if (s[x] < 0) {
    return x;
  } else {
    return s[x] = find(s[x]);
  }
}

int DisjSets::find(int x) const {
  if (s[x] <0) {
    return x;
  } else {
    return find(s[x]);
  }
}

void DisjSets::unionSets(int root1, int root2) {
  if (s[root2] < s[root1]) {
    s[root1] = root2;
  } else {
    if (s[root1] == s[root2]) {
      s[root1] -= 1;
    }
    s[root2] = root1;
  } 
}
