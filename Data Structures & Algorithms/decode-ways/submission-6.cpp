class Solution {
public:
    int numDecodings(string s) {
        vector<int>dp(s.size()+1, 0);
        dp[s.size()] = 1;
        // return helper(s, 0, dp);
        return helper(s, dp);
    }

    // int helper(string&s, int i, vector<int>&dp){
    //     if(i == s.size()) return 1;
    //     if(s[i] == '0') return 0; 
    //     if(dp[i] != -1) return dp[i];
        
    //     int res = helper(s, i+1, dp);

    //     if(i+1 < s.size()){
    //         if(s[i] == '1' || (s[i] == '2' && s[i+1] < '7')){
    //             res += helper(s, i+2, dp);
    //         }
    //     }

    //     return dp[i] = res;
    // }

    int helper(string&s, vector<int>&dp){
        for(int i=s.size()-1; i>=0; i--){
            int res = 0;
            if(s[i] != '0') res = dp[i+1];
            
            if(i+1 < s.size()){
                if(s[i] == '1' || (s[i] == '2') && s[i+1] < '7'){
                    res += dp[i+2];
                }
            } 
            dp[i] = res;
        }
        return dp[0];
    }
};
