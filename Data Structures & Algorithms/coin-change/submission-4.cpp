class Solution {
public:
    unordered_map<int, int>dp;
    int coinChange(vector<int>& coins, int amount) {
        int res = dfs(coins, amount);
        if(res >= 1e9) return -1;
        return res;
    }

    int dfs(vector<int>&coins, int amount){
        if(amount == 0) return 0;
        if(dp.find(amount) != dp.end()) return dp[amount]; 

        int res = INT_MAX;
        for(int coin: coins){
            if(amount - coin >= 0){
                int result = dfs(coins, amount-coin);
                if(result != INT_MAX){
                    res = min(res, 1+dfs(coins, amount-coin));
                }
            }
        }
        dp[amount] = res;
        return res;
    }
};
