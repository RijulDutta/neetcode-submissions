class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>words(wordDict.begin(), wordDict.end());
        int n = s.size();

        vector<bool>dp(n+1, false);
        dp[n] = true;

        for(int start=n-1; start>=0; start--){
            for(int end = start+1; end<=n; end++){
                string str = s.substr(start, end-start);
                if(dp[end] && words.find(str) != words.end()){
                    dp[start] = true;
                }
            }
        }
        return dp[0];
    }
};