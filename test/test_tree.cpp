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

    public:
        std::string empty_repr = "[]";
        std::string repr1      = "[1,2,3]";
        std::string repr2      = "[1,null,2,3]";
        std::string repr3      = "[1,null,2,3,null,4,null]";

        int tree1_size = 3;
        int tree2_size = 3;
        int tree3_size = 4;

        // Expected traversals
        std::vector<int> exp_inorder_1 = {2, 1, 3};
        std::vector<int> exp_inorder_2 = {1, 3, 2};
};


TEST_F(TestTree, test_repr_to_tree)
{
    TreeNode* repr1_tree;
    TreeNode* repr2_tree;
    TreeNode* repr3_tree;
    TreeNode* empty_tree;

    repr1_tree = repr_to_tree(this->repr1);
    ASSERT_NE(nullptr, repr1_tree);
    repr2_tree = repr_to_tree(this->repr2);
    ASSERT_NE(nullptr, repr2_tree);
    repr3_tree = repr_to_tree(this->repr3);
    ASSERT_NE(nullptr, repr3_tree);
    empty_tree = repr_to_tree(this->empty_repr);
    ASSERT_EQ(nullptr, empty_tree);
    
    // Since the traversals are tested seperately, we just test 
    // the size here.
    ASSERT_EQ(3, tree_size(repr1_tree));

    // clean up
    destroy_tree(repr1_tree);
    destroy_tree(repr2_tree);
    destroy_tree(repr3_tree);
    destroy_tree(empty_tree);
}


TEST_F(TestTree, test_tree_to_repr)
{
    // tree structurs
    TreeNode* empty_repr_tree;
    TreeNode* repr1_tree;
    TreeNode* repr2_tree;
    TreeNode* repr3_tree;

    // output reprs
    std::string tree_to_empty_repr;
    std::string tree_to_repr1;
    std::string tree_to_repr2;
    std::string tree_to_repr3;

    // Test the empty tree
    empty_repr_tree = repr_to_tree(this->empty_repr);
    tree_to_empty_repr = tree_to_repr(empty_repr_tree);
    std::cout << "Input repr was  : " << this->empty_repr << std::endl;
    std::cout << "Output repr was : " << tree_to_empty_repr << std::endl; 
    ASSERT_EQ(this->empty_repr, tree_to_empty_repr);

    // Test the basic [1,2,3] tree
    repr1_tree = repr_to_tree(this->repr1);
    tree_to_repr1 = tree_to_repr(repr1_tree);
    std::cout << "Input repr was  : " << this->repr1 << std::endl;
    std::cout << "Output repr was : " << tree_to_repr1 << std::endl; 
    ASSERT_EQ(this->repr1, tree_to_repr1);

    // Test the tree with a null nodes
    repr2_tree = repr_to_tree(this->repr2);
    tree_to_repr2 = tree_to_repr(repr2_tree);
    std::cout << "Input repr was  : " << this->repr2 << std::endl;
    std::cout << "Output repr was : " << tree_to_repr2 << std::endl; 
    ASSERT_EQ(this->repr2, tree_to_repr2);

    // Test more complex tree with null nodes
    repr3_tree = repr_to_tree(this->repr3);
    tree_to_repr3 = tree_to_repr(repr3_tree);
    std::cout << "Input repr was  : " << this->repr3 << std::endl;
    std::cout << "Output repr was : " << tree_to_repr3 << std::endl; 
    ASSERT_EQ(this->repr2, tree_to_repr2);

    destroy_tree(repr1_tree);
    destroy_tree(repr2_tree);
    destroy_tree(repr3_tree);
    destroy_tree(empty_repr_tree);
}


TEST_F(TestTree, test_tree_size)
{
    //TreeNode* tree;
    //std::string repr = "[1, 2, null, 3, 4, null, 5, 6, 7, null]";
    //int expected_size = 7;

    //tree = repr_to_tree(repr);
    //ASSERT_EQ(expected_size, tree_size(tree));

    // Test the sizes of the 3 test trees
    TreeNode* empty_tree;
    TreeNode* tree1;
    TreeNode* tree2;
    TreeNode* tree3;

    tree1 = repr_to_tree(this->repr1);
    ASSERT_EQ(this->tree1_size, tree_size(tree1));
    
    tree2 = repr_to_tree(this->repr2);
    ASSERT_EQ(this->tree2_size, tree_size(tree2));

    tree3 = repr_to_tree(this->repr3);
    ASSERT_EQ(this->tree3_size, tree_size(tree3));

    empty_tree = repr_to_tree(this->empty_repr);
    ASSERT_EQ(0, tree_size(empty_tree));

    destroy_tree(tree1);
    destroy_tree(tree2);
    destroy_tree(tree3);
    destroy_tree(empty_tree);
}



int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
