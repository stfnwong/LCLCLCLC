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
        std::string repr1      = "{0,1,2#1,2#2,2}";
        std::string repr2      = "{0,1,2#1,2#2,2#3,1,0#4,2,3}";
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
    // The key for the first node is zero, as is its value (as per the construction in createGraph())
    ASSERT_EQ(0, graph1->key);
    ASSERT_EQ(0, graph1->val);
    // Note that the string representation is just the key and value of THIS node - 
    // it does not traverse the graph to print all components.
    std::cout << "String representation of Graph1: " << std::endl  << graph1->toString() << std::endl;
}

// Breadth-first search on GraphNode object
TEST_F(TestGraph, test_graph_bfs)
{
    // Try to traverse the first graph
    GraphNode* graph1;
    std::vector<GraphKV> traversal1;

    graph1 = createGraph(this->repr1);
    ASSERT_NE(nullptr, graph1);

    std::cout << "Traversng graph1 (BFS)" << std::endl;
    graph_bfs(graph1, traversal1);
    //ASSERT_GT(0, traversal1.size());

    std::cout << "Printing BFS traversal1 (length " << traversal1.size() << ") :" << std::endl;
    for(unsigned int t = 0; t < traversal1.size(); ++t)
    {
        std::cout << "    " << traversal1[t].toString() << " ->" << std::endl;
    }

    // TODO : fix this - traversal is too long
    //ASSERT_EQ(3, traversal1.size());

    // Try to traverse the second graph
    GraphNode* graph2;
    std::vector<GraphKV> traversal2;

    graph2 = createGraph(this->repr2);
    ASSERT_NE(nullptr, graph2);

    std::cout << "Traversng graph2 (BFS)" << std::endl;
    graph_bfs(graph2, traversal2);
    //ASSERT_GT(0, traversal2.size());

    std::cout << "Printing BFS traversal2 (length " << traversal2.size() << ") :" << std::endl;
    for(unsigned int t = 0; t < traversal2.size(); ++t)
    {
        std::cout << "    " << traversal2[t].toString() << " ->" << std::endl;
    }
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
    // Make a repr here that we can parse. The most natural way to do this would be a similar adjacency 
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

    std::cout << "test_list string representation : " << std::endl;
    std::cout << "\t" << test_list.toString() << std::endl;
}



int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

