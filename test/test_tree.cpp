/* TEST_TREE
 * Test the actual tree stuff (eg the repr)
 *
 * Stefan Wong 2019
 */

#include <vector>
#include <string>
#include <gtest/gtest.h>
#include "tree.hpp"


class TestTree : public ::testing::Test
{
    virtual void SetUp() {}
    virtual void TearDown() {}
};


TEST_F(TestTree, test_string_to_repr)
{
    TreeNode* repr1_tree;
    TreeNode* repr2_tree;
    TreeNode* empty_tree;

    std::string repr1 = "[1,2,3]";
    std::string repr2 = "[1,null,2,3]";
    std::string empty_repr = "[]";

    repr1_tree = repr_to_tree(repr1);
    repr2_tree = repr_to_tree(repr2);
    empty_tree = repr_to_tree(empty_repr);


    ASSERT_EQ(nullptr, empty_tree);
}


TEST_F(TestTree, test_repr_to_string)
{
    TreeNode* repr1_tree;
    //TreeNode* repr2_tree;
    TreeNode* empty_repr_tree;

    std::string repr1 = "[1,2,3]";
    //std::string repr2 = "[1,null,2,3]";
    std::string empty_repr = "[]";

    std::string tree_to_repr1;
    std::string tree_to_empty_repr;

    // Create some trees 
    repr1_tree = repr_to_tree(repr1);
    tree_to_repr1 = tree_to_repr(repr1_tree);
    ASSERT_EQ(repr1, tree_to_repr1);

    // Test the empty tree
    empty_repr_tree = repr_to_tree(empty_repr);
    tree_to_empty_repr = tree_to_repr(empty_repr_tree);
    ASSERT_EQ(empty_repr, tree_to_empty_repr);
}




int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
