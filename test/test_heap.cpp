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

const std::vector<int> input_array   = {5, 8, 1, 10, 15, 4, 3};
const std::vector<int> expected_min_heap = {1, 8, 3, 10, 15 ,5, 4};   // final heap array format


// Just test that the object can be constructed (ie: this test doesn't deal with edge cases)
TEST_CASE("Test heap2 init", "[classic]")
{
    Heap test_heap;

    REQUIRE(test_heap.size() == 0);
    // the heap property tests are defined 
    // such that they pass for empty heaps
    REQUIRE(vector_is_min_heap(test_heap.getVec(), 0) == true);
    REQUIRE(vector_is_max_heap(test_heap.getVec(), 0) == true);
}

//TEST_CASE("Test heap2 ctors", "[classic]")
//{
//    std::vector<int> out_array;
//
//
//    //.Heap dst_heap;
//}

TEST_CASE("Test heap2 insert", "[classic]")
{
    Heap test_heap;
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
    REQUIRE(vec_out.size() == expected_min_heap.size());
    REQUIRE(vector_is_min_heap(vec_out, 0) == true);
    REQUIRE(vector_is_max_heap(vec_out, 0) == false);
}

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

    std::vector<int> vec_out = test_heap.getVec();
    REQUIRE(vector_is_min_heap(vec_out, 0) == true);
    REQUIRE(vector_is_max_heap(vec_out, 0) == false);
}


// Ens
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

    std::vector<int> vec_out = test_heap.getVec();
    REQUIRE(vector_is_min_heap(vec_out, 0) == true);
    REQUIRE(vector_is_max_heap(vec_out, 0) == false);
}
