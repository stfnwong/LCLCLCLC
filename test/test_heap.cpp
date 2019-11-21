/*
 * TEST_HEAP
 *
 * Stefan Wong 2019
 */


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

	Heap test_heap_8(8);
	ASSERT_EQ(8, test_heap_8.getMaxSize());
    // Obviously this should work for all positive values 
	Heap test_heap_512(512);
	ASSERT_EQ(512, test_heap_512.getMaxSize());
}


// Test construction of a new heap
TEST_F(TestHeap, test_heap_build)
{
    Heap test_heap;
	ASSERT_EQ(100, test_heap.getMaxSize());

    // TODO : create some nodes that we can add to the heap
    // Eventually we want to end up with the heap
    // [1,2,5,10,3,7,11,15,17,20,9,15,8,16]

    std::vector<int> node_keys = {16, 8, 15, 9, 20, 17, 15, 11, 7, 3, 10, 5, 2, 1};
    
    std::cout << "Input vector is {" << node_keys[0];
    for(unsigned int i = 1; i < node_keys.size(); ++i)
        std::cout << ", " << node_keys[i];
    std::cout << "}" << std::endl;

    for(unsigned int k = 0; k < node_keys.size(); ++k)
    {
        HeapNode node(node_keys[k], k);
        std::cout << "    Adding node " << node.toString() << std::endl;
        test_heap.insertNode(node);
        //test_heap.insertNode(HeapNode(k, 0));
    }

    std::vector<HeapNode> out_nodes = test_heap.getVector();
    std::cout << "==== Iterating over output vector " << std::endl;
    std::cout << "{";
    for(unsigned int n = 0; n < test_heap.getNumElem(); ++n)
    {
        std::cout << out_nodes[n].toString() << " ";
    }
    std::cout << "}" << std::endl;
}


int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
