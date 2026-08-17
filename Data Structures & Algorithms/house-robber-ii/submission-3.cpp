class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];

        int c1 = robLinear(nums, 0, n-2);
        int c2 = robLinear(nums, 1, n-1);

        return max(c1, c2);
    }

    int robLinear(vector<int>&nums, int start, int end){
        //if(start > end) return 0;

        int len = end-start+1;
        vector<int>dp(len+2, 0);

        for(int i=end; i>=start; i--){
            int index = i-start;
            dp[index] = max(nums[i] + dp[index+2], dp[index+1]);
        }

        return dp[0];
    }
};
