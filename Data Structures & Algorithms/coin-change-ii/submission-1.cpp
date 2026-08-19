class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>>dp(amount+1, vector<int>(coins.size(), -1));
        return helper(coins, amount, 0, dp);
    }

    int helper(vector<int>&coins, int amount, int start, vector<vector<int>>&dp){
        if(amount == 0) return 1;
        if(amount < 0) return 0;
        if(start == coins.size()) return 0;
        if(dp[amount][start] != -1) return dp[amount][start];

        int c1 = helper(coins, amount, start+1, dp);
        int c2 = helper(coins, amount-coins[start], start, dp);
        
        return dp[amount][start] = c1+c2;
    }
};
