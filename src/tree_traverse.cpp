/*
 * TRAVERSE A TREE
 * Basic stuff that I hope I know from LeetCode explore
 *
 * Stefan Wong 2019
 */

#include <stack>
#include "tree_traverse.hpp"

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
void tree_outorder_iter(TreeNode* root, std::vector<int>& traversal)
{
    std::stack <TreeNode*> tree_stack;

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
void tree_postorder_iter(TreeNode* root, std::vector<int>& traversal)
{
    // start with inferior two stack implementation 
    std::stack <TreeNode*> tree_stack;

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



// ---- LC-Style version---- //
LCTraverser::LCTraverser() {} 


void LCTraverser::init(void)
{
    this->traversal.clear();
}

std::vector<int> LCTraverser::preorder(const TreeNode* root)
{
    if(root != nullptr)
    {
        this->traversal.push_back(root->val);
        if(root->left != nullptr)
            this->preorder(root->left);
        if(root->right != nullptr)
            this->preorder(root->right);
    }

    return this->traversal;
}

std::vector<int> LCTraverser::inorder(const TreeNode* root)
{
    if(root != nullptr)
    {
        if(root->left != nullptr)
            this->inorder(root->left);
        this->traversal.push_back(root->val);
        if(root->right != nullptr)
            this->inorder(root->right);
    }

    return this->traversal;
}

std::vector<int> LCTraverser::outorder(const TreeNode* root)
{
    if(root != nullptr)
    {
        if(root->right != nullptr)
            this->outorder(root->right);
        this->traversal.push_back(root->val);
        if(root->left != nullptr)
            this->outorder(root->left);
    }

    return this->traversal;
}

std::vector<int> LCTraverser::postorder(const TreeNode* root)
{
    if(root != nullptr)
    {
        if(root->left != nullptr)
            this->postorder(root->left);
        if(root->right != nullptr)
            this->postorder(root->right);
        this->traversal.push_back(root->val);
    }

    return this->traversal;
}



