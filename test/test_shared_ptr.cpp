/* TEST_SHARED_PTR
 * Unit tests for shared_ptr object
 *
 * Stefan Wong 2019
 */

#define CATCH_CONFIG_MAIN
#include "catch/catch.hpp"

#include <vector>
#include <string>
#include "shared_ptr.hpp"



TEST_CASE("test_init", "shared_ptr")
{
    int* some_val = new int(42);
    int* some_other_val = new int(42);
    SharedPtr<int> ref1(some_val);

    REQUIRE(1 == ref1.numRef());

    SharedPtr<int> ref2(some_other_val);

    REQUIRE(1 == ref2.numRef());
    REQUIRE(ref1 != ref2);          // memory is not common, should fail
}

TEST_CASE("test_dtor", "shared_ptr")
{
    int* some_val = new int(24);

    SharedPtr<int> ref1(some_val);
    REQUIRE(1 == ref1.numRef());
    std::cout << "There are " << ref1.numRef() << " references to some_val" << std::endl;
    SharedPtr<int> ref2(ref1);
    REQUIRE(2 == ref1.numRef());
    std::cout << "There are " << ref1.numRef() << " references to some_val" << std::endl;
    SharedPtr<int> ref3(ref2);
    REQUIRE(3 == ref1.numRef());
    std::cout << "There are " << ref1.numRef() << " references to some_val" << std::endl;
    SharedPtr<int> ref4(ref3);
    REQUIRE(4 == ref1.numRef());
    std::cout << "There are " << ref1.numRef() << " references to some_val" << std::endl;

    // All these should be 'equal' since they have the same pointer
    REQUIRE(ref2 == ref1);
    REQUIRE(ref3 == ref2);
    REQUIRE(ref3 == ref4);
    REQUIRE(ref4 == ref1);

    // Now if we make some more shared pointers here with a different var, 
    // we should find that they fail any equality test with ref1 - ref4
    int* some_other_val = new int(24);
    // NOTE: we are only copy-constructing here 
    SharedPtr<int> new_ref1(some_other_val);
    SharedPtr<int> new_ref2(new_ref1);

    REQUIRE(new_ref1 == new_ref2);
    // Any combination of these will fail
    REQUIRE(ref1 != new_ref1);
    REQUIRE(ref1 != new_ref2);
    REQUIRE(ref2 != new_ref2);
    REQUIRE(ref2 != new_ref1);
    // And so on....
}

//TEST_CASE(TestSharedPtr, test_multiple_share)
//{
//
//}
