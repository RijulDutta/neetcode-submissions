class Solution {
public:
    int n;
    int rob(vector<int>& nums) {
        n = nums.size();
        vector<int>dp(n+1, -1);
        return helper(nums, 0, dp);
    }

    int helper(vector<int>&nums, int start, vector<int>&dp){
        if(start >= n) return 0;
        if(dp[start] != -1) return dp[start];

        int option1 = nums[start] + helper(nums, start+2, dp);
        int option2 = helper(nums, start+1, dp);

        return dp[start] = max(option1, option2);
    }
};
