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
    bool flag = true;
    bool isBalanced(TreeNode* root) {
        getDepth(root);
        return flag;
    }

    int getDepth(TreeNode* root){
        if(root == nullptr) return 0;

        int l = getDepth(root->left);
        int r = getDepth(root->right);

        if(abs(l-r) > 1){
            flag = false;
            return -1;
        }

        return 1 + max(getDepth(root->left), getDepth(root->right));
    }
};
