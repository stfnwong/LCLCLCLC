/* TEST_GRAPH
 * Test various graph things
 *
 * Stefan Wong 2019
 */

#define CATCH_CONFIG_MAIN
#include "catch/catch.hpp"

#include <vector>
#include <string>
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

const std::string empty_repr = "{}";
const std::string repr1      = "{0,1,2#1,2#2,2}";
const std::string repr2      = "{0,1,2#1,2#2,2,4#3,1,0#4,2,3}";
// this graph is from cracking the code pg 118
const std::string repr3      = "{0,1,4,5#1,4,3#2,1#3,2,4#4#5}";   

// expected outputs
// graph 1
const std::vector<int> expected_dfs_1 = {0,1,2};
const std::vector<int> expected_bfs_1 = {0,1,2};
// graph 2
const std::vector<int> expected_dfs_2 = {0,1,2,4,3};
const std::vector<int> expected_bfs_2 = {0,1,2,4,3};
// graph 3
const std::vector<int> expected_dfs_3 = {0, 1, 4, 3, 2, 5};
const std::vector<int> expected_bfs_3 = {0, 1, 4, 5, 3, 2};



// =============== TEST GRAPH NODE ================ //
TEST_CASE("GraphNode test_graph_size", "[classic]")
{
    GraphNode* graph1;
    GraphNode* graph2;
    GraphNode* graph3;
    GraphNode* empty_graph;

    graph1 = createGraph(repr1);
    REQUIRE(nullptr != graph1);
    REQUIRE(3 == graphNodeSize(graph1));

    graph2 = createGraph(repr2);
    REQUIRE(nullptr != graph2);
    REQUIRE(5 == graphNodeSize(graph2));

    graph3 = createGraph(repr3);
    REQUIRE(nullptr != graph3);
    REQUIRE(6 == graphNodeSize(graph3));
    
    empty_graph = createGraph(empty_repr);
    REQUIRE(nullptr == empty_graph);
    REQUIRE(0 == graphNodeSize(empty_graph));
}

// Test that we can turn a repr string into a graph
TEST_CASE("GraphNode test_graph_repr", "[classic]")
{
    GraphNode* empty_graph;
    GraphNode* graph1;

    // The empty graph contains nothing
    empty_graph = createGraph(empty_repr);    
    REQUIRE(nullptr == empty_graph);

    graph1 = createGraph(repr1);
    REQUIRE(nullptr != graph1);
    // The key for the first node is zero, as is its value (as per the construction in createGraph())
    REQUIRE(0 == graph1->uid);
    REQUIRE(0 == graph1->val);
    // Note that the string representation is just the key and value of THIS node - 
    // it does not traverse the graph to print all components.
    std::cout << "String representation of Graph1: " << std::endl  << graph1->toString() << std::endl;
}

// Breadth-first search on GraphNode object
TEST_CASE("GraphNode test_graph1_bfs", "[classic]")
{
    // ======== GRAPH 1 ======== //
    // Try to traverse the first graph
    GraphNode* graph1;
    std::vector<int> traversal1;

    graph1 = createGraph(repr1);
    REQUIRE(nullptr != graph1);

    std::cout << std::endl << "==== Traversng graph1 (BFS)" << std::endl;
    std::cout << graph1->toString() << std::endl;
    graph_node_bfs(graph1, traversal1);
    std::cout << "Graph1 " << repr1 << " traversal: " << std::endl;
    print_traversal(traversal1);
    std::cout << "Graph1 expected traversal :" << std::endl;
    print_array(expected_bfs_1);

    REQUIRE(traversal1.size() > 0);
    REQUIRE(expected_bfs_1.size() == traversal1.size());

    for(unsigned int n = 0; n < expected_bfs_1.size(); ++n)
    {
        REQUIRE(expected_bfs_1[n] == traversal1[n]);
    }
}

TEST_CASE("GraphNode test_graph2_bfs", "[classic]")
{
    // ======== GRAPH 2 ======== //
    // Try to traverse the second graph
    GraphNode* graph2;
    std::vector<int> traversal2;

    graph2 = createGraph(repr2);
    REQUIRE(nullptr != graph2);

    std::cout << std::endl << "==== Traversng graph2 (BFS)" << std::endl;
    std::cout << graph2->toString() << std::endl;
    graph_node_bfs(graph2, traversal2);

    std::cout << "Graph2 " << repr2 << " traversal: " << std::endl;
    print_traversal(traversal2);
    std::cout << "Graph2 expected traversal :" << std::endl;
    print_array(expected_bfs_2);

    // Do the real testing
    REQUIRE(traversal2.size() > 0);
    print_traversal(traversal2);
    REQUIRE(traversal2.size() > 0);
    REQUIRE(expected_bfs_2.size() == traversal2.size());

    for(unsigned int n = 0; n < expected_bfs_2.size(); ++n)
        REQUIRE(expected_bfs_2[n] == traversal2[n]);
}

TEST_CASE("GraphNode test_graph3_bfs", "[classic]")
{
    // ======== GRAPH 3 ======== //
    GraphNode* graph3;
    std::vector<int> traversal3;

    graph3 = createGraph(repr3);
    REQUIRE(nullptr != graph3);

    std::cout << std::endl << "==== Traversng graph3 (BFS)" << std::endl;
    graph_node_bfs(graph3, traversal3);

    REQUIRE(traversal3.size() > 0);
    print_traversal(traversal3);
    REQUIRE(traversal3.size() > 0);
    REQUIRE(expected_bfs_3.size() == traversal3.size());

    // check the traversal
    for(unsigned int n = 0; n < expected_bfs_3.size(); ++n)
        REQUIRE(expected_bfs_3[n] == traversal3[n]);
}

