class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size()+1, -1);
        return helper(nums, 0, dp);
    }

    int helper(vector<int>& nums, int curr, vector<int>&dp){
        if(curr >= nums.size()) return 0;
        if(dp[curr] != -1) return dp[curr];

        int option1 = nums[curr] + helper(nums, curr+2, dp);
        int option2 = helper(nums, curr+1, dp);

        return dp[curr] = max(option1, option2);
    }
};
