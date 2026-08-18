class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total_Sum = 0;
        for(int num: nums){
            total_Sum += num;
        }
        if(total_Sum % 2 != 0) return false;
        vector<vector<int>>dp(nums.size()+1, vector<int>(total_Sum/2+1 ,-1));
        return helper(nums, total_Sum/2, 0, dp);
    }

    bool helper(vector<int>&nums, int halfSum, int start, vector<vector<int>>&dp){
        if(halfSum == 0) return true;
        if(halfSum < 0) return false;
        if(start == nums.size()) return false;
        if(dp[start][halfSum] != -1) return dp[start][halfSum];

        bool skip = helper(nums, halfSum, start+1, dp);
        bool take = helper(nums, halfSum-nums[start], start+1, dp);

        return dp[start][halfSum] = skip || take;
    }
};
