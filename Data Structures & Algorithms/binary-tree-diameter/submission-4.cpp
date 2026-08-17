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
    int diameter = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        depth(root);
        return diameter;
    }

    int depth(TreeNode* root){
        if(root == nullptr) return 0;

        int left = depth(root->left);
        int right = depth(root->right);

        diameter = max(diameter, left + right);

        return 1+max(left, right);
    }
};
