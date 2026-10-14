class Solution {
public:
    vector<vector<int>>ans;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int>inter;
        helper(candidates, inter, target, 0);
        return ans;
    }

    void helper(vector<int>& candidates, vector<int>& inter, int target, int start){
        if(target == 0){
            ans.push_back(inter);
            return;
        }

        if(target < 0 || start == candidates.size()) return;

        for(int i=start; i<candidates.size(); i++){
            if(i != start && candidates[i] == candidates[i-1]) continue;

            inter.push_back(candidates[i]);
            helper(candidates, inter, target-candidates[i], i+1);
            inter.pop_back();
        }
    }
};
