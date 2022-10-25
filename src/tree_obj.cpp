// LC style (object oriented) traversals

#include <iostream>
#include <sstream>
#include <string>
#include <stack>
#include <queue>
#include <vector>

#include "tree.hpp"
#include "log.hpp"



// ---- LC-Style version---- //
ObjTraverser::ObjTraverser() {} 


void ObjTraverser::init(void)
{
    this->traversal.clear();
}

std::vector<int> ObjTraverser::preorder(const TreeNode* root)
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

std::vector<int> ObjTraverser::inorder(const TreeNode* root)
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

std::vector<int> ObjTraverser::outorder(const TreeNode* root)
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

std::vector<int> ObjTraverser::postorder(const TreeNode* root)
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


