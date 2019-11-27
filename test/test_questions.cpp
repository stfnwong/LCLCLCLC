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


TEST_F(TestQuestions, test_question_17)
{
    std::string input = "23";
    std::vector<std::string> expected_output = {"ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"};


    output = letter_combinations_17(input);


}


int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


