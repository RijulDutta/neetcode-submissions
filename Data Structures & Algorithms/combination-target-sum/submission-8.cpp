class Solution {
public:
    vector<vector<int>>ans;
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> inter;
        helper(nums, inter, target, 0);
        return ans;
    }

    void helper(vector<int>& nums, vector<int>& inter, int target, int i){
        if(target == 0){
            ans.push_back(inter);
            return;
        }
        if(target < 0) return;
        if(i == nums.size()) return;

        inter.push_back(nums[i]);
        helper(nums, inter, target-nums[i], i);
        inter.pop_back();
        helper(nums, inter, target, i+1); 
    }
};
