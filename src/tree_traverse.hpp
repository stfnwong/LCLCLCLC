/*
 * TREE_TRAVERSE
 * Stuff for traversing trees
 *
 */

#ifndef __LC_TREE_TRAVERSE
#define __LC_TREE_TRAVERSE

#include <vector>
#include "tree.hpp"


// Recursive methods
void tree_preorder(const TreeNode* root, std::vector<int>& traversal);
void tree_inorder(const TreeNode* root, std::vector<int>& traversal);
void tree_outorder(const TreeNode* root, std::vector<int>& traversal);
void tree_postorder(const TreeNode* root, std::vector<int>& traversal);

// Iterative methods



// ====== LC Style methods ===== /
struct LCTraverser
{
    std::vector<int> traversal;

    private:
        // disable fancy constructors
        LCTraverser(const LCTraverser& that) = delete;
        LCTraverser(const LCTraverser&& that) = delete;

    public:
        LCTraverser();
        void init(void);
        // traversals
        std::vector<int> preorder(const TreeNode* root);
        std::vector<int> inorder(const TreeNode* root);
        std::vector<int> outorder(const TreeNode* root);
        std::vector<int> postorder(const TreeNode* root);
};


#endif /*__LC_TREE_TRAVERSE*/
