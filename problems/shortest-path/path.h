
#include <vector>

class ShortestPath {
 public:
  void dijkstra(int, const std::vector< std::vector< std::pair<int, float> > >&, std::vector<int>&);

  // For directed acyclic graphs, topological sorting is faster than dijkstra.
  bool topsort(int, const std::vector< std::vector< std::pair<int, float> > >&, std::vector<int>&);
};
