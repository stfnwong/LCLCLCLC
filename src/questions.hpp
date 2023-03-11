/*
 * QUESTIONS
 * Solutions to specific Leetcode questions
 *
 * Stefan Wong 2019
 */

#ifndef __LC_QUESTIONS_HPP
#define __LC_QUESTIONS_HPP

#include <algorithm>
#include <stack>
#include <string>
#include <vector>
#include <unordered_map>
#include "list.hpp"
#include "tree.hpp"


// ==== QUESTION 1
// https://leetcode.com/problems/two-sum/
std::vector<int> two_sum_map(std::vector<int>& nums, int target);
std::vector<int> two_sum_pointer(std::vector<int>& nums, int target);
std::vector<int> two_sum_sort_and_pointer(std::vector<int>& nums, int target);
std::vector<int> two_sum_brute_force(std::vector<int>& nums, int target);

// ==== QUESTION 2
// https://leetcode.com/problems/add-two-numbers/
ListNode* add_two_numbers(ListNode* l1, ListNode* l2);

// ==== QUESTION 3
// https://leetcode.com/problems/longest-substring-without-repeating-characters/
int length_of_longest_substring(std::string& s);

// ==== QUESTION 14
std::string longest_common_prefix(std::vector<std::string>& strs);
std::string longest_common_prefix_binary_search(std::vector<std::string>& strs);
//std::string longest_common_prefix_vert(std::vector<std::string>& strs);
//std::string longest_common_prefix_div(std::vector<std::string>& strs);


// ==== QUESTION 17
// https://leetcode.com/problems/letter-combinations-of-a-phone-number/
std::vector<std::string> letter_combinations_17(std::string digits);

// ==== QUESTION 18
// https://leetcode.com/problems/4sum/
std::vector<std::vector<int>> four_sum(std::vector<int>& nums, int target);


/*
 * Question 21
 * Merge two sorted lists
 * https://leetcode.com/problems/merge-two-sorted-lists
 */
ListNode* merge_two_sorted_lists_21(ListNode* list1, ListNode* list2);


/*
 * Question 23
 * Merge k sorted lists 
 * https://leetcode.com/problems/merge-k-sorted-lists
 */
ListNode* merge_k_sorted_lists_23(const std::vector<ListNode*>& lists);


/*
 * Question 41
 * First Missing Positive Integer 
 * https://leetcode.com/problems/first-missing-positive/
 */
int first_missing_positive_integer_41(const std::vector<int>& nums);
 
/*
 * Question 42
 * Trapping rainwater
 * https://leetcode.com/problems/trapping-rain-water/
 */
// TODO: there are several ways to approach this, implement several of them here
int trapping_rain_water_42(const std::vector<int>& height);
int trapping_rain_water_42_two_pointers(const std::vector<int>& height);

/*
 * Question 49
 * Group Anagrams 
 * https://leetcode.com/problems/group-anagrams
 */
std::vector<std::vector<std::string>> group_anagrams_49(const std::vector<std::string>& strs);

/*
 * Question 53
 * Maxium Subarray
 * https://leetcode.com/problems/maximum-subarray
 */
int max_subarray_53(const std::vector<int>& nums);

// ==== QUESTION 55
// https://leetcode.com/problems/jump-game/
bool can_jump(std::vector<int>& nums);


/*
 * Question 66
 * Plus One
 * https://leetcode.com/problems/plus-one
 */
std::vector<int> plus_one_66(std::vector<int>& digits);

/*
 * Question 98
 * Valid Binary Search Tree
 * https://leetcode.com/problems/valid-binary-search-tree/
 */
bool is_valid_bst_98(TreeNode* root);

/*
 * Question 100
 * Same Tree
 * https://leetcode.com/problems/same-tree/
 */
bool same_tree_100(TreeNode* p, TreeNode* q);

/*
 * Question 102
 * Binary Tree Level Order Traversal
 * https://leetcode.com/problems/binary-tree-level-order-traversal/
 */
std::vector<std::vector<int>> level_order_traversal_102(const TreeNode* root);

/*
 * Question 111 
https://leetcode.com/problems/minimum-depth-of-binary-tree/
Minimum depth of binary tree
*/
int min_depth_of_binary_tree_111(const TreeNode* root);
int min_depth_of_binary_tree_111_rec(const TreeNode* root);


 /*
  * Question 114
  * https://leetcode.com/problems/path-sum-ii/description/
  */
std::vector<std::vector<int>> path_sum_ii_113(const TreeNode* root, int target_sum);
std::vector<std::vector<int>> path_sum_ii_113_bfs_iter(const TreeNode* root, int target_sum);
std::vector<std::vector<int>> path_sum_ii_113_dfs_iter(const TreeNode* root, int target_sum);

// ==== Question 141
// Linked List Cycle 
// https://leetcode.com/problems/linked-list-cycle
bool has_cycle_141(ListNode* head);

// ==== Question 142
// Linked List Cycle II
// https://leetcode.com/problems/linked-list-cycle-ii
ListNode* detect_cycle_142(ListNode* head);

// ==== Question 153
// Find minimum in rotated sorted array
// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array
int find_min_in_rotated_sorted_array(const std::vector<int>& nums);

// ==== Question 155
// Min stack
// https://leetcode.com/problems/min-stack
class MinStack
{
    std::stack<int> data;
    std::stack<int> mins;

