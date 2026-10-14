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
    int maxPathSum(TreeNode* root){
        getMaxSum(root);
        return maxSum;
    }

    int getMaxSum(TreeNode* root) {
        if(root == nullptr) return 0;

        int left = getMaxSum(root->left);
        int right = getMaxSum(root->right);

        left = (left<0)? 0:left;
        right = (right<0)? 0:right;

        maxSum = max(maxSum, left+right+root->val);

        return root->val + max(left, right); 
    }
};
