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

    // Encodes a tree to a single string.
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
            q.push(node->left);   // node is guaranteed non-null here, push unconditionally
            q.push(node->right);
        }
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

        TreeNode* root = new TreeNode(stoi(vec[0]));
        queue<TreeNode*> q;
        q.push(root);

        int i = 1; // next token to read
        while (!q.empty() && i < (int)vec.size()) {
            TreeNode* node = q.front();
            q.pop();

            // left child
            if (i < (int)vec.size()) {
                if (vec[i] != "#") {
                    node->left = new TreeNode(stoi(vec[i]));
                    q.push(node->left);
                }
                i++;
            }

            // right child
            if (i < (int)vec.size()) {
                if (vec[i] != "#") {
                    node->right = new TreeNode(stoi(vec[i]));
                    q.push(node->right);
                }
                i++;
            }
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));