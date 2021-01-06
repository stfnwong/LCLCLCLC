/* TEST_TRAVERSE_TREE 
 * Test LeetCode tree traversal1
 *
 * Stefan Wong 2019
 */

#define CATCH_CONFIG_MAIN
#include "catch/catch.hpp"

#include <vector>
#include <string>
// NOTE: maybe put these together?
#include "tree.hpp"

// Test inputs
const std::string repr1 = "[1,2,3]";
const std::string repr2 = "[1,2,3,4,5]";
const std::string repr3 = "[1,2,3,null,null,4,5]";
const std::string repr4 = "[1,2,null,3,4,5,null]";


void print_traversal(const std::vector<int>& traversal)
{
    std::cout << "[" << __func__ << "] traversal contains "
        << traversal.size() << " elements   :";

    std::cout << "[";
    for(unsigned int i = 0; i < traversal.size(); ++i)
        std::cout << traversal[i];
    std::cout << "]" << std::endl;
}


// ======== RECURSIVE SOLUTIONS ======== //

/*
 * PRE-ORDER
 */
TEST_CASE("TestTraverseTree, test_preorder_traversal", "[classic]")
{
    // Tree 1
    std::vector<int> traversal1;
    std::vector<int> expected_traversal1 = {1,2,3};
    TreeNode* tree1 = nullptr;

    tree1 = repr_to_tree(repr1);
    REQUIRE(nullptr != tree1);

    tree_preorder(tree1, traversal1);
    std::cout << "Tree 1 repr: " << repr1 << std::endl;
    print_traversal(traversal1);

    REQUIRE(expected_traversal1.size() == traversal1.size());
    for(unsigned int i = 0; i < traversal1.size(); ++i)
        REQUIRE(expected_traversal1[i] == traversal1[i]);

    // Tree 2
    std::vector<int> traversal2;
    std::vector<int> expected_traversal2 = {1,2,4,5,3};
    TreeNode* tree2 = nullptr;

    tree2 = repr_to_tree(repr2);
    REQUIRE(nullptr != tree2);
    tree_preorder(tree2, traversal2);
    std::cout << "Tree 2 repr: " << repr2 << std::endl;
    print_traversal(traversal2);

    REQUIRE(expected_traversal2.size() == traversal2.size());
    for(unsigned int i = 0; i < traversal2.size(); ++i)
        REQUIRE(expected_traversal2[i] == traversal2[i]);

    // Tree 3
    std::vector<int> traversal3;
    std::vector<int> expected_traversal3 = {1,2,3,4,5};
    TreeNode* tree3 = nullptr;

    tree3 = repr_to_tree(repr3);
    REQUIRE(nullptr != tree3);
    tree_preorder(tree3, traversal3);
    std::cout << "Tree 3 repr: " << repr3 << std::endl;
    print_traversal(traversal3);

    REQUIRE(expected_traversal3.size() == traversal3.size());
    for(unsigned int i = 0; i < traversal3.size(); ++i)
        REQUIRE(expected_traversal3[i] == traversal3[i]);

    destroy_tree(tree1);
    destroy_tree(tree2);
    destroy_tree(tree3);
}


/*
 * IN-ORDER
 */
