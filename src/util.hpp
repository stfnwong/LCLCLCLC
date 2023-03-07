// Utilities 

#ifndef __LC_UTIL_HPP
#define __LC_UTIL_HPP


#include <string>
#include <vector>


// helper to print vectors 
void print_vec(const std::vector<int>& vec);

std::string vec_to_str(const std::vector<int>& vec);
std::string vec_vec_to_str(const std::vector<std::vector<int>>& grid);

// Check fibonacci property 
bool check_fib_property(const std::vector<int>& seq);


inline int row_col_to_idx(int row, int col, int num_cols)
{
    return (row * num_cols) + col;
}

inline std::pair<int,int> idx_to_row_col(int idx, int num_cols)
{
    int row = idx / num_cols;
    int col = idx % num_cols;

    return std::make_pair(row, col);
}


#endif /*__LC_UTIL_HPP*/
