class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> vec;
        map<vector<int>, vector<string>> mp;

        for(int i=0; i<strs.size(); i++)
        {
            vector<int> key(26, 0);
            for(int j=0; j<strs[i].size(); j++)
            {
                key[strs[i][j] - 'a']++;
            }

            mp[key].push_back(strs[i]);
        }

        for(auto it : mp)
            vec.push_back(it.second);

        return vec;
    }
};
