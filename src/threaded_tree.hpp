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


struct ThreadedTreeNode
{
    int val;
    ThreadedTreeNode* left;
    ThreadedTreeNode* right;

    public:
        ThreadedTreeNode(int x) : val(x), left(nullptr), right(nullptr) {} 
};

struct DoubleThreadedTreeNode
{
    int val;
    DoubleThreadedTreeNode* left;
    DoubleThreadedTreeNode* right;

    public:
        DoubleThreadedTreeNode(int x) : val(x), left(nullptr), right(nullptr) {} 

};



/*
 * create_threaded_tree()
 * Note that this function expects the same level-order repr that the regular tree uses
 */
ThreadedTreeNode* create_threaded_tree(const std::vector<std::string>& token_vec);

ThreadedTreeNode* repr_to_threaded_tree(const std::string& repr);

/*
 * destroy_threaded_tree()
 * Delete a threaded tree. Really this should be templated for various sort 
 * of trees, but its not super important.
 */
void destroy_threaded_tree(ThreadedTreeNode* tree);

#endif /*__LC_THREADED_TREE_HPP*/
