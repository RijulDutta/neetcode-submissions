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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size() == 0 && inorder.size() == 0) return nullptr;

        int rootVal = preorder[0];

        int i;
        for(i=0; i<inorder.size(); i++){
            if(rootVal == inorder[i]){
                break;
            }
        }

        vector<int> l_in(inorder.begin(), inorder.begin()+i);
        vector<int> r_in(inorder.begin()+i+1, inorder.end()); 
        vector<int> l_pre(preorder.begin()+1, preorder.begin()+i+1);
        vector<int> r_pre(preorder.begin()+i+1, preorder.end());

        TreeNode* root = new TreeNode(rootVal);

        root->left = buildTree(l_pre, l_in);
        root->right = buildTree(r_pre, r_in);

        return root;
    }
};
