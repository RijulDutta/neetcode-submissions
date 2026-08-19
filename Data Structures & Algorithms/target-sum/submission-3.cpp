class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for(int it: nums){
            sum += it;
        }

        vector<vector<int>>dp(2*sum+1, vector<int>(nums.size(), -1));
        return helper(nums, target, 0, dp, sum);
    }

    int helper(vector<int>&nums, int target, int start, vector<vector<int>>&dp, int sum){
        if(target == 0 && start == nums.size()) return 1;
        else if(start == nums.size()) return 0;
        if(target > sum || target < -sum) return 0;
        if(dp[target+sum][start] != -1) return dp[target+sum][start];

        int c1 = helper(nums, target-nums[start], start+1, dp, sum);
        int c2 = helper(nums, target+nums[start], start+1, dp, sum);

        return dp[target+sum][start] = c1+c2; 
    }
};
