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


TEST_F(TestTraverseTree, test_preorder_traversal1)
{
    // Tree 1
    std::vector<int> traversal1;
    std::vector<int> expected_traversal1 = {1,2,3};
    TreeNode* tree = nullptr;

    tree = repr_to_tree(this->repr1);
    ASSERT_NE(nullptr, tree);

    tree_preorder(tree, traversal1);
    std::cout << "traversal1 contains " << traversal1.size() << " elements" << std::endl;
    std::cout << "[";
    for(unsigned int i = 0; i < traversal1.size(); ++i)
        std::cout << traversal1[i];
    std::cout << "]" << std::endl;

    ASSERT_EQ(expected_traversal1.size(), traversal1.size());
    for(unsigned int i = 0; i < traversal1.size(); ++i)
        ASSERT_EQ(expected_traversal1[i], traversal1[i]);
}


TEST_F(TestTraverseTree, test_inorder_traversal)
{
    // Tree 1
    std::vector<int> traversal1;
    std::vector<int> expected_traversal1 = {2,1,3};
    TreeNode* tree = nullptr;

    tree = repr_to_tree(this->repr1);
    ASSERT_NE(nullptr, tree);

    tree_inorder(tree, traversal1);
    std::cout << "traversal1 contains " << traversal1.size() << " elements" << std::endl;
    std::cout << "[";
    for(unsigned int i = 0; i < traversal1.size(); ++i)
        std::cout << traversal1[i];
    std::cout << "]" << std::endl;

    ASSERT_EQ(expected_traversal1.size(), traversal1.size());
    for(unsigned int i = 0; i < traversal1.size(); ++i)
        ASSERT_EQ(expected_traversal1[i], traversal1[i]);
}


TEST_F(TestTraverseTree, test_outorder_traversal)
{
    // Tree 1
    std::vector<int> traversal1;
    std::vector<int> expected_traversal1 = {3,1,2};
    TreeNode* tree = nullptr;

    tree = repr_to_tree(this->repr1);
    ASSERT_NE(nullptr, tree);

    tree_outorder(tree, traversal1);
    std::cout << "traversal1 contains " << traversal1.size() << " elements" << std::endl;
    std::cout << "[";
    for(unsigned int i = 0; i < traversal1.size(); ++i)
        std::cout << traversal1[i];
    std::cout << "]" << std::endl;

    ASSERT_EQ(expected_traversal1.size(), traversal1.size());
    for(unsigned int i = 0; i < traversal1.size(); ++i)
        ASSERT_EQ(expected_traversal1[i], traversal1[i]);
}


TEST_F(TestTraverseTree, test_postorder_traversal)
{
    // Tree 1
    std::vector<int> traversal1;
    std::vector<int> expected_traversal1 = {2,3,1};
    TreeNode* tree = nullptr;

    tree = repr_to_tree(this->repr1);
    ASSERT_NE(nullptr, tree);

    tree_postorder(tree, traversal1);
    std::cout << "traversal1 contains " << traversal1.size() << " elements" << std::endl;
    std::cout << "[";
    for(unsigned int i = 0; i < traversal1.size(); ++i)
        std::cout << traversal1[i];
    std::cout << "]" << std::endl;

    ASSERT_EQ(expected_traversal1.size(), traversal1.size());
    for(unsigned int i = 0; i < traversal1.size(); ++i)
        ASSERT_EQ(expected_traversal1[i], traversal1[i]);
}


int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


