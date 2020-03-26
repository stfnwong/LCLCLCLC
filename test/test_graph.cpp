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
        // this graph is from cracking the code pg 118
        std::string repr3      = "{0,1,4,5#1,4,3#2,1#3,2,4#4#5}";   

        // expected outputs
        // graph 1
        std::vector<int> expected_dfs_1 = {0,2,1};
        std::vector<int> expected_bfs_1 = {0,1,2};
        // graph 2
        std::vector<int> expected_dfs_2 = {0,1,2,3,4};
        std::vector<int> expected_bfs_2 = {0,1,2,3,4};
        // graph 3
        std::vector<int> expected_dfs_3 = {0, 1, 3, 2, 4, 5};
        std::vector<int> expected_bfs_3 = {0, 1, 4, 5, 3, 2};
};


/*
 * print_array()
 * Prints an array of its with matching {}
 */
void print_array(const std::vector<int>& array)
{
    std::cout << "[" << __func__ << "] array of " 
        << array.size() << " elements" << std::endl;
    std::cout << "  {" << array[0];
    for(unsigned int i = 1; i < array.size(); ++i)
        std::cout << "," << array[i];
    std::cout << "}" << std::endl;
}

/*
 * print_traversal()
 * Prints a GraphKV traversal of its with matching {}
 */
void print_traversal(const std::vector<GraphKV>& traversal)
{
    std::cout << "[" << __func__ << "] traversal with " 
        << traversal.size() << " steps" << std::endl;

    std::cout << "  {" << traversal[0].key;
    for(unsigned int t = 1; t < traversal.size(); ++t)
        std::cout << "," << traversal[t].key;
    std::cout << "}" << std::endl;
}


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
TEST_F(TestGraph, test_graph1_bfs)
{
    // ======== GRAPH 1 ======== //
    // Try to traverse the first graph
    GraphNode* graph1;
    std::vector<GraphKV> traversal1;

    graph1 = createGraph(this->repr1);
    ASSERT_NE(nullptr, graph1);

    std::cout << std::endl << "==== Traversng graph1 (BFS)" << std::endl;
    graph_bfs(graph1, traversal1);
    std::cout << "Graph1 " << this->repr1 << " traversal: " << std::endl;
    print_traversal(traversal1);
    std::cout << "Graph1 expected traversal :" << std::endl;
    print_array(this->expected_bfs_1);

    ASSERT_GT(0, traversal1.size());
    ASSERT_EQ(this->expected_bfs_1.size(), traversal1.size());

    for(unsigned int n = 0; n < this->expected_bfs_1.size(); ++n)
    {
        ASSERT_EQ(this->expected_bfs_1[n], traversal1[n].key);
    }
}


TEST_F(TestGraph, test_graph2_bfs)
{
    // ======== GRAPH 2 ======== //
    // Try to traverse the second graph
    GraphNode* graph2;
    std::vector<GraphKV> traversal2;

    graph2 = createGraph(this->repr2);
    ASSERT_NE(nullptr, graph2);

    std::cout << std::endl << "==== Traversng graph2 (BFS)" << std::endl;
    graph_bfs(graph2, traversal2);
    // Do the real testing
    ASSERT_GT(0, traversal2.size());
    print_traversal(traversal2);
    ASSERT_GT(0, traversal2.size());
    ASSERT_EQ(this->expected_bfs_2.size(), traversal2.size());
}

TEST_F(TestGraph, test_graph3_bfs)
{
    // ======== GRAPH 3 ======== //
    GraphNode* graph3;
    std::vector<GraphKV> traversal3;

    graph3 = createGraph(this->repr3);
    ASSERT_NE(nullptr, graph3);

    std::cout << std::endl << "==== Traversng graph3 (BFS)" << std::endl;
    graph_bfs(graph3, traversal3);

    ASSERT_GT(0, traversal3.size());
    print_traversal(traversal3);
    ASSERT_GT(0, traversal3.size());
    ASSERT_EQ(this->expected_bfs_3.size(), traversal3.size());

    // check the traversal

}

// Test graph dfs
TEST_F(TestGraph, test_graph_dfs)
{
    // Try to traverse the first graph
    GraphNode* graph3;
    std::vector<GraphKV> traversal3;

    graph3 = createGraph(this->repr3);
    ASSERT_NE(nullptr, graph3);

    std::cout << std::endl << "==== Traversng graph3 (DFS)" << std::endl;
    graph_dfs(graph3, traversal3);
    //ASSERT_GT(0, traversal3.size());

    std::cout << "Printing DFS traversal1 (length " << traversal3.size() << ") :" << std::endl;
    print_traversal(traversal3);
    std::cout << "Expected traversal : " << std::endl;
    print_array(this->expected_dfs_3);

    // Test each value in turn
    for(unsigned int t = 0; t < traversal3.size(); ++t)
    {
        ASSERT_EQ(this->expected_dfs_3[t], traversal3[t].key);
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
