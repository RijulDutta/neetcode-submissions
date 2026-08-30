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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans = "";
        if(root == nullptr) return ans;

        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();
            if(curr == nullptr){
                ans += "# ";
                continue;
            }
            ans += to_string(curr->val) + " ";
            q.push(curr->left);
            q.push(curr->right);
        }
        cout<<ans;
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty()) return nullptr;
        int start = 0;
        vector<string> vec;
        for(int i=0; i<data.size(); i++){
            if(data[i] != ' ') continue;
            vec.push_back(data.substr(start, i-start));
            start = i+1;
        }
    

        if(vec[0] == "#") return nullptr;

        queue<TreeNode*> q;
        int i = 0;
        TreeNode* root = new TreeNode(stoi(vec[i++]));
        q.push(root);

        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();

            if(vec[i] != "#") {
                node->left = new TreeNode(stoi(vec[i]));
                q.push(node->left);
            }else{
                node->left = nullptr;
            }
            i++;

            if(vec[i] != "#") {
                node->right = new TreeNode(stoi(vec[i]));
                q.push(node->right);
            }else{
                node->right = nullptr;
            }
            i++;
        }

        return root;
    }
};
