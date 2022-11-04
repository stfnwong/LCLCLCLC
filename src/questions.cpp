/*
 * QUESTIONS
 * Solutions to specific Leetcode questions
 *
 * Stefan Wong 2019
 */

#include <algorithm>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <queue>

#include "tree.hpp"
#include "questions.hpp"

/*
 * Question 1
 * https://leetcode.com/problems/two-sum/
 *
 * Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.
 */
std::vector<int> two_sum_map(std::vector<int>& nums, int target)
{
    std::vector<int> output(2);
    // why use a map here...
    std::unordered_map<int, int> diff_map;

    for(unsigned int n = 0; n < nums.size(); ++n)
    {
        int diff = target - nums[n];
        if(diff_map.count(diff) > 0)
        {
            //std::cout << "[" << __func__ << "] found key " << diff << std::endl;
            output[0] = diff_map[diff];
            output[1] = n;
            return output;
        }

        // add new differences to map
        diff_map.insert({nums[n], n});
    }

    return output;
}

//
// two sum sorted pointer
std::vector<int> two_sum_sort_and_pointer(std::vector<int>& nums, int target)
{
    unsigned int n = nums.size();
    std::vector<std::pair<int, int>> val_and_idx(n);

    // since we plan to sort the array we need to remember what the original index was 
    // create a vector of pairs that store a value and its position in the original array 
    for(int i = 0; i < n; ++i)
        val_and_idx[i] = std::make_pair(nums[i], i);

    // now we can sort the input 
    std::sort(val_and_idx.begin(), val_and_idx.end());
    int left = 0;
    int right = val_and_idx.size()-1;
    //int right = n-1;

    while(left < right) 
    {
        int s = val_and_idx[left].first + val_and_idx[right].first;
        std::cout << "[" << __func__ << "] left  (" << left << "): " << val_and_idx[left].first << std::endl;
        std::cout << "[" << __func__ << "] right (" << right << "): " << val_and_idx[right].first << std::endl;
        std::cout << "[" << __func__ << "] s: " << std::left << std::setw(4) << s << std::endl;
        if(s == target)
            return std::vector<int>{val_and_idx[left].second, val_and_idx[right].second};
        else if(s > target)
            right--;    //  too large, deccrease 
        else
            left++;     // too small, increase
    }

    // cant find anything
    return std::vector<int>{};

}

// two sum brute force 
std::vector<int> two_sum_brute_force(std::vector<int>& nums, int target)
{
    for(int i = 0; i < nums.size(); ++i)
    {
        for(int j = i+1; j < nums.size(); ++j)
        {
            int s = nums[i] + nums[j];
            if(s == target)
                return std::vector<int>{i, j};
        }
    }

    // in the real question I think we are guaranteed there is an answer 
    return std::vector<int>{};  
}

/*
 * Question 2
 */
lc_list::ListNode* add_two_numbers(lc_list::ListNode* l1, lc_list::ListNode* l2)
{
    int sum;
    int carry;
    lc_list::ListNode* output;
    lc_list::ListNode* root;

    // map pointers to the input lists 
    lc_list::ListNode* p = l1;
    lc_list::ListNode* q = l2;

    carry = 0;
    root = new lc_list::ListNode(0);
    output = root;

    //int q_val;
    //int p_val;

    while(p != nullptr || q != nullptr)
    {
        if(p != nullptr)
        {
            sum = sum + p->val;
            p = p->next;
        }
        if(q != nullptr)
        {
            sum = sum + q->val;
            q = q->next;
        }
        sum = sum + carry;
        carry = sum / 10;
        output->next = new lc_list::ListNode(sum % 10);
        output = output->next;
    }

    if(carry > 0)
        output->next = new lc_list::ListNode(carry);     // 'remainder' (but since list is reversed, its actually overflow)

    return root->next;    // ignore the first node - its just a dummy for init purposes
}


/*
 * Question 3
 */
