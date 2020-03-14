/* TEST_SHARED_PTR
 * Unit tests for SharedPtr object
 *
 * Stefan Wong 2019
 */

#define CATCH_CONFIG_MAIN
#include "catch/catch.hpp"

#include <vector>
#include <string>

// Module(s) under test
#include "shared_ptr.hpp"


// ================ INTRUSIVE SHARED POINTER ================= //
TEST_CASE("test_shared_ptr_intrusive_init", "[classic]")
{
    int* some_val = new int(42);
    int* some_other_val = new int(42);

    SharedPtrIntrusive<int> empty_ref();
    //REQUIRE(empty_ref.empty() == true);     // non-class type error?

    SharedPtrIntrusive<int> ref1(some_val);
    REQUIRE(ref1.empty() == false);

    REQUIRE(1 == ref1.numRef());

    SharedPtrIntrusive<int> ref2(some_other_val);

    REQUIRE(1 == ref2.numRef());
    REQUIRE(ref1 != ref2);          // memory is not common, should fail

    // also check the values
    REQUIRE(*ref1 == 42);
    REQUIRE(*ref2 == 42);
}


TEST_CASE("test_shared_ptr_intrusive_share", "[classic]")
{
    int* some_val = new int(24);

    SharedPtrIntrusive<int> ref1(some_val);
    REQUIRE(1 == ref1.numRef());
    std::cout << "There are " << ref1.numRef() << " references to <some_val>" << std::endl;
    SharedPtrIntrusive<int> ref2(ref1);
    REQUIRE(2 == ref1.numRef());
    std::cout << "There are " << ref1.numRef() << " references to <some_val>" << std::endl;
    SharedPtrIntrusive<int> ref3(ref2);
    REQUIRE(3 == ref1.numRef());
    std::cout << "There are " << ref1.numRef() << " references to <some_val>" << std::endl;
    SharedPtrIntrusive<int> ref4(ref3);
    REQUIRE(4 == ref1.numRef());
    std::cout << "There are " << ref1.numRef() << " references to <some_val>" << std::endl;

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

// ================ NON-INTRUSIVE SHARED POINTER ================= //
TEST_CASE("test_shared_ptr_init", "[classic]")
{
    // Externally, this works the same way as the intrusive shared pointer
    int* some_val = new int(42);
    int* some_other_val = new int(42);

    SharedPtr<int> ref1(some_val);

    REQUIRE(1 == ref1.numRef());

    SharedPtr<int> ref2(some_other_val);

    REQUIRE(1 == ref2.numRef());
    REQUIRE(ref1 != ref2);          // memory is not common, should fail

    // also check the values
    REQUIRE(*ref1 == 42);
    REQUIRE(*ref2 == 42);
}

TEST_CASE("test_shared_ptr_share", "[classic]")
{
    // This is also externally identical to SharedPtrIntrusive
    int* some_val = new int(24);

    SharedPtr<int> ref1(some_val);
    REQUIRE(1 == ref1.numRef());
    std::cout << "There are " << ref1.numRef() << " references to <some_val>" << std::endl;
    SharedPtr<int> ref2(ref1);
    REQUIRE(2 == ref1.numRef());
    std::cout << "There are " << ref1.numRef() << " references to <some_val>" << std::endl;
    SharedPtr<int> ref3(ref2);
    REQUIRE(3 == ref1.numRef());
    std::cout << "There are " << ref1.numRef() << " references to <some_val>" << std::endl;
    SharedPtr<int> ref4(ref3);
    REQUIRE(4 == ref1.numRef());
    std::cout << "There are " << ref1.numRef() << " references to <some_val>" << std::endl;

    // Do all the same checks as for the intrusive shared pointer
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
    SharedPtr<int> new_ref1(some_other_val);
    SharedPtr<int> new_ref2(new_ref1);

    REQUIRE(new_ref1 == new_ref2);
    // Any combination of these will fail
    REQUIRE(ref1 != new_ref1);
    REQUIRE(ref1 != new_ref2);
    REQUIRE(ref2 != new_ref2);
    REQUIRE(ref2 != new_ref1);

    // Dereferencing should get the value back
    REQUIRE(*new_ref1 == 48);
    REQUIRE(*new_ref2 == 48);
    REQUIRE(ref2 == ref1);
    REQUIRE(ref3 == ref2);
    REQUIRE(ref3 == ref4);
    REQUIRE(ref4 == ref1);

    // Also check that the value is correct
    REQUIRE(*ref1 == 24);
    REQUIRE(*ref2 == 24);
    REQUIRE(*ref3 == 24);
    REQUIRE(*ref4 == 24);
}