TEST_CASE("TestTraverseTree, test_inorder_traversal", "[classic]")
{
    // Tree 1
    std::vector<int> traversal1;
    std::vector<int> expected_traversal1 = {2,1,3};
    TreeNode* tree1 = nullptr;

    tree1 = repr_to_tree(repr1);
    REQUIRE(nullptr != tree1);

    tree_inorder(tree1, traversal1);
    std::cout << "Tree 1 repr: " << repr1 << std::endl;
    print_traversal(traversal1);

    REQUIRE(expected_traversal1.size() == traversal1.size());
    for(unsigned int i = 0; i < traversal1.size(); ++i)
        REQUIRE(expected_traversal1[i] == traversal1[i]);

    // Tree 2
    std::vector<int> traversal2;
    std::vector<int> expected_traversal2 = {4,2,5,1,3};
    TreeNode* tree2 = nullptr;

    tree2 = repr_to_tree(repr2);
    REQUIRE(nullptr != tree2);
    tree_inorder(tree2, traversal2);
    std::cout << "Tree 2 repr: " << repr2 << std::endl;
    print_traversal(traversal2);

    REQUIRE(expected_traversal2.size() == traversal2.size());
    for(unsigned int i = 0; i < traversal2.size(); ++i)
        REQUIRE(expected_traversal2[i] == traversal2[i]);

    // Tree 3
    std::vector<int> traversal3;
    std::vector<int> expected_traversal3 = {2,1,4,3,5};
    TreeNode* tree3 = nullptr;

    tree3 = repr_to_tree(repr3);
    REQUIRE(nullptr != tree3);
    tree_inorder(tree3, traversal3);
    std::cout << "Tree 3 repr: " << repr3 << std::endl;
    print_traversal(traversal3);

    REQUIRE(expected_traversal3.size() == traversal3.size());
    for(unsigned int i = 0; i < traversal3.size(); ++i)
        REQUIRE(expected_traversal3[i] == traversal3[i]);
}


/*
 * OUT-ORDER
 */
TEST_CASE("TestTraverseTree, test_outorder_traversal", "[classic]")
{
    // Tree 1
    std::vector<int> traversal1;
    std::vector<int> expected_traversal1 = {3,1,2};
    TreeNode* tree1 = nullptr;

    tree1 = repr_to_tree(repr1);
    REQUIRE(nullptr != tree1);

    tree_outorder(tree1, traversal1);
    std::cout << "Tree 1 repr: " << repr1 << std::endl;
    print_traversal(traversal1);

    REQUIRE(expected_traversal1.size() == traversal1.size());
    for(unsigned int i = 0; i < traversal1.size(); ++i)
        REQUIRE(expected_traversal1[i] == traversal1[i]);

    // Tree 2
    std::vector<int> traversal2;
    std::vector<int> expected_traversal2 = {3,1,5,2,4};
    TreeNode* tree2 = nullptr;

    tree2 = repr_to_tree(repr2);
    REQUIRE(nullptr != tree2);
    tree_outorder(tree2, traversal2);
    std::cout << "Tree 2 repr: " << repr2 << std::endl;
    print_traversal(traversal2);

    REQUIRE(expected_traversal2.size() == traversal2.size());
    for(unsigned int i = 0; i < traversal2.size(); ++i)
        REQUIRE(expected_traversal2[i] == traversal2[i]);

    // Tree 3
    std::vector<int> traversal3;
    std::vector<int> expected_traversal3 = {5,3,4,1,2};
    TreeNode* tree3 = nullptr;

    tree3 = repr_to_tree(repr3);
    REQUIRE(nullptr != tree3);
    tree_outorder(tree3, traversal3);
    std::cout << "Tree 3 repr: " << repr3 << std::endl;
    print_traversal(traversal3);

    REQUIRE(expected_traversal3.size() == traversal3.size());
    for(unsigned int i = 0; i < traversal3.size(); ++i)
        REQUIRE(expected_traversal3[i] == traversal3[i]);

    destroy_tree(tree1);
    destroy_tree(tree2);
    destroy_tree(tree3);
}


/*
 * POST-ORDER
 */
