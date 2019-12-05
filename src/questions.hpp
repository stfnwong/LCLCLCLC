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


// ==== QUESTION 1
// https://leetcode.com/problems/two-sum/
std::vector<int> two_sum_map(std::vector<int>& nums, int target);
std::vector<int> two_sum_pointer(std::vector<int>& nums, int target);

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

// ==== QUESTION 39
// https://leetcode.com/problems/combination-sum/
std::vector<std::vector<int>> combination_sum_i(std::vector<int>& candidates, int target);

// ==== QUESTION 40
// https://leetcode.com/problems/combination-sum-ii/
std::vector<std::vector<int>> combination_sum_ii(std::vector<int>& candidates, int target);

// ==== QUESTION 55
// https://leetcode.com/problems/jump-game/
bool can_jump(std::vector<int>& nums);


// ==== QUESTION 1222
// https://leetcode.com/problems/queens-that-can-attack-the-king/
std::vector<std::vector<int>> queensAttackTheKing(std::vector<std::vector<int>>& queens, std::vector<int>& king);

#endif /*__LC_QUESTIONS_HPP*/
