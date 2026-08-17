class Solution {
public:
    int n;
    int numDecodings(string s) {
        n = s.size();
        vector<int>dp(n+1, -1);
        return helper(s, 0, dp);
    }

    int helper(string&s, int start, vector<int>&dp){
        if(dp[start] != -1) return dp[start];
        if(start == n) return 1;
        if(s[start] == '0') return 0;

        int temp = helper(s, start+1, dp);
        if(start+1 < n){
            if(s[start] == '1' || s[start] == '2' && s[start+1] <= '6'){
                temp += helper(s, start+2, dp);
            }
        }

        return dp[start] = temp;
    }
};