TEST_CASE("TestTraverseTree, test_postorder_traversal", "[classic]")
{
    // Tree 1
    std::vector<int> traversal1;
    std::vector<int> expected_traversal1 = {2,3,1};
    TreeNode* tree1 = nullptr;

    tree1 = repr_to_tree(repr1);
    REQUIRE(nullptr != tree1);

    tree_postorder(tree1, traversal1);
    std::cout << "Tree 1 repr: " << repr1 << std::endl;
    print_traversal(traversal1);

    REQUIRE(expected_traversal1.size() == traversal1.size());
    for(unsigned int i = 0; i < traversal1.size(); ++i)
        REQUIRE(expected_traversal1[i] == traversal1[i]);

    // Tree 2
    std::vector<int> traversal2;
    std::vector<int> expected_traversal2 = {4,5,2,3,1};
    TreeNode* tree2 = nullptr;

    tree2 = repr_to_tree(repr2);
    REQUIRE(nullptr != tree2);
    tree_postorder(tree2, traversal2);
    std::cout << "Tree 2 repr: " << repr2 << std::endl;
    print_traversal(traversal2);

    REQUIRE(expected_traversal2.size() == traversal2.size());
    for(unsigned int i = 0; i < traversal2.size(); ++i)
        REQUIRE(expected_traversal2[i] == traversal2[i]);

    // Tree 3
    std::vector<int> traversal3;
    std::vector<int> expected_traversal3 = {2,4,5,3,1};
    TreeNode* tree3 = nullptr;

    tree3 = repr_to_tree(repr3);
    REQUIRE(nullptr != tree3);
    tree_postorder(tree3, traversal3);
    std::cout << "Tree 3 repr: " << repr3 << std::endl;
    print_traversal(traversal3);

    REQUIRE(expected_traversal3.size() == traversal3.size());
    for(unsigned int i = 0; i < traversal3.size(); ++i)
        REQUIRE(expected_traversal3[i] == traversal3[i]);

    destroy_tree(tree1);
    destroy_tree(tree2);
    destroy_tree(tree3);
}


/*
 * LEVEL ORDER
 */
TEST_CASE("TestTraverseTree, test_level_order_traverse", "[classic]")
{
    // Tree 1
    std::vector<int> traversal1;
    std::vector<int> expected_traversal1 = {1,2,3};
    TreeNode* tree1 = nullptr;

    tree1 = repr_to_tree(repr1);
    REQUIRE(nullptr != tree1);

    tree_levelorder(tree1, traversal1);
    std::cout << "Tree 1 repr: " << repr1 << std::endl;
    print_traversal(traversal1);

    REQUIRE(expected_traversal1.size() == traversal1.size());
    for(unsigned int i = 0; i < traversal1.size(); ++i)
        REQUIRE(expected_traversal1[i] == traversal1[i]);

    // Tree 2
    std::vector<int> traversal2;
    std::vector<int> expected_traversal2 = {1,2,3,4,5};
    TreeNode* tree2 = nullptr;

    tree2 = repr_to_tree(repr2);
    REQUIRE(nullptr != tree2);
    tree_levelorder(tree2, traversal2);
    std::cout << "Tree 2 repr: " << repr2 << std::endl;
    print_traversal(traversal2);

    REQUIRE(expected_traversal2.size() == traversal2.size());
    for(unsigned int i = 0; i < traversal2.size(); ++i)
        REQUIRE(expected_traversal2[i] == traversal2[i]);

    // Tree 3
    std::vector<int> traversal3;
    std::vector<int> expected_traversal3 = {1,2,3,4,5};
    TreeNode* tree3 = nullptr;

    tree3 = repr_to_tree(repr3);
    REQUIRE(nullptr != tree3);
    tree_levelorder(tree3, traversal3);
    std::cout << "Tree 3 repr: " << repr3 << std::endl;
    print_traversal(traversal3);

    REQUIRE(expected_traversal3.size() == traversal3.size());
    for(unsigned int i = 0; i < traversal3.size(); ++i)
        REQUIRE(expected_traversal3[i] == traversal3[i]);

    destroy_tree(tree1);
    destroy_tree(tree2);
    destroy_tree(tree3);
}

