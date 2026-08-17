class Solution {
public:
    int size;
    int minCostClimbingStairs(vector<int>& cost) {
        size = cost.size();
        vector<int>dp(size+2, 0);

        for(int i=size-1; i>=0; i--){
            dp[i] =  min((cost[i] + dp[i+1]), (cost[i] + dp[i+2]));  
        }     

        return min(dp[0], dp[1]);
    }
};
