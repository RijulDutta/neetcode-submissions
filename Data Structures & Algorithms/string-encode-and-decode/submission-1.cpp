class Solution {
public:

    string encode(vector<string>& strs) {
        string ans = "";
        for(int i=0; i<strs.size(); i++){
            ans += to_string(strs[i].size()) + "#" + strs[i];
        }
        return ans;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        int i = 0;

        while(i<s.size()){
            int j = i;
            while(s[j] != '#'){
                j++;
            }
            int len = stoi(s.substr(i, j - i));

            int start = j + 1;
            ans.push_back(s.substr(start, len));

            i = start + len;
        }
        return ans;
    }
};
