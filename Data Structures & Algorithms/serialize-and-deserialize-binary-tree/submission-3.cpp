#include <string>
#include <vector>
#include <queue>
using namespace std;

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
    string serialize(TreeNode* root) {
        if (!root) return "";

        string ans = "";
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (node == nullptr) {
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
        if (data.empty()) return nullptr;

        vector<string> vec;
        int start = 0;
        for (int i = 0; i < data.size(); i++) {
            if (data[i] == ' ') {
                vec.push_back(data.substr(start, i - start));
                start = i + 1;
            }
        }

        if (vec.empty() || vec[0] == "#") return nullptr;

        queue<TreeNode*> q;
        int i=0;
        TreeNode* root = new TreeNode(stoi(vec[i++]));
        q.push(root);

        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop(); 
            if(vec[i] != "#"){
                TreeNode* newNode = new TreeNode(stoi(vec[i]));
                q.push(newNode);
                node->left = newNode;
            } else{
                node->left = nullptr;
            }
            i++;

            if(vec[i] != "#"){
                TreeNode* newNode = new TreeNode(stoi(vec[i]));
                q.push(newNode);
                node->right = newNode;
            } else{
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