    public:
        MinStack() {}

        void push(int val) {
            this->data.push(val);
            if(this->mins.empty())
                this->mins.push(val);
            else
                this->mins.push(std::min(this->mins.top(), val));
        }

        void pop(void) {
            this->data.pop();
            this->mins.pop();
        }

        int top(void) {
            return this->data.top();
        }

        int get_min(void) {
            return this->mins.top();
        }
};

// ==== Question 198
// https://leetcode.com/problems/house-robber/
int house_robber_198(const std::vector<int>& nums);


/*
 Question 222
 https://leetcode.com/problems/count-complete-tree-nodes
 Count Complete Tree Nodes
*/
int count_nodes_222(TreeNode* root);

// Question 322
// https://leetcode.com/problems/coin-change/
int coin_change_vec_322(std::vector<int>& coins, int amount);


/*
 Question 337
 https://leetcode.com/problems/house-robber-iii
 House Robber III
*/
int house_robber_iii_337(TreeNode* root);

/*
 Question 389
 https://leetcode.com/problems/find-the-difference
 Find The Difference
*/
char find_the_difference_389(const std::string& s1, const std::string& s2);
char find_the_difference_389_um(const std::string& s1, const std::string& s2);


/*
 * Question 542
 * 01 Matrix
 * https://leetcode.com/problems/01-matrix/
 */
std::vector<std::vector<int>> matrix_542(const std::vector<std::vector<int>>& matrix);

/*
 * Question 779
 * Kth symbol in grammar
 * https://leetcode.com/problems/k-th-symbol-in-grammar
 */
int kth_symbol_in_grammar_779(int n, int k);

/*
 Question 802
 Find Eventual Safe States
 https://leetcode.com/problems/find-eventual-safe-states
*/
std::vector<int> find_eventual_safe_states_802(const std::vector<std::vector<int>>& graph);

// ==== QUESTION 842
// https://leetcode.com/problems/split-array-into-fibonacci-sequence/
std::vector<int> split_into_fib_seq_842(int i);


/*
 Question 929
 Unique Email Addresss
 https://leetcode.com/problems/unique-email-addresses
*/
int num_unique_emails_929(const std::vector<std::string>& emails);


// Question 931
// Minimum Falling Path Sum
// https://leetcode.com/problems/minimum-falling-path-sum/_931
int minimum_falling_path_sum_931(const std::vector<std::vector<int>>& grid);
int minimum_falling_path_sum_931_two_rows(const std::vector<std::vector<int>>& grid);

/*
 Question 994
 Rotting Oranges
 https://leetcode.com/problems/rotting-oranges/
*/
int oranges_rotting_994(const std::vector<std::vector<int>>& grid);
int oranges_rotting_994_2_eb(const std::vector<std::vector<int>>& grid);
int oranges_rotting_994_3_eb(const std::vector<std::vector<int>>& grid);


/*
 Question 1046
 Last Stone Weight
 https://leetcode.com/problems/last-stone-weight/
*/
int last_stone_weight_1046(std::vector<int>& stones);

/*
Question 1049
Last Stone Weight II
https://leetcode.com/problems/last-stone-weight-ii/
*/
int last_stone_weight_ii_1049(std::vector<int>& stones);


/*
 * Question 1091 
 * Shortest Path in Binary Matrix 
 * https://leetcode.com/problems/shortest-path-in-binary-matrix/
 */
int shortest_path_in_binary_matrix_1091(const std::vector<std::vector<int>>& grid);

// ==== QUESTION 1143
// https://leetcode.com/problems/longest-common-subsequence/
int longest_common_subsequence_1143(const std::string& text1, const std::string& text2);


/*
 * Question 1162 
 * As far from land as possible 
 * https://leetcode.com/problems/as-far-from-land-as-possible/
 */
int as_far_from_land_as_possible_1162(const std::vector<std::vector<int>>& grid);

// ==== QUESTION 1222
// https://leetcode.com/problems/queens-that-can-attack-the-king/
std::vector<std::vector<int>> queensAttackTheKing(std::vector<std::vector<int>>& queens, std::vector<int>& king);




/*
 Question 1293
 Shortest Path in Grid with Obstacles Elimination
 https://leetcode.com/problems/shortest-path-grid-with-obstacles-elimination
*/
int shortest_path_1293(const std::vector<std::vector<int>>& grid, int k);

// Question 1971
// https://leetcode.com/problems/find-if-path-exists-in-graph/submissions/
//bool find_if_path_exists_in_graph_1971(int n, const std::vector<std::vector<int>>& edges, int source, int dest);


struct Solution_1971
{
    std::vector<int> adj;
    std::vector<bool> vis;
    int source, dest;

    public:
        Solution_1971(int n, int source, int dest);
        bool dfs(int node_key);
        bool valid_path(int n, const std::vector<std::vector<int>>& edges, int source, int dest);
        //bool valid_path_iter(int n, const std::vector<std::vector<int>>& edges, int source, int dest);
};

/*
 * Question 1642 
 * Furthest Building You Can Reach
 * https://leetcode.com/problems/furthest-building-you-can-reach/
 */
int furthest_building_you_can_reach_1642(const std::vector<int>& heights, int bricks, int ladders);

#endif /*__LC_QUESTIONS_HPP*/
