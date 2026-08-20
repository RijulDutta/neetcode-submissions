class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>>dp(word1.size(), vector<int>(word2.size(), -1));
        return helper(word1, word2, 0, 0, dp);
    }

    int helper(string word1, string word2, int ptr1, int ptr2, vector<vector<int>>&dp){
        if(ptr1 == word1.size()) return word2.size() - ptr2; // insert remaining
        if(ptr2 == word2.size()) return word1.size() - ptr1; // delete remaining
        if(dp[ptr1][ptr2] != -1) return dp[ptr1][ptr2];

        if(word1[ptr1] == word2[ptr2]) return dp[ptr1][ptr2] = helper(word1, word2, ptr1+1, ptr2+1, dp);
        int c2 = 1 + helper(word1, word2, ptr1, ptr2+1, dp);    //Insert a character
        int c3 = 1 + helper(word1, word2, ptr1+1, ptr2, dp);    //Delete a character
        int c4 = 1 + helper(word1, word2, ptr1+1, ptr2+1, dp);  //Replace a character

        return dp[ptr1][ptr2] = min(c2, min(c3, c4));
    }
};
