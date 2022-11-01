
#define CATCH_CONFIG_MAIN
#include "catch/catch.hpp"

// Module(s) under test
#include "heap.hpp"



/*
 * NODE BASED HEAP
 */
TEST_CASE("test_heap_node_ctor", "HeapNode")
{
    HeapNode<int> root(0);

    REQUIRE(root.left == nullptr);
    REQUIRE(root.right == nullptr);

    REQUIRE(root.val == 0);
}

TEST_CASE("test_heap_node_max_heap", "HeapNode")
{
    // TODO: need functions to create a heap
}


/*
 * ARRAY BASED HEAP
 */

TEST_CASE("test_heap_array_ctor", "HeapArray")
{
    HeapArray<int> heap;
    
    REQUIRE(heap.size() == 0);
}
