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

};


TEST_F(TestGraph, test_clone)
{
    Node* src_graph;
    Node* dst_graph;


    // Need to make a src_graph to test with.
}


class TestAdj : public ::testing::Test
{
    virtual void SetUp() {}
    virtual void TearDown() {}

    public:
        unsigned int test_v = 8;

};

TEST_F(TestAdj, test_adj_matrix_init)
{
    AdjMatrix test_matrix(this->test_v);
    
    ASSERT_EQ(this->test_v, test_matrix.get_dim());     // TODO: come up with a real test

}


// Test that we can make a new AdjList object
TEST_F(TestAdj, test_adj_list_init)
{
    AdjList test_list;
}



int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

