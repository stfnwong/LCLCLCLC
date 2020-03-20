/*
 * TEST_HEAP2
 * Unit tests for new (simpler) heap structure.
 *
 * Stefan Wong 2020
 */

#define CATCH_CONFIG_MAIN
#include "catch/catch.hpp"
#include <iostream> 
#include <iomanip>
#include <vector>
#include <string>

// unit(s) under test 
#include "heap.hpp"

const std::vector<int> input_array       = {5, 8, 1, 10, 15, 4, 3};
const std::vector<int> expected_min_heap = {1, 8, 3, 10, 15 ,5, 4};   // final heap array format
const std::vector<int> expected_max_heap = {1, 8, 3, 10, 15 ,5, 4};   // final heap array format


// Ensure that the MinHeap actually satisfies the min heap property
TEST_CASE("Test MinHeap insert", "[classic]")
{
    MinHeap test_heap;
    REQUIRE(test_heap.empty() == true);

    // 
    for(unsigned int i = 0; i < input_array.size(); ++i)
    {
        test_heap.insert(input_array[i]);
        std::cout << "[after input " << i << "] : " << test_heap.toString() << std::endl;
    }
    std::cout << "MinHeap vec : " << test_heap.toString() << std::endl;
    REQUIRE(test_heap.isMinHeap() == true);
    REQUIRE(test_heap.isMaxHeap() == false);
}


// Ensure that the MaxHeap actually satisfies the max heap property
TEST_CASE("Test MaxHeap insert", "[classic]")
{
    MaxHeap test_heap;
    REQUIRE(test_heap.empty() == true);

    // 
    for(unsigned int i = 0; i < input_array.size(); ++i)
    {
        test_heap.insert(input_array[i]);
        std::cout << "[after input " << i << "] : " << test_heap.toString() << std::endl;
    }
    std::cout << "MaxHeap vec : " << test_heap.toString() << std::endl;
    REQUIRE(test_heap.isMinHeap() == false);
    REQUIRE(test_heap.isMaxHeap() == true);
}


TEST_CASE("Test MaxHeap get limits", "[classic]")
{
    MaxHeap test_heap;
    REQUIRE(test_heap.empty() == true);

    // construct the heap  
    for(unsigned int i = 0; i < input_array.size(); ++i)
        test_heap.insert(input_array[i]);

    REQUIRE(test_heap.isMinHeap() == false);
    REQUIRE(test_heap.isMaxHeap() == true);
    REQUIRE(test_heap.getMin() == 1);
    REQUIRE(test_heap.getMax() == 15);
}


TEST_CASE("Test MinHeap get limits", "[classic]")
{
    MinHeap test_heap;
    REQUIRE(test_heap.empty() == true);

    // construct the heap  
    for(unsigned int i = 0; i < input_array.size(); ++i)
        test_heap.insert(input_array[i]);

    REQUIRE(test_heap.isMinHeap() == true);
    REQUIRE(test_heap.isMaxHeap() == false);
    REQUIRE(test_heap.getMin() == 1);
    REQUIRE(test_heap.getMax() == 15);
}
