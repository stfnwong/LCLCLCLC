/*
 * Binary Tree
 * Various implementations of binary trees
 */


#ifndef __LC_BINARY_TREE_HPP
#define __LC_BINARY_TREE_HPP

#include <algorithm>
#include <iostream>
#include <memory>
#include <queue>
#include <string>
#include <vector>



/*
 * repr_tokenize()
 * Take a string that contains a level-order tree repr and tokenize it into a sequence
 * of strings that can be used to construct a tree object.
 */
std::vector<std::string> repr_tokenize(const std::string& repr)
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


/*
 * Binary Tree Node with raw pointers
 * I can't seem to move smart pointers to a stack or queue....
 */



/*
 * Binary Tree with left and right pointers
 */
template <typename T> struct BinaryTreeNode
{
    T value;
    std::unique_ptr<BinaryTreeNode> left;
    std::unique_ptr<BinaryTreeNode> right;

    public:
        explicit BinaryTreeNode(const T& val) : value(val), left(nullptr), right(nullptr) {} 

};


/*
 * BinaryTree
 * Object that implements a binary tree from BinaryTreeNodes
 */
template <typename T> class BinaryTree
{
    private:

        void insert(std::unique_ptr<BinaryTreeNode<T>>& node, const T& value)
        {
            if(node)
            {
                if(value < node->value)
                    this->insert(node->left, value);
                else
                    this->insert(node->right, value);
            }
            else
                node = std::make_unique<BinaryTreeNode<T>>(value); // <- TODO: fucked
        }

        bool contains(const std::unique_ptr<BinaryTreeNode<T>>& node, const T& value)
        {
            if(!node)
                return false;
            else if(node->value == value)
                return true;
            else
            {
                return (value < node->value) ?
                    this->contains(node->left, value) :
                    this->contains(node->right, value);
            }
        }

        // Note that this deletes by value...
        bool remove(std::unique_ptr<BinaryTreeNode<T>>& node, const T& value)
        {
            if(!node)
                return false;
            else if(node->value == value)
            {
                // This is the one to delete
                if(node->left)
                {
                    auto right = node->right;
                    auto left = std::move(node->left);  // TODO: read up on std::move()
                }


                return true;
            }
            else
            {
                return (value < node->value) ?
                    this->remove(node->left, value) :
                    this->remove(node->right, value);
            }
        }


    public:
        BinaryTree() {}         // this->root should == nullptr
        explicit BinaryTree(const T& val) :
            root(std::make_unique<BinaryTreeNode<T>>(val)) {}
        // TODO: destructor

        void insert(const T& value)
        {
            this->insert(this->root, value);
        }

        bool contains(const T& value)
        {
            return this->contains(this->root, value);
        }

        bool remove(const T& value)
        {
            return this->remove(this->root, value);
        }

        unsigned size(void) const
        {
            unsigned size = 0;
            std::queue<BinaryTreeNode<T>*> node_q;

            node_q.push(this->root.get());
            while(!node_q.empty())
            {
                auto cur_node = node_q.front();

                if(cur_node)
                {
                    size++;
                    if(cur_node->left)
                        node_q.push(cur_node->left.get());
                    if(cur_node->right)
                        node_q.push(cur_node->right.get());
                }

                node_q.pop();
            }

            return size;
        }

        // This is meant to give the total number of nodes
        //unsigned size(void) const
        //{
        //    unsigned size = 0;

        //    std::queue<const std::unique_ptr<BinaryTreeNode<T>>*> node_q;
        //    node_q.push(&this->root);

        //    while(!node_q.empty())
        //    {
        //        //std::unique_ptr<BinaryTreeNode<T>> cur_node = std::move(node_q.front());
        //        auto cur_node = node_q.front();

        //        if(cur_node)
        //        {
        //            if((*cur_node)->left != nullptr)
        //                node_q.push(&(*cur_node)->left);
        //            if((*cur_node)->right != nullptr)
        //                node_q.push(&(*cur_node)->right);
        //        }

        //        node_q.pop();
        //    }

        //    return size;
        //}

        //// Just the height
        //unsigned height(void) const 
        //{
        //    unsigned height = 0;
        //    
        //    //std::queue<std::unique_ptr<BinaryTreeNode<T>>> node_q;
        //    std::queue<std::unique_ptr<BinaryTreeNode<T>>> node_q;
        //    node_q.push(std::move(this->root));

        //    while(!node_q.empty())
        //    {
        //        // remember how many nodes there are on this level
        //        unsigned level = node_q.size();
        //        for(unsigned i = 0; i < level; ++i)
        //        {
        //            //std::unique_ptr<BinaryTreeNode<T>> cur_node = std::move(node_q.front());
        //            std::unique_ptr<BinaryTreeNode<T>> cur_node = std::move(node_q.front());

        //            if(cur_node != nullptr)
        //            {
        //                if(cur_node->left != nullptr)
        //                    node_q.push(std::move(cur_node->left));
        //                if(cur_node->right != nullptr)
        //                    node_q.push(std::move(cur_node->right));
        //            }
        //            node_q.pop();
        //        }

        //        height++;
        //    }

        //    return height;
        //}

    public:
        // Putting this here to make the tree easier to inspect later
        std::unique_ptr<BinaryTreeNode<T>> root;

};



/*
 * TRAVERSALS ON BINARY TREES
 */


#endif /*__LC_BINARY_TREE_HPP*/
