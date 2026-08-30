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
    int maxDiam = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        depth(root);
        return maxDiam;
    }

    int depth(TreeNode* root){
        if(root == nullptr) return 0;

        int left = depth(root->left);
        int right = depth(root->right);
        maxDiam = max(maxDiam, left + right);

        return 1+max(left, right);
    }
};
