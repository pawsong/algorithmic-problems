
#include "set.h"

int Set::find( int elem ) const {
  if ( elem > -1 && elem < parent.size() ) {
    // Follow parent pointers.
    while( parent[elem] > -1 ) {
      elem = parent[elem];
    }
    return elem;
  }
  return false;
}

void Set::merge( int elemA, int elemB ) {
  int subsetA = Set::find(elemA);
  int subsetB = Set::find(elemB);

  if ( subsetA == subsetB ) {
    return;
  }

  if (size[subsetA] >= size[subsetB]) {
    parent[subsetB] = subsetA;
    size[subsetA] += size[subsetB];
  }
  else {
    parent[subsetA] = subsetB;
    size[subsetB] += size[subsetA];
  }
}
