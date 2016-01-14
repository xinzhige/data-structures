#ifndef DISJ_SETS_H_
#define  DISJ_SETS_H_

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

#endif
