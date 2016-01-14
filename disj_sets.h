#ifndef DISJ_SETS_H_
#define  DISJ_SETS_H_



#include <vector>

class DisjSets {
public:
  explicit DisjSets(int numElements) : s(numElements, -1) { };
  int find(int x) const;
  int find(int x);
  // Use union-by-height
  void unionSets(int root1, int root2);
private:
  std::vector<int> s;
};

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

#endif
