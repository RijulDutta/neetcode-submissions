class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>, vector<string>>mp;

        for(int i=0; i<strs.size(); i++){
            vector<int>vec(26, 0);
            for(char ch: strs[i]){
                vec[ch - 'a']++;
            }
            mp[vec].push_back(strs[i]);
        }

        vector<vector<string>>ans;
        for(auto it: mp){
            ans.push_back(it.second);
        }

        return ans;
    }
};
