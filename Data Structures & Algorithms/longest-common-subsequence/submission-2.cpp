class Solution {
public:
    int n, m;
    int longestCommonSubsequence(string text1, string text2) {
        n = text1.size();
        m = text2.size();
        vector<vector<int>>dp(n+1, vector<int>(m+1, -1));
        return helper(text1, text2, 0, 0, dp);
    }

    int helper(string text1, string text2, int i, int j, vector<vector<int>>&dp){
        if(i == n || j == m) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        if(text1[i] == text2[j]) return dp[i][j] = 1 + helper(text1, text2, i+1, j+1, dp);
        else{
            return dp[i][j] = max(helper(text1, text2, i+1, j, dp), helper(text1, text2, i, j+1, dp));
        }
    }
};
