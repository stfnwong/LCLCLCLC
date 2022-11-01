/*
 * Binary Tree
 * Various implementations of binary trees
 */


#ifndef __LC_BINARY_TREE_HPP
#define __LC_BINARY_TREE_HPP

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>


/*
 * Binary Tree with left and right pointers
 */
template <typename T> struct BinaryTreeNode
{
    T elem;
    BinaryTreeNode<T>* left;
    BinaryTreeNode<T>* right;

    private:
        unsigned height_rec(const BinaryTreeNode<T>& root) const
        {
            if(root == nullptr)
                return 0;

            unsigned left_height = height_rec(root->left);
            unsigned right_height = height_rec(root->right);

            return std::max(left_height, right_height);
        }

    public:
        BinaryTreeNode(const T& v) : elem(v), left(nullptr), right(nullptr) {}
        ~BinaryTreeNode()
        {
            delete this->left;
            delete this->right;
        }

        unsigned height(void) const
        {
            return this->height_rec(this);
        }

};

template <typename T> void destroy_binary_tree(BinaryTreeNode<T>& root)
{
    if(root == nullptr)
        return;
    if(root->left != nullptr)
        destroy_binary_tree(root->left);
    if(root->right != nullptr)
        destroy_binary_tree(root->right);
}


/*
 * repr_tokenize()
 * Take a strng 
 */
std::vector<std::string> repr_tokenize(const std::string& repr)
{
    std::stringstream ss(repr);
    std::vector<std::string> token_vec;

    // first char should be a '['
    if(repr[0] != '[')
    {
        std::cerr << "[" << __func__ << "] repr must be in the form [a,...,n] (missing '[')"
            << std::endl;
        return token_vec;
    }

    // Check here for [], which is a valid empty tree
    if(repr.length() == 2)
    {
        if((repr[0] != '[') && (repr[1] != ']'))
            std::cerr << "[" << __func__ << "] invalid tree repr (" << repr << ")" << std::endl;

        return token_vec;
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

	return token_vec;
}

}

/*
 * repr_to_binary_tree()
 *
 * Construct a binary tree from a leetcode-style representation. Specifically, a list 
 * of tokens representing valid values arranged in level-order. "None" or "null" strings
 * indicate
 */
template <typename T> BinaryTreeNode<T> repr_to_binary_tree(const std::vector<std::string>& repr_tokens)
{
}


/*
 * TRAVERSALS ON BINARY TREES
 */


#endif /*__LC_BINARY_TREE_HPP*/
