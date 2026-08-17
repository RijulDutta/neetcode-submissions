class Solution {
public:
    int findMin(vector<int> &nums) {
        int size = nums.size();
        int left = 0;
        int right = size-1;
        int mid;

        while(right - left >= 2){
            mid = left + (right-left)/2;

            if(nums[mid] > nums[right]){
                left = mid;
            }else{
                right = mid;
            }
        }

        return min(nums[left], nums[right]);
    }
};
