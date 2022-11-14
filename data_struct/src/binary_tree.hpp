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
 * Binary Tree Node with left and right pointers
 * In reality this should be a private structure of the BinaryTree class 
 * as its strictly speaking an implementation detail.
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
    public:
        BinaryTree() : root(nullptr) {}         // this->root should == nullptr
        explicit BinaryTree(const T& val) :
            root(std::make_unique<BinaryTreeNode<T>>(val)) {}
        // TODO: destructor ? 

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

        //// Just the height
        unsigned height(void) const 
        {
            unsigned height = 0;

            if(!this->root)
                return height;
            
            std::queue<BinaryTreeNode<T>*> node_q;
            node_q.push(this->root.get());

            while(!node_q.empty())
            {
                // remember how many nodes there are on this level
                unsigned level = node_q.size();
                for(unsigned i = 0; i < level; ++i)
                {
                    auto cur_node = std::move(node_q.front());

                    if(cur_node)
                    {
                        if(cur_node->left != nullptr)
                            node_q.push(cur_node->left.get());
                        if(cur_node->right != nullptr)
                            node_q.push(cur_node->right.get());
                    }
                    node_q.pop();
                }

                height++;
            }

            return height;
        }

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

        void remove_one_node(std::unique_ptr<BinaryTreeNode<T>>& delete_me)
        {
            // this is a leaf or has only one child
            if(!delete_me->left)
                delete_me = std::move(delete_me->right);
            else if(!delete_me->right)
                delete_me = std::move(delete_me->left);
            else
                delete_me->value = this->find_ancestor(delete_me->right);

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

    // The actual data
    std::unique_ptr<BinaryTreeNode<T>> root;

};

/*
 * CREATE BINARY TREES
 */
// Convert a string to a vector of tokens
std::vector<std::string> repr_tokenize(const std::string& repr);

// For this its fine to just have a int specialization
BinaryTree<int> repr_to_tree(const std::vector<std::string>& token_vec);
BinaryTree<int> create_tree_from_repr(const std::string& repr);

/*
 * TRAVERSALS ON BINARY TREES
 */





/*
 * BALANCED BINARY TREE
 * Implemented with an array
 */
template <typename T> struct BalancedBinaryTree
{
    struct BalancedBinaryTreeNode
    {
        BalancedBinaryTreeNode(const T& v) : value(v) {} 

        T value;
    };

    unsigned left_child(unsigned idx) 
    {
        return 2 * idx + 1;
    }
    unsigned right_child(unsigned idx)
    {
        return 2 * idx + 2;
    }


    //std::vector<BalancedBinaryTreeNode*> children;
    std::vector<std::unique_ptr<BalancedBinaryTreeNode>> children;

    public:
        BalancedBinaryTree() {} 

        // For this I will push to back and then heapify from the bottom up
        void insert(const T& v)
        {
            this->children.push_back(
                    std::make_unique<BalancedBinaryTreeNode>(v)
            );
            // ensure that the resulting tree is balanced
        }



};



#endif /*__LC_BINARY_TREE_HPP*/
