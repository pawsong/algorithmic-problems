#include "solution.h"

template<typename T>
static T min(T A, T B) {
  return (A < B) ? A : B;
}

static int getKth( int *A, int sizeA, int *B, int sizeB, int k ) {
  // Ensure sizeA <= sizeB
  if ( sizeA > sizeB ) {
    return getKth(B, sizeB, A, sizeA, k);
  }

  if ( sizeA == 0 ) {
    return B[k-1];
  }

  if ( k == 1 ) {
    return min<>(A[0], B[0]);
  }

  int i = min<>( sizeA, k/2 );
  int j = min<>( sizeB, k/2 );

  if ( A[i-1] < B[j-1] ) {
    return getKth( A + i, sizeA - i, B, sizeB, k - i );
  }

  return getKth( A, sizeA, B + j, sizeB - j, k -j );
}

double Solution::findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
  int m = (nums1.size() + nums2.size() + 1 ) >> 1;
  int n = (nums1.size() + nums2.size() + 2 ) >> 1;

  return (getKth( &nums1[0], nums1.size(), &nums2[0], nums2.size(), m )
          + getKth( &nums1[0], nums1.size(), &nums2[0], nums2.size(), n )) / 2.f;
}
