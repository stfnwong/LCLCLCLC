/*
 * TREE
 * LeetCode tree stuff
 *
 * Stefan Wong 2019
 */


#include <iostream>
#include <sstream>
#include <string>
#include <stack>
#include <queue>
#include <vector>

#include "tree.hpp"
#include "log.hpp"


/*
 * tree_size()
 */
int tree_size(const TreeNode* root)
{
    int size = 1;

    if(root == nullptr)
        return 0;
    if(root->left != nullptr)
        size = size + tree_size(root->left);
    if(root->right != nullptr)
        size = size + tree_size(root->right);

    return size;
}


/*
 * create_tree()
 */
TreeNode* create_tree(const std::vector<std::string>& token_vec)
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
            lc_log("Assigning left node (" + std::to_string(cur_node->val) + ")");
            node_q.pop();
            cur_node->left = node;
            check_left = false;
        }
        // assign the right node 
        else
        {
            lc_log("Assigning right node (" + std::to_string(cur_node->val) + ")");
            cur_node->right = node;
            check_left = true;
        }
    }

    return root;
}

/*
 * destroy_tree()
 */
void destroy_tree(TreeNode* tree)
{
    if(tree == nullptr)
        return;
    if(tree->left != nullptr)
        destroy_tree(tree->left);
    if(tree->right != nullptr)
        destroy_tree(tree->right);
    delete tree;
}


/*
 * tree_to_repr()
 */
std::string tree_to_repr(TreeNode* root)
{
    //std::ostringstream oss;
    std::queue <TreeNode*> node_q;
    std::vector<std::string> tree_str_vec;
    TreeNode* cur_node = nullptr;

    // Because this is a level order representation we need to keep track of what 
    // level we are on. This is important for the output string since we need to insert
    // the null value if there is a middle layer somewhere where the tree is not 'full'
    if(root != nullptr)
    {
        node_q.push(root);
        while(!node_q.empty())
        {
            cur_node = node_q.front();
            node_q.pop();
            tree_str_vec.push_back(std::to_string(unsigned(cur_node->val)));
            
            // check subtrees
            if(cur_node->left != nullptr)
                node_q.push(cur_node->left);
            
            if(cur_node->right != nullptr)
                node_q.push(cur_node->right);

            // NOTE: the logic here is not quite correct...
            if(cur_node->left == nullptr && (cur_node->right != nullptr))
                tree_str_vec.push_back("null");
        }
    }

    std::string tree_output = "[";
    for(unsigned int n = 0; n < tree_str_vec.size(); ++n)
    {
        tree_output += tree_str_vec[n];
        if(n != tree_str_vec.size()-1)
            tree_output += ",";
    }
    tree_output += "]";

    return tree_output;
}


/*
 * repr_to_token_vec()
 */
std::vector<std::string> repr_to_token_vec(const std::string& repr)
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


// Effectively this is a create_tree() sort of function
/*
 * repr_to_tree()
 */
TreeNode* repr_to_tree(const std::string& repr)
{
    TreeNode* tree = nullptr;
    std::stringstream ss(repr);
    std::vector<std::string> token_vec;

    lc_log(repr);
    
    // Since we know this is binary tree, and we also know that the repr is given in level order,
    // we can therefore deduce that each level in the tree should have twice as many entries as 
    // the previous level (unless there was null, eg in the case of 
    //
    // [5, 4, 7, 3, null, 2, null, -1, null, 9]
    //
    // Which should be broken down as
    // [5]
    // [4, 7]
    // [3, null, 2, null]
    // [-1, null, 9]
    //
	token_vec = repr_to_token_vec(repr);
	if(token_vec.size() > 0)
	{
	    tree = create_tree(token_vec);
	    return tree;
	}
	else
	    return nullptr;
}


// ===== TRAVERSAL ==== //

// -------- Recursive variants -------- //

/*
 * tree_preorder()
 */
void tree_preorder(const TreeNode* root, std::vector<int>& traversal)
{
    if(root == nullptr)
        return;

    traversal.push_back(root->val);
    if(root->left != nullptr)
        tree_preorder(root->left, traversal);
    if(root->right != nullptr)
        tree_preorder(root->right, traversal);
}


/*
 * tree_inorder()
 */
void tree_inorder(const TreeNode* root, std::vector<int>& traversal)
{
    if(root == nullptr)
        return;

    if(root->left != nullptr)
        tree_inorder(root->left, traversal);
    traversal.push_back(root->val);
    if(root->right != nullptr)
        tree_inorder(root->right, traversal);
}

/*
 * tree_outorder()
 */
void tree_outorder(const TreeNode* root, std::vector<int>& traversal)
{
    if(root == nullptr)
        return;

    if(root->right != nullptr)
        tree_outorder(root->right, traversal);
    traversal.push_back(root->val);
    if(root->left != nullptr)
        tree_outorder(root->left, traversal);
}

/*
 * tree_postorder()
 */
void tree_postorder(const TreeNode* root, std::vector<int>& traversal)
{
    if(root == nullptr)
        return;
    
    if(root->left != nullptr)
        tree_postorder(root->left, traversal);
    if(root->right != nullptr)
        tree_postorder(root->right, traversal);
    traversal.push_back(root->val);
}

