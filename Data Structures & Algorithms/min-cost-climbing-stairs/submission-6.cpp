class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int>dp(n+1, -1);
        int c1 = helper(cost, 0, dp);
        int c2 = helper(cost, 1, dp);

        return min(c1, c2);
    }

    int helper(vector<int>&cost, int start, vector<int>&dp){
        if(start >= cost.size()) return 0;
        if(dp[start] != -1) return dp[start];

        int jump1 = cost[start] + helper(cost, start+1, dp);
        int jump2 = cost[start] + helper(cost, start+2, dp);

        return dp[start] = min(jump1, jump2);
    }
};
