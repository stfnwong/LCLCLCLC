/* TEST_GRAPH
 * Test various graph things
 *
 * Stefan Wong 2019
 */

#include <vector>
#include <string>
#include <gtest/gtest.h>
#include "graph.hpp"

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
 * Prints a int traversal of its with matching {}
 */
void print_traversal(const std::vector<int>& traversal)
{
    std::cout << "[" << __func__ << "] traversal with " 
        << traversal.size() << " steps" << std::endl;

    std::cout << "  {" << traversal[0];
    for(unsigned int t = 1; t < traversal.size(); ++t)
        std::cout << "," << traversal[t];
    std::cout << "}" << std::endl;
}


// ================ UNIT TESTS ================= //
class TestGraphNode : public ::testing::Test
{
    virtual void SetUp() {}
    virtual void TearDown() {}

    public:
        std::string empty_repr = "{}";
        std::string repr1      = "{0,1,2#1,2#2,2}";
        std::string repr2      = "{0,1,2#1,2#2,2,4#3,1,0#4,2,3}";
        // this graph is from cracking the code pg 118
        std::string repr3      = "{0,1,4,5#1,4,3#2,1#3,2,4#4#5}";   

        // expected outputs
        // graph 1
        std::vector<int> expected_dfs_1 = {0,1,2};
        std::vector<int> expected_bfs_1 = {0,1,2};
        // graph 2
        std::vector<int> expected_dfs_2 = {0,1,2,4,3};
        std::vector<int> expected_bfs_2 = {0,1,2,4,3};
        // graph 3
        std::vector<int> expected_dfs_3 = {0, 1, 4, 3, 2, 5};
        std::vector<int> expected_bfs_3 = {0, 1, 4, 5, 3, 2};
};



TEST_F(TestGraphNode, test_graph_size)
{
    GraphNode* graph1;
    GraphNode* graph2;
    GraphNode* graph3;
    GraphNode* empty_graph;

    graph1 = createGraph(this->repr1);
    ASSERT_NE(nullptr, graph1);
    ASSERT_EQ(3, graphNodeSize(graph1));

    graph2 = createGraph(this->repr2);
    ASSERT_NE(nullptr, graph2);
    ASSERT_EQ(5, graphNodeSize(graph2));

    graph3 = createGraph(this->repr3);
    ASSERT_NE(nullptr, graph3);
    ASSERT_EQ(6, graphNodeSize(graph3));
    
    empty_graph = createGraph(this->empty_repr);
    ASSERT_EQ(nullptr, empty_graph);
    ASSERT_EQ(0, graphNodeSize(empty_graph));
}


// Test that we can turn a repr string into a graph
TEST_F(TestGraphNode, test_graph_repr)
{
    GraphNode* empty_graph;
    GraphNode* graph1;

    // The empty graph contains nothing
    empty_graph = createGraph(this->empty_repr);    
    ASSERT_EQ(nullptr, empty_graph);

    graph1 = createGraph(this->repr1);
    ASSERT_NE(nullptr, graph1);
    // The key for the first node is zero, as is its value (as per the construction in createGraph())
    ASSERT_EQ(0, graph1->uid);
    ASSERT_EQ(0, graph1->val);
    // Note that the string representation is just the key and value of THIS node - 
    // it does not traverse the graph to print all components.
    std::cout << "String representation of Graph1: " << std::endl  << graph1->toString() << std::endl;
}

// Breadth-first search on GraphNode object
TEST_F(TestGraphNode, test_graph1_bfs)
{
    // ======== GRAPH 1 ======== //
    // Try to traverse the first graph
    GraphNode* graph1;
    std::vector<int> traversal1;

    graph1 = createGraph(this->repr1);
    ASSERT_NE(nullptr, graph1);

    std::cout << std::endl << "==== Traversng graph1 (BFS)" << std::endl;
    std::cout << graph1->toString() << std::endl;
    graph_node_bfs(graph1, traversal1);
    std::cout << "Graph1 " << this->repr1 << " traversal: " << std::endl;
    print_traversal(traversal1);
    std::cout << "Graph1 expected traversal :" << std::endl;
    print_array(this->expected_bfs_1);

    ASSERT_GT(traversal1.size(), 0);
    ASSERT_EQ(this->expected_bfs_1.size(), traversal1.size());

    for(unsigned int n = 0; n < this->expected_bfs_1.size(); ++n)
    {
        ASSERT_EQ(this->expected_bfs_1[n], traversal1[n]);
    }
}

