class Solution {
public:
    vector<vector<int>>ans;
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> inter;
        helper(nums, inter, 0, target);
        return ans;
    }

    void helper(vector<int>&nums, vector<int>&inter, int start, int target){
        if(target == 0){
            ans.push_back(inter);
            return;
        }

        if(start == nums.size() || target < 0) return;

        for(int i=start; i<nums.size(); i++){
            inter.push_back(nums[i]);
            helper(nums, inter, i, target-nums[i]);
            inter.pop_back();
        }
    }
};
