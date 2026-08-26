class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int left = 0;
        int sum = 0;
        int maxSum = INT_MIN;

        for(int right = 0; right<nums.size(); right++){
            sum += nums[right];

            if(sum < 0){
                maxSum = max(maxSum, sum);
                sum = 0;
                left = right+1;
                continue; 
            }

            maxSum = max(maxSum, sum);
        }

        return maxSum;
    }
};
