class Solution {
public:
    string longestPalindrome(string s) {
        vector<vector<int>>dp(s.size(), vector<int>(s.size(), -1));

        int maxLen = -1;
        int start = -1;
        for(int i=0; i<s.size(); i++){
            for(int j=i; j<s.size(); j++){
                if(isPalindrome(s, i, j, dp)){
                    int len = j-i+1;
                    if(len > maxLen){
                        start = i;
                        maxLen = len;
                    }
                }
            }
        }
        return s.substr(start, maxLen);
    }

    int isPalindrome(string&s, int start, int end, vector<vector<int>>&dp){
        if(start >= end) return 1;
        if(s[start] != s[end]) return 0;

        if(dp[start][end] != -1) return dp[start][end]; 

        return dp[start][end] = isPalindrome(s, start+1, end-1, dp);
    }
};
