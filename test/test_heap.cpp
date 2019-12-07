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

    public:
        std::vector<int> input_keys        = {9, 8, 6, 7, 4, 5, 2, 0, 3, 1};
        std::vector<int> min_expected_keys = {0, 1, 2, 4, 3, 7, 8, 5, 9, 6};
        std::vector<int> max_expected_keys = {9, 8, 6, 7, 4, 5, 2, 0, 3, 1};
};


// Test that we can create a MinHeap object 
TEST_F(TestHeap, test_min_heap_init)
{
	MinHeap test_heap_100;
	ASSERT_EQ(100, test_heap_100.getMaxSize());

    std::vector<HeapNode> out_nodes = test_heap_100.getVector();
    for(unsigned int n = 0; n < out_nodes.size(); ++n)
    {
        ASSERT_EQ(0, out_nodes[n].key);
        ASSERT_EQ(0, out_nodes[n].val);
    }

	MinHeap test_heap_8(8);
	ASSERT_EQ(8, test_heap_8.getMaxSize());
    out_nodes = test_heap_8.getVector();

    for(unsigned int n = 0; n < out_nodes.size(); ++n)
    {
        ASSERT_EQ(0, out_nodes[n].key);
        ASSERT_EQ(0, out_nodes[n].val);
    }

    // Obviously this should work for all positive values 
	MinHeap test_heap_512(512);
	ASSERT_EQ(512, test_heap_512.getMaxSize());
}


// Test that we can create a MinHeap object 
TEST_F(TestHeap, test_max_heap_init)
{
	MaxHeap test_heap_100;
	ASSERT_EQ(100, test_heap_100.getMaxSize());

    std::vector<HeapNode> out_nodes = test_heap_100.getVector();
    for(unsigned int n = 0; n < out_nodes.size(); ++n)
    {
        ASSERT_EQ(0, out_nodes[n].key);
        ASSERT_EQ(0, out_nodes[n].val);
    }

	MaxHeap test_heap_8(8);
	ASSERT_EQ(8, test_heap_8.getMaxSize());
    out_nodes = test_heap_8.getVector();

    for(unsigned int n = 0; n < out_nodes.size(); ++n)
    {
        ASSERT_EQ(0, out_nodes[n].key);
        ASSERT_EQ(0, out_nodes[n].val);
    }

    // Obviously this should work for all positive values 
	MaxHeap test_heap_512(512);
	ASSERT_EQ(512, test_heap_512.getMaxSize());
}


// Test construction of a new heap
TEST_F(TestHeap, test_min_heap)
{
    //auto rng = std::default_random_engine {};
    //std::shuffle(std::begin(input_keys), std::end(input_keys), rng);

    //std::cout << "Shuffled Input keys (length " << input_keys.size() << ") are :" << std::endl;
    std::cout << "Input keys (length " << this->input_keys.size() << ") are : " << std::endl;
    std::cout << "{" << input_keys[0];
    for(unsigned int k = 1; k < this->input_keys.size(); ++k)
    {
        std::cout << ", " << this->input_keys[k];
    }
    std::cout << "}" << std::endl;

    // Get a new heap
    MinHeap test_heap(int(this->input_keys.size()));

    ASSERT_EQ(input_keys.size(), test_heap.getMaxSize());
    ASSERT_EQ(0, test_heap.getNumElem());

    // Place the keys in the heap
    HeapNode node;
    for(unsigned int k = 0; k < this->input_keys.size(); ++k)
    {
        node.key = input_keys[k];
        node.val = k;
        test_heap.insertNode(node);
    }

    std::vector<HeapNode> out_nodes = test_heap.getVector();
    // Show the output vector
    ASSERT_EQ(input_keys.size(), test_heap.getNumElem());
    std::cout << "Internal heap vector : " << std::endl;
    std::cout << "{";
    for(unsigned int n = 0; n < out_nodes.size(); ++n)
    {
        //std::cout << out_nodes[n].toString() << " ";
        std::cout << out_nodes[n].key << " ";
    }
    std::cout << "}" << std::endl;

    // Ensure that the output is in the expected order 
    for(unsigned int k = 0; k < out_nodes.size(); ++k)
    {
        ASSERT_EQ(this->min_expected_keys[k], out_nodes[k].key);
    }
}


