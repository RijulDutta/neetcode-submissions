class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>>mp;

        for(int i=0; i<strs.size(); i++){
            string s(26, '0');
            for(char ch: strs[i]){
                s[ch-'a'] = (s[ch-'a'] - '0')+1;
            }
            mp[s].push_back(strs[i]);
        }

        vector<vector<string>>ans;
        for(auto it: mp){
            ans.push_back(it.second);
        }

        return ans;
    }
};
