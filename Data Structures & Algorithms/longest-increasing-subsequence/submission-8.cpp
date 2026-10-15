class Solution {
public:
    int n;
    int lengthOfLIS(vector<int>& nums) {
        n = nums.size();
        vector<vector<int>>dp(n+1, vector<int>(n+1, -1));
        return helper(nums, 0, -1, dp);
    }

    int helper(vector<int>& nums, int start, int lastMaxIndex, vector<vector<int>>&dp){
        if(start >= nums.size()) return 0;
        if(dp[start][lastMaxIndex+1] != -1) return dp[start][lastMaxIndex+1];

        int c1 = helper(nums, start+1, lastMaxIndex, dp);
        int c2;
        if(lastMaxIndex == -1 || nums[start] > nums[lastMaxIndex]){
            c2 = 1 + helper(nums, start+1, start, dp);
        }

        return dp[start][lastMaxIndex+1] = max(c1, c2);
    }
};
