#include <unordered_map>
#include <vector>

/**
 * Definition for undirected graph.
 */
struct UndirectedGraphNode {
  int label;
  std::vector<UndirectedGraphNode *> neighbors;
  UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
  std::unordered_map<int, UndirectedGraphNode*> labelToNode;

public:
  UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node);
};
