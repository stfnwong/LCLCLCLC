/*
 * QUESTIONS
 * Solutions to specific Leetcode questions
 *
 * Stefan Wong 2019
 */

#include <iostream>
#include "questions.hpp"


std::vector<std::string> letter_combinations_17(std::string digits)
{
    std::vector<std::string> output;

    if(digits.size() == 0)
        return output;

    // create a mapping of digits
    std::vector<std::string> digit_map = {
        "0",
        "1,",
        "abc",
        "def",
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tuv",
        "wxyz"
    };

    find_letter_combo(digits, output, digit_map, std::string(""), 0);
    // Show output
    std::cout << "[" << __func__ << "] output : " << std::endl;
    for(unsigned int n = 0; n < output.size(); ++n)
        std::cout << output[n] << std::endl;
    
    return output;
}


void find_letter_combo(
        std::string digits,
        std::vector<std::string> output,
        std::vector<std::string> mapping,
        std::string cur_string,
        int idx)
{
    if(idx == digits.size())
    {
        output.push_back(cur_string);
        return;
    }

    int cur_digit = std::stoi(std::string(digits[idx]));

    std::string substr = mapping[cur_digit];
    std::cout << "[" << __func__ << "] substr : " << substr << std::endl;
    for(unsigned int c = 0; c < cur_string.size(); ++c)
    {
        std::cout << "[" << __func__ << " substr[" << c << "] : " << substr << std::endl;
        //find_letter_combo(digits, output, mapping, std::string(substr[c]), idx+1);
    }
}
