/* TEST_DYNAMIC
 * Tests for dynamic programming examples
 *
 * Stefan Wong 2019
 */

#define CATCH_CONFIG_MAIN
#include "catch/catch.hpp"

#include <string>
#include "dynamic.hpp"
#include "util.hpp"

const std::vector<int> expected_fib_numbers = {
    0,           1,    1,     2,     3,     5,     8,    13, 21, 
    34,         55,   89,   144,   233,   377,   610,   987, 1597, 
    2584,     4181, 6765, 10946, 17711, 28657, 46368, 75025, 121393, 
    196418, 317811
};



// Fiboancci without memoization
TEST_CASE("dynamic_test_fib", "dynamic")
{
    std::vector<int> fib_outputs;

    for(unsigned int f = 0; f < expected_fib_numbers.size(); ++f)
        fib_outputs.push_back(fibonacci(f));
    REQUIRE(expected_fib_numbers.size() == fib_outputs.size());

    // Check
    for(unsigned int f = 0; f < fib_outputs.size(); ++f)
        REQUIRE(expected_fib_numbers[f] == fib_outputs[f]);
}

// Fibonacci withe memoization
TEST_CASE("dynamic_test_memo", "dynamic")
{
    std::vector<int> fib_outputs;

    for(unsigned int f = 0; f < expected_fib_numbers.size(); ++f)
        fib_outputs.push_back(fibonacci_memo(f));
    REQUIRE(expected_fib_numbers.size() == fib_outputs.size());
    std::cout << "fib_memo" << std::endl;

    // Check
    for(unsigned int f = 0; f < fib_outputs.size(); ++f)
        REQUIRE(expected_fib_numbers[f] == fib_outputs[f]);
}

TEST_CASE("fib_iter", "dynamic")
{
    // Note - we only find the kth fib number 
    std::vector<int> fib_outputs;

    for(unsigned int f = 0; f < expected_fib_numbers.size(); ++f)
        fib_outputs.push_back(fib_iter(f));
    REQUIRE(expected_fib_numbers.size() == fib_outputs.size());

    std::cout << "[" << __func__ << "]" << std::endl;
    std::cout << vec_to_str(fib_outputs) << std::endl;

    // Check
    for(unsigned int f = 0; f < fib_outputs.size(); ++f)
        REQUIRE(expected_fib_numbers[f] == fib_outputs[f]);
}
