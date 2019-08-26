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
 * tree_size()
 */
int tree_size(const TreeNode* root)
{
    int size = 1;

    if(root == nullptr)
        return 0;
    if(root->left != nullptr)
        size = size + tree_size(root->left);
    if(root->right != nullptr)
        size = size + tree_size(root->right);

    return size;
}


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

    // Create the base of the tree
    root = new TreeNode(std::stoi(token_vec[0]));
    node_q.push(root);
    bool check_left = true;

    // walk the rest of the token vector
    for(unsigned int n = 1; n < token_vec.size(); ++n)
    {
        // FIXME debug 
        std::cout << "[" << __func__ << "] checking token " << n << " [" << token_vec[n] << "]" << std::endl;

        TreeNode* node = nullptr;
        if(token_vec[n] != "null")
        {
            node_val = std::stoi(token_vec[n]);
            node = new TreeNode(node_val);
            node_q.push(node);

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
    }

    return root;
}


/*
 * tree_to_repr()
 */
std::string tree_to_repr(TreeNode* root)
{
    //std::ostringstream oss;
    std::queue <TreeNode*> node_q;
    std::vector<std::string> tree_str_vec;
    TreeNode* cur_node = nullptr;

    // insert the leading bracket
    //oss << "[";
    tree_str_vec.push_back("[");

    // Because this is a level order representation we need to keep track of what 
    // level we are on. This is important for the output string since we need to insert
    // the null value if there is a middle layer somewhere where the tree is not 'full'
    int cur_level = 0;
    int str_ptr   = 0;
    int num_nodes = 0;
    if(root != nullptr)
    {
        node_q.push(root);
        cur_level = 1;
        while(!node_q.empty())
        {
            cur_node = node_q.front();
            node_q.pop();
            //oss << unsigned(cur_node->val);
            tree_str_vec.push_back(std::to_string(unsigned(cur_node->val)));
            
            // check subtrees
            str_ptr = 0;
            num_nodes = (cur_level > 0) ? (2 * cur_level) : 1;

            if(cur_node->left != nullptr)
                node_q.push(cur_node->left);
            else
                tree_str_vec.push_back("null");

            //else
            //    layer_str[str_ptr] = "null"
            //str_ptr++;
            
            if(cur_node->right != nullptr)
                node_q.push(cur_node->right);
            else
                tree_str_vec.push_back("null");

            //else
            //    layer_str[str_ptr] = "null";
            //str_ptr++;

            // work out how many strings we need to make for this level

            // debug - remove
            std::cout << "[" << __func__ << "] on level " << cur_level << ", should be " 
                << num_nodes << " on this level" << std::endl;
            if(cur_node->left != nullptr)
                std::cout << "left has node" << std::endl;
            else
                std::cout << "left is null" << std::endl;
            if(cur_node->right != nullptr)
                std::cout << "right has node" << std::endl;
            else
                std::cout << "right is null" << std::endl;

            

            // Brute method for inserting nulls
            //if(cur_node->left == nullptr && cur_node->right != nullptr)
            //    oss << ",null";

            // Only add a comma if there is at least one 
            // non-null node on this level
            //if(!node_q.empty())
            //    oss << ",";
            if(node_q.size() == 1)
            {
                cur_level++;

                // update the string stream
            }
        }
    }

    // insert the trailing bracket
    tree_str_vec.push_back("]");

    std::string tree_output;
    for(unsigned int n = 0; n < tree_str_vec.size(); ++n)
    {
        tree_output += tree_str_vec[n];
        if((n > 0) && (n != tree_str_vec.size()-1))
            tree_output += ",";
    }

    return tree_output;
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
        // remove leading spaces 
        if(substr[0] == ' ')
            substr = substr.substr(1, substr.length()-1);
        // strip the '[' or ']' chars 
        if(substr[0] == '[')
           substr = substr.substr(1, substr.length()-1); 
        if(substr[substr.length()-1] == ']')
            substr = substr.substr(0, substr.length()-1);
        
        token_vec.push_back(substr);
    }

    for(unsigned int i = 0; i < token_vec.size(); ++i)
        std::cout << i << ": " << token_vec[i] << std::endl;

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
