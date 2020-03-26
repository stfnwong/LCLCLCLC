/*
 * TREE
 * LeetCode tree stuff
 *
 * Stefan Wong 2019
 */

#ifndef __LC_TREE_HPP
#define __LC_TREE_HPP

#include <string>
#include <vector>

/*
 * TreeNode structure
 */
struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;

    public:
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

/*
 * tree_size()
 * Count the number of nodes in a tree
 */
int tree_size(const TreeNode* root);

// NOTE: see https://support.leetcode.com/hc/en-us/articles/360011883654-What-does-1-null-2-3-mean-in-binary-tree-representation- for details about how this representation works.

std::vector<std::string> repr_to_token_vec(const std::string& repr);
TreeNode* create_tree(const std::vector<std::string>& token_repr);
void      destroy_tree(TreeNode* tree);

// Convert a string like [1, 2, 3] into a Tree
std::string tree_to_repr(TreeNode* root);

// Convert a tree into a string like [1, 2,3]
TreeNode* repr_to_tree(const std::string& repr);



// ======== TRAVERSAL METHODS ======== //
// Recursive methods
void tree_preorder(const TreeNode* root, std::vector<int>& traversal);
void tree_inorder(const TreeNode* root, std::vector<int>& traversal);
void tree_outorder(const TreeNode* root, std::vector<int>& traversal);
void tree_postorder(const TreeNode* root, std::vector<int>& traversal);
void tree_levelorder(const TreeNode* root, std::vector<int>& traversal);

// Recursive methods with stacks
void tree_preorder_stack(const TreeNode* root, std::vector<int>& traversal);

// Iterative methods
void tree_preorder_iter(TreeNode* root, std::vector<int>& traversal);
void tree_inorder_iter(TreeNode* root, std::vector<int>& traversal);
void tree_outorder_iter(TreeNode* root, std::vector<int>& traversal);
void tree_postorder_iter(TreeNode* root, std::vector<int>& traversal);


/*
 * Traversal object
 */
struct ObjTraverser
{
    std::vector<int> traversal;

    private:
        // disable fancy constructors
        ObjTraverser(const ObjTraverser& that) = delete;
        ObjTraverser(const ObjTraverser&& that) = delete;

    public:
        ObjTraverser();
        void init(void);
        // traversals
        std::vector<int> preorder(const TreeNode* root);
        std::vector<int> inorder(const TreeNode* root);
        std::vector<int> outorder(const TreeNode* root);
        std::vector<int> postorder(const TreeNode* root);
};


#endif /*__LC_TREE_HPP*/
