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
#include <string>
#include <queue>
#include <vector>

#include "tree.hpp"


/*
 * build_tree()
 */
TreeNode* build_tree(const std::vector<std::string>& token_vec)
{
    TreeNode* root = nullptr;

    // For root node, skip the leading '[' and get the digit 
    int node_val;
    std::string root_str = token_vec[0];
    // maintain a queue of nodes
    std::queue <TreeNode*> node_q;
    TreeNode* cur_node = nullptr;

    // Clean up?
    if(root_str[0] == '[')
        node_val = std::stoi(root_str.substr(1, 1), nullptr, 10);
    else
        node_val = std::stoi(root_str);
    
    root = new TreeNode(node_val);
    node_q.push(root);
    bool check_left = true;

    // walk the rest of the token vector
    for(unsigned int n = 1; n < token_vec.size(); ++n)
    {
        TreeNode* node = nullptr;
        if(token_vec[n] != "null")
        {
            if(n == token_vec.size() - 1)
                node_val = std::stoi(token_vec[n].substr(0,1) , nullptr, 10);
            else
                node_val = std::stoi(token_vec[n]);
            node = new TreeNode(node_val);
            node_q.push(node);
        }

        // assign the left node 
        if(check_left)
        {
            cur_node = node_q.front();
            node_q.pop();
            cur_node->left = node;
            check_left = false;
        }
        // assign the right node 
        else
        {
            cur_node->right = node;
            check_left = true;
        }
    }

    return root;
}


/*
 * tree_to_repr()
 */
std::string tree_to_repr(TreeNode* root)
{
    std::ostringstream oss;
    std::queue <TreeNode*> node_q;
    TreeNode* cur_node = nullptr;

    // insert the outer brackets
    oss << "[";

    if(root != nullptr)
    {
        node_q.push(root);
        while(!node_q.empty())
        {
            cur_node = node_q.front();
            node_q.pop();
            oss << unsigned(cur_node->val);
            
            // check subtrees
            if(cur_node->left != nullptr)
            {
                node_q.push(cur_node->left);
            }
            //else
            //    oss << ",null";
            if(cur_node->right != nullptr)
            {
                node_q.push(cur_node->right);
            }
            // Only add a comma if there is at least one 
            // non-null node on this level
            //if((cur_node->left != nullptr) && (cur_node->right != nullptr))
            //    oss << ",";
            if(!node_q.empty())
                oss << ",";

            //else
            //    oss << ",null";
        }
    }

    oss << "]";

    return oss.str();
}


// Effectively this is a build_tree() sort of function
/*
 * repr_to_tree()
 */
TreeNode* repr_to_tree(const std::string& repr)
{
    TreeNode* tree = nullptr;
    std::stringstream ss(repr);
    std::vector<std::string> token_vec;

    // DEBUG ONLY
    std::cout << "[" << __func__ << "] repr : " << repr << std::endl;
    
    // first char should be a '['
    if(repr[0] != '[')
    {
        std::cerr << "[" << __func__ << "] repr must be in the form [a,...,n] (missing '[')"
            << std::endl;
        return tree;
    }

    // Check here for [], which is a valid empty tree
    if(repr.length() == 2)
    {
        if((repr[0] != '[') && (repr[1] != ']'))
            std::cerr << "[" << __func__ << "] invalid tree repr (" << repr << ")" << std::endl;

        return tree;
    }

    // Tokenize whatever else we have 
    while(ss.good())
    {
        std::string substr;
        std::getline(ss, substr, ',');
        token_vec.push_back(substr);
    }

    //for(unsigned int i = 0; i < token_vec.size(); ++i)
    //    std::cout << i << ": " << token_vec[i] << std::endl;

    // Since we know this is binary tree, and we also know that the repr is given in level order,
    // we can therefore deduce that each level in the tree should have twice as many entries as 
    // the previous level (unless there was null, eg in the case of 
    //
    // [5, 4, 7, 3, null, 2, null, -1, null, 9]
    //
    // Which should be broken down as
    // [5]
    // [4, 7]
    // [3, null, 2, null]
    // [-1, null, 9]
    //

    //return build_tree(token_vec);
    tree = build_tree(token_vec);
    return tree;
}

#endif /*__TREE_HPP*/
