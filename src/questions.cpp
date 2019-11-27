/*
 * QUESTIONS
 * Solutions to specific Leetcode questions
 *
 * Stefan Wong 2019
 */

#include <iostream>
#include <unordered_map>
#include "questions.hpp"


/*
 * Question 17
 */
std::vector<std::string> letter_combinations_17(std::string digits)
{
    std::vector<std::string> output;

    if(digits.size() == 0)
        return output;

    // create a mapping of digits
    //std::vector<std::string> digit_map = {
    //    "0",
    //    "1,",
    //    "abc",
    //    "def",
    //    "ghi",
    //    "jkl",
    //    "mno",
    //    "pqrs",
    //    "tuv",
    //    "wxyz"
    //};
    
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
    // Show output
    std::cout << "[" << __func__ << "] output : " << std::endl;
    for(unsigned int n = 0; n < output.size(); ++n)
        std::cout << output[n] << std::endl;
    
    return output;
}


void find_letter_combo(
        std::string& digits,
        std::vector<std::string>& output,
        //std::vector<std::string> mapping,
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
    std::cout << "[" << __func__ << "] substr : " << substr << std::endl;
    for(unsigned int c = 0; c < substr.size(); ++c)
    {
        std::cout << "[" << __func__ << " substr[" << c << "] : " << substr << std::endl;
        //find_letter_combo(digits, output, mapping, std::string(substr[c]), idx+1);
    }
}
