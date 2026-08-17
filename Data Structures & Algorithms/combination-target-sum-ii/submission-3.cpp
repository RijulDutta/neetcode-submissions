class Solution {
public:
    vector<vector<int>>ans;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> inter;
        helper(candidates, inter, 0, target);
        return ans;
    }

    void helper(vector<int>&candidates, vector<int>&inter, int start, int target){
        if(target == 0){
            ans.push_back(inter);
            return;
        }

        if(start == candidates.size() || target < 0) return;

        for(int i=start; i<candidates.size(); i++){
            if(i != start && candidates[i] == candidates[i-1]) continue;

            inter.push_back(candidates[i]);
            helper(candidates, inter, i+1, target-candidates[i]);
            inter.pop_back();
        }
    }
};
