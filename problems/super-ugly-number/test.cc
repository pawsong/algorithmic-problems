
#include "gmock/gmock.h"
#include "solution.h"

using namespace testing;

int main(int argc, char** argv) {
  InitGoogleMock(&argc, argv);
  return RUN_ALL_TESTS();
}

template<int m, typename T>
void vectorize(const T (&arr)[m], std::vector<T>& outvec) {
  for (int i=0; i<m; i++) {
    outvec.push_back(arr[i]);
  }
}

TEST(SuperUglyNumberTest, 1247) {
  Solution sol;

  int expected[] = {1, 2, 4, 7, 8, 13, 14, 16, 19, 26, 28, 32};

  std::vector<int> primes;
  primes.push_back(2);
  primes.push_back(7);
  primes.push_back(13);
  primes.push_back(19);

  std::vector<int> actual;
  int i=11;
  for( int i=0; i<sizeof(expected)/sizeof(int); i++ ) {
    actual.push_back( sol.nthSuperUglyNumber(i+1, primes) );
  }
  EXPECT_THAT(actual, ElementsAreArray(expected));
}

TEST(SuperUglyNumberTest, LargeN) {
  Solution sol;

  int expected[] = {
    51200000,
    97200000
  };

  std::vector<int> primes;
  primes.push_back(2);
  primes.push_back(3);
  primes.push_back(5);

  std::vector<int> actual;
  int n = 1000;
  actual.push_back( sol.nthSuperUglyNumber(n, primes) );

  n = 1100;
  actual.push_back( sol.nthSuperUglyNumber(n, primes) );
  EXPECT_THAT(actual, ElementsAreArray(expected));
}

TEST(SuperUglyNumberTest, LargeK) {
  Solution sol;
  
  int n = 100000;

  int primes[] = {
    7,19,29,37,41,47,53,59,61,79,83,89,101,103,109,127,131,137,139,157,167,179,181,199,211,229,233,239,241,251
  };
  int expected[] = {
    1092889481
  };

  std::vector<int> input;
  vectorize(primes, input);

  std::vector<int> actual;
  actual.push_back( sol.nthSuperUglyNumber(n, input) );
  EXPECT_THAT(actual, ElementsAreArray(expected));
}
