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
#include "questions.hpp"
#include "util.hpp"


/*
 * Question 1
 * https://leetcode.com/problems/two-sum/
 *
 * Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.
 */
TEST_CASE("question_1", "leetcode")
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
//    ListNode* input1 = list_from_vector(vec1);
//    ListNode* input2 = list_from_vector(vec2);
//
//    std::cout << "[" << __func__ << "] created input lists" << std::endl;
//
//    int idx = 0;
//
//    std::cout << "input 1 " << std::endl;
//    print_list_node(input1);
//    std::cout << "input 2 " << std::endl;
//    print_list_node(input2);
//
//    ListNode* output = add_two_numbers(input1, input2);
//    REQUIRE(nullptr != output);
//
//    std::vector<int> expected_out_vec = {7, 0, 8};
//    ListNode* expected_output = list_from_vector(expected_out_vec);
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
//TEST_CASE("question_18", "leetcode")
//{
//    std::vector<int> input = {1, 0, -1, 0, -2, 2};
//    int target = 0;
//
//    // We need to find all combinations of unique 4-tuples that 
//    // add up to target. There must not be any duplicate tuples.
//}
//



/*
 * Question 21
 * Merge two sorted lists
 * https://leetcode.com/problems/merge-two-sorted-lists
 */
TEST_CASE("question_21", "leetcode")
{
    using list_pair = std::pair<std::vector<int>, std::vector<int>>;
    std::vector<list_pair> inputs = {
        {{1, 2, 4}, {1, 3, 4}},
        {{}, {}},
        {{}, {0}}
    };

    std::vector<std::vector<int>> exp_outputs = {
        {1, 1, 2, 3, 4, 4},
        {},
        {0}
    };
    
    for(unsigned t = 0; t < inputs.size(); ++t)
    {
        // Format the inputs
        ListNode* list1 = list_from_vector(inputs[t].first);
        ListNode* list2 = list_from_vector(inputs[t].second);

        ListNode* out = merge_two_sorted_lists_21(list1, list2);

        // convert output to vector and check
        std::vector<int> out_vec = vector_from_list(out);
        REQUIRE(out_vec.size() == exp_outputs[t].size());

        for(unsigned i = 0; i < out_vec.size(); ++i)
            REQUIRE(out_vec[i] == exp_outputs[t][i]);
    }
}

/*
 * Question 23
 * Merge k sorted lists 
 * https://leetcode.com/problems/merge-k-sorted-lists
 */
TEST_CASE("question_23", "leetcode")
{
    using list_of_lists = std::vector<std::vector<int>>;
    std::vector<list_of_lists> inputs = {
        {{4, 5, 6}, {7, 8, 1}, {2, 2, 2}},
        {{1, 4, 5}, {1, 3, 4}, {2, 6}},
        {},
        {{}},
        {{1, 1, 1}, {90, 9, 99}, {2,2,4}}
    };

    std::vector<std::vector<int>> exp_outputs = {
        {1, 2, 2, 2, 4, 5, 6, 7, 8},
        {1, 1, 2, 3, 4, 4, 5, 6},
        {},
        {},
        {1, 1, 1, 2, 2, 4, 9, 90, 99}
    };

    for(unsigned t = 0; t < inputs.size(); ++t)
    {
        // make a vector of lists 
        std::vector<ListNode*> list_vec;
        for(unsigned v = 0; v < inputs[t].size(); ++v)
        {
            ListNode* some_list = list_from_vector(inputs[t][v]);
            list_vec.push_back(some_list);
        }

        ListNode* out_node = merge_k_sorted_lists_23(list_vec);

        // convert the output to vector and check 
        std::vector<int> out_vec = vector_from_list(out_node);
        REQUIRE(out_vec.size() == exp_outputs[t].size());

        for(unsigned i = 0; i < out_vec.size(); ++i)
            REQUIRE(out_vec[i] == exp_outputs[t][i]);
    }
}


/*
 * Question 42
 * Trapping rainwater
 * https://leetcode.com/problems/trapping-rain-water/
 */

TEST_CASE("question_42", "leetcode")
{
    std::vector<std::vector<int>> inputs = {
        {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1},
        {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 0},
        {4, 2, 0, 3, 2, 5},
        {2, 6, 3, 4, 7, 3, 1, 5, 4},
        {0, 6, 5, 4, 3, 2, 1, 0, 6, 0},
        {0, 1, 2, 3, 4, 3, 2, 1, 0},
        {1, 0, 1},
        {3, 1, 0, 0, 1, 0}
    };
    std::vector<int> exp_outputs = {6, 6, 9, 11, 21, 0, 1, 2};

    for(unsigned t = 0; t < exp_outputs.size(); ++t)
    {
        int out = trapping_rain_water_42(inputs[t]);
        REQUIRE(out == exp_outputs[t]);
    }

    // Try it with the other solution
    for(unsigned t = 0; t < exp_outputs.size(); ++t)
    {
        int out = trapping_rain_water_42_two_pointers(inputs[t]);
        REQUIRE(out == exp_outputs[t]);
    }
}

