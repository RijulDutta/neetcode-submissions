class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int size = s.size();

        int left = 0;
        int longest = 0;

        vector<int>hash_map(128, 0);

        for(int right=0; right<size; right++){
            while(hash_map[s[right]] > 0){
                hash_map[s[left]]--;
                left++;
            }
            hash_map[s[right]]++;
            longest = max(longest, right-left+1);
        } 

        return longest;
    }
};
