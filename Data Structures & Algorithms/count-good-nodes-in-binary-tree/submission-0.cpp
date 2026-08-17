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
    int goodNodeCount = 0;
    int goodNodes(TreeNode* root) {
        helper(root, INT_MIN);
        return goodNodeCount;
    }

    void helper(TreeNode* root, int maxVal){
        if(root == nullptr) return;

        if(root->val >= maxVal) {
            maxVal = root->val;
            goodNodeCount++;
        }

        helper(root->left, maxVal);
        helper(root->right, maxVal);
    }
};
