#include "solution.h"

std::vector<int> Solution::get_longest_increasing_subsequence(const std::vector<int>& input) {
  std::vector<int> lengths( input.size() );
  std::vector<int> backpointers( input.size(), -1 );

  for (int j=0; j<lengths.size(); j++ ) {
    int max = 0;
    for (int i=0; i<j; i++ ) {
      if (input[i] < input[j] && max < lengths[i] ) {
        max = lengths[i];
        backpointers[j] = i;
      }
    }
    lengths[j] = 1 + max;
  }

  int max_idx = -1;
  int max_length = lengths[0];
  for (int i=1; i<lengths.size(); i++) {
    if (max_length < lengths[i]) {
      max_length = lengths[i];
      max_idx = i;
    }
  }

  // Reconstruct the sequence by following backpointers.
  std::vector<int> seq (max_length);
  int idx = max_idx;
  int seq_idx = max_length - 1;
  while (idx > -1 && seq_idx > -1) {
    seq[seq_idx] = input[idx];
    idx = backpointers[idx];
    seq_idx--;
  }

  return seq;
}

int Solution::lengthOfLIS( std::vector<int>& nums ) {
  int max = 0;

  std::vector<int> dp( nums.size(), 1 );
  for ( int i = 0; i < nums.size(); i++ ) {
    for ( int j = 0; j < i; j++ ) {
      if ( nums[j] < nums[i] ) {
        if ( dp[j] + 1 > dp[i] ) {
          dp[i] = dp[j] + 1;
        }
      }
    }

    if ( max < dp[i] )
      max = dp[i];
  }

  return max;
}