TEST_F(TestGraphNode, test_graph2_bfs)
{
    // ======== GRAPH 2 ======== //
    // Try to traverse the second graph
    GraphNode* graph2;
    std::vector<int> traversal2;

    graph2 = createGraph(this->repr2);
    ASSERT_NE(nullptr, graph2);

    std::cout << std::endl << "==== Traversng graph2 (BFS)" << std::endl;
    std::cout << graph2->toString() << std::endl;
    graph_node_bfs(graph2, traversal2);

    std::cout << "Graph2 " << this->repr2 << " traversal: " << std::endl;
    print_traversal(traversal2);
    std::cout << "Graph2 expected traversal :" << std::endl;
    print_array(this->expected_bfs_2);

    // Do the real testing
    ASSERT_GT(traversal2.size(), 0);
    print_traversal(traversal2);
    ASSERT_GT(traversal2.size(), 0);
    ASSERT_EQ(this->expected_bfs_2.size(), traversal2.size());

    for(unsigned int n = 0; n < this->expected_bfs_2.size(); ++n)
        ASSERT_EQ(this->expected_bfs_2[n], traversal2[n]);
}

TEST_F(TestGraphNode, test_graph3_bfs)
{
    // ======== GRAPH 3 ======== //
    GraphNode* graph3;
    std::vector<int> traversal3;

    graph3 = createGraph(this->repr3);
    ASSERT_NE(nullptr, graph3);

    std::cout << std::endl << "==== Traversng graph3 (BFS)" << std::endl;
    graph_node_bfs(graph3, traversal3);

    ASSERT_GT(traversal3.size(), 0);
    print_traversal(traversal3);
    ASSERT_GT(traversal3.size(), 0);
    ASSERT_EQ(this->expected_bfs_3.size(), traversal3.size());

    // check the traversal
    for(unsigned int n = 0; n < this->expected_bfs_3.size(); ++n)
        ASSERT_EQ(this->expected_bfs_3[n], traversal3[n]);
}

// Test graph dfs
TEST_F(TestGraphNode, test_graph1_dfs)
{
    GraphNode* graph1;
    std::vector<int> traversal1;

    graph1 = createGraph(this->repr1);
    ASSERT_NE(nullptr, graph1);

    std::cout << std::endl << "==== Traversng graph1 (DFS)" << std::endl;
    graph_node_dfs(graph1, traversal1);
    ASSERT_GT(traversal1.size(), 0);

    std::cout << "Graph1 " << this->repr1 << " traversal: " << std::endl;
    print_traversal(traversal1);
    std::cout << "Graph3 expected traversal :" << std::endl;
    print_array(this->expected_dfs_1);

    ASSERT_EQ(this->expected_dfs_1.size(), traversal1.size());

    for(unsigned int n = 0; n < this->expected_dfs_1.size(); ++n)
        ASSERT_EQ(this->expected_dfs_1[n], traversal1[n]);
}

TEST_F(TestGraphNode, test_graph2_dfs)
{
    GraphNode* graph2;
    std::vector<int> traversal2;

    graph2 = createGraph(this->repr2);
    ASSERT_NE(nullptr, graph2);

    std::cout << std::endl << "==== Traversng graph2 (DFS)" << std::endl;
    graph_node_dfs(graph2, traversal2);
    ASSERT_GT(traversal2.size(), 0);

    std::cout << "Graph2 " << this->repr2 << " traversal: " << std::endl;
    print_traversal(traversal2);
    std::cout << "Graph2 expected traversal :" << std::endl;
    print_array(this->expected_dfs_2);

    ASSERT_EQ(this->expected_dfs_2.size(), traversal2.size());

    // Test each value in turn
    for(unsigned int t = 0; t < traversal2.size(); ++t)
    {
        ASSERT_EQ(this->expected_dfs_2[t], traversal2[t]);
    }
}

TEST_F(TestGraphNode, test_graph3_dfs)
{
    // Try to traverse the first graph
    GraphNode* graph3;
    std::vector<int> traversal3;

    graph3 = createGraph(this->repr3);
    ASSERT_NE(nullptr, graph3);

    std::cout << std::endl << "==== Traversng graph3 (DFS)" << std::endl;
    graph_node_dfs(graph3, traversal3);
    ASSERT_GT(traversal3.size(), 0);

    std::cout << "Graph3 " << this->repr3 << " traversal: " << std::endl;
    print_traversal(traversal3);
    std::cout << "Graph3 expected traversal :" << std::endl;
    print_array(this->expected_dfs_3);

    ASSERT_EQ(this->expected_dfs_3.size(), traversal3.size());

    // Test each value in turn
    for(unsigned int t = 0; t < traversal3.size(); ++t)
    {
        ASSERT_EQ(this->expected_dfs_3[t], traversal3[t]);
    }
}


TEST_F(TestGraphNode, test_graph_equal)
{
    GraphNode* graph_a;
    GraphNode* graph_b;

    graph_a = createGraph(this->repr2);
    graph_b = createGraph(this->repr2);

    // These graphs are the same, and therefore we expect
    // that graph_node_equal() will return true
    ASSERT_EQ(true, graph_node_equal(graph_a, graph_b));
}

TEST_F(TestGraphNode, test_graph_not_equal)
{
    GraphNode* graph_a;
    GraphNode* graph_b;

    graph_a = createGraph(this->repr2);
    graph_b = createGraph(this->repr3);

    // These graphs are the same, and therefore we expect
    // that graph_node_equal() will return true
    ASSERT_EQ(false, graph_node_equal(graph_a, graph_b));
}


