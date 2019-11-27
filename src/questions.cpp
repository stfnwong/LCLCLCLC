/*
 * QUESTIONS
 * Solutions to specific Leetcode questions
 *
 * Stefan Wong 2019
 */

#include <cstdlib>
#include <iostream>
#include "questions.hpp"

/*
 * Question 1
 */
std::vector<int> two_sum(std::vector<int>& nums, int target)
{
    std::vector<int> output(2);
    // why use a map here...
    std::unordered_map<int, int> diff_map;

    for(unsigned int n = 0; n < nums.size(); ++n)
    {
        int diff = target - nums[n];
        if(diff_map.count(diff) > 0)
        {
            std::cout << "[" << __func__ << "] found key " << diff << std::endl;
            output[0] = diff_map[diff];
            output[1] = n;
            return output;
        }

        // add new differences to map
        diff_map.insert({nums[n], n});
    }

    return output;
}

/*
 * Question 17
 */
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




/*
 * Question 18
 */
std::vector<std::vector<int>> four_sum(std::vector<int>& nums, int target)
{
    
}
