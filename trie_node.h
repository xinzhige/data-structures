template <int Size>
class trieNode {
public:
  trieNode(): terminableSize(0), nodeSize(0) {
    for (int i = 0; i < Size; ++i) {
      children[i] = nullptr;
    }
  }
  ~trieNode() {
    for (int i = 0; i < Size; ++i) {
      delete children [i];
      children[i] = nullptr; 
    }
  }
  int terminableSize; //store the number of words that end at this node
  int nodeSize;  // store the number of children of this node
  trieNode *children[Size];
};
