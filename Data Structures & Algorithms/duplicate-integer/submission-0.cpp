class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        set<int> s;
        for(int it : nums)
            s.insert(it);

        if(nums.size() == s.size()) return false;
        return true;
    }
};