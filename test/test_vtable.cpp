/* TEST_VTABLE
 * Trying out some stuff with vtables, vpointers, and whatnot
 *
 * Stefan Wong 2020
 */

#define CATCH_CONFIG_MAIN
#include "catch/catch.hpp"

#include <vector>
#include <string>
//#include <gtest/gtest.h>

// Module(s) under test
#include "vtable.hpp"

TEST_CASE("test_vtable_order", "[classic]")
{
    Derived test_derived;
}
