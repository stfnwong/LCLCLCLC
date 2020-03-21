/* TEST_EDGE_GRAPH
 * Test various graph things - this time for edge weighted directed graph
 *
 * Stefan Wong 2020
 */
#define CATCH_CONFIG_MAIN
#include "catch/catch.hpp"

#include <vector>
#include <string>
#include "edge_graph.hpp"

const std::string tiny_graph_file = "data/tiny_ewd.txt";

TEST_CASE("TestDirectedEdge, test_init", "[classic]")
{
    DirectedEdge test_edge;

    std::cout << "[" << __func__ << "] Generated default DirectedEdge (" << 
        test_edge.toString() << ")" << std::endl;
    
    REQUIRE(0 == test_edge.getTo());
    REQUIRE(0 == test_edge.getFrom());
    REQUIRE(0.0 == Approx(test_edge.getWeight()));
}


/*
 * SOME GENERAL ASSUMPTIONS ABOUT GRAPHS BEING TESTED HERE
 *   - Paths are directed
 *   - Weights are not necessarily distance.
 *   - Not all verticies are reachable
 *   - Negative weights introduce complications.
 *   - Shortest paths are simple
 *   - Shortest paths are not strictly unique.
 *   - Parallel edges and self-loops may be present.
 */

TEST_CASE("TestEdgeGraph, test_file_read", "[classic]")
{
    std::string repr_text;

    repr_text = repr_from_file(tiny_graph_file);

    std::cout << "[" << __func__ << "] repr output:" << std::endl;
    std::cout << repr_text << std::endl;
}

TEST_CASE("TestEdgeGraph, test_init", "[classic]")
{
    // init a default graph
    EdgeWeightedDigraph default_graph;

    REQUIRE(0 == default_graph.numVerticies());
    REQUIRE(0 == default_graph.numEdges());
}
