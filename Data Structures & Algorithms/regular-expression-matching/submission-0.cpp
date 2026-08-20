class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<int>>dp(s.size()+1, vector<int>(p.size()+1, -1));
        return helper(s, p, 0, 0, dp);
    }

    bool helper(string& s, string& p, int s_ptr, int p_ptr, vector<vector<int>>&dp){
        if(s_ptr == s.size() && p_ptr == p.size()) return true;
        else if(p_ptr == p.size()) return false;

        if(dp[s_ptr][p_ptr] != -1) return dp[s_ptr][p_ptr];


        bool curMatch = (s_ptr < s.size()) && (p[p_ptr] == s[s_ptr] || p[p_ptr] == '.');

        if(p_ptr+1 < p.size() && p[p_ptr+1] == '*'){
            bool c1 = curMatch && helper(s, p, s_ptr+1, p_ptr, dp);
            bool c2 = helper(s, p, s_ptr, p_ptr+2, dp);
            return dp[s_ptr][p_ptr] = c1 || c2;
        }

        if(curMatch) return dp[s_ptr][p_ptr] = helper(s, p, s_ptr+1, p_ptr+1, dp);
        return dp[s_ptr][p_ptr] = false;
    } 
};