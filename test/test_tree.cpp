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


TEST_F(TestTree, test_repr_to_tree)
{
    TreeNode* repr1_tree;
    TreeNode* repr2_tree;
    TreeNode* empty_tree;

    std::string repr1 = "[1,2,3]";
    std::string repr2 = "[1,null,2,3]";
    std::string empty_repr = "[]";

    repr1_tree = repr_to_tree(repr1);
    ASSERT_NE(nullptr, repr1_tree);
    repr2_tree = repr_to_tree(repr2);
    ASSERT_NE(nullptr, repr2_tree);
    empty_tree = repr_to_tree(empty_repr);
    ASSERT_EQ(nullptr, empty_tree);
    
    // How to test the actual content of the trees...?
}


TEST_F(TestTree, test_tree_to_repr)
{
    // tree structurs
    TreeNode* empty_repr_tree;
    TreeNode* repr1_tree;
    TreeNode* repr2_tree;

    // input reprs 
    std::string empty_repr = "[]";
    std::string repr1 = "[1,2,3]";
    std::string repr2 = "[1,null,2,3,null,4,null]";

    // output reprs
    std::string tree_to_empty_repr;
    std::string tree_to_repr1;
    std::string tree_to_repr2;

    // Test the empty tree
    empty_repr_tree = repr_to_tree(empty_repr);
    tree_to_empty_repr = tree_to_repr(empty_repr_tree);
    std::cout << "Input repr was  : " << empty_repr << std::endl;
    std::cout << "Output repr was : " << tree_to_empty_repr << std::endl; 
    ASSERT_EQ(empty_repr, tree_to_empty_repr);

    // Test the basic [1,2,3] tree
    repr1_tree = repr_to_tree(repr1);
    tree_to_repr1 = tree_to_repr(repr1_tree);
    std::cout << "Input repr was  : " << repr1 << std::endl;
    std::cout << "Output repr was : " << tree_to_repr1 << std::endl; 
    ASSERT_EQ(repr1, tree_to_repr1);

    // Test the tree with a null in the repr
    repr2_tree = repr_to_tree(repr2);
    tree_to_repr2 = tree_to_repr(repr2_tree);
    std::cout << "Input repr was  : " << repr2 << std::endl;
    std::cout << "Output repr was : " << tree_to_repr2 << std::endl; 
    ASSERT_EQ(repr2, tree_to_repr2);

}


TEST_F(TestTree, test_tree_size)
{
    TreeNode* tree;
    std::string repr = "[1, 2, null, 3, 4, null, 5, 6, 7, null]";
    int expected_size = 7;

    tree = repr_to_tree(repr);
    ASSERT_EQ(expected_size, tree_size(tree));
}



int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
