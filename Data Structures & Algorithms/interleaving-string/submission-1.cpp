class Solution {
public:
    string s1, s2, s3;
    bool isInterleave(string s1, string s2, string s3) {
        this->s1 = s1;
        this->s2 = s2;
        this->s3 = s3;
        if(s3.size() > s1.size() + s2.size()) return false;

        vector<vector<vector<int>>> dp(s1.size()+1, vector<vector<int>>(s2.size()+1, vector<int>(s3.size()+1, -1)));
        return helper(0, 0, 0, dp);
    }

    bool helper(int start1, int start2, int start3, vector<vector<vector<int>>>& dp){
        if(start1 == s1.size() && start2 == s2.size() && start3 == s3.size()) return true;
        if(start3 == s3.size()) return false;
        if(dp[start1][start2][start3] != -1) return dp[start1][start2][start3];

        bool useS1 = (start1 < s1.size() && s1[start1] == s3[start3]) && helper(start1+1, start2, start3+1, dp);
        bool useS2 = (start2 < s2.size() && s2[start2] == s3[start3]) && helper(start1, start2+1, start3+1, dp);

        return dp[start1][start2][start3] = (useS1 || useS2);
    }
};
