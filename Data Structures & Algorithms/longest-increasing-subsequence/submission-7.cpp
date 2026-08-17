class Solution {
public:
    int n;
    int lengthOfLIS(vector<int>& nums) {
        n = nums.size();
        vector<vector<int>>dp(n+1, vector<int>(n+1, -1));
        return helper(nums, -1, 0, dp);
    }

    int helper(vector<int>&nums, int lastMaxIndex, int start, vector<vector<int>>&dp){
        if(start == n) return 0;
        int idx = lastMaxIndex+1;
        if(dp[start][idx] != -1) return dp[start][idx];

        int c1 = helper(nums, lastMaxIndex, start+1, dp);
        int c2;
        if(lastMaxIndex == -1 || nums[start] > nums[lastMaxIndex]) c2 = 1 + helper(nums, start, start+1, dp);
        
        return dp[start][idx] = max(c1, c2);
    }
};
