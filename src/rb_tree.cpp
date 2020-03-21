/*
 * RB_TREE
 * Implementation of a Red/Black Tree
 *
 * Stefan Wong 2020
 */

#include <iomanip>
#include <iostream>
#include <sstream>
#include "rb_tree.hpp"

std::string rb_color_to_string(const rb_color col)
{
    if(col == rb_color::red)
        return "red";
    else if(col == rb_color::black)
        return "black";
    else
        return "unknown";
}

/*
 * RedBlackNode
 */
RedBlackNode::RedBlackNode() : 
    color(rb_color::black),
    item(nullptr),
    left(nullptr),
    right(nullptr),
    parent(nullptr)
{}


std::string RedBlackNode::toString(void) const
{
    std::ostringstream oss;

    oss << "RedBlackNode [" << rb_color_to_string(this->color) << "]";

    return oss.str();
}


/*
 * Red/Black Tree
 */

RedBlackTree::RedBlackTree() {} 


// TODO : test this, then implement right rotate
void RedBlackTree::leftRotate(RedBlackNode* node)
{
    RedBlackNode* y;

    y = node->right;
    // turn y's left subtree into the target node right subtree
    node->right = y->left;
    if(y->left != nullptr)
        y->left->parent = node;

    // y's new parent was node->parent
    y->parent = node->parent;

    // Set the parent to point to y instead of node
    // Check if we are at the root
    if(node->parent == nullptr)
        this->root = y;
    else
    {
        // check if node was on the left of its parent
        if(node == (node->parent)->left)
            node->parent->left = y;
        else    // must have been on the right
            node->parent->right = y;
    }
    // Finally, put node on y's left 
    y->left = node;
    node->parent = y;
}
