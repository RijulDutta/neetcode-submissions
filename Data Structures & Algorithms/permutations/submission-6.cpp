class Solution {
public:
    vector<vector<int>>ans;
    unordered_set<int>s;
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int>inter;
        helper(nums, inter, 0);
        return ans;
    }

    void helper(vector<int>&nums, vector<int>&inter, int idx){
        if(idx == nums.size()){
            ans.push_back(inter);
            return;
        }

        for(int i=0; i<nums.size(); i++){
            if(s.find(nums[i]) != s.end()) continue;

            inter.push_back(nums[i]);
            s.insert(nums[i]);
            helper(nums, inter, idx+1);
            inter.pop_back();
            s.erase(nums[i]);
        }
    }
};
