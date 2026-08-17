class Solution {
public:
    int search(vector<int>& nums, int target) {
        int size = nums.size();
        int left = 0;
        int right = size-1;
        //Two Cases can occur
        while(left <= right){
            int mid = left + (right-left)/2;
            if(target == nums[mid]) return mid;
            //Case 1: the left->mid is sorted
            if(nums[left] <= nums[mid]){
                if(target < nums[mid] && target >= nums[left]) right = mid-1;
                else left = mid+1;
            }
            //Case 2: the mid->right is sorted
            else{
                if(target > nums[mid] && target <= nums[right]) left = mid+1;
                else right = mid-1;
            }
        }

        return -1;
    }
};
