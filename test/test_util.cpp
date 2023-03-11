/* 
 * TEST UTILS
 */

#define CATCH_CONFIG_MAIN
#include "catch/catch.hpp"

#include <iostream>

// Module(s) under test
#include "util.hpp"


TEST_CASE("test_vec_to_str_empty_vec", "vec_to_str")
{
    std::vector<int> empty_input;
    std::string out_string = vec_to_str(empty_input);
    REQUIRE(out_string.length() == 0);
}


TEST_CASE("test_vec_vec_to_str_empty_vec", "vec_to_str")
{
    std::vector<std::vector<int>> empty_input;
    std::string out_string = vec_vec_to_str(empty_input);
    REQUIRE(out_string.length() == 0);
    REQUIRE(out_string == "");
}

TEST_CASE("test_vec_vec_to_str", "vec_to_str")
{
    std::vector<std::vector<int>> input;

    for(unsigned i = 0; i < 4; ++i)
    {
        std::vector<int> col = {1, 2, 3, 4};
        input.push_back(col);
    }

    std::string out_string = vec_vec_to_str(input);
    std::string exp_output = "1 2 3 4 \n1 2 3 4 \n1 2 3 4 \n1 2 3 4 \n";

    REQUIRE(out_string == exp_output);
}

