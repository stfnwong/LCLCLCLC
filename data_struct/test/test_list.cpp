#define CATCH_CONFIG_MAIN
#include "catch/catch.hpp"

// Module(s) under test
#include "list.hpp"



/*
 * NODE BASED HEAP
 */
TEST_CASE("test_list_node_ctor", "ListNode")
{
    ListNode<int> node(100);

    REQUIRE(node.next == nullptr);
    REQUIRE(node.prev == nullptr);

    REQUIRE(node.value == 100);
}
