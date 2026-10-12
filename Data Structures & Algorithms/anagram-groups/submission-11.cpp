class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>>mp;

        for(auto it: strs){
            string key(26, '0');

            for(char c: it){
                key[c - 'a']++;
            }

            mp[key].push_back(it);
        }

        vector<vector<string>>ans;
        for(auto it: mp){
            ans.push_back(it.second);
        }

        return ans;
    }
};
