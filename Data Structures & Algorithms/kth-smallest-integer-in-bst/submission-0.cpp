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
    priority_queue<int> pq;
    int k;
    int kthSmallest(TreeNode* root, int k) {
        this->k = k;
        helper(root);
        return pq.top();
    }

    void helper(TreeNode* root){
        if(root == nullptr) return;

        helper(root->left);
        pq.push(root->val);
        if(pq.size() > k){
            pq.pop();
        }
        helper(root->right);
    }
};
