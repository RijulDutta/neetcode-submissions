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
    int goodCount = 0;
    int goodNodes(TreeNode* root) {
        helper(root, INT_MIN);
        return goodCount;
    }

    void helper(TreeNode* root, int prevGreater){
        if(root == nullptr) return;
        if(root->val >= prevGreater) goodCount++;

        prevGreater = max(prevGreater, root->val);
        helper(root->left, prevGreater);
        helper(root->right, prevGreater);
    }
};
