#include <queue>
#include "solution.h"

class Compare {
public:
  bool operator() (const std::pair<std::vector<int>::iterator, std::vector<int>::iterator>& A,
                   const std::pair<std::vector<int>::iterator, std::vector<int>::iterator>& B) const {
    return (*A.first + *A.second) > (*B.first + *B.second);
  }
};

std::vector<std::pair<int, int>> Solution::kSmallestPairs(std::vector<int>& nums1, std::vector<int>& nums2, int k) {
  std::vector<std::pair<int, int>> sol;

  std::priority_queue<std::pair<std::vector<int>::iterator, std::vector<int>::iterator>,
                      std::vector<std::pair<std::vector<int>::iterator,
                                            std::vector<int>::iterator>>,
                      Compare> minHeap;

  if ( nums1.size() == 0 || nums2.size() == 0 ) {
    return sol;
  }

  for( auto it=nums1.begin(); it != nums1.end(); ++it ) {
    minHeap.push( std::make_pair(it, nums2.begin()) );
  }

  while( sol.size() < k && minHeap.size() > 0 ) {
    auto popped = minHeap.top();
    sol.push_back(std::make_pair(*(popped.first), *(popped.second)));
    minHeap.pop();

    popped.second++;
    if ( popped.second != nums2.end() ) {
      minHeap.push( std::make_pair( popped.first, popped.second ) );
    }
  }

  return sol;
}
