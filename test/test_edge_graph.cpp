/* TEST_EDGE_GRAPH
 * Test various graph things - this time for edge weighted directed graph
 *
 * Stefan Wong 2020
 */

#include <vector>
#include <string>
#include <gtest/gtest.h>
#include "edge_graph.hpp"


/*
 * Test just the DirectedEdge class
 */
class TestDirectedEdge : public ::testing::Test
{
    virtual void SetUp() {}
    virtual void TearDown() {}

};

TEST_F(TestDirectedEdge, test_init)
{
    DirectedEdge test_edge;


    std::cout << "[" << __func__ << "] Generated default DirectedEdge (" << 
        test_edge.toString() << ")" << std::endl;
    
    ASSERT_EQ(0, test_edge.getTo());
    ASSERT_EQ(0, test_edge.getFrom());
    ASSERT_EQ(0.0, test_edge.getWeight());
}


/*
 * Tests for the Directed graph object
 */
class TestEdgeGraph : public ::testing::Test
{
    virtual void SetUp() {}
    virtual void TearDown() {}

    //std::string repr1 = "{4:5,5:4,4:7,5:7,7:5,5:1,0:4,0:2,7:3,1:3,2:7,6:2,3:6,6:0,6:4}";
};

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


TEST_F(TestEdgeGraph, test_file_read)
{
    std::string test_file = "data/tiny_ewd.txt";
    std::string repr_text;

    repr_text = repr_from_file(test_file);

    std::cout << "[" << __func__ << "] repr output:" << std::endl;
    std::cout << repr_text << std::endl;
}

TEST_F(TestEdgeGraph, test_init)
{
    // init a default graph
    EdgeWeightedDigraph default_graph;

    ASSERT_EQ(0, default_graph.numVerticies());
    ASSERT_EQ(0, default_graph.numEdges());
}



int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

