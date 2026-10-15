class Solution {
public:
    int climbStairs(int n) {
        vector<int>dp(n+1, -1);
        return helper(n, 0, dp);
    }

    int helper(int n, int curr, vector<int>&dp){
        if(curr == n) return 1;
        if(curr > n) return 0;
        if(dp[curr] != -1) return dp[curr];

        return dp[curr] = helper(n, curr+1, dp) + helper(n, curr+2, dp);
    }
};
