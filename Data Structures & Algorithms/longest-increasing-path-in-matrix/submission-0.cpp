class Solution {
public:
    int row;
    int col;
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int ans = 0;
        row = matrix.size();
        col = matrix[0].size();
        vector<vector<int>>dp(row, vector<int>(col, -1));
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                ans = max(ans, helper(matrix, -1, i, j, dp));
            }
        }

        return ans;
    }

    int helper(vector<vector<int>>& matrix, int prevValue, int i, int j, vector<vector<int>>&dp){
        if(i < 0 || j < 0 || i>=row || j>=col) return 0;
        if(matrix[i][j] <= prevValue) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        int c1 = 1 + helper(matrix, matrix[i][j], i+1, j, dp);
        int c2 = 1 + helper(matrix, matrix[i][j], i, j+1, dp);
        int c3 = 1 + helper(matrix, matrix[i][j], i-1, j, dp);
        int c4 = 1 + helper(matrix, matrix[i][j], i, j-1, dp);

        return dp[i][j] = max(c1, max(c2, max(c3, c4)));
    }
};
