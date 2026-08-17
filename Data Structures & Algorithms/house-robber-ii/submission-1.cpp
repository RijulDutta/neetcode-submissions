class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];

        vector<int>dp1(nums.size(), -1);
        vector<int>dp2(nums.size(), -1);

        int size =  nums.size()-1;

        int c1 = f(nums, 0, size-1, dp1);
        int c2 = f(nums, 1, size, dp2);

        return max(c1, c2);
    }

    int f(vector<int>&nums, int start, int end, vector<int>&dp){
        if(start > end) return 0;
        
        if(dp[start] != -1) return dp[start];

        return dp[start] = max(nums[start] + f(nums, start+2, end, dp), f(nums, start+1, end, dp));
    }
};