int length_of_longest_substring(std::string& s)
{
    unsigned int start = 0;
    unsigned int end = 0;
    int max_ever = 0;
    std::unordered_map <char, bool> seen_chars;


    // Create a sliding window and walk along the string. 
    while(end < s.size())
    {
        // add new characters to the map and move the pointer forward
        if(seen_chars.count(s[end]) == 0)
        {
            seen_chars.insert( {s[end], true} );
            end++;
            max_ever = std::max(max_ever, (int) seen_chars.size());
        }
        else
        {
            // this character has been seen before
            seen_chars.erase(s[start]);
            start++;
        }
    }

    return max_ever;
}


/*
 * Question 14
   https://leetcode.com/problems/longest-common-prefix/

   Write a function to find the longest common prefix amongst an array of strings. If
   there is no common prefix, return an empty string.

    Example:
    input: strs = ["flower", "flow", "flight"]
    output = "fl"
 */
std::string longest_common_prefix(std::vector<std::string>& strs)
{
    unsigned int max_prefix;
    std::string prefix;

    prefix = "";
    max_prefix = 9999999;

    // find the maximum length we could possibly need
    for(unsigned int s = 0; s < strs.size(); ++s)
    {
        if(strs[s].size() < max_prefix)
            max_prefix = strs[s].size();
    }

    // 'Vertically' scan over the strings and compare them with strs[0]
    for(unsigned int c = 0; c < max_prefix; ++c)
    {
        // check each string in turn
        for(unsigned int s = 1; s < strs.size(); ++s)
        {
            if(strs[0][c] != strs[s][c])
                return prefix;
        }
        prefix = prefix + strs[0][c];
    }

    return prefix;
}

/*
 * Question 14 again
 */

bool is_common_prefix(std::vector<std::string>& strs, unsigned int max_len)
{
    std::string ref_string = strs[0].substr(0, max_len);

    for(unsigned int c = 0; c < max_len; ++c)
    {
        for(unsigned int s = 1; s < strs.size(); ++s)
        {
            if(strs[s][c] != ref_string[c])
                return false;
        }
    }

    return true;
}




std::string longest_common_prefix_binary_search(std::vector<std::string>& strs)
{
    unsigned int min_len = 99998;
    std::string prefix = "";
    int low, high, mid;

    // if there are no strings, then we are done here
    if(strs.size() == 0)
        return prefix;

    // find the length of the shortest string
    for(unsigned int s = 0; s < strs.size(); ++s)
    {
        if(strs[s].size() < min_len)
            min_len = strs[s].size();
    }

    low = 0;
    high = min_len;
    while(low <= high)
    {
        std::cout << "[" << __func__ << "] low : " << low << " high : " << high << std::endl;
        mid = (high + low) / 2;
        if(is_common_prefix(strs, mid))
            low = mid + 1;      // all the characters below match (ignore)
        else
            high = mid - 1;     // none of the characters above match
    }
    // The prefix lies at the midpoint of low and high
    prefix = strs[0].substr(0, (low + high) / 2);

    return prefix;
}




/*
 * Question 17
 */

// recursive helper function
// TODO: what would the iterative version of this look like?
void find_letter_combo(
        std::string& digits,
        std::vector<std::string>& output,
        std::unordered_map<char, std::string> mapping,
        std::string cur_string,
        unsigned int idx)
{
    if(idx == digits.size())
    {
        output.push_back(cur_string);
        return;
    }

    std::string substr = mapping[digits[idx]];
    for(unsigned int c = 0; c < substr.size(); ++c)
    {
        find_letter_combo(digits, output, mapping, cur_string + substr[c], idx+1);
    }
}

std::vector<std::string> letter_combinations_17(std::string digits)
{
    std::vector<std::string> output;

    if(digits.size() == 0)
        return output;

    std::unordered_map<char, std::string> digit_map = {
        {'0', "0"},
        {'1', "1"},
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"},
    };
    find_letter_combo(digits, output, digit_map, std::string(""), 0);
    
    return output;
}



/*
 * Question 18
 */
//std::vector<std::vector<int>> four_sum(std::vector<int>& nums, int target)
//{
//    
//}

