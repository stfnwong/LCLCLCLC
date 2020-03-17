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

const std::vector<int> input_array   = {5, 8, 1, 10, 15, 4, 3};
const std::vector<int> expected_heap = {1, 8, 3, 10, 15 ,5, 4};   // final heap array format


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

//TEST_CASE("Test heap2 ctors", "[classic]")
//{
//    std::vector<int> out_array;
//
//
//    //.Heap2 dst_heap;
//}

TEST_CASE("Test heap2 insert", "[classic]")
{
    Heap2 test_heap;
    REQUIRE(test_heap.empty() == true);
    
    // Start inserting elements into the heap 
    for(unsigned int i = 0; i < input_array.size(); ++i)
    {
        test_heap.insert(input_array[i]);
        std::cout << "[after input " << i << "] : " << test_heap.toString() << std::endl;
    }

    std::cout << "Heapvec : " << test_heap.toString() << std::endl;

    std::vector<int> vec_out = test_heap.getVec();

    REQUIRE(test_heap.empty() == false);
    REQUIRE(vec_out.size() == expected_heap.size());
    REQUIRE(vector_is_min_heap2(vec_out, 0) == true);
    REQUIRE(vector_is_max_heap2(vec_out, 0) == false);

    //bool vector_is_min_heap2(const std::vector<int>& vec, unsigned int idx);
    //// Test if a vector has the max heap property
    //bool vector_is_max_heap2(const std::vector<int>& vec, unsigned int idx);

    // TODO : why does 1 not go to the top?
}

