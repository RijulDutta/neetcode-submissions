class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxIndexReachable = 0;
        for(int i=0; i<nums.size(); i++){
            if(i > maxIndexReachable) return false;
            maxIndexReachable = max(maxIndexReachable, i+nums[i]);
        }
        return true;;
    }
};
