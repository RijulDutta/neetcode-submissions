class Solution {
public:
    vector<vector<int>>ans;
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>inter;
        helper(nums, inter, 0);
        return ans;
    }

    void helper(vector<int>&nums, vector<int>&inter, int start){
        if(start == nums.size()){
            ans.push_back(inter);
            return;
        }

        inter.push_back(nums[start]);
        helper(nums, inter, start+1);
        inter.pop_back();
        helper(nums, inter, start+1);
    }
};
