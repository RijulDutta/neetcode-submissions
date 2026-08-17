class Solution {
public:
    vector<vector<int>>ans;
    vector<vector<int>> permute(vector<int>& nums) {
        unordered_set<int>s;
        vector<int> inter;
        helper(nums, inter, s);
        return ans;
    }

    void helper(vector<int>&nums, vector<int>&inter, unordered_set<int>&s){
        if(inter.size() == nums.size()){
            ans.push_back(inter);
            return;
        }

        for(int i=0; i<nums.size(); i++){
            if(s.find(nums[i]) != s.end()) continue;

            inter.push_back(nums[i]);
            s.insert(nums[i]);
            helper(nums, inter, s);
            inter.pop_back();
            s.erase(nums[i]);
        }
    }
};
