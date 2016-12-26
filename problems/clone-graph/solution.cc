#include "solution.h"

UndirectedGraphNode *Solution::cloneGraph(UndirectedGraphNode *node) {
  if (node == nullptr) return node;

  if ( labelToNode.find(node->label) != labelToNode.end() ) {
    return labelToNode[node->label];
  }

  labelToNode[node->label] = new UndirectedGraphNode( node->label );
  labelToNode[node->label]->neighbors = std::vector<UndirectedGraphNode*>();
  for ( UndirectedGraphNode *neighbor : node->neighbors ) {
    labelToNode[node->label]->neighbors.push_back( cloneGraph( neighbor ) );
  }

  return labelToNode[node->label];
}
