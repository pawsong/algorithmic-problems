#include "solution.h"

enum {
  RED = 0,
  WHITE,
  BLUE
};

static void swap( int &a, int &b ) {
  int tmp = a;
  a = b;
  b = tmp;
}

void Solution::sortColors(std::vector<int>& nums) {
  int red = 0;
  int blue = nums.size() - 1;

  while ( red < blue ) {
    int i = red;
    while (i < blue && nums[i] == WHITE) {
      i++;
    }

    int j = blue;
    while (j > red && nums[j] == WHITE) {
      j--;
    }

    if ( i > j ) break;

    swap( nums[red], nums[i] );
    swap( nums[blue], nums[j] );

    if ( nums[red] == BLUE && nums[blue] == RED ) {
      swap( nums[red], nums[blue] );
      red += 1;
      blue -= 1;
    }
    else {
      if ( nums[red] == RED ) {
        red += 1;
      }
      if ( nums[blue] == BLUE ) {
        blue -= 1;
      }
    }
  }
}
