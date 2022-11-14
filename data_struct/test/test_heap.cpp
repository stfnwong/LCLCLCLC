
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
    REQUIRE(heap.depth() == 0);
}

TEST_CASE("test_build_max_heap", "HeapArray")
{
    std::vector<int> inp_array = {20, 30, 4, 3, 19, 18, 16, 2, 1, 9};
    std::vector<int> exp_array = {30, 20, 18, 3, 19, 4, 16, 2, 1, 9};

    // Note that this heap will use std::less() by default, which makes it a MaxHeap
    // because the test is std::less(a, b), swapping if true, where 
    //
    // a = left, b = idx (in the first test)
    // a = right, b = whichever is less of (a, b)
    //HeapArray<int> test_heap(inp_array);

    build_max_heap_array(inp_array);

    for(unsigned i = 0; i < inp_array.size(); ++i)
        REQUIRE(inp_array[i] == exp_array[i]);
}


// Well, turns out I'm pretty shit with this
TEST_CASE("test_max_heapify_array_small", "Heap")
{
    std::vector<int> inp_array = {1, 2, 3, 4};
    std::vector<int> exp_array = {4, 3, 1, 2};

    std::vector<int> heapify_inp_array = {20, 30, 4, 3, 19, 18, 16, 2, 1, 9};
    std::vector<int> max_heapify_exp_array = {16, 14, 10, 8, 7, 9, 3, 2, 4, 1};

    std::cout << "array before heapify : " << vec_to_str(heapify_inp_array) << std::endl;
    //build_max_heap_array(inp_array);
    std::cout << "array after heapify  : " << vec_to_str(heapify_inp_array) << std::endl;
    
    for(unsigned idx = 0; idx < heapify_inp_array.size(); ++idx)
        REQUIRE(heapify_inp_array[idx] == max_heapify_exp_array[idx]);
}
