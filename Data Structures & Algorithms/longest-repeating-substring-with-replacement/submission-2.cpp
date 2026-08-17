class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> mp;
        int left = 0;
        int maxFreq = 0;
        int longest = 0;

        for(int right = 0; right < s.size(); right++){
            mp[s[right]]++;
            maxFreq = max(maxFreq, mp[s[right]]);

            int windowLen = right - left + 1;
            if(windowLen - maxFreq > k){
                mp[s[left]]--;
                left++;
                maxFreq = 0;
                for(auto it: mp){
                    maxFreq = max(maxFreq, it.second);
                }
            }

            longest = max(longest, right - left + 1);
        }
        return longest;
    }
};