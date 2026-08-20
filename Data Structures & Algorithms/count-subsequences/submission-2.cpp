class Solution {
public:
    int numDistinct(string s, string t) {
        vector<vector<int>>dp(s.size(), vector<int>(t.size(), -1));
        return helper(s, t, 0, 0, dp);
    }

    int helper(string s, string t, int s_ptr, int t_ptr, vector<vector<int>>&dp){
        if(t_ptr == t.size()) return 1;
        if(s_ptr == s.size()) return 0;
        if(dp[s_ptr][t_ptr] != -1) return dp[s_ptr][t_ptr];

        int c1 = helper(s, t, s_ptr+1, t_ptr, dp);
        int c2 = 0;
        if(s[s_ptr] == t[t_ptr]) c2 = helper(s, t, s_ptr+1, t_ptr+1, dp);
        return dp[s_ptr][t_ptr] = c1+c2;
    }
};
