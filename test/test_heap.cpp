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


const constexpr bool verbose = false;

const std::vector<int> input_array       = {5, 8, 1, 10, 15, 4, 3};
const std::vector<int> expected_min_heap = {1, 8, 3, 10, 15 ,5, 4};   // final heap array format
const std::vector<int> expected_max_heap = {1, 8, 3, 10, 15 ,5, 4};   // final heap array format


// Ensure that the MinHeap actually satisfies the min heap property
TEST_CASE("test_minheap_insert", "heap")
{
    MinHeap test_heap;
    REQUIRE(test_heap.empty() == true);

    // 
    for(unsigned int i = 0; i < input_array.size(); ++i)
    {
        test_heap.insert(input_array[i]);
        if(verbose)
            std::cout << "[after input " << i << "] : " << test_heap.toString() << std::endl;
    }
    if(verbose)
        std::cout << "MinHeap vec : " << test_heap.toString() << std::endl;

    REQUIRE(test_heap.isMinHeap() == true);
    REQUIRE(test_heap.isMaxHeap() == false);
}


// Ensure that the MaxHeap actually satisfies the max heap property
TEST_CASE("test_maxheap_insert", "heap")
{
    MaxHeap test_heap;
    REQUIRE(test_heap.empty() == true);

    // 
    for(unsigned int i = 0; i < input_array.size(); ++i)
    {
        test_heap.insert(input_array[i]);
        if(verbose)
            std::cout << "[after input " << i << "] : " << test_heap.toString() << std::endl;
    }

    if(verbose)
        std::cout << "MaxHeap vec : " << test_heap.toString() << std::endl;

    REQUIRE(test_heap.isMinHeap() == false);
    REQUIRE(test_heap.isMaxHeap() == true);
}


TEST_CASE("test_maxheap_get_limits", "heap")
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


TEST_CASE("test_maxheap_pop_max", "heap")
{
    MaxHeap test_heap;
    REQUIRE(test_heap.empty() == true);

    for(unsigned int i = 0; i < input_array.size(); ++i)
        test_heap.insert(input_array[i]);

    REQUIRE(test_heap.isMinHeap() == false);
    REQUIRE(test_heap.isMaxHeap() == true);
    REQUIRE(test_heap.size() == input_array.size());

    // remove the max element
    int max;
    // See if we can pop the minimum element
    if(verbose)
    {
        std::cout << test_heap.toString() << std::endl;
        std::cout << " (before popMax())" << std::endl;
    }

    max = test_heap.popMax();
    REQUIRE(max == 15);
    REQUIRE(test_heap.size() == input_array.size() - 1);
    REQUIRE(test_heap.isMaxHeap() == true);

    if(verbose)
    {
        std::cout << test_heap.toString() << std::endl;
        std::cout << " (after popMax())" << std::endl;
    }

    // Remove some more
    max = test_heap.popMax();
    REQUIRE(max == 10);
    REQUIRE(test_heap.size() == input_array.size() - 2);
    REQUIRE(test_heap.isMaxHeap() == true);
}


TEST_CASE("test_maxheap_pop_min", "heap")
{
    MaxHeap test_heap;
    REQUIRE(test_heap.empty() == true);

    for(unsigned int i = 0; i < input_array.size(); ++i)
        test_heap.insert(input_array[i]);

    REQUIRE(test_heap.isMinHeap() == false);
    REQUIRE(test_heap.isMaxHeap() == true);
    REQUIRE(test_heap.size() == input_array.size());

    int min;
    // See if we can pop the minimum element
    if(verbose)
    {
        std::cout << test_heap.toString() << std::endl;
        std::cout << " (before popMin())" << std::endl;
    }

    min = test_heap.popMin();
    REQUIRE(min == 1);
    REQUIRE(test_heap.size() == input_array.size() - 1);
    REQUIRE(test_heap.isMaxHeap() == true);

    // Try the next one
    if(verbose)
    {
        std::cout << test_heap.toString() << std::endl;
        std::cout << " (before popMin())" << std::endl;
    }

    min = test_heap.popMin();
    REQUIRE(min == 3);
    REQUIRE(test_heap.size() == input_array.size() - 2);
    REQUIRE(test_heap.isMaxHeap() == true);
}


