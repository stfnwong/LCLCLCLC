/* TEST_QUESTIONS
 * Run the test cases for the questions
 *
 * Stefan Wong 2019
 */

#include <vector>
#include <string>
#include <gtest/gtest.h>
#include "list.hpp"
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

    two_sum_out = two_sum_map(inputs, target);

    std::cout << "{";
    for(unsigned int i = 0; i < two_sum_out.size(); ++i)
        std::cout << two_sum_out[i] << ", ";
    std::cout << "}" << std::endl;

    ASSERT_EQ(expected_output.size(), two_sum_out.size());
    for(unsigned int i = 0; i < two_sum_out.size(); ++i)
        ASSERT_EQ(expected_output[i], two_sum_out[i]);

    // Also try another implementation (two pointers)
    std::vector<int> two_sum_pointer_out = two_sum_pointer(inputs, target);
    std::cout << "{";
    for(unsigned int i = 0; i < two_sum_pointer_out.size(); ++i)
        std::cout << two_sum_pointer_out[i] << ", ";
    std::cout << "}" << std::endl;

    ASSERT_EQ(expected_output.size(), two_sum_pointer_out.size());
    for(unsigned int i = 0; i < two_sum_pointer_out.size(); ++i)
        ASSERT_EQ(expected_output[i], two_sum_pointer_out[i]);
}


/*
 * Question 2
 */
TEST_F(TestQuestions, test_question_2)  // two-sum
{
    std::vector<int> vec1 = {2, 4, 3};
    std::vector<int> vec2 = {5, 6, 4};
    lc_list::ListNode* input1 = lc_list::list_from_vector(vec1);
    lc_list::ListNode* input2 = lc_list::list_from_vector(vec2);

    std::cout << "[" << __func__ << "] created input lists" << std::endl;

    int idx = 0;

    std::cout << "input 1 " << std::endl;
    lc_list::print_list_node(input1);
    std::cout << "input 2 " << std::endl;
    lc_list::print_list_node(input2);

    lc_list::ListNode* output = add_two_numbers(input1, input2);
    ASSERT_NE(nullptr, output);

    std::vector<int> expected_out_vec = {7, 0, 8};
    lc_list::ListNode* expected_output = lc_list::list_from_vector(expected_out_vec);

    int out_len = 0;
    int exp_len = 3;
    
    while(output != nullptr || expected_output != nullptr)
    {
        ASSERT_EQ(expected_output, output);
        //ASSERT_NE(nullptr, output);
        //ASSERT_NE(nullptr, expected_output);
        output = output->next;
        expected_output = expected_output->next;
        out_len++;
    }

    ASSERT_EQ(exp_len, out_len);

    //delete output;
    //delete expected_output;
}

/*
 * Question 3
 */
TEST_F(TestQuestions, test_question_3)  // longest substring
{
    std::string input_1 = "abcabcbb";
    std::string input_2 = "bbbbb";
    std::string input_3 = "pwwkew";
    int exp1 = 3;
    int exp2 = 1;
    int exp3 = 3;

    int out1, out2, out3;

    out1 = length_of_longest_substring(input_1);
    out2 = length_of_longest_substring(input_2);
    out3 = length_of_longest_substring(input_3);

    ASSERT_EQ(exp1, out1); 
    ASSERT_EQ(exp2, out2); 
    ASSERT_EQ(exp3, out3); 
}


/*
 * Question 14
 */
TEST_F(TestQuestions, test_question_14)
{
    std::vector<std::string> inputs_1 = {"flower", "flow", "flight"};
    std::string expected_output_1 = "fl";

    std::vector<std::string> inputs_2 = {"dog", "racecar", "car"};
    std::string expected_output_2 = "";

    // Output prefixes
    std::string p1, p2;
    p1 = longest_common_prefix(inputs_1);
    std::cout << "Input {";
    for(unsigned int s = 0; s < inputs_1.size(); ++s)
    {
        std::cout << inputs_1[s] << ",";
    }
    std::cout << "} expected [" << expected_output_1 << "], got [" 
        << p1 << "]" << std::endl;

    ASSERT_EQ(expected_output_1, p1);

    p2 = longest_common_prefix(inputs_2);
    std::cout << "Input {";
    for(unsigned int s = 0; s < inputs_2.size(); ++s)
    {
        std::cout << inputs_2[s] << ",";
    }
    std::cout << "} expected [" << expected_output_2 << "], got [" 
        << p1 << "]" << std::endl;

    ASSERT_EQ(expected_output_2, p2);
}

/*
 * Question 14 again
 */
TEST_F(TestQuestions, test_question_14_binary_search)
{
    std::vector<std::string> inputs_1 = {"flower", "flow", "flight"};
    std::string expected_output_1 = "fl";

    std::vector<std::string> inputs_2 = {"dog", "racecar", "car"};
    std::string expected_output_2 = "";

    // Output prefixes
    std::string p1, p2;
    p1 = longest_common_prefix_binary_search(inputs_1);
    std::cout << "Input {";
    for(unsigned int s = 0; s < inputs_1.size(); ++s)
    {
        std::cout << inputs_1[s] << ",";
    }
    std::cout << "} expected [" << expected_output_1 << "], got [" 
        << p1 << "]" << std::endl;

    ASSERT_EQ(expected_output_1, p1);

    p2 = longest_common_prefix_binary_search(inputs_2);
    std::cout << "Input {";
    for(unsigned int s = 0; s < inputs_2.size(); ++s)
    {
        std::cout << inputs_2[s] << ",";
    }
    std::cout << "} expected [" << expected_output_2 << "], got [" 
        << p1 << "]" << std::endl;

    ASSERT_EQ(expected_output_2, p2);
}


/*
 * Question 17
 */
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

/*
 * Question 18
 */
TEST_F(TestQuestions, test_question_18)
{
    std::vector<int> input = {1, 0, -1, 0, -2, 2};
    int target = 0;

    // We need to find all combinations of unique 4-tuples that 
    // add up to target. There must not be any duplicate tuples.



}

/*
 * Question 55
 */
TEST_F(TestQuestions, test_question_55)
{
    std::vector<int> inp1 = {2, 3, 1, 1, 4};
    std::vector<int> inp2 = {3, 2, 1, 0, 4};
    std::vector<int> inp3 = {1, 5, 2, 1, 0, 2, 0};
    std::vector<int> inp4 = {2, 0};

    bool out1, out2, out3, out4;
    bool exp1 = true;
    bool exp2 = false;
    bool exp3 = true;
    bool exp4 = true;

    out1 = can_jump(inp1);
    ASSERT_EQ(exp1, out1);

    out2 = can_jump(inp2);
    ASSERT_EQ(exp2, out2);

    out3 = can_jump(inp3);
    ASSERT_EQ(exp3, out3);

    out4 = can_jump(inp4);
    ASSERT_EQ(exp4, out4);
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


