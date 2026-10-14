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

            if(curr){
                ans += to_string(curr->val) + ' ';
                q.push(curr->left);
                q.push(curr->right);
            }
            else ans += "# ";
        }
        cout<<ans<<endl;
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data == "") return nullptr;

        vector<string>vec;
        int start = 0;
        for(int i=0; i<data.size(); i++){
            if(data[i] == ' '){
                vec.push_back(data.substr(start, i-start));
                start = i+1;
            }
        }

        if(vec[0] == "#") return nullptr;

        queue<TreeNode*> q;
        int i=0;
        TreeNode* root = new TreeNode(stoi(vec[i++]));
        q.push(root);

        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();

            //Left Child
            if(vec[i] != "#"){
                node->left = new TreeNode(stoi(vec[i]));
                q.push(node->left);
            }else{
                node->left = nullptr;
            }
            i++;

            //Right Child
            if(vec[i] != "#"){
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
