/*
 * QUESTIONS
 * Solutions to specific Leetcode questions
 *
 * Stefan Wong 2019
 */

#include <algorithm>
#include <cstdlib>
#include <iostream>
#include "questions.hpp"

/*
 * Question 1
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

// version where we move two pointers in a sorted array
std::vector<int> two_sum_pointer(std::vector<int>& nums, int target)
{
    unsigned int start, end;
    std::vector<int> output(2);

    start = 0;
    end = nums.size() - 1;

    // The idea here is that we have two pointers, one at the start and 
    // one at the end which we move closer towards each other.
    // This only works if the array is sorted.
    // TODO: if we want to return the index in the original unsorted array then we 
    // need to make a copy here.
    std::sort(nums.begin(), nums.end());     // default comparison is <

    // Now we test the start and end pointers in turn.
    while(start <= end)
    {
        int sum = nums[start] + nums[end];
        if(sum > target)
            end--;
        if(sum < target)
            start++;
        if(sum == target)
            break;
    }

    // Start and end are now the positions in the sorted array that 
    // contain the two elements that sum correctly. Now we need to map
    // these back to the positions in the original array
    ///int start_unsorted = -1;
    ///int end_unsorted = -1;
    ///for(unsigned int n = 0; n < nums.size(); ++n)
    ///{
    ///    // map the sorted index back to the unsorted index
    ///    if(start == nums[n])
    ///        start_unsorted = n;
    ///    if(end == nums[n])
    ///        end_unsorted = n;
    ///    std::cout << "[" << __func__ << "] idx : " << n 
    ///        << " start unsorted " << start_unsorted << ", end unsorted " << end_unsorted 
    ///        << " nums[" << n << "] : " << nums[n] << std::endl;
    ///}
    output[0] = start;
    output[1] = end;

    return output;
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

    int q_val;
    int p_val;

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
    // NOTE : this wastes memory...
}


/*
 * Question 3
 */
int length_of_longest_substring(std::string& s)
{
    // First idea - The question specifies that this must be a substring 
    // and is therefore contiguous
}

/*
 * Question 14
 */
std::string longest_common_prefix_horz(std::vector<std::string>& strs)
{
    std::string output;

    // This method is slow - we try scanning along each string in turn 
    // looking for common prefixes
    std::string prefix = strs[0];       // test against first string
    for(unsigned int s = 1; s < strs.size(); ++s)
    {

    }

    return output;
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
        int idx)
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
std::vector<std::vector<int>> four_sum(std::vector<int>& nums, int target)
{
    
}

/*
 * Question 55
 */
// Lets implement the dumb way here. 

bool can_jump_here_basic(int cur_pos, std::vector<int>& nums)
{
    if(cur_pos == nums.size()-1)
        return true;

    int max_jump;
    if((cur_pos + nums[cur_pos]) > nums.size()-1)
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
