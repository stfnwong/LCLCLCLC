/*
 * Binary tree implementations 
 */

#include <string>
#include <sstream>
#include <vector>

#include "binary_tree.hpp"


/*
 * repr_tokenize()
 * Take a string that contains a level-order tree repr and tokenize it into a sequence
 * of strings that can be used to construct a tree object.
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

BinaryTree<int> repr_to_tree(const std::vector<std::string>& token_vec)
{
    std::queue<BinaryTreeNode<int>*> node_q;
}

BinaryTree<int> create_tree_from_repr(const std::string& repr)
{
    std::vector<std::string> token_vec = repr_tokenize(repr);

    if(token_vec.size() == 0)
        return BinaryTree<int>();

    return repr_to_tree(token_vec);
}


