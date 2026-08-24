class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int>mp;
        int maj = 0;
        int maxi = 0;
        int left = 0;

        for(int right = 0; right<s.size(); right++){
            mp[s[right]]++;
            maj = max(maj, mp[s[right]]);
            
            while(right-left+1 - maj > k){
                mp[s[left]]--;
                left++;
                maj = 0;
                for(auto it: mp){
                    maj = max(maj, it.second);
                }
            }
            maxi = max(maxi, right-left+1);
        }
        return maxi;
    }
};
