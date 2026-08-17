class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if(n == 0) return "";

        int bestLen = 1;
        int bestStart = 0; 

        vector<vector<int>>dp(n, vector<int>(n, -1));

        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                if(isPalindrome(s, i, j, dp)){
                    if(j-i+1 > bestLen){
                        bestLen = j-i+1;
                        bestStart = i;
                    }
                }
            }
        }

        return s.substr(bestStart, bestLen);
    }

    bool isPalindrome(string&s, int left, int right, vector<vector<int>>&dp){
        if(left >= right) return true;
        if(dp[left][right] != -1) return dp[left][right];
        if(s[left] != s[right]) return false;
        return dp[left][right] = isPalindrome(s, left+1, right-1, dp);
    }
};
