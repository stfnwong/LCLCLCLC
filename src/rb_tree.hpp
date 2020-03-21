/*
 * RB_TREE
 * Implementation of a Red/Black Tree
 *
 * Stefan Wong 2020
 */

#ifndef __LC_RB_TREE_HPP
#define __LC_RB_TREE_HPP

#include <string>
#include <vector>

enum rb_color{red, black};

std::string rb_color_to_string(const rb_color col);

// TODO : template this rather than use a void*
/*
 * RedBlackNode
 * Single node in an RBTree
 */
struct RedBlackNode
{
    rb_color      color;
    void*         item;
    RedBlackNode* left;
    RedBlackNode* right;
    RedBlackNode* parent;

    public:
        RedBlackNode();
        //~RedBlackNode();

        std::string toString(void) const;
};



/*
 * RedBlackTree
 */
class RedBlackTree
{
    RedBlackNode*             root;
    std::vector<RedBlackNode> nodes;

    public:
        RedBlackTree();

        unsigned int getBlackHeight(void) const;
        void         leftRotate(RedBlackNode* node);

        std::string toString(void) const;
};


#endif /*__LC_RB_TREE_HPP*/
