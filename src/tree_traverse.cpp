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
void tree_preorder_iter(const TreeNode* root, std::vector<int>& traversal)
{
    std::stack <TreeNode*> tree_stack;
    // tree is empty
    if(root == nullptr)
        return;

    

}

// TODO : I need to remove the const here, but actually the value 
// will never change. Is there a way to tell the compiler this?
void tree_inorder_iter(TreeNode* tree, std::vector<int>& traversal)
{
    std::stack<TreeNode*> tree_stack;

    if(tree != nullptr)
    {
        do
        {
            // store left nodes in the stack
            while(tree != nullptr)
            {
                tree_stack.push(tree);
                tree = tree->left;
            }

            // vist right side
            if(!tree_stack.empty())
            {
                tree = tree_stack.top();
                tree_stack.pop();
                traversal.push_back(tree->val);
                tree = tree->right;
            }

        }while(!tree_stack.empty() || (tree != nullptr));
    }
}

void tree_outorder_iter(const TreeNode* root, std::vector<int>& traversal)
{

}

void tree_postorder_iter(const TreeNode* root, std::vector<int>& traversal)
{

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



