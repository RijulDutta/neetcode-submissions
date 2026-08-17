/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans = "";
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(node == nullptr){
                ans += "# ";
                continue;
            }

            ans += to_string(node->val) + " ";
            q.push(node->left);
            q.push(node->right);
        }
        cout<<ans<<endl;
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int start = 0;
        vector<string> vec;
        for(int i=0; i<data.size(); i++){
            if(data[i] == ' '){
                vec.push_back(data.substr(start, i-start));
                start = i+1;
            }
        }

        if(vec[0] == "#") return nullptr;

        queue<TreeNode*> q;
        int i = 0;
        TreeNode* root = new TreeNode(stoi(vec[i++]));
        q.push(root);

        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();

            if(vec[i] != "#"){
                TreeNode* newNode = new TreeNode(stoi(vec[i]));
                q.push(newNode);
                node->left = newNode;
            }else{
                node->left = nullptr;
            }
            i++;

            if(vec[i] != "#"){
                TreeNode* newNode = new TreeNode(stoi(vec[i]));
                q.push(newNode);
                node->right = newNode;
            }else{
                node->right = nullptr;
            }
            i++;
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));