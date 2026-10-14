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
        getDepth(root);
        return diameter;   
    }

    int getDepth(TreeNode* root){
        if(root == nullptr) return 0;

        int l = getDepth(root->left);
        int r = getDepth(root->right);
        diameter = max(diameter, l+r);

        return 1 + max(l, r);
    }
};
