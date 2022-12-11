/* TEST_QUESTIONS
 * Run the test cases for the questions
 *
 * Stefan Wong 2019
 */

#define CATCH_CONFIG_MAIN
#include "catch/catch.hpp"

#include <functional>
#include <string>
#include <vector>
#include <utility>

#include "list.hpp"
#include "tree.hpp"
#include "util.hpp"
#include "questions.hpp"


/*
 * Question 1
 * https://leetcode.com/problems/two-sum/
 *
 * Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.
 */
// TODO: we should be able to simplify this by placing function pointers into a vector 
// and passing the same args to each function in a loop (probably while printing the function name)?
TEST_CASE("q1_two_sum", "leetcode")
{
    using two_sum_function = std::function<std::vector<int>(std::vector<int>&, int)>;
    std::vector<std::pair<two_sum_function, std::string>> functions = {
        {(*two_sum_map), "two_sum_map()"},
        {(*two_sum_sort_and_pointer), "two_sum_sort_and_pointer()"},
        {(*two_sum_brute_force), "two_sum_brute_force()"},
    };

    std::vector<int> targets = {9, 6, 6};
    std::vector<std::vector<int>> inputs = {
        {2, 7, 11, 15},
        {3, 2, 4},
        {3, 3}
    };

    std::vector<std::vector<int>> expected_outputs = {
        {0, 1},
        {1, 2},
        {0, 1}
    };

    unsigned num_test_cases = targets.size();

    for(auto& func: functions)
    {
        std::cout << "Running function [" << func.second << "]" << std::endl;
        for(unsigned test_case = 0; test_case < num_test_cases; ++test_case)
        {
            std::vector<int> out = func.first(
                    inputs[test_case],
                    targets[test_case]
            );
            REQUIRE(out.size() == expected_outputs[test_case].size());

            std::cout << "Got      : " << vec_to_str(out) << std::endl;
            std::cout << "Expected : " << vec_to_str(expected_outputs[test_case]) << std::endl;

            for(unsigned elem = 0; elem < out.size(); ++elem)
                REQUIRE(out[elem] == expected_outputs[test_case][elem]);
        }
    }
}
/*
 * Question 2
 * TODO: fix this in other branch
 */
//TEST_CASE("question_2", "leetcode")  // two-sum
//{
//    std::vector<int> vec1 = {2, 4, 3};
//    std::vector<int> vec2 = {5, 6, 4};
//    lc_list::ListNode* input1 = lc_list::list_from_vector(vec1);
//    lc_list::ListNode* input2 = lc_list::list_from_vector(vec2);
//
//    std::cout << "[" << __func__ << "] created input lists" << std::endl;
//
//    int idx = 0;
//
//    std::cout << "input 1 " << std::endl;
//    lc_list::print_list_node(input1);
//    std::cout << "input 2 " << std::endl;
//    lc_list::print_list_node(input2);
//
//    lc_list::ListNode* output = add_two_numbers(input1, input2);
//    REQUIRE(nullptr != output);
//
//    std::vector<int> expected_out_vec = {7, 0, 8};
//    lc_list::ListNode* expected_output = lc_list::list_from_vector(expected_out_vec);
//
//    int out_len = 0;
//    int exp_len = 3;
//    
//    while(output != nullptr || expected_output != nullptr)
//    {
//        REQUIRE(expected_output == output);
//        //ASSERT_NE(nullptr, output);
//        //ASSERT_NE(nullptr, expected_output);
//        output = output->next;
//        expected_output = expected_output->next;
//        out_len++;
//    }
//
//    REQUIRE(exp_len == out_len);
//
//    //delete output;
//    //delete expected_output;
//}

/*
 * Question 3
 */
TEST_CASE("question_3", "leetcode")  // longest substring
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

    REQUIRE(exp1 == out1); 
    REQUIRE(exp2 == out2); 
    REQUIRE(exp3 == out3); 
}


/*
 * Question 14
   https://leetcode.com/problems/longest-common-prefix/
 */
TEST_CASE("question_14", "leetcode")
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

    REQUIRE(expected_output_1 == p1);

    p2 = longest_common_prefix(inputs_2);
    std::cout << "Input {";
    for(unsigned int s = 0; s < inputs_2.size(); ++s)
    {
        std::cout << inputs_2[s] << ",";
    }
    std::cout << "} expected [" << expected_output_2 << "], got [" 
        << p1 << "]" << std::endl;

    REQUIRE(expected_output_2 == p2);
}