/*
 * Question 55
 */
// Lets implement the dumb way here. 

bool can_jump_here_basic(int cur_pos, std::vector<int>& nums)
{
    if(cur_pos == (int) nums.size()-1)
        return true;

    int max_jump;
    if((cur_pos + nums[cur_pos]) > (int) nums.size()-1)
        max_jump = nums.size()-1;
    else
        max_jump = cur_pos + nums[cur_pos];

    for(int next_pos = cur_pos+1; next_pos <= max_jump; ++next_pos)
    {
        //std::cout << "[" << __func__ << "] jumping from " << 
        //    cur_pos << "->" << next_pos << std::endl;
        if(can_jump_here_basic(next_pos, nums))
            return true;
    }

    return false;
}




bool can_jump(std::vector<int>& nums)
{
    return can_jump_here_basic(0, nums);
}


/*
 * Question 102
 * Binary Tree Level Order Traversal
 * https://leetcode.com/problems/binary-tree-level-order-traversal/
 */
std::vector<std::vector<int>> level_order_traversal_102(const TreeNode* root)
{
    if(not root)
        return std::vector<std::vector<int>>();

    std::queue<TreeNode*> node_q;
    std::vector<std::vector<int>> traversal;

    node_q.push(new TreeNode(*root));
    while(!node_q.empty())
    {
        std::vector<int> level;
    }


    return traversal;
}




/*
Question 322
https://leetcode.com/problems/coin-change/
You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin
 */
int coin_change_vec_322(std::vector<int>& coins, int amount)
{
    // Time complexity: O(AC)
    // Space complexity: O(A)

    int MAX_COST = amount + 1;
    std::vector<int> min_num_coins(amount+1);

    min_num_coins[0] = 0;

    for(int n = 1; n < min_num_coins.size(); ++n)
        min_num_coins[n] = amount + 1;

    // the nth element of min_num_coins represents the minimum number of coins to sum to n
    for(int n = 1; n <= min_num_coins.size(); ++n)
    {
        for(int c = 0; c < coins.size(); ++c)
        {
            // If the difference between n and coins[c] is positive, it means that 
            // coins[c] could be used as part of the solution.
            if((n - coins[c]) >= 0)
                min_num_coins[n] = std::min(min_num_coins[n], 1 + min_num_coins[n - coins[c]]);
        }
    }

    if(min_num_coins[amount] < (amount + 1))
        return min_num_coins[amount];

    return -1;
}

// TODO: BFS solution with memo


/*
 * Question 842
 * Split array into Fibonacci like sequence
 */
std::vector<int> split_into_fib_seq_842(int i)
{
}




/*
 * Question 1222
 * Queens that can attack a King
 */

// helper function to ensure that this row, col pair lies on the board
bool is_inside(int row, int col)
{
    if(row >= 0 && row <= 7 && col >= 0 && col <= 7)
        return true;

    return false;
}

std::vector<std::vector<int>> queensAttackTheKing(std::vector<std::vector<int>>& queens, std::vector<int>& king) 
{
    int row, col;
    std::vector<std::vector<bool>> has_queen(8, std::vector<bool>(8));
    std::vector<std::vector<int>> output;

    // populate the vector that tells us if we have a queen
    for(std::vector<int> q : queens)
    {
        has_queen[q[0]][q[1]] = true;
    }
    
    // walk over the board in delta co-ordinates 
    for(int d1 = -1; d1 <=1; d1++)
    {
        for(int d2 = -1; d2 <= 1; d2++)
        {
            if(d1 == 0 && d2 == 0)
                continue;
            // we know that the kind vector is a 2-tuple
            row = king[0];
            col = king[1];
            do{
                row += d1;
                col += d2;
            } while(is_inside(row, col) && !has_queen[row][col]);

            // Getting we stop here if we are outside the board or there was
            // a queen. Therefore if we test if we are inside then there must
            // not have been a queen here.
            if(is_inside(row, col))
            {
                output.push_back({row, col});       // didn't realise this syntax was legal
            }
        }
    }

    return output;
}
