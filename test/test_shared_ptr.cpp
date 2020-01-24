/* TEST_SHARED_PTR
 * Unit tests for shared_ptr object
 *
 * Stefan Wong 2019
 */

#define CATCH_CONFIG_MAIN
#include "catch/catch.hpp"

#include <vector>
#include <string>
//#include <gtest/gtest.h>

// Module(s) under test
#include "shared_ptr.hpp"


TEST_CASE("test_shared_ptr_intrusive_init", "[classic]")
{
    int* some_val = new int(42);
    int* some_other_val = new int(42);
    SharedPtrIntrusive<int> ref1(some_val);

    REQUIRE(1 == ref1.numRef());

    SharedPtrIntrusive<int> ref2(some_other_val);

    REQUIRE(1 == ref2.numRef());
    REQUIRE(ref1 != ref2);          // memory is not common, should fail
}


TEST_CASE("test_shared_ptr_intrusive_share", "[classic]")
{
    int* some_val = new int(24);

    SharedPtrIntrusive<int> ref1(some_val);
    REQUIRE(1 == ref1.numRef());
    std::cout << "There are " << ref1.numRef() << " references to some_val" << std::endl;
    SharedPtrIntrusive<int> ref2(ref1);
    REQUIRE(2 == ref1.numRef());
    std::cout << "There are " << ref1.numRef() << " references to some_val" << std::endl;
    SharedPtrIntrusive<int> ref3(ref2);
    REQUIRE(3 == ref1.numRef());
    std::cout << "There are " << ref1.numRef() << " references to some_val" << std::endl;
    SharedPtrIntrusive<int> ref4(ref3);
    REQUIRE(4 == ref1.numRef());
    std::cout << "There are " << ref1.numRef() << " references to some_val" << std::endl;

    // All these should be 'equal' since they have the same pointer
    // Equality test is overloaded for the pointers than the value
    REQUIRE(ref2 == ref1);
    REQUIRE(ref3 == ref2);
    REQUIRE(ref3 == ref4);
    REQUIRE(ref4 == ref1);

    // Also check that the value is correct
    REQUIRE(*ref1 == 24);
    REQUIRE(*ref2 == 24);
    REQUIRE(*ref3 == 24);
    REQUIRE(*ref4 == 24);

    // Now if we make some more shared pointers here with a different var, 
    // we should find that they fail any equality test with ref1 - ref4
    int* some_other_val = new int(48);
    // NOTE: we are only copy-constructing here 
    SharedPtrIntrusive<int> new_ref1(some_other_val);
    SharedPtrIntrusive<int> new_ref2(new_ref1);

    REQUIRE(new_ref1 == new_ref2);
    // Any combination of these will fail
    REQUIRE(ref1 != new_ref1);
    REQUIRE(ref1 != new_ref2);
    REQUIRE(ref2 != new_ref2);
    REQUIRE(ref2 != new_ref1);

    // Dereferencing should get the value back
    REQUIRE(*new_ref1 == 48);
    REQUIRE(*new_ref2 == 48);
}



//TEST_CASE("test_shared_ptr_intrusive_ref", "[classic]")
//{
//    int* some_val = new int(24);
//
//
//}


//TEST_F(TestSharedPtrIntrusive, test_multiple_share)
//{
//
//}
