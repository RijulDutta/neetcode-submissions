class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>>dp(2, vector<int>(prices.size()+1, -1));
        return helper(prices, 0, false, dp);
    }

    int helper(vector<int>& prices, int start, bool holding, vector<vector<int>>&dp){
        if(start >= prices.size()) return 0;
        if(dp[holding][start] != -1) return dp[holding][start];

        int c1 = helper(prices, start+1, holding, dp); 

        int c2 = 0;
        if(holding){
            c2 += prices[start];                      
            c2 += helper(prices, start+2, false, dp);
        } else {
            c2 -= prices[start];                       
            c2 += helper(prices, start+1, true, dp);
        }

        return dp[holding][start] = max(c1, c2);
    }
};