/*
 * Question 49
 * Group Anagrams 
 * https://leetcode.com/problems/group-anagrams
 */
TEST_CASE("question_49", "leetcode")
{
    std::vector<std::vector<std::string>> inputs = {
        {"eat", "tea", "tan", "ate", "nat", "bat"},
        {""},
        {"a"},
    };

    std::vector<std::vector<std::vector<std::string>>> exp_outputs = {
        {{"bat"}, {"nat", "tan"}, {"ate", "eat", "tea"}},
        {{""}},
        {{"a"}},
    };

    REQUIRE(inputs.size() == exp_outputs.size());

    // Try to compare with 2 unordered_map

    for(unsigned t = 0; t < exp_outputs.size(); ++t)
    {
        std::unordered_map<std::string, std::vector<std::string>> out_map;
        std::unordered_map<std::string, std::vector<std::string>> exp_map;

        std::vector<std::vector<std::string>> out = group_anagrams_49(inputs[t]);
        // check the number of groups is equal 
        REQUIRE(out.size() == exp_outputs[t].size());  

        // Create a map that we can iterate over
        for(std::vector<std::string>& group : out)
        {
            std::string group_key = group[0];
            std::sort(group_key.begin(), group_key.end());
            std::vector<std::string> sorted_group = group;
            std::sort(sorted_group.begin(), sorted_group.end());
            for(std::string s : sorted_group)
                out_map[group_key].push_back(s);
        }

        for(std::vector<std::string>& group : exp_outputs[t])
        {
            //std::string group_key = std::sort(group[0].begin(), group[0].end());
            std::string group_key = group[0];
            std::sort(group_key.begin(), group_key.end());
            std::vector<std::string> sorted_group = group;
            std::sort(sorted_group.begin(), sorted_group.end());
            for(std::string s : sorted_group)
                exp_map[group_key].push_back(s);
        }

        for(std::pair<std::string, std::vector<std::string>> group : out_map)
        {
            REQUIRE(group.second.size() == exp_map[group.first].size());
            for(unsigned s = 0; s < group.second.size(); ++s)
                REQUIRE(group.second[s] == exp_map[group.first][s]);
        }


        // TEST
        //std::cout << "out[" << t << "]" << std::endl;
        //for(std::pair<std::string, std::vector<std::string>> out_group: out_map)
        //{
        //    std::cout << out_group.first << ": [";
        //    for(unsigned i = 0; i < out_group.second.size(); ++i)
        //        std::cout << out_group.second[i] << ",";
        //    std::cout << "]" << std::endl;
        //}

        //std::cout << "exp_out[" << t << "]" << std::endl;
        //for(std::pair<std::string, std::vector<std::string>> out_group: exp_map)
        //{
        //    std::cout << out_group.first << ": [";
        //    for(unsigned i = 0; i < out_group.second.size(); ++i)
        //        std::cout << out_group.second[i] << ",";
        //    std::cout << "]" << std::endl;
        //}
    }
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
 * Question 66
 * Plus One
 * https://leetcode.com/problems/plus-one
 */
TEST_CASE("question_66", "leetcode")
{
    std::vector<std::vector<int>> inputs = {
        {1, 2, 3},
        {4, 3, 2, 1}
    };
    std::vector<std::vector<int>> exp_outputs = {
        {1, 2, 4},
        {4, 3, 2, 2}
    };

    unsigned num_tests = exp_outputs.size();
    for(unsigned t = 0; t < num_tests; ++t)
    {
        std::vector<int> out = plus_one_66(inputs[t]);
        REQUIRE(out.size() == exp_outputs[t].size());
        for(unsigned e = 0; e < out.size(); ++e)
            REQUIRE(out[e] == exp_outputs[t][e]);
    }
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
 * Question 113 
 * https://leetcode.com/problems/path-sum-ii/description/
*/
TEST_CASE("question_113", "leetcode")
{
    std::vector<std::string> repr_inputs = {
        "[5,4,8,11,null,13,4,7,2,null,null,5,1]",
        "[1, 2, 3]",
        "[1, 2]",
    };
    std::vector<int> target_sum_inputs = {22, 5, 0};
    std::vector<std::vector<std::vector<int>>> exp_outputs = {
        {{5, 4, 11, 2}, {5, 8, 4, 5}},
        {},
        {}
    };

    unsigned num_test_cases = repr_inputs.size();
    std::vector<std::vector<int>> results;
    for(unsigned t = 0; t < num_test_cases; ++t)
    {
        TreeNode* root = repr_to_tree(repr_inputs[t]);
        results = path_sum_ii_113(root, target_sum_inputs[t]);
        REQUIRE(results.size() == exp_outputs[t].size());
        for(unsigned r = 0; r < results.size(); ++r)
            REQUIRE(results[r] == exp_outputs[t][r]);
    }
}

// The iterative BFS version 
TEST_CASE("question_113_bfs_iter", "leetcode")
{
    std::vector<std::string> repr_inputs = {
        "[5,4,8,11,null,13,4,7,2,null,null,5,1]",
        "[1, 2, 3]",
        "[1, 2]",
    };
    std::vector<int> target_sum_inputs = {22, 5, 0};

    //std::vector<std::vector<int>> exp_outputs;
    //exp_outputs.push_back({{5, 4, 11,2}, {5, 8, 4, 5}});
    //exp_outputs.push_back({});
    //exp_outputs.push_back({});

    std::vector<std::vector<std::vector<int>>> exp_outputs = {
        {{5, 4, 11, 2}, {5, 8, 4, 5}},
        {},
        {}
    };

    unsigned num_test_cases = repr_inputs.size();
    std::vector<std::vector<int>> results;
    for(unsigned t = 0; t < num_test_cases; ++t)
    {
        TreeNode* root = repr_to_tree(repr_inputs[t]);
        results = path_sum_ii_113_bfs_iter(root, target_sum_inputs[t]);
        REQUIRE(results.size() == exp_outputs[t].size());
    }
}


// ==== Question 153
// Find minimum in rotated sorted array
// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array
TEST_CASE("question_153", "leetcode")
{
    std::vector<std::vector<int>> inputs = {
        {3, 4, 5, 1, 2},
        {4, 5, 6, 7, 0, 1, 2},
        {11 ,13, 15, 17},       // non-rotated array
    };
    std::vector<int> exp_outputs = {1, 0, 11};

    for(unsigned t = 0; t < exp_outputs.size(); ++t)
    {
        int out = find_min_in_rotated_sorted_array(inputs[t]);
        REQUIRE(out == exp_outputs[t]);
    }
}

// ==== Question 155
// Min stack
// https://leetcode.com/problems/min-stack
TEST_CASE("question_155", "leetcode")
{
    // this is how leetcode instantiate the stack 
    MinStack* obj = new MinStack();
    int ret;

    // Example 1
    obj->push(-2);
    obj->push(0);
    obj->push(-3);
    ret = obj->get_min();
    
    REQUIRE(ret == -3);
    obj->pop();
    ret = obj->top();
    REQUIRE(ret == 0);

    ret = obj->get_min();
    REQUIRE(ret == -2);

    delete obj;
}



/*
 ==== Question 198
 https://leetcode.com/problems/house-robber/
*/
TEST_CASE("question_198", "leetcode")
{
    std::vector<std::vector<int>> inputs = {
        {1, 2, 3, 1},
        {2, 7, 9, 3, 1},
    };
    std::vector<int> exp_outputs = {4, 12};

    for(unsigned test_case = 0; test_case < inputs.size(); ++test_case)
    {
        int out = house_robber_198(inputs[test_case]);
        REQUIRE(out == exp_outputs[test_case]);
    }
}

/*
 Question 222
 https://leetcode.com/problems/count-complete-tree-nodes
 Count Complete Tree Nodes
*/
TEST_CASE("question_222", "leetcode")
{
    std::vector<std::string> inputs = {
        "[1, 2, 3, 4, 5, 6]",
        "[]",
        "[1]",
        "[1, 2, 3]",
        "[1, 2]",
    };

    std::vector<int> exp_outputs = {6, 0, 1, 3, 2};

    for(unsigned t = 0; t < exp_outputs.size(); ++t)
    {
        TreeNode* cur_tree = repr_to_tree(inputs[t]);
        int out = count_nodes_222(cur_tree);
        REQUIRE(out == exp_outputs[t]);
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


/*
 Question 337
 https://leetcode.com/problems/house-robber-iii
 House Robber III
*/
TEST_CASE("question_337", "leetcode")
{
    std::vector<std::string> inputs = {
        "[3, 2, 3, null, 3, null, 1]",
        "[3, 4, 5, 1, 3, null, 1]"
    };

    std::vector<int> exp_outputs = {7, 9};

    for(unsigned t = 0; t < exp_outputs.size(); ++t)
    {
        TreeNode* inp_root = repr_to_tree(inputs[t]);
        int out = house_robber_iii_337(inp_root);
        REQUIRE(out == exp_outputs[t]);
    }
}


/*
 Question 389
 https://leetcode.com/problems/find-the-difference
 Find The Difference
*/
TEST_CASE("question_389", "leetcode")
{
    using input_t = std::pair<std::string, std::string>;
    std::vector<input_t> inputs = {
        {"abcd", "abcde"},
        {"", "y"},
        {"", ""}
    };
    std::vector<char> exp_outputs = {'e', 'y', '\0'};

    for(unsigned t = 0; t < exp_outputs.size(); ++t)
    {
        char out = find_the_difference_389(inputs[t].first, inputs[t].second);
        REQUIRE(out == exp_outputs[t]);
        out = find_the_difference_389_um(inputs[t].first, inputs[t].second);
        REQUIRE(out == exp_outputs[t]);
    }
}


/*
 Question 929
 Unique Email Addresss
 https://leetcode.com/problems/unique-email-addresses
*/
TEST_CASE("question_929", "leetcode")
{
    std::vector<std::vector<std::string>> inputs = {
        {"test.email+alex@leetcode.com", "test.e.mail+bob.cathy@leetcode.com", "testemail@lee.tcode.com"},
        {"a@leetcode.com", "b@leetcode.com", "c@leetcode.com"}
    };

    std::vector<int> exp_outputs = {2, 3};

    for(unsigned t = 0; t < exp_outputs.size(); ++t)
    {
        int out = num_unique_emails_929(inputs[t]);
        REQUIRE(out == exp_outputs[t]);
    }
}

/*
 Question 994
 Rotting Oranges
 https://leetcode.com/problems/rotting-oranges/
*/
TEST_CASE("question_994", "leetcode")
{
    std::vector<std::vector<std::vector<int>>> inputs = {
        {{2, 1, 1}, {1, 1, 0}, {0, 1, 1}},
        {{2, 1, 1}, {0, 1, 1}, {1, 0, 1}},
        {{0, 2}}
    };
    std::vector<int> exp_outputs = {4, -1, 0};

    for(unsigned t = 0; t < exp_outputs.size(); ++t)
    {
        int out = oranges_rotting_994(inputs[t]);
        REQUIRE(out == exp_outputs[t]);
    }
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
//TEST_CASE("question_1049", "leetcode")
//{
//    std::vector<std::vector<int>> inputs = {
//        {2, 7, 4, 1, 8, 1},
//        {31, 26, 33, 21 ,40},
//    };
//    std::vector<int> exp_outputs = {1, 5};
//
//    for(unsigned test_case = 0; test_case < exp_outputs.size(); ++test_case)
//    {
//        int out = last_stone_weight_ii_1049(inputs[test_case]);
//        REQUIRE(out == exp_outputs[test_case]);
//    }
//}
//


/*
 * Question 1091 
 * Shortest Path in Binary Matrix 
 * https://leetcode.com/problems/shortest-path-in-binary-matrix/
 */
TEST_CASE("question_1091", "leetcode")
{
    using grid_t = std::vector<std::vector<int>>;
    std::vector<grid_t> inputs = {
        {{0, 1}, {1, 0}},
        {{0, 0, 0}, {1, 1, 0}, {1, 1, 0}},
        {{1, 0, 0}, {1, 1, 0}, {1, 1, 0}}

    };

    std::vector<int> exp_outputs = {2, 4, -1};

    for(unsigned t = 0; t < exp_outputs.size(); ++t)
    {
        int out = shortest_path_in_binary_matrix_1091(inputs[t]);
        REQUIRE(out == exp_outputs[t]);
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




/*
 Question 1293
 Shortest Path in Grid with Obstacles Elimination
 https://leetcode.com/problems/shortest-path-in-a-grid-with-obstacles-elimination
*/
TEST_CASE("question_1293", "leetcode")
{
    using grid_t = std::vector<std::vector<int>>;

    std::vector<grid_t> grids = {
        {{0,0,0}, {1,1,0}, {0,0,0}, {0,1,1}, {0,0,0}},
        {{0,1,1}, {1,1,1}, {1,0,0}}
    };

    std::vector<int> ks = {1, 1};

    std::vector<int> exp_outputs = {6, -1};

    for(unsigned t = 0; t < exp_outputs.size(); ++t)
    {
        // first arg is grid, second arg is k
        //int out = shortest_path_1293(inputs[t].first, inputs[t].second);
        int out = shortest_path_1293(grids[t], ks[t]);
        REQUIRE(out == exp_outputs[t]);
    }
}
