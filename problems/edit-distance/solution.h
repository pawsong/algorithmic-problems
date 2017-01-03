#include <string>
#include <vector>

struct AlignedPair {
  std::string stringA;
  std::string stringB;

  int editDistance;
  std::string alignedA;
  std::string alignedB;
};

class Solution {
public:
  AlignedPair align(const std::string&, const std::string&);

  int minDistance(std::string word1, std::string word2);
};
