/* TEST_LIST
 * Tests for dynamic programming examples
 *
 * Stefan Wong 2019
 */

#define CATCH_CONFIG_MAIN
#include "catch/catch.hpp"

#include "list.hpp"


TEST_CASE("test_create_list_node", "list")
{
    ListNode* test_node = new ListNode();

    REQUIRE(test_node->next == nullptr);
    REQUIRE(test_node->val == 0);

    delete test_node;
}

TEST_CASE("test_create_list_from_vector", "list")
{
    std::vector<int> test_inp = {1, 2, 3, 4, 5};

    ListNode* test_list;
    test_list = list_from_vector(test_inp);

    REQUIRE(test_list != nullptr);
    REQUIRE(list_length(test_list) == test_inp.size());

    unsigned idx = 0;
    while(test_list)
    {
        REQUIRE(test_list->val == test_inp[idx]);
        test_list = test_list->next;
        idx++;
    }

    delete test_list;
}


TEST_CASE("test_create_list_from_vector_with_tail_pointer_with_cycle", "list")
{
    std::vector<int> test_inp = {0, 1};
    int target_pos = 0;

    ListNode* test_list = list_from_vector_with_tail_pointer(test_inp, target_pos);
    REQUIRE(test_list != nullptr);

    // Do cycle detection on the list, if we 
    REQUIRE(list_has_cycle(test_list) == true);
}

TEST_CASE("test_create_list_from_vector_with_tail_pointer_with_cycle_2", "list")
{
    // Try on a larger list
    std::vector<int> test_inp = {1, 2, 3, 4, 5, 6};
    int target_pos = 3;
    ListNode* test_list = list_from_vector_with_tail_pointer(test_inp, target_pos);

    REQUIRE(test_list != nullptr);
    REQUIRE(list_has_cycle(test_list) == true);
}

TEST_CASE("test_create_list_from_vector_with_tail_pointer_without_cycle", "list")
{
    std::vector<int> test_inp = {1, 2, 3, 4};
    
    ListNode* test_list = list_from_vector_with_tail_pointer(test_inp, -1);
    
    REQUIRE(list_has_cycle(test_list) == false);
    REQUIRE(list_length(test_list) == test_inp.size());
}


TEST_CASE("test_create_vector_from_list", "list")
{
    ListNode* test_list = new ListNode();

    // create a sample list 
    std::vector<int> sample_list_vals = {1, 2, 3, 4};
    ListNode* inp_list = list_from_vector(sample_list_vals);

    // turn this list back into a vector
    std::vector<int> out_vec = vector_from_list(inp_list);

    // This vector should have the same dimensions as the input vec
    REQUIRE(out_vec.size() == sample_list_vals.size());
    for(unsigned i = 0 ; i < out_vec.size(); ++i)
        REQUIRE(out_vec[i] == sample_list_vals[i]);

    // can also test against the list object itself
    REQUIRE(list_length(inp_list) == out_vec.size());
    
    unsigned idx = 0;
    while(inp_list)
    {
        REQUIRE(inp_list->val == out_vec[idx]);
        inp_list = inp_list->next;
        idx++;
    }

    delete test_list;
}
