/* TEST_TRAVERSE_TREE 
 * Test LeetCode tree traversal1
 *
 * Stefan Wong 2019
 */

#include <vector>
#include <string>
#include <gtest/gtest.h>
// NOTE: maybe put these together?
#include "tree.hpp"
#include "tree_traverse.hpp"

class TestTraverseTree : public ::testing::Test
{
    virtual void SetUp() {}
    virtual void TearDown() {}

    public:
        std::string repr1 = "[1,2,3]";
        std::string repr2 = "[1,2,3,4,5]";
        std::string repr3 = "[1,2,3,null,null,4,5]";
        //std::string tree_repr = "[1,2,null,3,4,5,null]";
};

void print_traversal(const std::vector<int>& traversal)
{
    std::cout << "[" << __func__ << "] traversal contains "
        << traversal.size() << " elements" << std::endl;

    std::cout << "[";
    for(unsigned int i = 0; i < traversal.size(); ++i)
        std::cout << traversal[i];
    std::cout << "]" << std::endl;
}


// ======== RECURSIVE SOLUTIONS ======== //

TEST_F(TestTraverseTree, test_preorder_traversal)
{
    // Tree 1
    std::vector<int> traversal1;
    std::vector<int> expected_traversal1 = {1,2,3};
    TreeNode* tree1 = nullptr;

    tree1 = repr_to_tree(this->repr1);
    ASSERT_NE(nullptr, tree1);

    tree_preorder(tree1, traversal1);
    print_traversal(traversal1);

    ASSERT_EQ(expected_traversal1.size(), traversal1.size());
    for(unsigned int i = 0; i < traversal1.size(); ++i)
        ASSERT_EQ(expected_traversal1[i], traversal1[i]);

    // Tree 2
    std::vector<int> traversal2;
    std::vector<int> expected_traversal2 = {1,2,4,5,3};
    TreeNode* tree2 = nullptr;

    tree2 = repr_to_tree(this->repr2);
    ASSERT_NE(nullptr, tree2);
    tree_preorder(tree2, traversal2);
    print_traversal(traversal2);

    ASSERT_EQ(expected_traversal2.size(), traversal2.size());
    for(unsigned int i = 0; i < traversal2.size(); ++i)
        ASSERT_EQ(expected_traversal2[i], traversal2[i]);
}


TEST_F(TestTraverseTree, test_inorder_traversal)
{
    // Tree 1
    std::vector<int> traversal1;
    std::vector<int> expected_traversal1 = {2,1,3};
    TreeNode* tree1 = nullptr;

    tree1 = repr_to_tree(this->repr1);
    ASSERT_NE(nullptr, tree1);

    tree_inorder(tree1, traversal1);
    print_traversal(traversal1);

    ASSERT_EQ(expected_traversal1.size(), traversal1.size());
    for(unsigned int i = 0; i < traversal1.size(); ++i)
        ASSERT_EQ(expected_traversal1[i], traversal1[i]);

    // Tree 2
    std::vector<int> traversal2;
    std::vector<int> expected_traversal2 = {4,2,5,1,3};
    TreeNode* tree2 = nullptr;

    tree2 = repr_to_tree(this->repr2);
    ASSERT_NE(nullptr, tree2);
    tree_inorder(tree2, traversal2);
    print_traversal(traversal2);

    ASSERT_EQ(expected_traversal2.size(), traversal2.size());
    for(unsigned int i = 0; i < traversal2.size(); ++i)
        ASSERT_EQ(expected_traversal2[i], traversal2[i]);
}


TEST_F(TestTraverseTree, test_outorder_traversal)
{
    // Tree 1
    std::vector<int> traversal1;
    std::vector<int> expected_traversal1 = {3,1,2};
    TreeNode* tree1 = nullptr;

    tree1 = repr_to_tree(this->repr1);
    ASSERT_NE(nullptr, tree1);

    tree_outorder(tree1, traversal1);
    print_traversal(traversal1);

    ASSERT_EQ(expected_traversal1.size(), traversal1.size());
    for(unsigned int i = 0; i < traversal1.size(); ++i)
        ASSERT_EQ(expected_traversal1[i], traversal1[i]);

    // Tree 2
    std::vector<int> traversal2;
    std::vector<int> expected_traversal2 = {3,1,5,2,4};
    TreeNode* tree2 = nullptr;

    tree2 = repr_to_tree(this->repr2);
    ASSERT_NE(nullptr, tree2);
    tree_outorder(tree2, traversal2);
    print_traversal(traversal2);

    ASSERT_EQ(expected_traversal2.size(), traversal2.size());
    for(unsigned int i = 0; i < traversal2.size(); ++i)
        ASSERT_EQ(expected_traversal2[i], traversal2[i]);
}


