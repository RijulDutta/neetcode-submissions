class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int count = 0;
        vector<vector<int>>dp(n+1, vector<int>(n+1, -1));
        for(int i=0; i<s.size(); i++){
            for(int j=i; j<s.size(); j++){
                if(isPalindrome(s, i, j, dp)){
                    count++;
                }
            }
        }
        return count;
    }

    bool isPalindrome(string&s, int i, int j, vector<vector<int>>&dp){
        if(i >= j) return true;
        if(s[i] != s[j]) return false;
        if(dp[i][j] != -1) return dp[i][j];

        return dp[i][j] = isPalindrome(s, i+1, j-1, dp);
    }
};
