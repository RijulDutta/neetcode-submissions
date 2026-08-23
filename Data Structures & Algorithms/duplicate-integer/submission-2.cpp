class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int>s;
        for(int it: nums){
            if(s.find(it) != s.end()) return true;
            s.insert(it);
        }
        return false;
    }
};