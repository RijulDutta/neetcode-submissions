class Solution {
public:
    int m;
    int n;
    int uniquePaths(int m, int n) {
        this->m = m;
        this->n = n;
        vector<vector<int>>dp(m, vector<int>(n, -1));

        return helper(0, 0, dp);
    }

    int helper(int i, int j, vector<vector<int>>&dp){
        if(i == m-1 && j == n-1) return 1;
        if(i >= m || j >= n) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        return  dp[i][j] = helper(i+1, j, dp) + helper(i, j+1, dp);
    }
};
