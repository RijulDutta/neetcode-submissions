class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int currMax = nums[0];
        int currMin = nums[0];
        int ans = nums[0];
        int n = nums.size();

        for(int i=1; i<n; i++){
            int val = nums[i];
            if(val < 0) swap(currMax, currMin);

            currMax = max(val, currMax * val);
            currMin = min(val, currMin * val);

            ans = max(ans, currMax);
        }
        return ans;
    }
};