// ======== RECURSIVE SOLUTIONS WITH STACKS ======== //
TEST_CASE("TestTraverseTree, test_preorder_traversal_stack", "[classic]")
{
    // Tree 1
    std::vector<int> traversal1;
    std::vector<int> expected_traversal1 = {1,2,3};
    TreeNode* tree1 = nullptr;

    tree1 = repr_to_tree(repr1);
    REQUIRE(nullptr != tree1);

    tree_preorder_stack(tree1, traversal1);
    std::cout << "Tree 1 repr: " << repr1 << std::endl;
    print_traversal(traversal1);

    REQUIRE(expected_traversal1.size() == traversal1.size());
    for(unsigned int i = 0; i < traversal1.size(); ++i)
        REQUIRE(expected_traversal1[i] == traversal1[i]);

    // Tree 2
    std::vector<int> traversal2;
    std::vector<int> expected_traversal2 = {1,2,4,5,3};
    TreeNode* tree2 = nullptr;

    tree2 = repr_to_tree(repr2);
    REQUIRE(nullptr != tree2);
    tree_preorder_stack(tree2, traversal2);
    std::cout << "Tree 2 repr: " << repr2 << std::endl;
    print_traversal(traversal2);

    REQUIRE(expected_traversal2.size() == traversal2.size());
    for(unsigned int i = 0; i < traversal2.size(); ++i)
        REQUIRE(expected_traversal2[i] == traversal2[i]);

    // Tree 3
    std::vector<int> traversal3;
    std::vector<int> expected_traversal3 = {1,2,3,4,5};
    TreeNode* tree3 = nullptr;

    tree3 = repr_to_tree(repr3);
    REQUIRE(nullptr != tree3);
    tree_preorder_stack(tree3, traversal3);
    std::cout << "Tree 3 repr: " << repr3 << std::endl;
    print_traversal(traversal3);

    REQUIRE(expected_traversal3.size() == traversal3.size());
    for(unsigned int i = 0; i < traversal3.size(); ++i)
        REQUIRE(expected_traversal3[i] == traversal3[i]);

    destroy_tree(tree1);
    destroy_tree(tree2);
    destroy_tree(tree3);
}

// ======== ITERATIVE SOLUTIONS ======== //
TEST_CASE("TestTraverseTree, test_preorder_traversal_iter", "[classic]")
{
    // Tree 1
    std::vector<int> traversal1;
    std::vector<int> expected_traversal1 = {1,2,3};
    TreeNode* tree1 = nullptr;

    tree1 = repr_to_tree(repr1);
    REQUIRE(nullptr != tree1);

    tree_preorder_iter(tree1, traversal1);
    std::cout << "Tree 1 repr: " << repr1 << std::endl;
    print_traversal(traversal1);

    REQUIRE(expected_traversal1.size() == traversal1.size());
    for(unsigned int i = 0; i < traversal1.size(); ++i)
        REQUIRE(expected_traversal1[i] == traversal1[i]);

    // Tree 2
    std::vector<int> traversal2;
    std::vector<int> expected_traversal2 = {1,2,4,5,3};
    TreeNode* tree2 = nullptr;

    tree2 = repr_to_tree(repr2);
    REQUIRE(nullptr != tree2);
    tree_preorder_iter(tree2, traversal2);
    std::cout << "Tree 2 repr: " << repr2 << std::endl;
    print_traversal(traversal2);

    REQUIRE(expected_traversal2.size() == traversal2.size());
    for(unsigned int i = 0; i < traversal2.size(); ++i)
        REQUIRE(expected_traversal2[i] == traversal2[i]);

    destroy_tree(tree1);
    destroy_tree(tree2);
    //destroy_tree(tree3);
}

TEST_CASE("TestTraverseTree, test_inorder_traversal_iter", "[classic]")
{
    // Tree 1
    std::vector<int> traversal1;
    std::vector<int> expected_traversal1 = {2,1,3};
    TreeNode* tree1 = nullptr;

    tree1 = repr_to_tree(repr1);
    REQUIRE(nullptr != tree1);

    tree_inorder_iter(tree1, traversal1);
    std::cout << "Tree 1 repr: " << repr1 << std::endl;
    print_traversal(traversal1);

    REQUIRE(expected_traversal1.size() == traversal1.size());
    for(unsigned int i = 0; i < traversal1.size(); ++i)
        REQUIRE(expected_traversal1[i] == traversal1[i]);

    // Tree 2
    std::vector<int> traversal2;
    std::vector<int> expected_traversal2 = {4,2,5,1,3};
    TreeNode* tree2 = nullptr;

    tree2 = repr_to_tree(repr2);
    REQUIRE(nullptr != tree2);
    tree_inorder_iter(tree2, traversal2);
    std::cout << "Tree 2 repr: " << repr2 << std::endl;
    print_traversal(traversal2);

    REQUIRE(expected_traversal2.size() == traversal2.size());
    for(unsigned int i = 0; i < traversal2.size(); ++i)
        REQUIRE(expected_traversal2[i] == traversal2[i]);

    destroy_tree(tree1);
    destroy_tree(tree2);
    //destroy_tree(tree3);
}
