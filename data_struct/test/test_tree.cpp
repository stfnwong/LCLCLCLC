/*
 * Tree unit tests
 */

#define CATCH_CONFIG_MAIN
#include "catch/catch.hpp"

// Module(s) under test
#include "tree.hpp"



TEST_CASE("test_array_tree_ctor", "ArrayTree")
{
    ArrayTree<int> root(0);

    REQUIRE(root.get() == 0);
    REQUIRE(root.num_children() == 0);
}
