class Solution {
public:
    vector<vector<int>>ans;
    unordered_set<int>s;
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> inter;
        helper(nums, inter);
        return ans;
    }

    void helper(vector<int>&nums, vector<int>&inter){
        if(inter.size() == nums.size()){
            ans.push_back(inter);
        }

        for(int i=0; i<nums.size(); i++){
            if(s.find(nums[i]) != s.end()) continue;

            s.insert(nums[i]);
            inter.push_back(nums[i]);
            helper(nums, inter);
            inter.pop_back();
            s.erase(nums[i]);
        }
    }
};
