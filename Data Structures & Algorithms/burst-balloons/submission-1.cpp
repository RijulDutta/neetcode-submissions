class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n+1, vector<int>(n+1, -1));
        return helper(nums, 0, n-1, dp);
    }

    int helper(vector<int>& nums, int left, int right, vector<vector<int>>&dp){
        if(left > right) return 0;
        if(dp[left][right] != -1) return dp[left][right];

        int best = 0;
        for(int i=left; i<=right; i++){
            int leftVal = (left-1 < 0)? 1 : nums[left-1];
            int rightVal = (right+1 >= nums.size())?  1 : nums[right+1];
            int product = nums[i]*leftVal*rightVal;

            int curr = product + helper(nums, i+1, right, dp) + helper(nums, left, i-1, dp);
            best = max(best, curr);
        }

        return dp[left][right] = best;
    }
};
