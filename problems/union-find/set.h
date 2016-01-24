
#include <vector>

class Set {
 private:
  std::vector<int> parent;
  std::vector<int> size; // Size of each subset.

 public:
  Set( int n ) : parent(n, -1), size(n, 1) {}
  ~Set() {}

  int find( int elem ) const;
  inline bool contains( int elem ) const {
    return (Set::find(elem) > -1);
  }
  inline bool connected( int elemA, int elemB ) const {
    if ( Set::contains(elemA) && Set::contains(elemB) ) {
      return (Set::find(elemA) == Set::find(elemB));
    }
    return false;
  }
  void merge( int elemA, int elemB );
};