TEST_F(TestGraphNode, test_clone)
{
    GraphNode* src_graph;
    GraphNode* dst_graph;

    // Use graph3
    src_graph = createGraph(this->repr3);
    ASSERT_NE(nullptr, src_graph);

    // Now try to clone
    dst_graph = cloneGraphNode(src_graph); 
    ASSERT_NE(nullptr, dst_graph);

    // If the clone worked, then these graphs will be equal
    ASSERT_EQ(true, graph_node_equal(src_graph, dst_graph));
}



class TestGraph : public ::testing::Test
{
    virtual void SetUp() {}
    virtual void TearDown() {}

    public:

};

TEST_F(TestGraph, test_graph_init)
{
    Graph test_graph;

    ASSERT_EQ(0, test_graph.size());
}

TEST_F(TestGraph, test_graph_add_node)
{
    Graph test_graph;
    GraphNode* test_node1 = new GraphNode(0, 1);

    ASSERT_EQ(0, test_graph.size());

    test_graph.addNode(test_node1);
    std::cout << "Added node [" << test_node1->toString() << "] to graph" << std::endl;
    ASSERT_EQ(1, test_graph.size());

    // Show updated node
    std::cout << test_graph.toString() << std::endl;

    GraphNode* test_node2 = new GraphNode(1, 2);
    test_graph.addNode(test_node2);
    ASSERT_EQ(2, test_graph.size());

    // Show updated node
    std::cout << test_graph.toString() << std::endl;

    // Now add a node that has 0, 1 as neighous
    GraphNode* test_node3 = new GraphNode(2, 2);
    test_node3->addAdj(test_node1);
    test_node3->addAdj(test_node2);
    ASSERT_EQ(2, test_node3->numAdj());

    test_graph.addNode(test_node3);

    ASSERT_EQ(3, test_graph.size());

    // Show updated node
    std::cout << test_graph.toString() << std::endl;

    std::vector<int> ids = test_graph.getIds();
    std::cout << "Found there are " << ids.size() << " ids in graph" << std::endl;
    for(unsigned int i = 0; i < ids.size(); ++i)
    {
        std::cout << "    " << i << " : " << ids[i] << std::endl;
    }

    // Now check some of the nodes
    GraphNode* out_node;

    // There is no such node, so we should get a nullptr here
    out_node = test_graph.get(10);
    ASSERT_EQ(nullptr, out_node);       

    out_node = test_graph.get(0);
    ASSERT_NE(nullptr, out_node);
    ASSERT_EQ(test_node1, out_node);

    out_node = test_graph.get(1);
    ASSERT_NE(nullptr, out_node);
    ASSERT_EQ(test_node2, out_node);

    out_node = test_graph.get(2);
    ASSERT_NE(nullptr, out_node);
    ASSERT_EQ(test_node3, out_node);

    test_graph.init();
    ASSERT_EQ(0, test_graph.size());
}


//TEST_F(TestGraph, test_graph_add_edge)
//{
//
//}

//class TestAdj : public ::testing::Test
//{
//    virtual void SetUp() {}
//    virtual void TearDown() {}
//
//    public:
//        unsigned int test_v = 8;
//        std::string repr1 = "{0,1,2#1,2#2,2}";
//};
//
//
//TEST_F(TestAdj, test_adj_matrix_init)
//{
//    AdjMatrix test_matrix(this->test_v);
//    
//    ASSERT_EQ(this->test_v, test_matrix.getDim());     // TODO: come up with a real test
//    // Start adding some edges 
//    // Make a repr here that we can parse. The most natural way to do this would be a similar adjacency 
//    // list format, maybe something like [k1, k2, #] for an edge that connectes to nodes k1, k2 (values are omitted).
//    std::vector<GraphEdge> edge1 = {GraphEdge(2, 0)};
//    std::vector<GraphEdge> edge2 = {GraphEdge(8, 1), GraphEdge(5, 1), GraphEdge(4, 1), GraphEdge(1, 0)};
//    std::vector<GraphEdge> edge3 = {GraphEdge(4, 0)};
//    std::vector<GraphEdge> edge4 = {GraphEdge(2, 0), GraphEdge(3, 0)};
//    std::vector<GraphEdge> edge5 = {GraphEdge(2, 0), GraphEdge(7, 0), GraphEdge(6, 0), GraphEdge(9, 0)};
//    std::vector<GraphEdge> edge6 = {GraphEdge(5, 0)};
//    std::vector<GraphEdge> edge7 = {GraphEdge(5, 0)};
//    std::vector<GraphEdge> edge8 = {GraphEdge(2, 0)};
//    std::vector<GraphEdge> edge9 = {GraphEdge(5, 0)};
//
//}
// Test that we can make a new AdjList object
//TEST_F(TestAdj, test_adj_list_init)
//{
//    AdjList test_list(this->repr1);
//
//    std::cout << "test_list string representation : " << std::endl;
//    std::cout << "\t" << test_list.toString() << std::endl;
//}



int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

