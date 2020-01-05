/*
 * PALINDROME
 * Some implementations of palindrome detection
 */

#include <algorithm>        // for std::equal
#include <string>

bool is_palindrome_iter(const std::string& s)
{
    return std::equal(s.begin(), s.begin() + s.size() / 2, s.rbegin());
}

//bool is_palindrome_2(const std::string& s)
//{
//    auto half = s.length() / 2;
//    return s.take(half).equals(s.retro.take(half));
//}