/*
 * tree_levelorder()
 * This is a crap implementation
 */
void tree_levelorder(const TreeNode* root, std::vector<int>& traversal)
{
    std::queue <const TreeNode*> tree_queue;

    tree_queue.push(root);

    while(!tree_queue.empty())
    {
        const TreeNode* cur_node = tree_queue.front();
        tree_queue.pop();
        traversal.push_back(cur_node->val);
        if(cur_node->left != nullptr)
            tree_queue.push(cur_node->left);
        if(cur_node->right != nullptr)
            tree_queue.push(cur_node->right);
    }
}


// ---- Recursive solutions with stacks ---- //
void tree_preorder_stack(const TreeNode* root, std::vector<int>& traversal)
{
    std::stack <const TreeNode*> tree_stack;

    tree_stack.push(root);

    while(!tree_stack.empty())
    {
        const TreeNode* current;
        current = tree_stack.top();
        tree_stack.pop();
        
        if(current != nullptr)
        {
            // Push unvisited nodes to stack. We push right then left here
            // to ensure that the traversal is symmetric.
            tree_stack.push(current->right);
            tree_stack.push(current->left);

            traversal.push_back(current->val);
        }
    }
}



// ---- iterative versions ---- //

/*
 * tree_preorder_iter()
 * A more general way to state the algorithm here would be to say 
 * - Get a stack. This stack will hold nodes to be processed
 * - To process a node, visit the node, push its right child onto the stack,
 *   then process the left child.
 * - If there is no left child, get another node from the stack
 */
void tree_preorder_iter(TreeNode* root, std::vector<int>& traversal)
{
    std::stack <TreeNode*> tree_stack;

    if(root != nullptr)
    {
        do
        {
            // visit the left side
            while(root != nullptr)
            {
                tree_stack.push(root);
                traversal.push_back(root->val);
                root = root->left;
            }

            // visit the right side
            if(!tree_stack.empty())
            {
                root = tree_stack.top();
                tree_stack.pop();
                root = root->right;
            }
        }while(!tree_stack.empty() || (root != nullptr));
    }
}

/*
 * tree_inorder_iter()
 * - Get a stack. This stack holds nodes to be visited.
 * - Each time we pop a node from the stack, visit it and then 
 *   process the right child.
 * - When a node is processed, put it on the stack and then process its left child
 */
void tree_inorder_iter(TreeNode* root, std::vector<int>& traversal)
{
    std::stack<TreeNode*> tree_stack;

    if(root != nullptr)
    {
        do
        {
            // store left nodes in the stack
            while(root != nullptr)
            {
                tree_stack.push(root);
                root = root->left;
            }

            // unwind stack, visiting right side of each unwound node
            if(!tree_stack.empty())
            {
                root = tree_stack.top();
                tree_stack.pop();
                traversal.push_back(root->val);
                root = root->right;
            }

        }while(!tree_stack.empty() || (root != nullptr));
    }
}

/*
 * tree_outorder_iter()
 */
void tree_outorder_iter(const TreeNode* root, std::vector<int>& traversal)
{
    std::stack <const TreeNode*> tree_stack;

    if(root != nullptr)
    {
        do
        {
            // Stack up all the right-side nodes
            while(root != nullptr)
            {
                tree_stack.push(root);
                root = root->right;
            }

            // unwind stack, visiting left side of each unwound node 
            if(!tree_stack.empty())
            {
                root = tree_stack.top();
                tree_stack.pop();
                traversal.push_back(root->val);
                root = root->left;
            }
        }while(!tree_stack.empty() || (root != nullptr));
    }

}

/*
 * tree_postorder_iter()
 * This case is the hardest. In the previous cases the stack just stores either nodes that
 * need to be visited, or nodes that need to be processed. In this case the visiting order 
 * and the processing order are not linked by such a simple pattern, and so the stack needs 
 * to store both the nodes to visit and the nodes to process (because in DFS, we need to 
 * process all child nodes before processing the current node).
 *
 *
 */
void tree_postorder_iter(const TreeNode* root, std::vector<int>& traversal)
{
    // start with inferior two stack implementation 
    std::stack <const TreeNode*> tree_stack;

    if(root != nullptr)
    {
        do
        {
            // stack up left sides of tree
            while(root != nullptr)
            {
                tree_stack.push(root);
                root = root->left;
            }

            // stack up right sides of tree, then add current node value
            if(!tree_stack.empty())
            {
                root = tree_stack.top();
                tree_stack.pop();
                root = root->right;
            }

        }while(!tree_stack.empty() || (root != nullptr));
    }
}

/*
 * Breadth-First Traversal
 */

void tree_bfs(TreeNode* root, std::vector<int>& traversal)
{
    std::queue<TreeNode*> q;

    q.push(root);
    while(!q.empty())
    {
        for(int i = 0; i < q.size(); ++i)
        {
            const TreeNode* cur_node = q.front();
            traversal.push_back(cur_node->val);

            if(cur_node->left != nullptr)
                q.push(cur_node->left);
            if(cur_node->right != nullptr)
                q.push(cur_node->right);
            q.pop();
        }
    }
}