// Test graph dfs
TEST_CASE("GraphNode test_graph1_dfs", "[classic]")
{
    GraphNode* graph1;
    std::vector<int> traversal1;

    graph1 = createGraph(repr1);
    REQUIRE(nullptr != graph1);

    std::cout << std::endl << "==== Traversng graph1 (DFS)" << std::endl;
    graph_node_dfs(graph1, traversal1);
    REQUIRE(traversal1.size() > 0);

    std::cout << "Graph1 " << repr1 << " traversal: " << std::endl;
    print_traversal(traversal1);
    std::cout << "Graph3 expected traversal :" << std::endl;
    print_array(expected_dfs_1);

    REQUIRE(expected_dfs_1.size() == traversal1.size());

    for(unsigned int n = 0; n < expected_dfs_1.size(); ++n)
        REQUIRE(expected_dfs_1[n] == traversal1[n]);
}

TEST_CASE("GraphNode test_graph2_dfs", "[classic]")
{
    GraphNode* graph2;
    std::vector<int> traversal2;

    graph2 = createGraph(repr2);
    REQUIRE(nullptr != graph2);

    std::cout << std::endl << "==== Traversng graph2 (DFS)" << std::endl;
    graph_node_dfs(graph2, traversal2);
    REQUIRE(traversal2.size() > 0);

    std::cout << "Graph2 " << repr2 << " traversal: " << std::endl;
    print_traversal(traversal2);
    std::cout << "Graph2 expected traversal :" << std::endl;
    print_array(expected_dfs_2);

    REQUIRE(expected_dfs_2.size() == traversal2.size());

    // Test each value in turn
    for(unsigned int t = 0; t < traversal2.size(); ++t)
    {
        REQUIRE(expected_dfs_2[t] == traversal2[t]);
    }
}

TEST_CASE("GraphNode test_graph3_dfs", "[classic]")
{
    // Try to traverse the first graph
    GraphNode* graph3;
    std::vector<int> traversal3;

    graph3 = createGraph(repr3);
    REQUIRE(nullptr != graph3);

    std::cout << std::endl << "==== Traversng graph3 (DFS)" << std::endl;
    graph_node_dfs(graph3, traversal3);
    REQUIRE(traversal3.size() > 0);

    std::cout << "Graph3 " << repr3 << " traversal: " << std::endl;
    print_traversal(traversal3);
    std::cout << "Graph3 expected traversal :" << std::endl;
    print_array(expected_dfs_3);

    REQUIRE(expected_dfs_3.size() == traversal3.size());

    // Test each value in turn
    for(unsigned int t = 0; t < traversal3.size(); ++t)
    {
        REQUIRE(expected_dfs_3[t] == traversal3[t]);
    }
}


TEST_CASE("GraphNode test_graph_equal", "[classic]")
{
    GraphNode* graph_a;
    GraphNode* graph_b;

    graph_a = createGraph(repr2);
    graph_b = createGraph(repr2);

    // These graphs are the same, and therefore we expect
    // that graph_node_equal() will return true
    REQUIRE(true == graph_node_equal(graph_a, graph_b));
}

TEST_CASE("GraphNode test_graph_not_equal", "[classic]")
{
    GraphNode* graph_a;
    GraphNode* graph_b;

    graph_a = createGraph(repr2);
    graph_b = createGraph(repr3);

    // These graphs are the same, and therefore we expect
    // that graph_node_equal() will return true
    REQUIRE(false == graph_node_equal(graph_a, graph_b));
}


TEST_CASE("GraphNode test_clone", "[classic]")
{
    GraphNode* src_graph;
    GraphNode* dst_graph;

    // Use graph3
    src_graph = createGraph(repr3);
    REQUIRE(nullptr != src_graph);

    // Now try to clone
    dst_graph = cloneGraphNode(src_graph); 
    REQUIRE(nullptr != dst_graph);

    // If the clone worked, then these graphs will be equal
    REQUIRE(true == graph_node_equal(src_graph, dst_graph));
}


// =============== TEST GRAPH ================ //
TEST_CASE("TestGraph, test_graph_init", "[classic]")
{
    Graph test_graph;

    REQUIRE(0 == test_graph.size());
}

TEST_CASE("TestGraph, test_graph_add_node", "[classic]")
{
    Graph test_graph;
    GraphNode* test_node1 = new GraphNode(0, 1);

    REQUIRE(0 == test_graph.size());

    test_graph.addNode(test_node1);
    std::cout << "Added node [" << test_node1->toString() << "] to graph" << std::endl;
    REQUIRE(1 == test_graph.size());

    // Show updated node
    std::cout << test_graph.toString() << std::endl;

    GraphNode* test_node2 = new GraphNode(1, 2);
    test_graph.addNode(test_node2);
    REQUIRE(2 == test_graph.size());

    // Show updated node
    std::cout << test_graph.toString() << std::endl;

    // Now add a node that has 0, 1 as neighous
    GraphNode* test_node3 = new GraphNode(2, 2);
    test_node3->addAdj(test_node1);
    test_node3->addAdj(test_node2);
    REQUIRE(2 == test_node3->numAdj());

    test_graph.addNode(test_node3);

    REQUIRE(3 == test_graph.size());

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
    REQUIRE(nullptr == out_node);       

    out_node = test_graph.get(0);
    REQUIRE(nullptr != out_node);
    REQUIRE(test_node1 == out_node);

    out_node = test_graph.get(1);
    REQUIRE(nullptr != out_node);
    REQUIRE(test_node2 == out_node);

    out_node = test_graph.get(2);
    REQUIRE(nullptr != out_node);
    REQUIRE(test_node3 == out_node);

    test_graph.init();
    REQUIRE(0 == test_graph.size());
}

