class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>inter;
        helper(nums, inter, 0);
        return ans;
    }

    void helper(vector<int>&nums, vector<int>&inter, int i){
        if(i == nums.size()){
            ans.push_back(inter);
            return;
        }

        helper(nums, inter, i+1);
        inter.push_back(nums[i]);
        helper(nums, inter, i+1);
        inter.pop_back();
    }
};
