class Solution {
public:
    // unordered_map<int, int>dp;
    // int coinChange(vector<int>& coins, int amount) {
    //     dp[0] = 0;
    //     int res = dfs(coins, amount);
    //     if(res >= 1e9) return -1;
    //     return res;
    // }

    // int dfs(vector<int>&coins, int amount){
    //     if(amount == 0) return 0;
    //     if(dp.find(amount) != dp.end()) return dp[amount]; 

    //     int res = INT_MAX;
    //     for(int coin: coins){
    //         if(amount - coin >= 0){
    //             int result = dfs(coins, amount-coin);
    //             if(result != INT_MAX){
    //                 res = min(res, 1+result);
    //             }
    //         }
    //     }
    //     dp[amount] = res;
    //     return res;
    // }

    int coinChange(vector<int>&coins, int amount){
        vector<int>dp(amount+1, amount+1);
        dp[0] = 0;

        for(int a=1; a<=amount; a++){
            for(int coin: coins){
                if(a-coin >= 0){
                    dp[a] = min(dp[a], 1+dp[a-coin]);
                }
            }
        }
        return dp[amount] > amount ? -1: dp[amount];
    }
};
