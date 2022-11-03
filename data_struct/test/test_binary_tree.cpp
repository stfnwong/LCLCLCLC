/*
 * Binary tree unit tests
 */

#define CATCH_CONFIG_MAIN
#include "catch/catch.hpp"

#include <vector>

// Module(s) under test
#include "binary_tree.hpp"



TEST_CASE("test_binary_tree_node_ctor", "BinaryTreeNode")
{
    BinaryTreeNode<int> root(0);

    REQUIRE(root.value == 0);
    REQUIRE(root.left == nullptr);
    REQUIRE(root.right == nullptr);
}



TEST_CASE("test_binary_tree_ctor_no_args", "BinaryTree")
{
    BinaryTree<int> tree;

    REQUIRE(tree.root == nullptr);
    //REQUIRE(tree.height() == 0);
    REQUIRE(tree.size() == 0);
}



TEST_CASE("test_binary_tree_insert", "BinaryTree")
{
    BinaryTree<int> tree;
    std::vector<int> inputs = {2, 3, 4, 5, 6, 7};

    //REQUIRE(tree.height() == 0);
    for(unsigned i = 0; i < inputs.size(); ++i)
    {
        tree.insert(inputs[i]);
        //REQUIRE(tree.size() == i+1);
    }

}

//TEST_CASE("test_binary_tree_ctor_val_arg", "BinaryTree")
//{
//    BinaryTree<int> tree(42);
//    REQUIRE(tree.root == 42);
//}
//




//TEST_CASE("test_binary_tree_node_ctor", "BinaryTreeNode")
//{
//    BinaryTreeNode<int> root(0);
//
//    REQUIRE(root.elem == 0);
//    REQUIRE(root.left == nullptr);
//    REQUIRE(root.right == nullptr);
//}
//
//TEST_CASE("test_binary_tree_node_destroy", "BinaryTreeNode")
//{
//    BinaryTreeNode<int> root(0);
//
//    REQUIRE(root.elem == 0);        // ensure the root was constructed
//
//    root.left = new BinaryTreeNode<int>(1);
//    root.right = new BinaryTreeNode<int>(2);
//
//    REQUIRE(root.height() == 1);
//}
//
//
//TEST_CASE("test_construct_binary_tree", "BinaryTreeNode")
//{
//}
