/*
 * UTIL
 * Functions that don't fit anywhere else
 */

#ifndef __UTIL_HPP
#define __UTIL_HPP


#include <string>
#include <sstream>
#include <vector>


template <typename T> void swp(T& a, T& b)
{
    T temp = a;
    a = b;
    b = temp;
}


template <typename T> std::string vec_to_str(const std::vector<T>& vec)
{
    std::ostringstream oss;

    oss << "[";
    for(unsigned i = 0; i < vec.size(); ++i)
    {
        oss << vec[i];
        if(i < vec.size()-1)
            oss << ",";
    }
    oss << "]";

    return oss.str();
}

#endif /*__UTIL_HPP*/
