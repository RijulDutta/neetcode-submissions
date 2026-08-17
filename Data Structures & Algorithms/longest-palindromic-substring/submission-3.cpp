class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));

        int start = 0, maxLen = 1;

        // Every single character is a palindrome of length 1
        for(int i = 0; i < n; i++) dp[i][i] = true;

        // Build up by substring length (2, 3, 4, ...)
        for(int len = 2; len <= n; len++){
            for(int i = 0; i + len - 1 < n; i++){
                int j = i + len - 1;

                if(s[i] == s[j]){
                    // length 2 needs no "inner" check; else check dp[i+1][j-1]
                    if(len == 2 || dp[i+1][j-1]){
                        dp[i][j] = true;
                        if(len > maxLen){
                            start = i;
                            maxLen = len;
                        }
                    }
                }
            }
        }

        return s.substr(start, maxLen);
    }
};