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

    void helper(TreeNode* root, int minVal, int maxVal){
        if(root == nullptr) return;

        if(!(root->val > minVal && root->val < maxVal)) result = false;

        helper(root->left, minVal, root->val);
        helper(root->right, root->val, maxVal); 
    }
};
