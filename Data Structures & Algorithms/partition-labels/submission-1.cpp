class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int>ans;
        unordered_map<char, int>mp;

        for(int i=0; i<s.size(); i++){
            mp[s[i]] = i;
        }

        int size = 0;
        int end = 0;

        for(int i=0; i<s.size(); i++){
            end = max(end, mp[s[i]]);
            size++;
            if(i == end){
                ans.push_back(size);
                size = 0;
            }
        }

        return ans;
    }
};
