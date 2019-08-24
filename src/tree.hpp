/*
 * TREE
 * LeetCode tree stuff
 *
 * Stefan Wong 2019
 */

#include <string>

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    
    public:
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// NOTE: see https://support.leetcode.com/hc/en-us/articles/360011883654-What-does-1-null-2-3-mean-in-binary-tree-representation- for details about how this representation works.

// Convert a string like [1, 2, 3] into a Tree
std::string tree_to_repr(const TreeNode* root);


// Convert a tree into a string like [1, 2,3]
TreeNode* repr_to_tree(const std::string& repr);
