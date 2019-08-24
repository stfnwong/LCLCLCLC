/*
 * TREE
 * LeetCode tree stuff
 *
 * Stefan Wong 2019
 */

#ifndef __TREE_HPP
#define __TREE_HPP

#include <iostream>
#include <sstream>
#include <vector>

#include "tree.hpp"


std::string tree_to_repr(const TreeNode* root)
{
    std::string repr;

    return repr;
}


TreeNode* repr_to_tree(const std::string& repr)
{
    TreeNode* root;
    std::stringstream ss(repr);
    std::vector<std::string> token_vec;

    // DEBUG ONLY
    std::cout << "[" << __func__ << "] repr : " << repr << std::endl;
    
    // first char should be a '['
    if(repr[0] != '[')
    {
        std::cerr << "[" << __func__ << "] repr must be in the form [a,...,n] (missing '[')"
            << std::endl;
        return nullptr;
    }

    // Check here for [], which is a valid empty tree
    if(repr.length() == 2)
    {
        if((repr[0] != '[') && (repr[1] != ']'))
            std::cerr << "[" << __func__ << "] invalid tree repr (" << repr << ")" << std::endl;

        return nullptr;
    }

    // check last char is a '['
    //if(repr.back()-1 != '[')
    //{
    //    std::cerr << "[" << __func__ << "] unterminated final ']'" << std::endl;
    //    return nullptr;
    //}

    // Tokenize whatever else we have 
    while(ss.good())
    {
        std::string substr;
        std::getline(ss, substr, ',');
        token_vec.push_back(substr);
    }

    
    for(unsigned int i = 0; i < token_vec.size(); ++i)
        std::cout << i << ": " << token_vec[i] << std::endl;

    return nullptr;
}

#endif /*__TREE_HPP*/
