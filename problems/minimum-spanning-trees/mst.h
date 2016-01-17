
#include <vector>

class MinimumSpanningTrees {
 public:
  // Prim's algorithm for dense graphs.
  void prim( const std::vector< std::vector<bool> >&, const std::vector< std::vector<float> >&, std::vector< std::vector<int> >& );

  // TODO: Kruskal's algorithm for sparse graphs.
  void kruskal( const std::vector< std::vector< std::pair<int, float> > >& adjLists, std::vector< std::vector<int> >& );
};
