/*
 * TRAVERSE A TREE
 * Basic stuff that I hope I know from LeetCode explore
 *
 * Stefan Wong 2019
 */

#include <vector>

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


// Apparently, this requires 10.9MB (!!!) of memory
//class Solution {
//    public:
//        std::vector<int> preorderTraversal(TreeNode* root) {
//
//            vector<int> values;
//            vector<int> out_values;
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
//

