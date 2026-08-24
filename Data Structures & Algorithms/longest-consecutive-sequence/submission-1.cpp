class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>s(nums.begin(), nums.end());
        int maxLength = 0;

        for(int it: nums){
            if(s.find(it-1) != s.end()) continue;

            int start = it;
            int count = 1;
            while(s.find(start+1) != s.end()){
                start++;
                count++;
            }
            maxLength = max(maxLength, count);
        }

        return maxLength;
    }
};
