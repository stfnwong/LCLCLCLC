// Utilities 

#ifndef __LC_UTIL_HPP
#define __LC_UTIL_HPP

#include <vector>
#include <sstream>
#include <iostream>
#include <string>


// helper to print vectors 
void print_vec(const std::vector<int>& vec);

std::string vec_to_str(const std::vector<int>& vec);

// Check fibonacci property 
bool check_fib_property(const std::vector<int>& seq);


inline int row_col_to_idx(int row, int col, int num_cols)
{
    return (row * num_cols) + col;
}

#endif /*__LC_UTIL_HPP*/
