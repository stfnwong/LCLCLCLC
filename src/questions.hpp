/*
 * QUESTIONS
 * Solutions to specific Leetcode questions
 *
 * Stefan Wong 2019
 */

#ifndef __LC_QUESTIONS_HPP
#define __LC_QUESTIONS_HPP

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
lc_list::ListNode* add_two_numbers(lc_list::ListNode* l1, lc_list::ListNode* l2);

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

// ==== QUESTION 55
// https://leetcode.com/problems/jump-game/
bool can_jump(std::vector<int>& nums);

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


 /*
  * Question 114
  * https://leetcode.com/problems/path-sum-ii/description/
  */
std::vector<std::vector<int>> path_sum_ii_113(const TreeNode* root, int target_sum);
std::vector<std::vector<int>> path_sum_ii_113_bfs_iter(const TreeNode* root, int target_sum);

// ==== Question 198
// https://leetcode.com/problems/house-robber/
int house_robber_198(const std::vector<int>& nums);



// Question 322
// https://leetcode.com/problems/coin-change/
int coin_change_vec_322(std::vector<int>& coins, int amount);


// ==== QUESTION 842
// https://leetcode.com/problems/split-array-into-fibonacci-sequence/
std::vector<int> split_into_fib_seq_842(int i);


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


// ==== QUESTION 1143
// https://leetcode.com/problems/longest-common-subsequence/
int longest_common_subsequence_1143(const std::string& text1, const std::string& text2);


// ==== QUESTION 1222
// https://leetcode.com/problems/queens-that-can-attack-the-king/
std::vector<std::vector<int>> queensAttackTheKing(std::vector<std::vector<int>>& queens, std::vector<int>& king);

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


#endif /*__LC_QUESTIONS_HPP*/
