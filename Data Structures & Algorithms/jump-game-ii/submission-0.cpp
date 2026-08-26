class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0;
        int left = 0;
        int right = 0;

        while(right < nums.size()-1){
            int maxReachable = right;
            for(int i=left; i<=right; i++){
                maxReachable = max(maxReachable, i+nums[i]);
            }
            left = right+1;
            right = maxReachable;
            jumps++;
        }

        return jumps;
    }
};
