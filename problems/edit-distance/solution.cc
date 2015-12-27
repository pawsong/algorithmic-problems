
#include <iostream>

#include "solution.h"

int diff(char charA, char charB) {
  if (charA != charB) {
    return 1;
  }
  return 0;
}

AlignedPair Solution::align(const std::string& stringA, const std::string& stringB) {

  AlignedPair pair;
  pair.stringA = stringA;
  pair.stringB = stringB;

  int numSubprobs = (stringA.length() + 1) * (stringB.length() + 1);

  std::vector<int> distances ( numSubprobs );
  std::vector<int> backpointersA ( numSubprobs, -1 );
  std::vector<int> backpointersB ( numSubprobs, -1 );

  // Edit distances for base cases.
  distances[0] = 0;

  for ( int i=1; i<stringA.length()+1; i++ ) {
    distances[i] = i;
    backpointersA[i] = i-1;
    backpointersB[i] = 0;
  }

  for ( int j=1; j<stringB.length()+1; j++ ) {
    int idx = j * (stringA.length()+1);
    distances[idx] = j;
    backpointersA[idx] = 0;
    backpointersB[idx] = j-1;
  }

  // Edit distances for the rest of subproblems.
  for ( int i=1; i<stringA.length()+1; i++ ) {
    for ( int j=1; j<stringB.length()+1; j++ ) {
      int distAB = distances[(i-1) + (j-1) * (stringA.length()+1)] + diff(stringA[i-1], stringB[j-1]);
      int distA = distances[(i-1) + j * (stringA.length()+1)] + 1;
      int distB = distances[i + (j-1) * (stringA.length()+1)] + 1;

      int idx = i + j * (stringA.length()+1);

      if (distAB < distA && distAB < distB ) {
        backpointersA[idx] = (i-1);
        backpointersB[idx] = (j-1);
      }
      else if (distA < distB) {
        backpointersA[idx] = (i-1);
        backpointersB[idx] = j;
      }
      else {
        backpointersA[idx] = i;
        backpointersB[idx] = (j-1);
      }

      distances[idx] = std::min<int>(distAB, std::min<int>(distA, distB));
    }
  }

  pair.editDistance = distances[distances.size() - 1];

  // Reconstruct path by following backpointers.
  int idxA = stringA.length();
  int idxB = stringB.length();
  
  while ( idxA > 0 || idxB > 0 ) {
    int idx = idxA + idxB * (stringA.length() + 1);

    if (idxA > 0 && idxA > backpointersA[idx]) {
      pair.alignedA.insert(pair.alignedA.begin(), stringA[idxA-1]);
    }
    else {
      pair.alignedA.insert(pair.alignedA.begin(), '-');
    }

    if (idxB > 0 && idxB > backpointersB[idx]) {
      pair.alignedB.insert(pair.alignedB.begin(), stringB[idxB-1]);
    }
    else {
      pair.alignedB.insert(pair.alignedB.begin(), '-');
    }
      
    idxA = backpointersA[idx];
    idxB = backpointersB[idx];
  }

  return pair;
}
