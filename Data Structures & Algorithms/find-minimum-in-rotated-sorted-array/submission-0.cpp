class Solution {
public:
    int findMin(vector<int> &nums) {
        int mini = INT_MAX;
        int size = nums.size();
        int left = 0;
        int right = size-1;

        while(left <= right){
            int mid = left + (right-left)/2;

            mini = min(mini, nums[mid]);

            if(nums[mid] > nums[right]){
                left = mid+1;
            }else{
                right = mid-1;
            }
        }

        return mini;
    }
};
