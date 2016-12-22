#include <map>

#include "solution.h"

class Subtree {
public:
  bool isRoot;
  int parent;
  int height; // valid if root
  int size; // valid if root

  Subtree() {}
  Subtree(int i) : isRoot(true), parent(i), height(1), size(1) {}
};

static std::map<int, Subtree> parents;

int Find( int i ) {
  int root = i;
  auto it = parents.find(root);
  do {
    root = it->second.parent;
    it = parents.find(root);
  }
  while ( it != parents.end() && it->second.isRoot == false );

  return root;
}

int Union( int a, int b ) {
  int rootA = Find(a);
  int rootB = Find(b);

  // Merge
  int root = rootA;
  if (parents[rootA].height > parents[rootB].height) {
    parents[rootB].parent = rootA;
    parents[rootB].isRoot = false;
    parents[rootA].size += parents[rootB].size;
  }
  else {
    root = rootB;
    parents[rootA].parent = rootB;
    parents[rootA].isRoot = false;
    parents[rootB].size += parents[rootA].size;

    if ( parents[rootA].height == parents[rootB].height ) {
      parents[rootB].height++;
    }
  }

  return root;
}

int Solution::longestConsecutive(std::vector<int>& nums) {
  parents.clear();

  int maxSize = 0;

  for( int num : nums ) {
    if ( parents.find(num) != parents.end() ) {
      continue;
    }

    int root = num;
    parents[root] = Subtree(root);

    int predecessor = num - 1;
    auto it = parents.find(predecessor);
    if ( it != parents.end() ) {
      root = Union(it->first, root);
    }

    int successor = num + 1;
    it = parents.find(successor);
    if ( it != parents.end() ) {
      root = Union(it->first, root);
    }

    if ( maxSize < parents[root].size ) {
      maxSize = parents[root].size;
    }
  }

  return maxSize;
}
