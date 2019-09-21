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
        std::string empty_repr = "[]";
        std::string repr1      = "[1,2,3]";
        std::string repr2      = "[1,null,2,3]";
        std::string repr3      = "[1,null,2,3,null,4,null]";

        int tree1_size = 3;
        int tree2_size = 3;
        int tree3_size = 4;
};


TEST_F(TestGraph, test_clone)
{
    Node* src_graph;
    Node* dst_graph;


    // Need to make a src_graph to test with.
}


int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

