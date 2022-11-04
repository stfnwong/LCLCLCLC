/* TEST_TREE
 * Test the actual tree stuff (eg the repr)
 *
 * Stefan Wong 2019
 */

#define CATCH_CONFIG_MAIN
#include "catch/catch.hpp"

#include <vector>
#include <string>
#include "tree.hpp"


// Test variables
const std::string empty_repr = "[]";
const std::string repr1      = "[1,2,3]";
const std::string repr2      = "[1,null,2,3]";
const std::string repr3      = "[1,null,2,3,null,4,null]";
const int tree1_size = 3;
const int tree2_size = 3;
const int tree3_size = 4;


TEST_CASE("test_repr_to_tree", "TreeNode")
{
    TreeNode* repr1_tree;
    TreeNode* repr2_tree;
    TreeNode* repr3_tree;
    TreeNode* empty_tree;

    repr1_tree = repr_to_tree(repr1);
    REQUIRE(nullptr != repr1_tree);
    repr2_tree = repr_to_tree(repr2);
    REQUIRE(nullptr != repr2_tree);
    repr3_tree = repr_to_tree(repr3);
    REQUIRE(nullptr != repr3_tree);
    empty_tree = repr_to_tree(empty_repr);
    REQUIRE(nullptr == empty_tree);
    
    // Since the traversals are tested seperately, we just test 
    // the size here.
    REQUIRE(tree_size(repr1_tree) == 3);
    REQUIRE(tree_size(repr2_tree) == 3);
    REQUIRE(tree_size(repr3_tree) == 4);
    REQUIRE(tree_size(empty_tree) == 0);

    // clean up
    destroy_tree(repr1_tree);
    destroy_tree(repr2_tree);
    destroy_tree(repr3_tree);
    destroy_tree(empty_tree);
}


TEST_CASE("test_tree_to_repr", "TreeNode")
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
    empty_repr_tree = repr_to_tree(empty_repr);
    tree_to_empty_repr = tree_to_repr(empty_repr_tree);
    std::cout << "Input repr was  : " << empty_repr << std::endl;
    std::cout << "Output repr was : " << tree_to_empty_repr << std::endl; 
    REQUIRE(empty_repr == tree_to_empty_repr);

    // Test the basic [1,2,3] tree
    repr1_tree = repr_to_tree(repr1);
    tree_to_repr1 = tree_to_repr(repr1_tree);
    std::cout << "Input repr was  : " << repr1 << std::endl;
    std::cout << "Output repr was : " << tree_to_repr1 << std::endl; 
    REQUIRE(repr1 == tree_to_repr1);

    // Test the tree with a null nodes
    repr2_tree = repr_to_tree(repr2);
    tree_to_repr2 = tree_to_repr(repr2_tree);
    std::cout << "Input repr was  : " << repr2 << std::endl;
    std::cout << "Output repr was : " << tree_to_repr2 << std::endl; 
    REQUIRE(repr2 == tree_to_repr2);

    // Test more complex tree with null nodes
    repr3_tree = repr_to_tree(repr3);
    tree_to_repr3 = tree_to_repr(repr3_tree);
    std::cout << "Input repr was  : " << repr3 << std::endl;
    std::cout << "Output repr was : " << tree_to_repr3 << std::endl; 
    REQUIRE(repr2 == tree_to_repr2);

    destroy_tree(repr1_tree);
    destroy_tree(repr2_tree);
    destroy_tree(repr3_tree);
    destroy_tree(empty_repr_tree);
}


TEST_CASE("test_repr_to_tree_and_levelorder_traverse", "TreeNode")
{
    std::vector<std::string> reprs = {
        "[]",
        "[1, 2, 3]",
        "[1, null, 3]",
        "[1, 2, 3, null, 4, 5, 6]",
        //"[1, null, 2, null, null, 4]"
    };

    std::vector<std::vector<std::vector<int>>> exp_traversals = {
        //{{}},
        {},
        {{1}, {2, 3}},
        {{1}, {3}},
        {{1}, {2, 3}, {4, 5, 6}},
        //{{1}, {2}, {4}}
    };
    std::vector<std::vector<int>> traversal_out;

    // What sizes are the vectors in exp_traversals collection?
    for(unsigned n = 0; n < exp_traversals.size(); ++n)
    {
        std::cout << n << ":" << exp_traversals[n].size() << std::endl;
    }
    std::cout << std::endl;

    TreeNode* tree;
    
    for(unsigned test_case = 0; test_case < exp_traversals.size(); ++test_case)
    {
        tree = repr_to_tree(reprs[test_case]);
        traversal_out = tree_level_order_level_wise(tree);
        std::cout << "Traversal length:" << traversal_out.size() << std::endl;

        REQUIRE(traversal_out.size() == exp_traversals[test_case].size());
    }

}


TEST_CASE("test_tree_size", "TreeNode")
{
    //TreeNode* tree;
    //std::string repr = "[1, 2, null, 3, 4, null, 5, 6, 7, null]";
    //int expected_size = 7;

    //tree = repr_to_tree(repr);
    //REQUIRE(expected_size == tree_size(tree));

    // Test the sizes of the 3 test trees
    TreeNode* empty_tree;
    TreeNode* tree1;
    TreeNode* tree2;
    TreeNode* tree3;

    tree1 = repr_to_tree(repr1);
    REQUIRE(tree1_size == tree_size(tree1));
    
    tree2 = repr_to_tree(repr2);
    REQUIRE(tree2_size == tree_size(tree2));

    tree3 = repr_to_tree(repr3);
    REQUIRE(tree3_size == tree_size(tree3));

    empty_tree = repr_to_tree(empty_repr);
    REQUIRE(0 == tree_size(empty_tree));

    destroy_tree(tree1);
    destroy_tree(tree2);
    destroy_tree(tree3);
    destroy_tree(empty_tree);
}

TEST_CASE("test_tree_size_iter", "TreeNode")
{
    TreeNode* empty_tree;
    TreeNode* tree1;
    TreeNode* tree2;
    TreeNode* tree3;

    tree1 = repr_to_tree(repr1);
    REQUIRE(tree1_size == tree_size_iter(tree1));
    
    tree2 = repr_to_tree(repr2);
    REQUIRE(tree2_size == tree_size_iter(tree2));

    tree3 = repr_to_tree(repr3);
    REQUIRE(tree3_size == tree_size_iter(tree3));

    empty_tree = repr_to_tree(empty_repr);
    REQUIRE(0 == tree_size_iter(empty_tree));

    destroy_tree(tree1);
    destroy_tree(tree2);
    destroy_tree(tree3);
    destroy_tree(empty_tree);
}
