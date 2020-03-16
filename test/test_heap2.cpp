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
#include "heap2.hpp"


// Just test that the object can be constructed (ie: this test doesn't deal with edge cases)
TEST_CASE("Test heap2 init", "[classic]")
{
    Heap2 test_heap;

    REQUIRE(test_heap.size() == 0);
    // the heap property tests are defined 
    // such that they pass for empty heaps
    REQUIRE(vector_is_min_heap2(test_heap.getVec(), 0) == true);
    REQUIRE(vector_is_max_heap2(test_heap.getVec(), 0) == true);
}

TEST_CASE("Test heap2 insert", "[classic]")
{
    std::vector<int> input_array   = {5, 8, 1, 10, 15, 4, 3};
    std::vector<int> expected_heap = {1, 8, 3, 10, 15 ,5, 4};   // final heap array format

    Heap2 test_heap;
    REQUIRE(test_heap.empty() == true);




    // Note that this is a heap of ints 
     
}
