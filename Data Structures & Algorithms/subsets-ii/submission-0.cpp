class Solution {
public:
    vector<vector<int>>ans;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int>inter;
        sort(nums.begin(), nums.end());
        helper(nums, inter, 0);
        return ans;
    }

    void helper(vector<int>&nums, vector<int>&inter, int start){
        ans.push_back(inter);

        for(int i=start; i<nums.size(); i++){
            if(i != start && nums[i] == nums[i-1]) continue;

            inter.push_back(nums[i]);
            helper(nums, inter, i+1);
            inter.pop_back();
        }
    }
};
