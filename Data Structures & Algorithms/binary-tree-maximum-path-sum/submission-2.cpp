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
    int maxSum = INT_MIN;
    int maxPathSum(TreeNode* root) {
        helper(root);
        return maxSum;
    }

    int helper(TreeNode* root){
        if(root == nullptr) return 0;

        int lSum = 0;
        int rSum = 0;

        if(root->left) lSum = helper(root->left);
        lSum = (lSum>=0)? lSum: 0;
        if(root->right) rSum = helper(root->right);
        rSum = (rSum>=0)? rSum: 0;
        

        maxSum = max(maxSum, root->val + lSum + rSum);

        return root->val + max(lSum, rSum);
    }
};
