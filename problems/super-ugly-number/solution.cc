
#include "solution.h"

int Solution::nthSuperUglyNumber(int n, std::vector<int>& primes) {
  std::vector<int> nums ( n, -1 );
  std::vector<int> indexes ( primes.size(), 0 );
  std::vector<int> values ( primes );

  int i = 0;
  nums[i++] = 1;

  while ( i < n ) {
    int prev = nums[i-1];
    int min = -1;

    int selected = 0;

    for (int j=0; j<indexes.size(); j++) {
      int next = values[j];

      while ( indexes[j] < i && next <= prev ) {
        indexes[j]++;
        values[j] = nums[indexes[j]] * primes[j];
        next = values[j];
      }

      // Update min.
      if ( min == -1 || (next < min && prev < next) ) {
        min = next;
        selected = j;
      }
    }

    nums[i++] = min;

    indexes[selected]++;
    values[selected] = nums[indexes[selected]] * primes[selected];
  }

  return nums[n-1];
}
