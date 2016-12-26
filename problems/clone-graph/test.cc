#include "gmock/gmock.h"
#include "solution.h"

using namespace testing;

int main ( int argc, char** argv ) {
  InitGoogleMock( &argc, argv );
  return RUN_ALL_TESTS();
}

TEST(CloneGraph, 2Vertices) {
  UndirectedGraphNode* v0 = new UndirectedGraphNode(-1);
  UndirectedGraphNode* v1 = new UndirectedGraphNode(1);

  v0->neighbors.push_back(v1);

  Solution sol;
  UndirectedGraphNode* v0_clone = sol.cloneGraph( v0 );

  EXPECT_NE(nullptr, v0_clone);
  EXPECT_NE(v0, v0_clone);
  EXPECT_EQ(v0->neighbors.size(), v0_clone->neighbors.size());
  EXPECT_NE(v0->neighbors[0], v0_clone->neighbors[0]);
  EXPECT_EQ(v0->neighbors[0]->neighbors.size(), v0_clone->neighbors[0]->neighbors.size());
}

TEST(CloneGraph, 3VerticesWithCycle) {
  UndirectedGraphNode* v0 = new UndirectedGraphNode(-1);
  UndirectedGraphNode* v1 = new UndirectedGraphNode(1);
  UndirectedGraphNode* v2 = new UndirectedGraphNode(2);

  v0->neighbors.push_back(v1);
  v0->neighbors.push_back(v2);

  v1->neighbors.push_back(v2);

  v2->neighbors.push_back(v2);

  Solution sol;
  UndirectedGraphNode *v0_clone = sol.cloneGraph(v0);
  EXPECT_NE(nullptr, v0_clone);
  EXPECT_NE(v0, v0_clone);
  EXPECT_EQ(v0->neighbors.size(), v0_clone->neighbors.size());
  for ( int i=0; i<v0_clone->neighbors.size(); i++ ) {
    EXPECT_NE(nullptr, v0_clone->neighbors[i]);
    EXPECT_NE(v0->neighbors[i], v0_clone->neighbors[i]);

    EXPECT_EQ(v0->neighbors[i]->label, v0_clone->neighbors[i]->label);
    EXPECT_EQ(1, v0_clone->neighbors[i]->neighbors.size());
    EXPECT_NE(v2, v0_clone->neighbors[i]->neighbors[0]);
  }
}

