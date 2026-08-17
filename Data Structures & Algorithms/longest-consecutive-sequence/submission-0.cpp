class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>s;
        int largest = 0;

        for(int i=0; i<nums.size(); i++){
            s.insert(nums[i]);
        }

        for(int i=0; i<nums.size(); i++){
            if(s.find(nums[i] - 1) != s.end()) continue;
            int it = nums[i];
            int count = 0;
            while(s.find(it) != s.end()){
                it++;
                count++;
            }
            largest = max(largest, count);
        }

        return largest;
    }
};
