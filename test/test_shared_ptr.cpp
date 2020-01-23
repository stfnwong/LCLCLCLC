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
    int* some_other_val = new int(42);
    SharedPtr<int> ref1(some_val);

    ASSERT_EQ(1, ref1.numRef());

    SharedPtr<int> ref2(some_other_val);

    ASSERT_EQ(1, ref2.numRef());
    ASSERT_NE(ref1, ref2);          // memory is not common, should fail
}

TEST_F(TestSharedPtr, test_dtor)
{
    int* some_val = new int(24);

    SharedPtr<int> ref1(some_val);
    ASSERT_EQ(1, ref1.numRef());
    std::cout << "There are " << ref1.numRef() << " references to some_val" << std::endl;
    SharedPtr<int> ref2(ref1);
    ASSERT_EQ(2, ref1.numRef());
    std::cout << "There are " << ref1.numRef() << " references to some_val" << std::endl;
    SharedPtr<int> ref3(ref2);
    ASSERT_EQ(3, ref1.numRef());
    std::cout << "There are " << ref1.numRef() << " references to some_val" << std::endl;
    SharedPtr<int> ref4(ref3);
    ASSERT_EQ(4, ref1.numRef());
    std::cout << "There are " << ref1.numRef() << " references to some_val" << std::endl;

    // All these should be 'equal' since they have the same pointer
    ASSERT_EQ(ref2, ref1);
    ASSERT_EQ(ref3, ref2);
    ASSERT_EQ(ref3, ref4);
    ASSERT_EQ(ref4, ref1);

    // Now if we make some more shared pointers here with a different var, 
    // we should find that they fail any equality test with ref1 - ref4
    int* some_other_val = new int(24);
    // NOTE: we are only copy-constructing here 
    SharedPtr<int> new_ref1(some_other_val);
    SharedPtr<int> new_ref2(new_ref1);

    ASSERT_EQ(new_ref1, new_ref2);
    // Any combination of these will fail
    ASSERT_NE(ref1, new_ref1);
    ASSERT_NE(ref1, new_ref2);
    ASSERT_NE(ref2, new_ref2);
    ASSERT_NE(ref2, new_ref1);
    // And so on....
}

//TEST_F(TestSharedPtr, test_multiple_share)
//{
//
//}



int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}