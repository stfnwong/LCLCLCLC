/*
 * Binary tree unit tests
 */

#define CATCH_CONFIG_MAIN
#include "catch/catch.hpp"

// Module(s) under test
#include "binary_tree.hpp"



TEST_CASE("test_binary_tree_node_ctor", "BinaryTreeNode")
{
    BinaryTreeNode<int> root(0);

    REQUIRE(root.elem == 0);
    REQUIRE(root.left == nullptr);
    REQUIRE(root.right == nullptr);
}

TEST_CASE("test_binary_tree_node_destroy", "BinaryTreeNode")
{
    BinaryTreeNode<int> root(0);

    REQUIRE(root.elem == 0);        // ensure the root was constructed

    root.left = new BinaryTreeNode<int>(1);
    root.right = new BinaryTreeNode<int>(2);

    REQUIRE(root.height() == 1);
}


TEST_CASE("test_construct_binary_tree", "BinaryTreeNode")
{
}
