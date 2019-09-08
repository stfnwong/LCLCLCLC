/*
 * THREADED TREE
 * A threaded tree implementation.
 *
 * Stefan Wong 2019
 */

#include <sstream>
#include <queue>
#include "log.hpp"
#include "threaded_tree.hpp"



/*
 * create_threaded_tree()
 */
TreeNode* create_threaded_tree(const std::vector<std::string>& token_vec)
{
    TreeNode* root = nullptr;

    int node_val;
    // maintain a queue of nodes
    std::queue <TreeNode*> node_q;
    TreeNode* cur_node = nullptr;

    // Create the base of the tree
    root = new TreeNode(std::stoi(token_vec[0]));
    node_q.push(root);
    bool check_left = true;

    // walk the rest of the token vector
    for(unsigned int n = 1; n < token_vec.size(); ++n)
    {
        TreeNode* node = nullptr;
        // TODO : this might not be handling null left-pointers correctly...
        // A better implementation would be to check how many tokens there are, 
        // and perhaps even pad the string automatically (so that omitted trailing
        // tokens are explicitly turned into <null>)
        if(token_vec[n] != "null")
        {
            node_val = std::stoi(token_vec[n]);
            node = new TreeNode(node_val);
            node_q.push(node);
            lc_log("Added Node (" + std::to_string(node->val) + ")");
        }

        // assign the left node 
        if(check_left)
        {
            cur_node = node_q.front();
			if(cur_node == nullptr)
					lc_log("Left node (token vec " + token_vec[n] + ") is nullptr");
            lc_log("Assigning left node (" + std::to_string(cur_node->val) + ")");
            node_q.pop();
            cur_node->left = node;
            check_left = false;
        }
        // assign the right node 
        else
        {
			if(cur_node == nullptr)
					lc_log("Right node (token vec " + token_vec[n] + ") is nullptr");
            lc_log("Assigning right node (" + std::to_string(cur_node->val) + ")");
            cur_node->right = node;
            check_left = true;
        }
    }

    return root;
}


TreeNode* repr_to_threaded_tree(const std::string& repr)
{
    TreeNode* tree = nullptr;
    std::stringstream ss(repr);
    std::vector<std::string> token_vec;

	token_vec = repr_to_token_vec(repr);
	if(token_vec.size() > 0)
	{
	    tree = create_threaded_tree(token_vec);
	    return tree;
	}
	else
	    return nullptr;

    lc_log(repr);
    

}

