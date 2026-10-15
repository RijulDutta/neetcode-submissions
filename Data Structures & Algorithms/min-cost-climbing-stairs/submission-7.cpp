class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int>dp(cost.size()+1, -1);
        int c1 = helper(cost, 0, dp);
        int c2 = helper(cost, 1, dp);

        return min(c1, c2);
    }

    int helper(vector<int>& cost, int curr, vector<int>&dp){
        if(curr >= cost.size()) return 0;
        if(dp[curr] != -1) return dp[curr];

        int c1 = helper(cost, curr+1, dp);
        int c2 = helper(cost, curr+2, dp);

        return dp[curr] = cost[curr] + min(c1, c2);
    }
};
