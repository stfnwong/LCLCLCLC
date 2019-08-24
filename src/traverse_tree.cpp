/*
 * TRAVERSE A TREE
 * Basic stuff that I hope I know from LeetCode explore
 *
 * Stefan Wong 2019
 */

#include <vector>
#include "tree.hpp"


// Apparently, this requires 10.9MB (!!!) of memory
class Solution {
    public:
        std::vector<int> preorderTraversal(TreeNode* root) {

            std::vector<int> values;
            std::vector<int> out_values;
            
            if(root == NULL)
                return values;
            
            values.push_back(root->val);
            if(root->left != NULL)
            {
                out_values = preorderTraversal(root->left);
                values.insert(values.end(), out_values.begin(), out_values.end());
            }
            if(root->right != NULL)
            {
                out_values = preorderTraversal(root->right);
                values.insert(values.end(), out_values.begin(), out_values.end());
            }
            return values;
        }
};


// Since I don't have access to the real LC test harness I will just write something myself that does a similar thing
