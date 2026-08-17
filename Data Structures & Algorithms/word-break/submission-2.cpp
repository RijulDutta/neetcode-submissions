class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int>dp(s.size(), -1);
        return helper(s, wordDict, 0, dp);
    }

    bool helper(string s, vector<string>&wordDict, int start, vector<int>&dp){
        if(start == s.size()) return true;
        if(dp[start] != -1) return dp[start];

        for(string& word: wordDict){
            int size = word.size();
            if(start + size <= s.size() && s.substr(start, size) == word){
                if(helper(s, wordDict, start+size, dp)) return dp[start] = true;
            }
        }
        return dp[start] = false;
    }
};
