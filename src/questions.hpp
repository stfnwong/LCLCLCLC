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


// ==== QUESTION 17
// https://leetcode.com/problems/letter-combinations-of-a-phone-number/
std::vector<std::string> letter_combinations_17(std::string digits);

void find_letter_combo(
        std::string& digits,
        std::vector<std::string>& output,
        //std::vector<std::string> mapping,
        std::unordered_map<char, std::string> mapping,
        std::string cur_string,
        int idx
);

#endif /*__LC_QUESTIONS_HPP*/
