/* TEST_DYNAMIC
 * Tests for dynamic programming examples
 *
 * Stefan Wong 2019
 */

#include <vector>
#include <string>
#include <gtest/gtest.h>
#include "dynamic.hpp"


class TestDynamic : public ::testing::Test
{
    virtual void SetUp() {}
    virtual void TearDown() {}

    public:
        std::vector<int> expected_fib_numbers = {
            0,           1,    1,     2,     3,     5,     8,    13, 21, 
            34,         55,   89,   144,   233,   377,   610,   987, 1597, 
            2584,     4181, 6765, 10946, 17711, 28657, 46368, 75025, 121393, 
            196418, 317811};
};


// Fiboancci without memoization
TEST_F(TestDynamic, test_fib)
{
    std::vector<int> fib_outputs;

    for(unsigned int f = 0; f < this->expected_fib_numbers.size(); ++f)
    {
        fib_outputs.push_back(fibonacci(f));
    }
    ASSERT_EQ(this->expected_fib_numbers.size(), fib_outputs.size());

    // Check
    for(unsigned int f = 0; f < fib_outputs.size(); ++f)
        ASSERT_EQ(this->expected_fib_numbers[f], fib_outputs[f]);
}

// Fibonacci withe memoization
TEST_F(TestDynamic, test_fib_memo)
{
    std::vector<int> fib_outputs;

    for(unsigned int f = 0; f < this->expected_fib_numbers.size(); ++f)
    {
        fib_outputs.push_back(fibonacci_memo(f));
    }
    ASSERT_EQ(this->expected_fib_numbers.size(), fib_outputs.size());

    // Check
    for(unsigned int f = 0; f < fib_outputs.size(); ++f)
        ASSERT_EQ(this->expected_fib_numbers[f], fib_outputs[f]);
}


// ======== EGG DROP ======== //



int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
