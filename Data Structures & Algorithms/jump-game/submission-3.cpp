class Solution {
public:
    bool canJump(vector<int>& nums) {
        bool res = false;
        vector<int>dp(2*nums.size(), -1);
        return helper(nums, 0, dp);
    }

    bool helper(vector<int>& nums, int start, vector<int>&dp){
        if(start >= nums.size()-1) return true;

        int farthestJump = nums[start];
        if(farthestJump == 0) return false;
        if(dp[start] != -1) return dp[start];

        bool res = false;
        for(int i=1; i<=farthestJump; i++){
            res = res || helper(nums, start+i, dp);
        }

        return dp[start] = res;
    }   
};
