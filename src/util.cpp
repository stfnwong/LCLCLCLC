
#include "util.hpp"

// helper to print vectors 
void print_vec(const std::vector<int>& vec)
{
    for(auto& elem : vec)
        std::cout << elem << " ";

    std::cout << std::endl;
}

std::string vec_to_str(const std::vector<int>& vec)
{
    std::ostringstream oss;

    for(auto& elem : vec)
        oss << elem << " ";

    return oss.str();
}


std::string vec_vec_to_str(const std::vector<std::vector<int>>& grid)
{
    std::ostringstream oss;
    unsigned num_rows = grid.size();
    unsigned num_cols = grid[0].size();

    for(unsigned r = 0; r < num_rows; ++r)
    {
        for(unsigned c = 0; c < num_cols; ++c)
            oss << grid[r][c] << " ";
        oss << std::endl;
    }

    return oss.str();
}

// Check fibonacci property 
bool check_fib_property(const std::vector<int>& seq)
{
    if(seq.size() <= 2)
        return true;

    for(unsigned n = 2; n < seq.size(); ++n)
    {
        if(seq[n] != (seq[n-1] + seq[n-2]))
            return false;
    }

    return true;
}