/*
 * Question 14 again
   https://leetcode.com/problems/longest-common-prefix/
 */
TEST_CASE("question_14_binary_search", "leetcode")
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

    REQUIRE(expected_output_1 == p1);

    p2 = longest_common_prefix_binary_search(inputs_2);
    std::cout << "Input {";
    for(unsigned int s = 0; s < inputs_2.size(); ++s)
    {
        std::cout << inputs_2[s] << ",";
    }
    std::cout << "} expected [" << expected_output_2 << "], got [" 
        << p1 << "]" << std::endl;

    REQUIRE(expected_output_2 == p2);
}


/*
 * Question 17
 */
TEST_CASE("question_17", "leetcode")
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

    REQUIRE(expected_output.size() == output.size());
    for(unsigned int i = 0; i < output.size(); ++i)
        REQUIRE(expected_output[i] == output[i]);
}

/*
 * Question 18
 */
TEST_CASE("question_18", "leetcode")
{
    std::vector<int> input = {1, 0, -1, 0, -2, 2};
    int target = 0;

    // We need to find all combinations of unique 4-tuples that 
    // add up to target. There must not be any duplicate tuples.
}

/*
 * Question 55
 */
TEST_CASE("question_55", "leetcode")
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
    REQUIRE(exp1 == out1);

    out2 = can_jump(inp2);
    REQUIRE(exp2 == out2);

    out3 = can_jump(inp3);
    REQUIRE(exp3 == out3);

    out4 = can_jump(inp4);
    REQUIRE(exp4 == out4);
}

/*
 * Question 102
 * Binary Tree Level Order Traversal
 * https://leetcode.com/problems/binary-tree-level-order-traversal/
 */
TEST_CASE("question_102", "leetcode")
{
    std::string inp_repr = "[3,9,20,null,null,15,7]";
    std::vector<std::vector<int>> exp_traversal = {
        {{3}, {9, 20}, {15, 7}}
    };

    TreeNode* root = repr_to_tree(inp_repr);
    std::vector<std::vector<int>> traversal = level_order_traversal_102(root);

    REQUIRE(traversal.size() == exp_traversal.size());
    for(unsigned i = 0; i < traversal.size(); ++i)
        REQUIRE(traversal[i] == exp_traversal[i]);
}

/*
 * Question 111 
https://leetcode.com/problems/minimum-depth-of-binary-tree/
Minimum depth of binary tree
*/
TEST_CASE("question_111", "leetcode")
{
    std::vector<std::string> tree_reprs = {
        "[3,9,20,null,null,15,7]",
        "[2,null,3,null,4,null,5,null,6]"
    };
    std::vector<int> exp_min_height = {2, 5};

    for(unsigned i = 0; i < tree_reprs.size(); ++i)
    {
        TreeNode* tree = repr_to_tree(tree_reprs[i]);
        int min_height = min_depth_of_binary_tree_111(tree);
        REQUIRE(min_height == exp_min_height[i]);
    }
}


/*
 * Question 239
 * https://leetcode.com/problems/sliding-window-maximum/
 * Max in sliding window 
 */
TEST_CASE("question_239", "leetcode")
{
    std::vector<std::vector<int>> input_arrays = {
        {1, 3, -1, -3, 5, 3, 6, 7},
        {1}
    };
    std::vector<int> input_wsize = {3, 1};

    std::vector<std::vector<int>> exp_outputs = {
        {3, 3, 5, 5, 6, 7},
        {1}
    };


}

TEST_CASE("question_842", "leetcode")
{
}



/*
 Question 1046
 Last Stone Weight
 https://leetcode.com/problems/last-stone-weight/
*/
TEST_CASE("question_1046", "leetcode")
{
    std::vector<std::vector<int>> inputs = {
        {2, 7, 4, 1, 8, 1},
        {1},
        {3, 7, 2}
    };

    std::vector<int> exp_output = {1, 1, 2};

    for(unsigned test_case = 0; test_case < exp_output.size(); ++test_case)
    {
        int out = last_stone_weight_1046(inputs[test_case]);
        REQUIRE(out == exp_output[test_case]);
    }
}


