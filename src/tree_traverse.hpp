/*
 * TREE_TRAVERSE
 * Stuff for traversing trees
 *
 */

#ifndef __LC_TREE_TRAVERSE
#define __LC_TREE_TRAVERSE

#include <vector>
#include "tree.hpp"


// Recursive methods
void tree_preorder(const TreeNode* root, std::vector<int>& traversal);
void tree_inorder(const TreeNode* root, std::vector<int>& traversal);
void tree_outorder(const TreeNode* root, std::vector<int>& traversal);
void tree_postorder(const TreeNode* root, std::vector<int>& traversal);

// Iterative methods

#endif /*__LC_TREE_TRAVERSE*/
