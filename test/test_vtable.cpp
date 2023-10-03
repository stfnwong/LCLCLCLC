/* TEST_VTABLE
 * Trying out some stuff with vtables, vpointers, and whatnot
 *
 * Stefan Wong 2020
 */

#define CATCH_CONFIG_MAIN
#include "catch/catch.hpp"

#include <iostream>
#include <vector>
#include <string>
//#include <gtest/gtest.h>

// Module(s) under test
#include "vtable.hpp"


// This implements the incorrect behaviour (base dtor is not virtual)
TEST_CASE("test_vtable_order_non_virtual_dtor", "vtable")
{
    int test_num = 42;

    std::cout << "[" << __func__ << "] creating new Derived class where Base does not have virtual dtor" << std::endl;
    DerivedNotVirtual* test_derived = new DerivedNotVirtual(test_num);

    REQUIRE(test_derived != nullptr);

    delete test_derived;
}


// This implements the correct dtor order
TEST_CASE("test_vtable_order_virtual_dtor", "vtable")
{
    int test_num = 42;
    std::cout << "[" << __func__ << "] creating new Derived class where Base does have virtual dtor" << std::endl;
    DerivedVirtual* test_derived = new DerivedVirtual(test_num);
    REQUIRE(test_derived != nullptr);

    delete test_derived;
}
