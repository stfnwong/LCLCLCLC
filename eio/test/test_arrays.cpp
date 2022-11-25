/*
 * TEST_DS_ARRAYS
 * All the questions in the array's subsection of the data structures part
 * of the Educative coding interview course
 */
#define CATCH_CONFIG_MAIN
#include "catch/catch.hpp"

#include <iostream>
#include <utility>
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
    
    // TODO: implement this
    //REQUIRE(result.size() == exp_out.size());
    //for(unsigned i = 0; i < result.size(); ++i)
    //    REQUIRE(result[i] == exp_out[i]);
}



// Test some palindromes 
TEST_CASE("test_is_palindrome", "ds")
{
    std::vector<std::pair<std::string, bool>> inputs = {
        {"kayak", true},
        {"hello", false},
        {"RACEACAR", false},
        {"A", true},
        {"ABCDABCD", false},
        {"DCBAABCD", true},
        {"ABCBA", true}
    };

    unsigned num_test_cases = inputs.size();
    for(unsigned test_case = 0; test_case < num_test_cases; ++test_case)
    {
        std::cout << "Case " << test_case << ", checking [" << inputs[test_case].first << "]" << std::endl;
        bool out = is_palindrome(inputs[test_case].first);
        REQUIRE(out == inputs[test_case].second);
    }
}
