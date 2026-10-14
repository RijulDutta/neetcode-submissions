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
        int n = preorder.size();
        return buildTree(preorder, 0, n-1, inorder, 0, n-1);
    }

    TreeNode* buildTree(vector<int>& preorder, int pstart, int pend, vector<int>& inorder, int istart, int iend){
        if(pstart > pend || istart > iend) return nullptr;

        int val = preorder[pstart];
        TreeNode* newNode = new TreeNode(val);

        int i_ref;
        int count = 0;
        for(int i=istart; i<=iend; i++){
            if(inorder[i] == val){
                i_ref = i;
                break; 
            }
            count++;
        }

        newNode->left = buildTree(preorder, pstart+1, pend+count, inorder, istart, i_ref-1);
        newNode->right = buildTree(preorder, pstart+count+1, pend, inorder, i_ref+1, iend);

        return newNode;
    }
};
