class Solution {
public:
    int n;
    int numDecodings(string s) {
        n = s.size();
        vector<int>dp(n+1, -1);
        return helper(s, 0, dp);
    }

    int helper(string& s, int curr, vector<int>&dp){
        if(curr >= n) return 1;
        if(s[curr] == '0') return 0; 
        if(dp[curr] != -1) return dp[curr];

        int c1 = helper(s, curr+1, dp);
        int c2=0;
        if(curr+1 < n){
            if(s[curr] == '1' || (s[curr] == '2' && s[curr+1] <= '6')) c2 = helper(s, curr+2, dp); 
        }

        return dp[curr] =  c1+c2;
    }
};
