class Solution {
public:
    vector<vector<int>>ans;
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int>inter;
        helper(nums, inter, 0, target);
        return ans;
    }

    void helper(vector<int>&nums, vector<int>&inter, int start, int target){
        if(target == 0){
            ans.push_back(inter);
            return;
        }

        if(target < 0 || start == nums.size()) return;

        inter.push_back(nums[start]);
        helper(nums, inter, start, target-nums[start]);
        inter.pop_back();
        helper(nums, inter, start+1, target);
    }
};
