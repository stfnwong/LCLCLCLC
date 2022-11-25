/*
 * TEST_DS_ARRAYS
 * All the questions in the array's subsection of the data structures part
 * of the Educative coding interview course
 */
#define CATCH_CONFIG_MAIN
#include "catch/catch.hpp"

#include "arrays.hpp"

// TODO: Another test is case is 
// inp = {-4, 2, -5, 3, 6};
// wsize = 3;
// out = {2, 3 ,6};
TEST_CASE("test_find_max_sliding_window", "ds")
{
    std::vector<int> inp = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    unsigned int wsize = 3;
    std::vector<int> exp_out = {3, 4, 5, 6, 7, 8, 9, 10};

    std::vector<int> result =  find_max_sliding_window(inp, wsize);
    
    REQUIRE(result.size() == exp_out.size());
    for(unsigned i = 0; i < result.size(); ++i)
        REQUIRE(result[i] == exp_out[i]);
}



// Test some palindromes 
TEST_CASE("test_is_palindrome", "ds")
{
    std::vector<std::string> inputs = {
        "kayak",
        "hello",
        "RACEACAR",
        "A",
        "ABCDABCD",
        "DCBAABCD",
        "ABCBA"
    };

    std::vector<bool> exp_outputs = {
        true,
        false,
        false,
        true,
        false,
        true,
        true
    };

    unsigned num_test_cases = inputs.size();
    for(unsigned test_case = 0; test_case < num_test_cases; ++test_case)
    {
        bool out = is_palindrome(inputs[test_case]);
        REQUIRE(out == exp_outputs[test_case]);
    }
}
