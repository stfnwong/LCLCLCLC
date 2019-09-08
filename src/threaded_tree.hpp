/*
 * THREADED TREE
 * A threaded tree implementation.
 *
 * Stefan Wong 2019
 */

#ifndef __LC_THREADED_TREE_HPP
#define __LC_THREADED_TREE_HPP

#include <string>
#include <vector>
#include "tree.hpp"



/*
 * create_threaded_tree()
 * Note that this function expects the same level-order repr that the regular tree uses
 */
TreeNode* create_threaded_tree(const std::vector<std::string>& token_vec);

TreeNode* repr_to_threaded_tree(const std::string& repr);


#endif /*__LC_THREADED_TREE_HPP*/
