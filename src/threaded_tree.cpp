/*
 * THREADED TREE
 * A threaded tree implementation.
 *
 * Stefan Wong 2019
 */

#include <queue>
#include "threaded_tree.hpp"



/*
 * create_threaded_tree()
 */
ThreadedTreeNode* create_threaded_tree(const std::vector<std::string>& token_vec)
{
    ThreadedTreeNode* root = nullptr;

    int node_val;
    // maintain a queue of nodes
    std::queue <ThreadedTreeNode*> node_q;
    ThreadedTreeNode* cur_node = nullptr;

    // Create the base of the tree
    root = new ThreadedTreeNode(std::stoi(token_vec[0]));
    node_q.push(root);
    bool check_left = true;

    return root;
}


ThreadedTreeNode* repr_to_threaded_tree(const std::string& repr)
{
    // tokenize

}

/*
 * destroy_threaded_tree()
 */
void destroy_threaded_tree(ThreadedTreeNode* tree)
{
    if(tree == nullptr)
        return;
    if(tree->left != nullptr)
        destroy_threaded_tree(tree->left);
    if(tree->right != nullptr)
        destroy_threaded_tree(tree->right);
    delete tree;
}
