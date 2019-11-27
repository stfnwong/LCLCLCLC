/* TEST_QUESTIONS
 * Run the test cases for the questions
 *
 * Stefan Wong 2019
 */

#include <vector>
#include <string>
#include <gtest/gtest.h>
#include "questions.hpp"

class TestQuestions : public ::testing::Test
{
    virtual void SetUp() {}
    virtual void TearDown() {}

};


TEST_F(TestQuestions, test_question_1)  // two-sum
{
    int target = 9;
    std::vector<int> inputs = {2, 7, 11, 15};
    std::vector<int> expected_output = {0, 1};

    std::vector<int> two_sum_out;

    two_sum_out = two_sum(inputs, target);

    std::cout << "{";
    for(unsigned int i = 0; i < two_sum_out.size(); ++i)
        std::cout << two_sum_out[i] << ", ";
    std::cout << "}" << std::endl;

    for(unsigned int i = 0; i < two_sum_out.size(); ++i)
        ASSERT_EQ(expected_output[i], two_sum_out[i]);

}

TEST_F(TestQuestions, test_question_17)
{
    std::string input = "23";
    std::vector<std::string> expected_output = {"ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"};
    std::vector<std::string> output;

    // Get the outputs
    output = letter_combinations_17(input);
    std::cout << "Outputs are ;" << std::endl;
    for(unsigned int i = 0; i < output.size(); ++i)
        std::cout << output[i] << ", ";
    std::cout << std::endl;

    ASSERT_EQ(expected_output.size(), output.size());
    for(unsigned int i = 0; i < output.size(); ++i)
        ASSERT_EQ(expected_output[i], output[i]);
}

TEST_F(TestQuestions, test_question_18)
{
    std::vector<int> input = {1, 0, -1, 0, -2, 2};
    int target = 0;

    // We need to find all combinations of unique 4-tuples that 
    // add up to target. There must not be any duplicate tuples.



}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


