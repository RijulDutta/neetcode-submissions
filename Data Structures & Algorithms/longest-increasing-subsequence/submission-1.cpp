class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n+1, vector<int>(n+1, -1));
        return getSize(nums, 0, -1, dp);
    }

    int getSize(vector<int>&nums, int start, int prevIdx, vector<vector<int>>&dp){
        if(start == nums.size()) return 0;
        if(dp[start][prevIdx+1] != -1) return dp[start][prevIdx+1];

        int skip = getSize(nums, start+1, prevIdx, dp);
        int take = 0;
        if(prevIdx == -1 || nums[start] > nums[prevIdx]){
            take += 1 + getSize(nums, start+1, start, dp);
        }
        return dp[start][prevIdx+1] = max(skip, take);
    }
};
