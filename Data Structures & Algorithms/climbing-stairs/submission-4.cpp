class Solution {
public:
    int climbStairs(int n) {
        vector<int>dp(n+1, -1);
        return helper(n, 0, dp);
    }

    int helper(int n, int start, vector<int>&dp){
        if(start == n) return 1;
        if(start > n) return 0;
        if(dp[start] != -1) return dp[start];

        return dp[start] = (helper(n, start+1, dp) + helper(n, start+2, dp));
    }
};
