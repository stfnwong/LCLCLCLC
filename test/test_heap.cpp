/*
 * TEST_HEAP
 *
 * Stefan Wong 2019
 */


#include <algorithm>
#include <random>
#include <vector>
#include <gtest/gtest.h>
#include "heap.hpp"


class TestHeap : public ::testing::Test
{
    virtual void SetUp() {}
    virtual void TearDown() {}
};


// Test that we can create a heap object 
TEST_F(TestHeap, test_heap_init)
{
	Heap test_heap_100;
	ASSERT_EQ(100, test_heap_100.getMaxSize());

    std::vector<HeapNode> out_nodes = test_heap_100.getVector();
    for(unsigned int n = 0; n < out_nodes.size(); ++n)
    {
        ASSERT_EQ(0, out_nodes[n].key);
        ASSERT_EQ(0, out_nodes[n].val);
    }

	Heap test_heap_8(8);
	ASSERT_EQ(8, test_heap_8.getMaxSize());
    out_nodes = test_heap_8.getVector();

    for(unsigned int n = 0; n < out_nodes.size(); ++n)
    {
        ASSERT_EQ(0, out_nodes[n].key);
        ASSERT_EQ(0, out_nodes[n].val);
    }

    // Obviously this should work for all positive values 
	Heap test_heap_512(512);
	ASSERT_EQ(512, test_heap_512.getMaxSize());
}


// Test construction of a new heap
TEST_F(TestHeap, test_heap_build)
{
    // Create a vector that looks how we expect the heap to be after insertion
    std::vector<int> expected_keys = {9, 8, 6, 7, 4, 5, 2, 0, 3, 1};
    // Shuffle the keys and make a new vector to provide to the heap
    std::vector<int> input_keys = {9, 8, 6, 7, 4, 5, 2, 0, 3, 1};
    auto rng = std::default_random_engine {};
    std::shuffle(std::begin(input_keys), std::end(input_keys), rng);

    std::cout << "Shuffled Input keys (length " << input_keys.size() << ") are :" << std::endl;
    std::cout << "{" << input_keys[0];
    for(unsigned int k = 1; k < input_keys.size(); ++k)
    {
        std::cout << ", " << input_keys[k];
    }
    std::cout << "}" << std::endl;

    // Get a new heap
    Heap test_heap(int(input_keys.size()));

    ASSERT_EQ(input_keys.size(), test_heap.getMaxSize());
    ASSERT_EQ(0, test_heap.getNumElem());

    // Place the keys in the heap
    HeapNode node;
    for(unsigned int k = 0; k < input_keys.size(); ++k)
    {
        node.key = input_keys[k];
        node.val = k;
        std::cout << "Inserting node " << node.toString() << std::endl;
        test_heap.insertNode(node);
    }

    std::vector<HeapNode> out_nodes = test_heap.getVector();
    // Show the output vector
    ASSERT_EQ(input_keys.size(), test_heap.getNumElem());
    std::cout << "Internal heap vector : " << std::endl;
    for(unsigned int n = 0; n < out_nodes.size(); ++n)
    {
        std::cout << out_nodes[n].toString() << " ";
    }
    std::cout << "}" << std::endl;

    // Ensure that the output is in the expected order 
    for(unsigned int k = 0; k < out_nodes.size(); ++k)
    {
        ASSERT_EQ(input_keys[k], out_nodes[k].key);
    }
}



//TEST_F(TestHeap, test_heap_build)
//{
//    Heap test_heap;
//	ASSERT_EQ(100, test_heap.getMaxSize());
//
//    // TODO : create some nodes that we can add to the heap
//    // Eventually we want to end up with the heap
//    // [1,2,5,10,3,7,11,15,17,20,9,15,8,16]
//
//    std::vector<int> node_keys = {16, 8, 15, 9, 20, 17, 15, 11, 7, 3, 10, 5, 2, 1};
//    
//    std::cout << "Input vector is {" << node_keys[0];
//    for(unsigned int i = 1; i < node_keys.size(); ++i)
//        std::cout << ", " << node_keys[i];
//    std::cout << "}" << std::endl;
//
//    for(unsigned int k = 0; k < node_keys.size(); ++k)
//    {
//        HeapNode node(node_keys[k], k);
//        std::cout << "    Adding node " << node.toString() << std::endl;
//        test_heap.insertNode(node);
//        //test_heap.insertNode(HeapNode(k, 0));
//    }
//
//    std::vector<HeapNode> out_nodes = test_heap.getVector();
//    std::cout << "==== Iterating over output vector " << std::endl;
//    std::cout << "{";
//    for(unsigned int n = 0; n < test_heap.getNumElem(); ++n)
//    {
//        std::cout << out_nodes[n].toString() << " ";
//    }
//    std::cout << "}" << std::endl;
//}


int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
