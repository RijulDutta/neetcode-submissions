/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    bool result = true;
    bool isValidBST(TreeNode* root) {
        helper(root, INT_MIN, INT_MAX);
        return result;
    }

    void helper(TreeNode* root, int lower, int higher){
        if(root == nullptr) return;

        if(root->val <= lower || root->val >= higher) result &= false;

        if(!result) return;
        if(root->left) helper(root->left, lower, root->val); 
        if(root->right) helper(root->right, root->val, higher);
    }
};