// Test construction of a new heap
TEST_F(TestHeap, test_max_heap)
{
    std::cout << "Input keys (length " << this->input_keys.size() << ") are : " << std::endl;
    std::cout << "{" << input_keys[0];
    for(unsigned int k = 1; k < this->input_keys.size(); ++k)
    {
        std::cout << ", " << this->input_keys[k];
    }
    std::cout << "}" << std::endl;

    // Get a new heap
    MaxHeap test_heap(int(this->input_keys.size()));

    ASSERT_EQ(input_keys.size(), test_heap.getMaxSize());
    ASSERT_EQ(0, test_heap.getNumElem());

    // Place the keys in the heap
    HeapNode node;
    for(unsigned int k = 0; k < this->input_keys.size(); ++k)
    {
        node.key = input_keys[k];
        node.val = k;
        test_heap.insertNode(node);
    }

    std::vector<HeapNode> out_nodes = test_heap.getVector();
    // Show the output vector
    ASSERT_EQ(input_keys.size(), test_heap.getNumElem());
    std::cout << "Internal heap vector : " << std::endl;
    std::cout << "{";
    for(unsigned int n = 0; n < out_nodes.size(); ++n)
    {
        std::cout << out_nodes[n].key << " ";
    }
    std::cout << "}" << std::endl;

    // Ensure that the output is in the expected order 
    for(unsigned int k = 0; k < out_nodes.size(); ++k)
    {
        ASSERT_EQ(this->max_expected_keys[k], out_nodes[k].key);
    }
}


// ======== HEAP UTILITY FUNCTION TEST ======== //
// Test that we can find the min heap property
TEST_F(TestHeap, test_min_heap_property)
{
    MinHeap min_heap(int(this->input_keys.size()));

    HeapNode node;
    for(unsigned int k = 0; k < this->input_keys.size(); ++k)
    {
        node.key = input_keys[k];
        node.val = k;
        min_heap.insertNode(node);
    }

    std::vector<HeapNode> out_nodes = min_heap.getVector();

    ASSERT_EQ(input_keys.size(), min_heap.getNumElem());
    std::cout << "Internal heap vector : " << std::endl;
    std::cout << "{";
    for(unsigned int n = 0; n < out_nodes.size(); ++n)
    {
        std::cout << out_nodes[n].key << " ";
    }
    std::cout << "}" << std::endl;

    // Ensure that the output is in the expected order 
    for(unsigned int k = 0; k < out_nodes.size(); ++k)
    {
        ASSERT_EQ(this->min_expected_keys[k], out_nodes[k].key);
    }
    // Also check that the correct heap property holds
    ASSERT_EQ(false, has_max_heap_property(min_heap));
    ASSERT_EQ(true, has_min_heap_property(min_heap));
}

// Test that we can determine the max heap property
TEST_F(TestHeap, test_max_heap_property)
{
    MaxHeap min_heap(int(this->input_keys.size()));

    HeapNode node;
    for(unsigned int k = 0; k < this->input_keys.size(); ++k)
    {
        node.key = input_keys[k];
        node.val = k;
        std::cout << "Inserting node " << node.toString() << std::endl;
        min_heap.insertNode(node);
    }

    std::vector<HeapNode> out_nodes = min_heap.getVector();
    ASSERT_EQ(input_keys.size(), min_heap.getNumElem());
    std::cout << "Internal heap vector : " << std::endl;
    std::cout << "{";
    for(unsigned int n = 0; n < out_nodes.size(); ++n)
    {
        //std::cout << out_nodes[n].toString() << " ";
        std::cout << out_nodes[n].key << " ";
    }
    std::cout << "}" << std::endl;

    // Ensure that the output is in the expected order 
    for(unsigned int k = 0; k < out_nodes.size(); ++k)
    {
        ASSERT_EQ(this->min_expected_keys[k], out_nodes[k].key);
    }
    // Also check that the correct heap property holds
    ASSERT_EQ(true, has_max_heap_property(min_heap));
    ASSERT_EQ(false, has_min_heap_property(min_heap));

}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