TEST_CASE("test_maxheap_pop_all_from_root", "heap")
{
    MaxHeap test_heap;
    REQUIRE(test_heap.empty() == true);

    // construct the heap  
    for(unsigned int i = 0; i < input_array.size(); ++i)
        test_heap.insert(input_array[i]);

    // NOTE the weak ordering here...
    std::vector<int> expected_max_vec = {15, 10, 8, 5, 4, 3, 1};
    int max;

    unsigned int num_iter = 0;
    while(!test_heap.empty())
    {
        max = test_heap.popMax();
        if(verbose)
            std::cout << "max " << num_iter << " :" << max << std::endl;

        REQUIRE(max == expected_max_vec[num_iter]);
        REQUIRE(test_heap.isMaxHeap() == true);

        if(verbose)
            std::cout << test_heap.toString() << std::endl;

        //REQUIRE(test_heap.isMinHeap() == false);      // 
        num_iter++;

        if(num_iter > input_array.size())
            break;
        REQUIRE(test_heap.size() == input_array.size() - num_iter);
    }

    REQUIRE(num_iter == input_array.size());
}


TEST_CASE("test_minheap_get_limits", "heap")
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



TEST_CASE("test_minheap_pop_min", "heap")
{
    MinHeap test_heap;
    REQUIRE(test_heap.empty() == true);

    // construct the heap  
    for(unsigned int i = 0; i < input_array.size(); ++i)
        test_heap.insert(input_array[i]);

    REQUIRE(test_heap.isMinHeap() == true);
    REQUIRE(test_heap.isMaxHeap() == false);
    REQUIRE(test_heap.getMin() == 1);
    REQUIRE(test_heap.size() == input_array.size());

    int min;
    // See if we can pop the minimum element
    if(verbose)
    {
        std::cout << test_heap.toString() << std::endl;
        std::cout << " (before popMin())" << std::endl;
    }

    min = test_heap.popMin();
    REQUIRE(min == 1);
    REQUIRE(test_heap.size() == input_array.size() - 1);
    REQUIRE(test_heap.isMinHeap() == true);

    if(verbose)
    {
        std::cout << test_heap.toString() << std::endl;
        std::cout << " (after popMin())" << std::endl;
    }

    // Remove some more
    min = test_heap.popMin();
    REQUIRE(min == 3);
    REQUIRE(test_heap.size() == input_array.size() - 2);
    REQUIRE(test_heap.isMinHeap() == true);
}


TEST_CASE("test_minheap_pop_max", "heap")
{
    MinHeap test_heap;
    REQUIRE(test_heap.empty() == true);
    
    for(unsigned int i = 0; i < input_array.size(); ++i)
        test_heap.insert(input_array[i]);

    REQUIRE(test_heap.isMinHeap() == true);
    REQUIRE(test_heap.isMaxHeap() == false);

    int max;
    // See if we can pop the minimum element
    if(verbose)
    {
        std::cout << test_heap.toString() << std::endl;
        std::cout << " (before popMax())" << std::endl;
    }

    max = test_heap.popMax();
    REQUIRE(max == 15);
    REQUIRE(test_heap.size() == input_array.size() - 1);
    REQUIRE(test_heap.isMinHeap() == true);

    if(verbose)
    {
        std::cout << test_heap.toString() << std::endl;
        std::cout << " (after popMax())" << std::endl;
    }

    // Remove some more
    max = test_heap.popMax();
    REQUIRE(max == 10);
    REQUIRE(test_heap.size() == input_array.size() - 2);
}


// TODO : consider chaning the API to just be 'pop()'
TEST_CASE("test_minheap_pop_all_from_root", "heap")
{
    MinHeap test_heap;
    REQUIRE(test_heap.empty() == true);

    // construct the heap  
    for(unsigned int i = 0; i < input_array.size(); ++i)
        test_heap.insert(input_array[i]);

    // NOTE the weak ordering here...
    std::vector<int> expected_min_vec = {1, 3, 4, 5, 8, 15, 10};
    int min;

    unsigned int num_iter = 0;
    while(!test_heap.empty())
    {
        min = test_heap.popMin();
        if(verbose)
            std::cout << "min " << num_iter << " :" << min << std::endl;

        REQUIRE(min == expected_min_vec[num_iter]);
        REQUIRE(test_heap.isMinHeap() == true);
        //REQUIRE(test_heap.isMaxHeap() == false);
        num_iter++;

        if(num_iter > input_array.size())
            break;
        REQUIRE(test_heap.size() == input_array.size() - num_iter);
    }

    REQUIRE(num_iter == input_array.size());
}
