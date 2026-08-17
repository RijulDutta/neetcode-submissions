class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size(), -1);
        return helper(nums, dp, 0);
    }

    int helper(vector<int>& nums, vector<int>&dp, int start){
        if(start >= nums.size()) return 0;
        if(start == nums.size()-1) return nums[start];

        if(dp[start] != -1) return dp[start];

        return dp[start] = max(nums[start]+helper(nums, dp, start+2), helper(nums, dp, start+1));
    }
};