TEST_F(TestTraverseTree, test_postorder_traversal)
{
    // Tree 1
    std::vector<int> traversal1;
    std::vector<int> expected_traversal1 = {2,3,1};
    TreeNode* tree1 = nullptr;

    tree1 = repr_to_tree(this->repr1);
    ASSERT_NE(nullptr, tree1);

    tree_postorder(tree1, traversal1);
    print_traversal(traversal1);

    ASSERT_EQ(expected_traversal1.size(), traversal1.size());
    for(unsigned int i = 0; i < traversal1.size(); ++i)
        ASSERT_EQ(expected_traversal1[i], traversal1[i]);

    // Tree 2
    std::vector<int> traversal2;
    std::vector<int> expected_traversal2 = {4,5,2,3,1};
    TreeNode* tree2 = nullptr;

    tree2 = repr_to_tree(this->repr2);
    ASSERT_NE(nullptr, tree2);
    tree_postorder(tree2, traversal2);
    print_traversal(traversal2);

    ASSERT_EQ(expected_traversal2.size(), traversal2.size());
    for(unsigned int i = 0; i < traversal2.size(); ++i)
        ASSERT_EQ(expected_traversal2[i], traversal2[i]);
}

// ======== ITERATIVE SOLUTIONS ======== //
TEST_F(TestTraverseTree, test_preorder_traversal_iter)
{
    // Tree 1
    std::vector<int> traversal1;
    std::vector<int> expected_traversal1 = {1,2,3};
    TreeNode* tree1 = nullptr;

    tree1 = repr_to_tree(this->repr1);
    ASSERT_NE(nullptr, tree1);

    tree_preorder_iter(tree1, traversal1);
    print_traversal(traversal1);

    ASSERT_EQ(expected_traversal1.size(), traversal1.size());
    for(unsigned int i = 0; i < traversal1.size(); ++i)
        ASSERT_EQ(expected_traversal1[i], traversal1[i]);

    // Tree 2
    std::vector<int> traversal2;
    std::vector<int> expected_traversal2 = {1,2,4,5,3};
    TreeNode* tree2 = nullptr;

    tree2 = repr_to_tree(this->repr2);
    ASSERT_NE(nullptr, tree2);
    tree_preorder_iter(tree2, traversal2);
    print_traversal(traversal2);

    ASSERT_EQ(expected_traversal2.size(), traversal2.size());
    for(unsigned int i = 0; i < traversal2.size(); ++i)
        ASSERT_EQ(expected_traversal2[i], traversal2[i]);
}

TEST_F(TestTraverseTree, test_inorder_traversal_iter)
{
    // Tree 1
    std::vector<int> traversal1;
    std::vector<int> expected_traversal1 = {2,1,3};
    TreeNode* tree1 = nullptr;

    tree1 = repr_to_tree(this->repr1);
    ASSERT_NE(nullptr, tree1);

    tree_inorder_iter(tree1, traversal1);
    print_traversal(traversal1);

    ASSERT_EQ(expected_traversal1.size(), traversal1.size());
    for(unsigned int i = 0; i < traversal1.size(); ++i)
        ASSERT_EQ(expected_traversal1[i], traversal1[i]);

    // Tree 2
    std::vector<int> traversal2;
    std::vector<int> expected_traversal2 = {4,2,5,1,3};
    TreeNode* tree2 = nullptr;

    tree2 = repr_to_tree(this->repr2);
    ASSERT_NE(nullptr, tree2);
    tree_inorder_iter(tree2, traversal2);
    print_traversal(traversal2);

    ASSERT_EQ(expected_traversal2.size(), traversal2.size());
    for(unsigned int i = 0; i < traversal2.size(); ++i)
        ASSERT_EQ(expected_traversal2[i], traversal2[i]);
}




int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


