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

        int leftSum = max(0, helper(root->left));
        int rightSum = max(0, helper(root->right));

        maxSum = max(maxSum, root->val + leftSum + rightSum);

        return root->val + max(leftSum, rightSum);
    }
};
