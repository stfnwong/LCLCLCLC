/* TEST_GRAPH
 * Test various graph things
 *
 * Stefan Wong 2019
 */

#include <vector>
#include <string>
#include <gtest/gtest.h>
#include "graph.hpp"

class TestGraph : public ::testing::Test
{
    virtual void SetUp() {}
    virtual void TearDown() {}

    public:
        std::string empty_repr = "{}";
        std::string repr1 = "{0,1,2#1,2#2,2}";
};

// Test that we can turn a repr string into a graph
TEST_F(TestGraph, test_graph_repr)
{
    GraphNode* empty_graph;
    GraphNode* graph1;

    // The empty graph contains nothing
    empty_graph = createGraph(this->empty_repr);    
    ASSERT_EQ(nullptr, empty_graph);

    graph1 = createGraph(this->repr1);
    ASSERT_NE(nullptr, graph1);
    std::cout << "graph1->key : " << graph1->key << std::endl;
    std::cout << "graph1->val : " << graph1->val << std::endl;
    std::cout << "Graph1: " << std::endl  << graph1->toString() << std::endl;
}

//TEST_F(TestGraph, test_clone)
//{
//    GraphNode* src_graph;
//    GraphNode* dst_graph;
//
//
//    // Need to make a src_graph to test with.
//}


class TestAdj : public ::testing::Test
{
    virtual void SetUp() {}
    virtual void TearDown() {}

    public:
        unsigned int test_v = 8;
        std::string repr1 = "{0,1,2#1,2#2,2}";
};

TEST_F(TestAdj, test_adj_matrix_init)
{
    AdjMatrix test_matrix(this->test_v);
    
    ASSERT_EQ(this->test_v, test_matrix.getDim());     // TODO: come up with a real test
    // Start adding some edges 
    // TODO : make a repr here that we can parse. The most natural way to do this would be a similar adjacency 
    // list format, maybe something like [k1, k2, #] for an edge that connectes to nodes k1, k2 (values are omitted).

    std::vector<GraphEdge> edge1 = {GraphEdge(2, 0)};
    std::vector<GraphEdge> edge2 = {GraphEdge(8, 1), GraphEdge(5, 1), GraphEdge(4, 1), GraphEdge(1, 0)};
    std::vector<GraphEdge> edge3 = {GraphEdge(4, 0)};
    std::vector<GraphEdge> edge4 = {GraphEdge(2, 0), GraphEdge(3, 0)};
    std::vector<GraphEdge> edge5 = {GraphEdge(2, 0), GraphEdge(7, 0), GraphEdge(6, 0), GraphEdge(9, 0)};
    std::vector<GraphEdge> edge6 = {GraphEdge(5, 0)};
    std::vector<GraphEdge> edge7 = {GraphEdge(5, 0)};
    std::vector<GraphEdge> edge8 = {GraphEdge(2, 0)};
    std::vector<GraphEdge> edge9 = {GraphEdge(5, 0)};

}


// Test that we can make a new AdjList object
TEST_F(TestAdj, test_adj_list_init)
{
    AdjList test_list(this->repr1);

    std::cout << test_list.toString() << std::endl;
}



int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

