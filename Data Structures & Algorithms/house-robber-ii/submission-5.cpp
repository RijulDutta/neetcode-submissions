class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];

        vector<int>dp1(n, -1);
        vector<int>dp2(n, -1);
        int startFirst = helper(nums, 0, n-2, dp1);
        int startSecond = helper(nums, 1, n-1, dp2);

        return max(startFirst, startSecond);
    }

    int helper(vector<int>&nums, int start, int end, vector<int>&dp){
        if(start > end) return 0;
        if(dp[start] != -1) return dp[start];

        int option1 = nums[start] + helper(nums, start+2, end, dp);
        int option2 = helper(nums,  start+1, end, dp);

        return dp[start] = max(option1, option2);
    }
};
