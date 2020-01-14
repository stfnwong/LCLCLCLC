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

