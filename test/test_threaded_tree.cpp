/*
 * TEST_THREADED_TREE
 * Unit tests for threaded tree
 *
 * Stefan Wong 2019
 */


#include <vector>
#include <string>
#include <gtest/gtest.h>
#include "threaded_tree.hpp"


class TestThreadedTree : public ::testing::Test
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

TEST_F(TestThreadedTree, test_repr_to_threaded_tree)
{
    TreeNode* repr1_tree;
    TreeNode* repr2_tree;
    TreeNode* repr3_tree;
    TreeNode* empty_tree;

    repr1_tree = repr_to_threaded_tree(this->repr1);
    ASSERT_NE(nullptr, repr1_tree);
    repr2_tree = repr_to_threaded_tree(this->repr2);
    ASSERT_NE(nullptr, repr2_tree);
    repr3_tree = repr_to_threaded_tree(this->repr3);
    ASSERT_NE(nullptr, repr3_tree);
    empty_tree = repr_to_threaded_tree(this->empty_repr);
    ASSERT_EQ(nullptr, empty_tree);
    
    // How to test the actual content of the trees...?

    // clean up
    destroy_tree(repr1_tree);
    destroy_tree(repr2_tree);
    destroy_tree(repr3_tree);
    destroy_tree(empty_tree);
}



int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
