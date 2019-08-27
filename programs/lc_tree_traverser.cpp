/* 
 * LC_TREE_TRAVERSER
 * Program that traverses a simple tree. 
 * This program does the traversal in the style used by the leetcode
 * question (where each node produces a vector of ints that needs to 
 * be concatenated together)
 *
 * Stefan Wong 2019
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <getopt.h>
// Modules
#include "tree.hpp"
#include "tree_traverse.hpp"



int main(int argc, char *argv[])
{
    TreeNode* tree = nullptr;
    std::string repr = "[1,2,3]";
    std::vector<int> traversal;

    tree = repr_to_tree(repr);
    if(tree == nullptr)
    {
        std::cout << "[" << __func__ << "] failed to create tree from repr " << repr << std::endl;
        return -1;
    }

    std::cout << "Performing LC style in-order traversal" << std::endl;
    lc_tree_inorder(tree, traversal);
    std::cout << "traversal contains " << traversal.size() << " nodes" << std::endl;
    std::cout << "[";
    for(unsigned int i = 0; i < traversal.size(); ++i)
        std::cout << traversal[i] << " ";
    std::cout << "]" << std::endl << std::endl;

    return 0;
}
