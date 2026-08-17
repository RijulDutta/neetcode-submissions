class Solution {
public:
    unordered_set<int>s;
    vector<vector<int>>ans;
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int>inter;
        getPermute(nums, inter);
        return ans;
    }

    void getPermute(vector<int>&nums, vector<int>&inter){
        if(inter.size() == nums.size()){
            ans.push_back(inter);
        }

        for(auto n: nums){
            if(s.find(n) != s.end()) continue;

            inter.push_back(n);
            s.insert(n);
            getPermute(nums, inter);
            inter.pop_back();
            s.erase(n);
        }
    }
};
