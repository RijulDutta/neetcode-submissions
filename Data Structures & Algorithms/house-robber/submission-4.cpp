class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size(), -1);
        return f(nums, 0, dp);
    }
    
    int f(vector<int>&nums, int start, vector<int>&dp){
        if(start >= nums.size()) return 0;

        if(dp[start] != -1) return dp[start];

        return dp[start] = max(nums[start] + f(nums, start+2, dp), f(nums, start+1, dp));
    }
};
