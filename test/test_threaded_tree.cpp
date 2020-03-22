/*
 * TEST_THREADED_TREE
 * Unit tests for threaded tree
 *
 * Stefan Wong 2019
 */

#define CATCH_CONFIG_MAIN
#include "catch/catch.hpp"

#include <vector>
#include <string>
#include <gtest/gtest.h>
#include "threaded_tree.hpp"

// test inputs 
const std::string empty_repr = "[]";
const std::string repr1      = "[1,2,3]";
const std::string repr2      = "[1,null,2,3]";
const std::string repr3      = "[1,null,2,3,null,4,null]";
const int tree1_size = 3;
const int tree2_size = 3;
const int tree3_size = 4;


TEST_CASE("TestThreadedTree, test_repr_to_threaded_tree", "[classic]")
{
    TreeNode* repr1_tree;
    TreeNode* repr2_tree;
    TreeNode* repr3_tree;
    TreeNode* empty_tree;

    repr1_tree = repr_to_threaded_tree(repr1);
    REQUIRE(nullptr != repr1_tree);
    repr2_tree = repr_to_threaded_tree(repr2);
    REQUIRE(nullptr != repr2_tree);
    repr3_tree = repr_to_threaded_tree(repr3);
    REQUIRE(nullptr != repr3_tree);
    empty_tree = repr_to_threaded_tree(empty_repr);
    REQUIRE(nullptr == empty_tree);
    
    // How to test the actual content of the trees...?

    // clean up
    destroy_tree(repr1_tree);
    destroy_tree(repr2_tree);
    destroy_tree(repr3_tree);
    destroy_tree(empty_tree);
}
