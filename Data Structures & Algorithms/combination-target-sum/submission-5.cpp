class Solution {
public:
    int target;
    vector<vector<int>>ans;
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        this->target = target;
        vector<int>inter;
        helper(nums, inter, 0, 0);
        return ans;
    }

    void helper(vector<int>&nums, vector<int>&inter, int i, int sum){
        if(sum == target){
            ans.push_back(inter);
            return;
        }
        if(sum > target || i == nums.size()) return;

        inter.push_back(nums[i]);
        helper(nums, inter, i, sum + nums[i]);
        inter.pop_back();
        helper(nums, inter, i+1, sum);
    }
};
