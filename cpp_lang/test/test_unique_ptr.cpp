/* TEST_UNIQUE_PTR
 * Unit tests for UniquePtr object
 *
 * Stefan Wong 2019
 */

#define CATCH_CONFIG_MAIN
#include "catch/catch.hpp"

#include <vector>
#include <string>

// Module(s) under test
#include "unique_ptr.hpp"


TEST_CASE("Test unique_ptr init", "[classic]")
{
    // TODO : how do we construct a new object..
    int* some_test_val = new int(42);
    //int* other_test_val = new int(56);

    // Get an empty pointer
    UniquePtr<int> empty_ptr;    

    REQUIRE(empty_ptr.empty() == true);

    UniquePtr<int> test_ptr(some_test_val);
    REQUIRE(test_ptr.empty() == false);
    REQUIRE(*test_ptr == 42);

    // move pointer to another pointer 
    UniquePtr<int> dest_ptr;
    
    dest_ptr = std::move(test_ptr);            // assign with move semantics

    REQUIRE(test_ptr.empty() == true);
    REQUIRE(dest_ptr.empty() == false);
}
