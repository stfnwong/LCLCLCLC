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
	ASSERT_EQ(100, test_heap_100.getMax());

	Heap test_heap_8(8);
	ASSERT_EQ(8, test_heap_8.getMax());
}



int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
