/* TEST_SHARED_PTR
 * Unit tests for shared_ptr object
 *
 * Stefan Wong 2019
 */

#include <vector>
#include <string>
#include <gtest/gtest.h>
#include "shared_ptr.hpp"


class TestSharedPtr : public ::testing::Test
{
    virtual void SetUp() {}
    virtual void TearDown() {}
};

TEST_F(TestSharedPtr, test_init)
{
    int* some_val = new int(42);
    SharedPtr<int> ref1(some_val);

    ASSERT_EQ(1, ref1.numRef());
}

TEST_F(TestSharedPtr, test_dtor)
{
    int* some_val = new int(24);

    SharedPtr<int> ref1(some_val);
    ASSERT_EQ(1, ref1.numRef());
    SharedPtr<int> ref2(ref1);
    ASSERT_EQ(2, ref1.numRef());
    SharedPtr<int> ref3(ref2);
    ASSERT_EQ(3, ref1.numRef());
    SharedPtr<int> ref4(ref3);
    ASSERT_EQ(4, ref1.numRef());

    // All these should be 'equal' since they have the same pointer
    ASSERT_EQ(ref2, ref1);
    ASSERT_EQ(ref3, ref2);
    ASSERT_EQ(ref3, ref4);

    std::cout << "There are " << ref4.numRef() << " references to some_val remaining" << std::endl;
}


int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
