
#define CATCH_CONFIG_MAIN
#include "catch/catch.hpp"

#include <iostream>

// Module(s) under test
#include "heap.hpp"
#include "util.hpp"



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


TEST_CASE("test_max_heapify_array_small", "Heap")
{
    std::vector<int> inp_array = {1, 2, 3};
    std::vector<int> exp_array = {3, 2, 1};

    std::cout << "array before heapify : " << vec_to_str(inp_array) << std::endl;
    max_heapify_array(inp_array, 0);
    std::cout << "array after heapify  : " << vec_to_str(inp_array) << std::endl;
    
    for(unsigned idx = 0; idx < inp_array.size(); ++idx)
        REQUIRE(inp_array[idx] == exp_array[idx]);
}


TEST_CASE("test_max_heapify_array", "Heap")
{
    std::vector<int> inp_array = {1, 2, 3, 4, 7, 8, 9, 10, 14 ,16};
    std::vector<int> exp_array = {16, 14, 10, 8, 7, 9, 3, 2, 4, 1};

    std::cout << "array before heapify : " << vec_to_str(inp_array) << std::endl;
    max_heapify_array(inp_array, 0);
    std::cout << "array after heapify  : " << vec_to_str(inp_array) << std::endl;
    
    for(unsigned idx = 0; idx < inp_array.size(); ++idx)
        REQUIRE(inp_array[idx] == exp_array[idx]);
}
