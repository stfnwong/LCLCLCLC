/* TEST_UNIQUE_PTR
 * Unit tests for UniquePtr object
 *
 * Stefan Wong 2019
 */

#define CATCH_CONFIG_MAIN
#include "catch/catch.hpp"

#include <vector>
#include <string>
#include <iostream>

// Module(s) under test
#include "unique_ptr.hpp"


TEST_CASE("Test unique_ptr init", "[classic]")
{
    int* some_test_val = new int(42);

    // Get an empty pointer
    UniquePtr<int> empty_ptr;    
    REQUIRE(empty_ptr.empty() == true);

    UniquePtr<int> test_ptr(some_test_val);
    REQUIRE(test_ptr.empty() == false);
    REQUIRE(*test_ptr == 42);
}

TEST_CASE("Test unique_ptr move", "[classic]")
{
    int* some_test_val = new int(9999);

    UniquePtr<int> test_ptr(some_test_val);
    REQUIRE(*test_ptr == 9999);
    REQUIRE(test_ptr.empty() == false);

    std::cout << "[" << __func__ << "] *test_ptr == " << *test_ptr << std::endl;

    // move pointer to another pointer 
    UniquePtr<int> dest_ptr;
    REQUIRE(test_ptr != dest_ptr);

    // assign with move semantics
    dest_ptr = std::move(test_ptr);   
    REQUIRE(test_ptr.empty() == true);
    REQUIRE(dest_ptr.empty() == false);

    std::cout << "[" << __func__ << "] *dest_ptr == " << *dest_ptr << std::endl;

    // the pointer should have the same value
    REQUIRE(*dest_ptr == 9999);        
}
