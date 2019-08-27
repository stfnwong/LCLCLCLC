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
void tree_preorder(const treenode* root, std::vector<int>& traversal);
void tree_inorder(const treenode* root, std::vector<int>& traversal);
void tree_outorder(const treenode* root, std::vector<int>& traversal);
void tree_postorder(const TreeNode* root, std::vector<int>& traversal);

// Recursive methods (LC style) - these do all sorts of vector shenanigans
/*
std::vector<int> lc_tree_preorder(const treenode* root);  
std::vector<int> lc_tree_inorder(const treenode* root); 
std::vector<int> lc_tree_outorder(const treenode* root);
std::vector<int> lc_tree_postorder(const TreeNode* root);
*/

// Iterative methods

#endif /*__LC_TREE_TRAVERSE*/
