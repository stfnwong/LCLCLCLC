/*
 * TRAVERSE A TREE
 * Basic stuff that I hope I know from LeetCode explore
 *
 * Stefan Wong 2019
 */

#include "tree_traverse.hpp"


// Apparently, this requires 10.9MB (!!!) of memory
//class Solution {
//    public:
//        std::vector<int> preorderTraversal(TreeNode* root) {
//
//            std::vector<int> values;
//            std::vector<int> out_values;
//            
//            if(root == NULL)
//                return values;
//            
//            values.push_back(root->val);
//            if(root->left != NULL)
//            {
//                out_values = preorderTraversal(root->left);
//                values.insert(values.end(), out_values.begin(), out_values.end());
//            }
//            if(root->right != NULL)
//            {
//                out_values = preorderTraversal(root->right);
//                values.insert(values.end(), out_values.begin(), out_values.end());
//            }
//            return values;
//        }
//};


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



