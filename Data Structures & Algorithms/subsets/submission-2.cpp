class Solution {
public:
    vector<vector<int>> fans;
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> ans;
        getSubsets(nums, ans, 0);
        return fans;
    }

    void getSubsets(vector<int>& nums, vector<int>&ans, int i){
        if(i == nums.size()) {
            fans.push_back(ans);
            return;
        }

        ans.push_back(nums[i]);
        getSubsets(nums, ans, i+1);
        ans.pop_back();
        getSubsets(nums, ans, i+1);
    }
};
