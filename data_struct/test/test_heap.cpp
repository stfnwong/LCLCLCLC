
#define CATCH_CONFIG_MAIN
#include "catch/catch.hpp"

// Module(s) under test
#include "heap.hpp"



TEST_CASE("test_heap_ctor", "HeapNode")
{
    HeapNode<int> root(0);

    REQUIRE(root.left == nullptr);
    REQUIRE(root.right == nullptr);

    REQUIRE(root.elem == 0);
}