/*
 Question 1049
 Last Stone Weight II
 https://leetcode.com/problems/last-stone-weight-ii/
*/
TEST_CASE("question_1049", "leetcode")
{
    std::vector<std::vector<int>> inputs = {
        {2, 7, 4, 1, 8, 1},
        {31, 26, 33, 21 ,40},
    };
    std::vector<int> exp_outputs = {1, 5};

    for(unsigned test_case = 0; test_case < exp_outputs.size(); ++test_case)
    {
        int out = last_stone_weight_ii_1049(inputs[test_case]);
        REQUIRE(out == exp_outputs[test_case]);
    }
}



/*
 * Question 1222
 */
TEST_CASE("question_1222", "leetcode")
{
    // inputs 
    std::vector<std::vector<int>> queen_input_1 = {{0,1},{1,0},{4,0},{0,4},{3,3},{2,4}};
    std::vector<int> king_input_1 = {0, 0};
    std::vector<std::vector<int>> queen_input_2 ={{0,0},{1,1},{2,2},{3,4},{3,5},{4,4},{4,5}}; 
    std::vector<int> king_input_2 = {3, 3};
    std::vector<std::vector<int>> queen_input_3 ={{5,6},{7,7},{2,1},{0,7},{1,6},{5,1},{3,7},{0,3},{4,0},{1,2},{6,3},{5,0},{0,4},{2,2},{1,1},{6,4},{5,4},{0,0},{2,6},{4,5},{5,2},{1,4},{7,5},{2,3},{0,5},{4,2},{1,0},{2,7},{0,1},{4,6},{6,1},{0,6},{4,3},{1,7}}; 
    std::vector<int> king_input_3 = {3, 4};

    // expected outputs
    std::vector<std::vector<int>> exp_output_1 = {{0,1},{1,0},{3,3}};
    std::vector<std::vector<int>> exp_output_2 = {{2,2},{3,4},{4,4}};
    std::vector<std::vector<int>> exp_output_3 = {{2,3},{1,4},{1,6},{3,7},{4,3},{5,4},{4,5}};

    // real outputs 
    std::vector<std::vector<int>> output1;
    std::vector<std::vector<int>> output2;
    std::vector<std::vector<int>> output3;

    // ---- test 1
    output1 = queensAttackTheKing(queen_input_1, king_input_1);

    // I think that while its legal in the leetcode submission to use any order
    // the values in the output are 'sorted' in a sense
    std::cout << "Output1 : " << std::endl << "{";
    for(unsigned int o = 0; o < output1.size(); ++o)
    {
        std::cout << "(" << output1[o][0] << "," << output1[o][1] << "),";
    }
    std::cout << "}" << std::endl;
    REQUIRE(exp_output_1.size() == output1.size());

    // Check each element of the output vector in turn
    for(unsigned int elem = 0; elem < output1.size(); ++elem)
    {
        REQUIRE(exp_output_1[elem][0] == output1[elem][0]);
        REQUIRE(exp_output_1[elem][1] == output1[elem][1]);
    }

    // ---- test 2
    output2 = queensAttackTheKing(queen_input_2, king_input_2);

    std::cout << "Output2 : " << std::endl << "{";
    for(unsigned int o = 0; o < output2.size(); ++o)
    {
        std::cout << "(" << output2[o][0] << "," << output2[o][1] << "),";
    }
    std::cout << "}" << std::endl;
    REQUIRE(exp_output_2.size() == output2.size());

    // Check each element of the output vector in turn
    for(unsigned int elem = 0; elem < output2.size(); ++elem)
    {
        REQUIRE(exp_output_2[elem][0] == output2[elem][0]);
        REQUIRE(exp_output_2[elem][1] == output2[elem][1]);
    }

    // ---- test 3
    output3 = queensAttackTheKing(queen_input_3, king_input_3);

    std::cout << "Output3 : " << std::endl << "{";
    for(unsigned int o = 0; o < output3.size(); ++o)
    {
        std::cout << "(" << output3[o][0] << "," << output3[o][1] << "),";
    }
    std::cout << "}" << std::endl;
    REQUIRE(exp_output_3.size() == output3.size());

    // Check each element of the output vector in turn
    for(unsigned int elem = 0; elem < output3.size(); ++elem)
        REQUIRE(exp_output_3[elem][1] == output3[elem][1]);
}
