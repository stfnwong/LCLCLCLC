/*
 * TREE
 * LeetCode tree stuff
 *
 * Stefan Wong 2019
 */

#ifndef __LC_TREE_HPP
#define __LC_TREE_HPP

#include <string>
#include <vector>

/*
 * TreeNode structure
 */
struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    
    public:
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        // TODO: implement proper dtor (post-order traverse + delete):w
};

/*
 * tree_size()
 * Count the number of nodes in a tree
 */
int tree_size(const TreeNode* root);

// NOTE: see https://support.leetcode.com/hc/en-us/articles/360011883654-What-does-1-null-2-3-mean-in-binary-tree-representation- for details about how this representation works.

TreeNode* build_tree(const std::vector<std::string>& token_repr);

// Convert a string like [1, 2, 3] into a Tree
std::string tree_to_repr(TreeNode* root);

// Convert a tree into a string like [1, 2,3]
TreeNode* repr_to_tree(const std::string& repr);


#endif /*__LC_TREE_HPP*/
