class Solution {
public:
    int size;
    int minCostClimbingStairs(vector<int>& cost) {
        size = cost.size();
        vector<int>dp(size+1, -1);

        int cost1 = f(cost, 0, dp);
        int cost2 = f(cost, 1, dp);

        return min(cost1, cost2);      
    }

    int f(vector<int>&cost, int start, vector<int>&dp){
        if(start >= size) return 0;

        if(dp[start] != -1) return dp[start];

        int jump1 = cost[start] + f(cost, start+1, dp);
        int jump2 = cost[start] + f(cost, start+2, dp);

        return dp[start] = min(jump1, jump2);
    }
};
