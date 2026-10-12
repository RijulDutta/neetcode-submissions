class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int>mp;
        for(int i=0; i<nums.size(); i++){
            int curr = nums[i];
            int rem = target - curr;

            if(mp.find(rem) != mp.end()){
                return {mp[rem], i};
            }

            mp[curr] = i;
        }
    }
};
